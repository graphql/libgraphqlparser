/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#pragma once

#include "AstNode.h"
#include "AstVisitor.h"

#include <sstream>
#include <vector>

namespace facebook {
namespace graphql {
namespace ast {
namespace visitor {

/**
 * Produces a JSON string describing the visited AST, in a format that
 * would be a valid graphql-js AST when parsed.
 */
class JsonVisitor : public AstVisitor {
  // Stack of lists of printed children.
  // Postvisit method precondition: printed.back() contains strings
  // for this node's children.
  // Postvisit method postcondition: *(printed.rbegin() - 1) has had this
  std::vector<std::vector<std::string>> printed_;
  std::ostringstream out_;

  // Print the opening of a new JSON dictionary, the node kind, and
  // the node location.
  void startPrintingNodeWithoutTrailingComma(const char *kind, const yy::location &location);

  // Like startPrintingNodeWithoutTrailingComma, but adds a trailing
  // comma for convenience.
  void startPrintingNode(const char *kind, const yy::location &location);

  void printLocation(const yy::location &location);

  // Must be called at the start of all visit methods for node types
  // that have children. Maintains printed_.
  void visitNode();

  // Must be called at the end of all visit methods for node types
  // that have children. Maintains printed_.
  void endVisitNode();

  // Prints a non-null array of n children from the given
  // iterator. Does not update the iterator.
  void printChildList(
    const std::vector<std::string>::const_iterator &childIterator,
    size_t numChildren);

  // Prints one of the many FooValue types that is prepresented with a
  // single string.
  template <typename ValueType>
  void endVisitValueRepresentedAsString(const char *valueKind, const ValueType &value);

public:
  JsonVisitor() {}
  ~JsonVisitor() {}

  std::string getResult() const {
    return out_.str();
  }

  bool visitDocument(const Document &document) override;
  void endVisitDocument(const Document &document) override;

  bool visitOperationDefinition(const OperationDefinition &operationDefinition) override;
  void endVisitOperationDefinition(const OperationDefinition &operationDefinition) override;

  bool visitVariableDefinition(const VariableDefinition &variableDefinition) override;
  void endVisitVariableDefinition(const VariableDefinition &variableDefinition) override;

  bool visitSelectionSet(const SelectionSet &selectionSet) override;
  void endVisitSelectionSet(const SelectionSet &selectionSet) override;

  bool visitField(const Field &field) override;
  void endVisitField(const Field &field) override;

  bool visitArgument(const Argument &argument) override;
  void endVisitArgument(const Argument &argument) override;

  bool visitFragmentSpread(const FragmentSpread &fragmentSpread) override;
  void endVisitFragmentSpread(const FragmentSpread &fragmentSpread) override;

  bool visitInlineFragment(const InlineFragment &inlineFragment) override;
  void endVisitInlineFragment(const InlineFragment &inlineFragment) override;

  bool visitFragmentDefinition(const FragmentDefinition &fragmentDefinition) override;
  void endVisitFragmentDefinition(const FragmentDefinition &fragmentDefinition) override;

  bool visitVariable(const Variable &variable) override;
  void endVisitVariable(const Variable &variable) override;

  void endVisitIntValue(const IntValue &intValue) override;

  void endVisitFloatValue(const FloatValue &floatValue) override;

  void endVisitStringValue(const StringValue &stringValue) override;

  void endVisitBooleanValue(const BooleanValue &booleanValue) override;

  void endVisitNullValue(const NullValue &nullValue) override;

  void endVisitEnumValue(const EnumValue &enumValue) override;

  bool visitListValue(const ListValue &arrayValue) override;
  void endVisitListValue(const ListValue &arrayValue) override;

  bool visitObjectValue(const ObjectValue &objectValue) override;
  void endVisitObjectValue(const ObjectValue &objectValue) override;

  bool visitObjectField(const ObjectField &objectField) override;
  void endVisitObjectField(const ObjectField &objectField) override;

  bool visitDirective(const Directive &directive) override;
  void endVisitDirective(const Directive &directive) override;

  void endVisitName(const Name &name) override;

  bool visitNamedType(const NamedType &namedType) override;
  void endVisitNamedType(const NamedType &namedType) override;

  bool visitListType(const ListType &listType) override;
  void endVisitListType(const ListType &listType) override;

  bool visitNonNullType(const NonNullType &nonNullType) override;
  void endVisitNonNullType(const NonNullType &nonNullType) override;

};

}
}
}
}
