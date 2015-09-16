# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake
import ast_cython_c
import ast_cython


def field_prototype(owning_type, type, name, nullable, plural):
  if plural:
    return 'def get_%s_size(self):' % snake(name)
  else:
    return 'def get_%s(self):' % snake(name)


class Printer(object):
  '''Printer for a visitor in cython
  '''

  def __init__(self):
    self._types = []

  def start_file(self):
    print ast_cython_c.license_comment() + '''

cimport %s

cdef class GraphQLAst:
   """Base class for all Ast pieces"""

   def __init__(self, name=None, alias=None):
       self.name = name
       self.alias = alias

''' % ast_cython_c.CMODULE_NAME

  def start_type(self, name):
    self._current_type = name
    _map = {'snake': snake(name), 'name': name}
    print '''

cdef class %(name)s(GraphQLAst):

    @staticmethod
    cdef create(%(cmodule)s.%(name)s *thing):
        node = %(name)s()
        node._wrapped = thing
        return node

''' % {'name': ast_cython_c.struct_name(name),
       'cmodule': ast_cython_c.CMODULE_NAME}

  def field(self, type, name, nullable, plural):
    pass
    #print field_prototype(self._current_type, type, name, nullable, plural)

  def end_type(self, name):
    print
    print

  def end_file(self):
    pass

  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    pass
