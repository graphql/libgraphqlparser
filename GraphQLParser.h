/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant 
 * of patent rights can be found in the PATENTS file in the same directory.
 */

/**
 * The purpose of this file is to provide a nice interface to parsing
 * GraphQL, rather than the old-fashioned interface provided by bison
 * and flex.
 */

#pragma once

#include <memory>
#include <stdio.h>

namespace facebook {
namespace graphql {

namespace ast {
  class Node;
}

/**
 * Parse the given GraphQL source string, returning an AST. Returns
 * nullptr on error and, if error is not null, places a string
 * describing what went wrong in error that must be freed with free(3).
 */
std::unique_ptr<ast::Node> parseString(const char *text, const char **error);

/**
 * Read and parse GraphQL source from the given file, returning an
 * AST. Returns nullptr on error and, if error is not null, places an
 * error string in error that must be freed with free(3).
 */
std::unique_ptr<ast::Node> parseFile(FILE *file, const char **error);

}
}
