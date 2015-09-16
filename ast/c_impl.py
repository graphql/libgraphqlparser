# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from c import field_prototype, return_type, struct_name
from casing import title
from license import C_LICENSE_COMMENT

class Printer(object):
  '''Printer for the implementation of the pure C interface to the AST.
  '''

  def __init__(self):
    self._current_type = None

  def start_file(self):
    print C_LICENSE_COMMENT + '''/** @generated */

#include "GraphQLAst.h"
#include "../Ast.h"

using namespace facebook::graphql::ast;
'''

  def end_file(self):
    pass

  def start_type(self, name):
    self._current_type = name

  def field(self, type, name, nullable, plural):
    print field_prototype(self._current_type, type, name, nullable, plural) + ' {'
    print '  const auto *realNode = (const %s *)node;' % self._current_type
    title_name = title(name)
    call_get = 'realNode->get%s()' % title_name
    if plural:
      if nullable:
        print '  return %s ? %s->size() : 0;' % (call_get, call_get)
      else:
        print '  return %s.size();' % call_get
    else:
      if type in ['string', 'OperationKind', 'boolean']:
        print '  return %s;' % call_get
      else:
        fmt = '  return (const struct %s *)%s%s;'
        print fmt % (struct_name(type), '' if nullable else '&', call_get)

    print '}'

  def end_type(self, name):
    pass

  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    pass
