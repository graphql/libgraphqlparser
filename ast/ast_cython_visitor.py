# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake
import ast_cython_c


class Printer(object):
  '''Printer for a visitor in cython
  '''

  def __init__(self):
    self._types = []

  def start_file(self):
    print ast_cython_c.license_comment() + '''

cdef extern from "GraphQLAstVisitor.h":

    struct GraphQLAstNode:
        pass


'''

  def start_type(self, name):
    self._types.append(name)
    _map = {'snake': snake(name), 'name': name}
    print '    struct %s:' % ast_cython_c.struct_name(name)
    print '        pass'
    print '    ctypedef int (*visit_%(snake)s_func)(GraphQLAst%(name)s*, void*)' % _map
    print '    ctypedef void (*end_visit_%(snake)s_func)(GraphQLAst%(name)s*, void*)' % _map

  def field(self, type, name, nullable, plural):
    pass

  def end_type(self, name):
    pass

  def end_file(self):
    print '    struct GraphQLAstVisitorCallbacks:'
    for name in self._types:
      _map = {'snake': snake(name)}
      print '        visit_%(snake)s_func visit_%(snake)s' % _map
      print '        end_visit_%(snake)s_func end_visit_%(snake)s' % _map

    print '''
    void graphql_node_visit(GraphQLAstNode *node,
                            GraphQLAstVisitorCallbacks *callbacks,
                            void *userData)
'''

  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    pass
