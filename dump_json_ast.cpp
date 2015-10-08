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
#include "c/GraphQLAstToJSON.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>


using std::cout;
using std::cerr;
using std::endl;
using std::fopen;
using std::fclose;
using std::free;


int main(int argc, char **argv) {
  const char *error;
  FILE * in;
  if (argc > 1) {
    in = fopen(argv[1], "r");
  } else {
    in = stdin;
  }
  auto AST = facebook::graphql::parseFile(in, &error);
  if (argc > 1) {
    fclose(in);
  }
  if (!AST) {
    cerr << "Parser failed with error: " << error << endl;
    free((void *)error);
    return 1;
  }

  const char *json = graphql_ast_to_json((const struct GraphQLAstNode *)AST.get());
  puts(json);
  free((void *)json);

  return 0;
}
