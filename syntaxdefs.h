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

yy::GraphQLParserImpl::syntax_error make_error(const yy::location &loc, const std::string &str);

struct LexerExtra {
  std::string str;
  yy::location loc;
};
