# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake
import re
import ast_cython
from license import C_LICENSE_COMMENT

CMODULE_NAME = 'cGraphQLAst'


def struct_name(type):
  return 'GraphQLAst' + type


def return_type(type):
  if type == 'OperationKind' or type == 'string':
    return 'const char *'

  if type == 'boolean':
    return 'int'

  return 'const %s *' % struct_name(type)


def field_prototype(owning_type, type, name, nullable, plural):
  st_name = struct_name(owning_type)
  if plural:
    return 'int %s_get_%s_size(const %s *node)' % (
      st_name, snake(name), st_name)
  else:
    ret_type = return_type(type)
    return '%s %s_get_%s(const %s *node)' % (
      ret_type, st_name, snake(name), st_name)


def license_comment():
  return re.sub(re.compile(r'^[ ]*', re.MULTILINE), '#', C_LICENSE_COMMENT) + '# @generated'


class Printer(object):
  '''Printer for the Ast low-level C cython interface.

  '''
  def start_file(self):
    print license_comment() + '''

cdef extern from "GraphQLAst.h":

'''

  def end_file(self):
    pass

  def start_type(self, name):
    # Forward declarations for AST nodes.
    st_name = struct_name(name)
    print '    struct ' + st_name + ':'
    print '        pass'
    self._current_type = name
    self._current_type_fields = []

  def field(self, type, name, nullable, plural):
    self._current_type_fields.append((type, name, nullable, plural))
    print '    ' + field_prototype(self._current_type, type, name, nullable, plural)

  def end_type(self, name):
    print
    print

  def start_union(self, name):
    print '    struct ' + struct_name(name) + ':'
    print '        pass'

  def union_option(self, option):
    pass

  def end_union(self, name):
    print
