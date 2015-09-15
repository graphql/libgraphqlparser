# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake, title

from license import C_LICENSE_COMMENT

from ast_c import struct_name

def field_accessor(owning_type, type, name, nullable, plural):
  preface =  '  struct %s *node;\n' % struct_name(owning_type)
  preface += '  TypedData_Get_Struct(self, struct %s, &%s_type, node);\n' % (
            struct_name(owning_type), snake(owning_type))

  call_get = "%s_get_%s" % (struct_name(owning_type), snake(name))
  func = '%s_get_%s' % (snake(owning_type), snake(name))
  ret = '  return '

  if plural:
    func += '_size'
    call_get += '_size(node)'
    ret += 'INT2FIX(%s)' % call_get
  else:
    call_get += '(node)'
    if nullable:
      preface += '  if (%s == NULL) return Qnil;\n' % call_get
    if type in ['string', 'OperationKind']:
      ret += 'rb_str_new_cstr(%s)' % call_get
    elif type in ['boolean']:
      ret += 'INT2BOOL(%s)' % call_get
    else:
      ret += 'TypedData_Wrap_Struct(%s_class, &%s_type, (void*)%s)' % (
          snake(type), snake(type), call_get)

  return 'static VALUE ' + func + '(VALUE self) {\n' + preface + ret + ';\n}\n'

def type_visitor_body(name):
  ret =  '  VALUE parent = (VALUE)user_data;\n'
  ret += '  VALUE param = TypedData_Wrap_Struct(%s_class, &%s_type, (void*)%s);\n' % (
      snake(name), snake(name), snake(name))
  return ret

def type_visitor(name):
  prototype = 'static int visit_%s(const struct GraphQLAst%s *%s, void *user_data) {\n' % (
      snake(name), name, snake(name))
  ret = '  return rb_funcall(parent, visit_%s_id, 1, param) != skip_children;\n' % (
      snake(name))
  return prototype + type_visitor_body(name) + ret + '}\n'

def type_end_visitor(name):
  prototype = 'static void end_visit_%s(const struct GraphQLAst%s *%s, void *user_data) {\n' % (
      snake(name), name, snake(name))
  ret = '  rb_funcall(parent, end_visit_%s_id, 1, param);\n' % (
      snake(name))
  return prototype + type_visitor_body(name) + ret + '}\n'


class Printer(object):
  '''Printer for Ruby wrapper's C implementation.
  '''

  def __init__(self):
    self._current_type = None
    self._class_init_buffer = ''
    self._func_init_buffer = ''
    self._sym_init_buffer = ''
    self._cbs_init_buffer = ''

  def start_file(self):
    print C_LICENSE_COMMENT + '''/** @generated */

#include "c/GraphQLParser.h"
#include "c/GraphQLAstNode.h"
#include "c/GraphQLAstVisitor.h"
#include "c/GraphQLAst.h"

#include <ruby.h>

#include "graphql_ruby.h"

VALUE ast_class, parse_error, skip_children;

static struct GraphQLAstVisitorCallbacks cbs;

static void free_ast(void *x) {
  graphql_node_free((struct GraphQLAstNode*)x);
}

static const rb_data_type_t ast_type = { "AST", {0, free_ast,}, };

static VALUE INT2BOOL(int x) {
  return x ? Qtrue : Qfalse;
}

'''

  def end_file(self):
    print '''
static VALUE parse(VALUE self, VALUE text) {
  char *input;
  struct GraphQLAstNode *n;
  const char *error;

  input = StringValueCStr(text);

  n = graphql_parse_string(input, &error);

  if (n == NULL) {
      VALUE exc = rb_exc_new_cstr(parse_error, error);
      graphql_error_free(error);
      rb_exc_raise(exc);
      return Qnil;
  }

  return TypedData_Wrap_Struct(ast_class, &ast_type, n);
}

static VALUE accept(VALUE self, VALUE ast) {
  struct GraphQLAstNode *n;

  TypedData_Get_Struct(ast, struct GraphQLAstNode, &ast_type, n);

  graphql_node_visit(n, &cbs, (void*)self);

  return Qnil;
}

void init_graphql(void) {
  VALUE module, parser, visitor, node_class;

  module = rb_define_module("GraphQL");

  parser = rb_define_module_under(module, "Parser");
  rb_define_module_function(parser, "parse", parse, 1);

  visitor = rb_define_class_under(module, "Visitor", rb_cObject);
  rb_define_method(visitor, "accept", accept, 1);

  parse_error = rb_define_class_under(module, "ParseError", rb_eArgError);

  ast_class = rb_define_class_under(module, "AST", rb_cObject);

  node_class = rb_define_class_under(module, "Node", rb_cObject);

  skip_children = rb_class_new_instance(0, NULL, rb_cObject);
  rb_define_const(module, "SKIP_CHILDREN", skip_children);

'''
    print self._class_init_buffer
    print self._func_init_buffer
    print self._sym_init_buffer
    print self._cbs_init_buffer
    print '}'

  def start_type(self, name):
    # define the values declared 'extern' in the header
    print 'const rb_data_type_t %s_type = { "%s", {}, };' % (
            snake(name), struct_name(name))
    print 'VALUE %s_class;' % snake(name)
    print 'ID visit_%s_id;' % snake(name)
    print 'ID end_visit_%s_id;' % snake(name)

    # build the two visitor methods
    print type_visitor(name)
    print type_end_visitor(name)

    # init the class
    self._class_init_buffer += '  %s_class = rb_define_class_under(module, "%s", node_class);\n' % (
            snake(name), name)

    # init the symbols
    self._sym_init_buffer += '  visit_%s_id = rb_intern("visit_%s");\n' % (
        snake(name), snake(name))
    self._sym_init_buffer += '  end_visit_%s_id = rb_intern("end_visit_%s");\n' % (
        snake(name), snake(name))

    # init the visitor struct
    self._cbs_init_buffer += '  cbs.visit_%s = visit_%s;\n' % (
            snake(name), snake(name))
    self._cbs_init_buffer += '  cbs.end_visit_%s = end_visit_%s;\n' % (
            snake(name), snake(name))
    self._current_type = name

  def field(self, type, name, nullable, plural):
    owning_type = self._current_type

    # build the field accessor method
    print field_accessor(owning_type, type, name, nullable, plural)

    # associate the method with the class
    trailer = '_size' if plural else ''
    self._func_init_buffer += '  rb_define_method(%s_class, "%s%s", %s_get_%s%s, 0);\n' % (
            snake(owning_type), snake(name), trailer,
            snake(owning_type), snake(name), trailer)

  def end_type(self, name):
    print

  def start_union(self, name):
    print 'const rb_data_type_t %s_type = { "%s", {}, };' % (snake(name), struct_name(name))
    print 'VALUE %s_class;' % snake(name)

  def union_option(self, option):
    pass

  def end_union(self, name):
    print
