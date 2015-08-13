/**
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 */
#pragma once

/***
 * This file contains definitions that need to be shared by the parser
 * and the lexer.
 */

#define YY_DECL                                 \
  int yylex(YYSTYPE *yylval_param, YYLTYPE *yylloc_param)

YY_DECL;

yy::GraphQLParserImpl::syntax_error make_error(const yy::location &loc, const std::string &str);
