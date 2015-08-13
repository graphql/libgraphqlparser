/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant 
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "GraphQLParser.h"
#include "../GraphQLParser.h"
#include "../AstNode.h"

#include <cstdlib>

struct GraphQLAstNode *graphql_parse_string(const char *text, const char **error) {
  return (struct GraphQLAstNode *)facebook::graphql::parseString(text, error).release();
}

struct GraphQLAstNode *graphql_parse_file(FILE *file, const char **error) {
  return (struct GraphQLAstNode *)facebook::graphql::parseFile(file, error).release();
}

void graphql_error_free(const char *error) {
  std::free((void *)error);
}
