# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake
import ast_cython_c

CMODULE_NAME = 'cGraphQLAstVisitor'


class Printer(object):
  '''Printer for a visitor implementation in cython
  '''

  def __init__(self):
    self._types = []

  def start_file(self):
    print ast_cython_c.license_comment() + '''

from libc.string cimport memset
cimport %(cmodule)s
cimport GraphQLAstNode
cimport cGraphQLAstNode
cimport cGraphQLAst
cimport GraphQLAst

cdef class GraphQLAstVisitor:

    def visit_node(self, node):
      cdef %(cmodule)s.GraphQLAstVisitorCallbacks callbacks_c
      memset(&callbacks_c, 0, sizeof(callbacks_c))
      set_callbacks(&callbacks_c)
      cdef void* userData = <void *>self
      cdef cGraphQLAstNode.GraphQLAstNode *node_c;
      node_c = (<GraphQLAstNode.GraphQLAstNode?>node)._node
      %(cmodule)s.graphql_node_visit(node_c, &callbacks_c, userData)

''' % {'cmodule': CMODULE_NAME}

  def start_type(self, name):
    self._types.append(name)

  def field(self, type, name, nullable, plural):
    pass

  def end_type(self, name):
    pass

  def end_file(self):
    for type in self._types:
      _map = {'snake': snake(type), 'name': type, 'cmodule': CMODULE_NAME}
      print '''

cdef int _visit_%(snake)s(%(cmodule)s.GraphQLAst%(name)s* node, void* userData, int end):
    cdef GraphQLAstVisitor visitor
    ast = GraphQLAst.GraphQLAst%(name)s.create(node)
    if userData is not NULL:
      visitor = <GraphQLAstVisitor>userData
      attname = 'end_visit_%(snake)s' if end else 'visit_%(snake)s'
      fun = getattr(visitor, attname, None)
      if fun is not None:
        retval = fun(ast)
        return 0 if retval is None else retval

cdef int visit_%(snake)s(%(cmodule)s.GraphQLAst%(name)s* node, void* userData):
    return _visit_%(snake)s(node, userData, 0)

cdef void end_visit_%(snake)s(%(cmodule)s.GraphQLAst%(name)s* node, void* userData):
    _visit_%(snake)s(node, userData, 1)
''' % _map

    print '''

cdef set_callbacks(%(cmodule)s.GraphQLAstVisitorCallbacks *callbacks):
''' % {'cmodule': CMODULE_NAME}

    for type in self._types:
      _map = {'snake': snake(type), 'name': type, 'cmodule': CMODULE_NAME}
      print '''
    callbacks.visit_%(snake)s = &visit_%(snake)s
    callbacks.end_visit_%(snake)s = &end_visit_%(snake)s
''' % _map


  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    pass
