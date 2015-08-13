/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "AstNode.h"
#include "GraphQLParser.h"
#include "JsonVisitor.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>


using std::cout;
using std::cerr;
using std::endl;
using std::free;


int main(int argc, char **argv) {
  const char *error;
  auto AST = facebook::graphql::parseFile(stdin, &error);
  if (!AST) {
    cerr << "Parser failed with error: " << error << endl;
    free((void *)error);
    return 1;
  }

  facebook::graphql::ast::visitor::JsonVisitor visitor;
  AST->accept(&visitor);

  cout << visitor.getResult() << endl;

  return 0;
}
