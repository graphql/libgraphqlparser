/**
 * Copyright (c) 2016, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include <gtest/gtest.h>

#include "Ast.h"
#include "GraphQLParser.h"
#include "c/GraphQLAstToJSON.h"

using facebook::graphql::parseString;

TEST(JsonVisitorTests, NullValueEmitsValidJSONWithoutTrailingComma) {
  const char *error = nullptr;
  auto AST = parseString("{field(arg: null)}", &error);
  ASSERT_STREQ(nullptr, error) << "GraphQL parser error: " << error;
  const char *json = graphql_ast_to_json(reinterpret_cast<const struct GraphQLAstNode *>(AST.get()));

  EXPECT_STREQ(
    json,
    "{\"kind\":\"Document\",\"loc\":{\"start\": {\"line\": 1,\"column\":1}, \"end\": {\"line\":1,\"column\":19}},\"definitions\":[{\"kind\":\"OperationDefinition\",\"loc\":{\"start\": {\"line\": 1,\"column\":1}, \"end\": {\"line\":1,\"column\":19}},\"operation\":\"query\",\"name\":null,\"variableDefinitions\":null,\"directives\":null,\"selectionSet\":{\"kind\":\"SelectionSet\",\"loc\":{\"start\": {\"line\": 1,\"column\":1}, \"end\": {\"line\":1,\"column\":19}},\"selections\":[{\"kind\":\"Field\",\"loc\":{\"start\": {\"line\": 1,\"column\":2}, \"end\": {\"line\":1,\"column\":18}},\"alias\":null,\"name\":{\"kind\":\"Name\",\"loc\":{\"start\": {\"line\": 1,\"column\":2}, \"end\": {\"line\":1,\"column\":7}},\"value\":\"field\"},\"arguments\":[{\"kind\":\"Argument\",\"loc\":{\"start\": {\"line\": 1,\"column\":8}, \"end\": {\"line\":1,\"column\":17}},\"name\":{\"kind\":\"Name\",\"loc\":{\"start\": {\"line\": 1,\"column\":8}, \"end\": {\"line\":1,\"column\":11}},\"value\":\"arg\"},\"value\":{\"kind\":\"NullValue\",\"loc\":{\"start\": {\"line\": 1,\"column\":13}, \"end\": {\"line\":1,\"column\":17}}}}],\"directives\":null,\"selectionSet\":null}]}}]}"
  );

  free((void *)json);
}
