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
  const char *actualError = nullptr;
  auto ast = parseString(queryStr, &actualError);

  EXPECT_FALSE(ast);
  EXPECT_STREQ(expectedError, actualError);

  std::free((void *)actualError);
}

static void expectSuccess(const char *queryStr) {
  const char *actualError = nullptr;
  auto ast = parseString(queryStr, &actualError);

  EXPECT_TRUE(ast != nullptr);
  EXPECT_STREQ(nullptr, actualError);

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

TEST(ParserTests, RejectsControlCharacter) {
  expectError("query myQuery { \a }",
              "1.17: unrecognized character \\a");
}

TEST(ParserTests, AcceptsUnicodeBOM) {
  expectSuccess("\xef\xbb\xbfquery myquery { field }");
  expectSuccess("query myquery\xef\xbb\xbf{ field }");
}

TEST(ParserTests, ReportsErrorLocationAfterIgnoredBOM) {
  expectError("\xef\xbb\xbfquery myquery { field };",
              "1.27: unrecognized character ;");

}

TEST(ParserTests, RejectsPartialBOM) {
  expectError("\xefquery myquery { field };",
              "1.1: unrecognized character \\xef");
}

TEST(ParserTests, RejectsVerticalTab) {
  expectError("\v", "1.1: unrecognized character \\v");
}

TEST(ParserTests, RejectsFormFeed) {
  expectError("\f", "1.1: unrecognized character \\f");
}

TEST(ParserTests, RejectsNoBreakSpace) {
  expectError("\xa0", "1.1: unrecognized character \\xa0");
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

TEST(ParserTests, LocationTrackingCollapsesCRLF) {
  expectError("\r\n;", "2.1: unrecognized character ;");
}

TEST(ParserTests, AcceptsEmptyString) {
  expectSuccess("{ field(arg:\"\") }");
}

TEST(ParserTests, UnterminatedString) {
  expectError("\"", "1.1: Unterminated string at EOF");
  expectError("\"\n\"", "1.1-2: Unterminated string");
}

TEST(ParserTests, RejectControlCharacterInString) {
  expectError("{ field(arg:\"\b\") }", "1.13-14: unrecognized character \\b");
}

TEST(ParserTests, RejectsBadXEscapeSequence) {
  expectError("{ field(arg:\"\\x\") }", "1.13-15: bad escape sequence \\x");
}

TEST(ParserTests, RejectsIncompleteUnicodeEscape) {
  expectError("{ field(arg:\"\\u1\") }", "1.13-15: bad Unicode escape sequence");
}

TEST(ParserTests, RejectsUnicodeEscapeWithBadChars) {
  expectError("{ field(arg:\"\\u0XX1\") }", "1.13-15: bad Unicode escape sequence");
  expectError("{ field(arg:\"\\uXXXX\") }", "1.13-15: bad Unicode escape sequence");
  expectError("{ field(arg:\"\\uFXXX\") }", "1.13-15: bad Unicode escape sequence");
  expectError("{ field(arg:\"\\uXXXF\") }", "1.13-15: bad Unicode escape sequence");
}

TEST(ParserTests, TracksLocationAcrossStrings) {
  expectError("{ field(arg:\"\\uFEFF\\n\") };",
              "1.26: unrecognized character ;");
}

TEST(ParserTests, UsefulErrors) {
  expectError("{ ...MissingOn }\nfragment MissingOn Type",
              "2.20-23: syntax error, unexpected IDENTIFIER, expecting on");

  expectError("{ field: {} }",
              "1.10: syntax error, unexpected {");

  expectError(
    "notanoperation Foo { field }",
    "1.1-14: syntax error, unexpected IDENTIFIER");

  expectError("...",
              "1.1-3: syntax error, unexpected ...");
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

TEST(ParserTests, AcceptsSimpleQuery) {
  expectSuccess("query MyQuery { myfield }");
}

TEST(ParserTests, AcceptsSimpleMutation) {
  expectSuccess("mutation MyMut { myfield }");
}

TEST(ParserTests, AcceptsSimpleSubscription) {
  expectSuccess("subscription MySub { myfield }");
}

TEST(ParserTests, AcceptsQueryShorthand) {
  expectSuccess("{ myfield }");
}

TEST(ParserTests, AcceptsLonghandUnnamedQuery) {
  expectSuccess("query { myfield }");
}

TEST(ParserTests, AcceptsLonghandUnnamedMutation) {
  expectSuccess("mutation { myfield }");
}

TEST(ParserTests, AcceptsLonghandUnnamedSubscription) {
  expectSuccess("subscription { myfield }");
}

TEST(ParserTests, AllowsNonKeywordsForNames) {
  const char *nonKeywords[] = {
    "on",
    "fragment",
    "query",
    "mutation",
    "subscription",
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
