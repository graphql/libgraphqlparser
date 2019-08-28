# Copyright (c) 2015-present, Facebook, Inc.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
from __future__ import print_function
from casing import camel, title
from license import C_LICENSE_COMMENT

class Printer(object):
  def __init__(self):
    pass

  def start_file(self):
    print(C_LICENSE_COMMENT + '''/** @generated */

#pragma once

#include "Ast.h"

namespace facebook {
namespace graphql {
namespace ast {
namespace visitor {

class AstVisitor {
public:
  virtual ~AstVisitor() {}
''')

  def end_file(self):
    print('};') # end AstVisitor
    print()
    print('}')
    print('}')
    print('}')
    print('}')

  def start_type(self, name):
    titleName = title(name)
    camelName = camel(titleName)
    print('  virtual bool visit%s(const %s &%s) { return true; }' % (
      titleName,
      titleName,
      camelName))
    print('  virtual void endVisit%s(const %s &%s) { }' % (
      titleName,
      titleName,
      camelName))
    print()

  def end_type(self, name):
    pass

  def field(self, type, name, nullable, plural):
    pass

  def start_union(self, name):
    pass

  def union_option(self, option):
    pass

  def end_union(self, name):
    pass
