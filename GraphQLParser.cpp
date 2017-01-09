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
#include "syntaxdefs.h"

namespace facebook {
namespace graphql {

// Given properly-configured yylex, run the parser and return the
// result.
static std::unique_ptr<ast::Node> doParse(const char **outError, yyscan_t scanner, bool enableSchema) {
  Node *outAST;
  yy::GraphQLParserImpl parser(enableSchema, &outAST, outError, scanner);
  int failure = parser.parse();
  return !failure ? std::unique_ptr<ast::Node>(outAST) : nullptr;
}

static std::unique_ptr<ast::Node> parseStringImpl(const char *text, const char **error, bool enableSchema) {
  yyscan_t scanner;
  struct LexerExtra extra;
  yylex_init_extra(&extra, &scanner);
  YY_BUFFER_STATE buffer = yy_scan_string(text, scanner);
  yy_switch_to_buffer(buffer, scanner);

  auto result = doParse(error, scanner, enableSchema);
  yylex_destroy(scanner);
  return result;
}

std::unique_ptr<ast::Node> parseString(const char *text, const char **error) {
  return parseStringImpl(text, error, false);
}

std::unique_ptr<ast::Node> parseStringWithExperimentalSchemaSupport(
    const char *text, const char **error) {
  return parseStringImpl(text, error, true);
}

static std::unique_ptr<ast::Node> parseFileImpl(
    FILE *file, const char **error, bool enableSchema) {
  yyscan_t scanner;
  struct LexerExtra extra;
  yylex_init_extra(&extra, &scanner);
  yyset_in(file, scanner);

  auto result = doParse(error, scanner, enableSchema);
  yylex_destroy(scanner);

  return result;
}

std::unique_ptr<ast::Node> parseFile(FILE *file, const char **error) {
  return parseFileImpl(file, error, false);
}

std::unique_ptr<ast::Node> parseFileWithExperimentalSchemaSupport(
    FILE *file, const char **error) {
  return parseFileImpl(file, error, true);
}


}
}
