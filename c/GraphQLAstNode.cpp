/**
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 */

#include "GraphQLAstNode.h"
#include "../AstNode.h"

using facebook::graphql::ast::Node;

void graphql_node_get_location(const struct GraphQLAstNode *node,
                               struct GraphQLAstLocation *location) {
  const Node *realNode = (Node *)node;
  const auto &loc = realNode->getLocation();
  location->beginLine = loc.begin.line;
  location->beginColumn = loc.begin.column;
  location->endLine = loc.end.line;
  location->endColumn = loc.end.column;
}

void graphql_node_free(struct GraphQLAstNode *node) {
  delete (Node *)node;
}
