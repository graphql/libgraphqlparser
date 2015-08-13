/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant 
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "GraphQLParser.h"

#include "AstNode.h"

#include "parser.tab.hpp"
#include "lexer.h"

void lexer_reset();

namespace facebook {
namespace graphql {

// Given properly-configured yylex, run the parser and return the
// result.
static std::unique_ptr<ast::Node> doParse(const char **outError) {
  Node *outAST;
  lexer_reset();
  yy::GraphQLParserImpl parser(&outAST, outError);
  int failure = parser.parse();
  yylex_destroy();
  return !failure ? std::unique_ptr<ast::Node>(outAST) : nullptr;
}

std::unique_ptr<ast::Node> parseString(const char *text, const char **error) {
  YY_BUFFER_STATE buffer = yy_scan_string(text);
  yy_switch_to_buffer(buffer);

  return doParse(error);
}

std::unique_ptr<ast::Node> parseFile(FILE *file, const char **error) {
  yyin = file;

  return doParse(error);
}

}
}
