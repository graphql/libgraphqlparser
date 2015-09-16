# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake
import re
import ast_cython_c

CMODULE_NAME = 'GraphQLAst'


class Printer(object):
  '''Printer for the Ast Python Object level cython interface.

  '''
  def start_file(self):
    print ast_cython_c.license_comment() + '''

cimport %s


cdef class GraphQLAst:
    """Base class for all Ast pieces"""
    pass

''' % ast_cython_c.CMODULE_NAME

  def end_file(self):
    pass

  def start_type(self, name):
    st_name = ast_cython_c.struct_name(name)
    print '''
cdef class %(name)s(GraphQLAst):

    cdef %(cmodule)s.%(name)s* _wrapped

    @staticmethod
    cdef create(cGraphQLAst.%(name)s *thing)

''' % {'name': st_name, 'cmodule': ast_cython_c.CMODULE_NAME}
    self._current_type = name

  def field(self, type, name, nullable, plural):
    pass

  def end_type(self, name):
    print
    print

  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    print
