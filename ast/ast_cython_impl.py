# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake
from license import C_LICENSE_COMMENT
import ast_cython

CMODULE_NAME = 'cGraphQLAst'

def field_prototype(owning_type, type, name, nullable, plural):
  _map = {'st_name': ast_cython.struct_name(owning_type),
          'snake': snake(name),
          'cmodule': CMODULE_NAME}
  if plural:
    return '    def get_%(snake)s_size(self):\n        return %(cmodule)s.%(st_name)s_get_%(snake)s_size(self._wrapped)' % _map
  else:
    return ''
    ret_type = ast_cython.return_type(type)
    return '%s %s_get_%s(const %s *node)' % (
      ret_type, st_name, snake(name), st_name)

class Printer(object):
  '''Printer for a visitor in cython
  '''

  def __init__(self):
    self._types = []

  def start_file(self):
    print ast_cython.license_comment() + '''

cimport %s

''' % CMODULE_NAME

  def start_type(self, name):
    self._current_type = name
    _map = {'snake': snake(name), 'name': name}
    print '''


cdef class %(name)s:

    cdef %(cmodule)s.%(name)s* _wrapped

''' % {'name': ast_cython.struct_name(name),
       'cmodule': CMODULE_NAME}

  def field(self, type, name, nullable, plural):
    print field_prototype(self._current_type, type, name, nullable, plural)

  def end_type(self, name):
    pass

  def end_file(self):
    pass

  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    pass
