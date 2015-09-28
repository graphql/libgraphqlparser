/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include <gtest/gtest.h>
#include <cstdlib>

#include "Ast.h"
#include "GraphQLParser.h"

using namespace facebook::graphql;
using namespace facebook::graphql::ast;


static void expectError(const char *queryStr, const char *expectedError) {
  const char *actualError;
  auto ast = parseString(queryStr, &actualError);

  EXPECT_FALSE(ast);
  EXPECT_STREQ(expectedError, actualError);

  std::free((void *)actualError);
}

static void expectSuccess(const char *queryStr) {
  const char *actualError = nullptr;
  auto ast = parseString(queryStr, &actualError);

  EXPECT_TRUE(ast != nullptr);
  EXPECT_FALSE(actualError);

  std::free((void *)actualError);
}

static void checkSimpleError() {
  expectError("query myquery on type { field }",
              "1.15-16: syntax error, unexpected on, expecting ( or @ or {");
}

TEST(ParserTests, RejectsUnrecognizedCharacter) {
  expectError("query myquery { field };",
              "1.24: unrecognized character ;");
}

TEST(ParserTests, LocationTracking) {
  SCOPED_TRACE("LocationTracking");
  checkSimpleError();
}

TEST(ParserTests, LocationTrackingResetsAcrossInputs) {
  {
    SCOPED_TRACE("LocationTrackingResetsAcrossInputsFirstTime");
    checkSimpleError();
  }

  {
    SCOPED_TRACE("LocationTrackingResetsAcrossInputsSecondTime");
    checkSimpleError();
  }

}

TEST(ParserTests, UsefulErrors) {
  expectError("{ ...MissingOn }\nfragment MissingOn Type",
              "2.20-23: syntax error, unexpected IDENTIFIER, expecting on");

  expectError("{ field: {} }",
              "1.10: syntax error, unexpected {");

  expectError(
    "notanoperation Foo { field }",
    "1.1-14: syntax error, unexpected IDENTIFIER, expecting fragment or "
    "mutation or query or {");

  expectError("...",
              "1.1-3: syntax error, unexpected ..., expecting fragment or "
              "mutation or query or {");
}

TEST(ParserTests, AcceptsVariableInlineValues) {
  expectSuccess("{ field(complex: { a: { b: [ $var ] } }) }");
}

TEST(ParserTests, RejectsVariablesInConstantValues) {
  expectError("query Foo($x: Complex = { a: { b: [ $var ] } }) { field }",
              "1.37-40: syntax error, unexpected VARIABLE");
}

TEST(ParserTests, RejectsFragmentsNamedOn) {
  expectError("fragment on on on { on }",
              "1.10-11: syntax error, unexpected on");
}

TEST(ParserTests, RejectsFragmentSpreadOfOn) {
  expectError("{ ...on }",
              "1.9: syntax error, unexpected }");
};

TEST(ParserTests, RejectsNullValue) {
  expectError("{ fieldWithNullableStringInput(input: null) }",
              "1.39-42: syntax error, unexpected null");
}

TEST(ParserTests, AllowsNonKeywordsForNames) {
  const char *nonKeywords[] = {
    "on",
    "fragment",
    "query",
    "mutation",
    "true",
    "false"
  };

  for (int ii = 0; ii < sizeof(nonKeywords) / sizeof(nonKeywords[0]); ++ii) {
    const char *keyword = nonKeywords[ii];
    const char *fragmentName = !strcmp(keyword, "on") ? "a" : keyword;

    std::ostringstream str;

    str << "query " << keyword << "{\n"
        << "  ... " << fragmentName << '\n'
        << "  ... on " << keyword << " { field }\n"
        << "}\n"
        << "fragment " << fragmentName << " on Type {"
        << "  " << keyword << '(' << keyword << ": $" << keyword << ") @" << keyword << '(' << keyword << ": " << keyword << ")\n"
        << "}\n";
    expectSuccess(str.str().c_str());
  }
}
