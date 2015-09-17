/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct GraphQLAstNode;

/**
 * Serialize the given AST to JSON. The returned C string must be
 * freed with free().
 */
const char *graphql_ast_to_json(const struct GraphQLAstNode *node);

#ifdef __cplusplus
}
#endif
