/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "position.hh"
#include "JsonVisitor.h"

#include <assert.h>
#include <iterator>

namespace facebook {
namespace graphql {
namespace ast {
namespace visitor {


JsonVisitor::NodeFieldPrinter::NodeFieldPrinter(
    JsonVisitor &visitor,
    const char *nodeKind,
    const Node &node)
    : visitor_(visitor)
{
  if (!visitor_.printed_.empty()) {
    nextChild_ = visitor_.printed_.back().begin();
  }
  out_ << "{\"kind\":\"" << nodeKind << "\",\"loc\":";
  printLocation(out_, node.getLocation());
}

std::string JsonVisitor::NodeFieldPrinter::finishPrinting() {
  assert(!out_.str().empty());
  out_ << '}';
  auto result(out_.str());
#ifndef NDEBUG
  out_.str("");
#endif
  return result;

}

void JsonVisitor::NodeFieldPrinter::printFieldSeparator()
{
  out_ << ',';
}

void JsonVisitor::NodeFieldPrinter::printSingularPrimitiveField(
    const char *fieldName,
    const char *value) {
  printFieldSeparator();
  out_ << '"' << fieldName << "\":";
  out_ << '"' << value << '"';
}

void JsonVisitor::NodeFieldPrinter::printSingularBooleanField(
    const char *fieldName,
    bool value) {
  printFieldSeparator();
  out_ << '"' << fieldName << "\":";
  out_ << (value ? "true" : "false");
}

void JsonVisitor::NodeFieldPrinter::printSingularObjectField(const char *fieldName) {
  printFieldSeparator();
  out_ << '"' << fieldName << "\":";
  assert(!visitor_.printed_.empty());
  out_ << *nextChild_++;
}

void JsonVisitor::NodeFieldPrinter::printNullableSingularObjectField(
    const char *fieldName,
    const void *value) {
  printFieldSeparator();
  out_ << '"' << fieldName << "\":";
  if (value != nullptr) {
    assert(!visitor_.printed_.empty());
    out_ << *nextChild_++;
  } else {
    out_ << "null";
  }
}

// Method invariant: printed_ contains strings for this node's children.
void JsonVisitor::NodeFieldPrinter::printLocation(
    std::ostringstream &out,
    const yy::location &location)
{
  out << "{\"start\":" << location.begin.column
       << ",\"end\":" << location.end.column  << '}';
}

void JsonVisitor::NodeFieldPrinter::printChildList(
    std::ostringstream &out,
    const std::vector<std::string>::const_iterator &childIterator,
    size_t numChildren) {
  out << '[';
  for (size_t ii = 0; ii < numChildren; ++ii) {
    if (ii != 0) {
      out << ',';
    }
    out << *(childIterator + ii);
  }
  out << ']';
}

JsonVisitor::JsonVisitor() {
  printed_.emplace_back();
}

void JsonVisitor::visitNode() {
  printed_.emplace_back();
}

void JsonVisitor::endVisitNode(std::string &&str) {
  printed_.pop_back();
  printed_.back().emplace_back(std::move(str));
}

bool JsonVisitor::visitDocument(const Document &document) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitDocument(const Document &document) {
  NodeFieldPrinter fields(*this, "Document", document);
  fields.printPluralField("definitions", document.getDefinitions());
  endVisitNode(fields.finishPrinting());
  assert(printed_.size() == 1);
}

bool JsonVisitor::visitOperationDefinition(const OperationDefinition &operationDefinition) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitOperationDefinition(const OperationDefinition &operationDefinition) {
  NodeFieldPrinter fields(*this, "OperationDefinition", operationDefinition);

  fields.printSingularPrimitiveField("operation", operationDefinition.getOperation());
  fields.printNullableSingularObjectField("name", operationDefinition.getName());

  fields.printNullablePluralField(
    "variableDefinitions",
    operationDefinition.getVariableDefinitions());

  fields.printNullablePluralField(
    "directives",
    operationDefinition.getDirectives());

  fields.printSingularObjectField("selectionSet");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitVariableDefinition(const VariableDefinition &variableDefinition) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitVariableDefinition(const VariableDefinition &variableDefinition) {
  NodeFieldPrinter fields(*this, "VariableDefinition", variableDefinition);
  fields.printSingularObjectField("variable");
  fields.printSingularObjectField("type");
  fields.printNullableSingularObjectField(
    "defaultValue",
    variableDefinition.getDefaultValue());


  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitSelectionSet(const SelectionSet &selectionSet) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitSelectionSet(const SelectionSet &selectionSet) {
  NodeFieldPrinter fields(*this, "SelectionSet", selectionSet);
  fields.printPluralField("selections", selectionSet.getSelections());

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitField(const Field &field) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitField(const Field &field) {
  NodeFieldPrinter fields(*this, "Field", field);
  fields.printNullableSingularObjectField("alias", field.getAlias());
  fields.printSingularObjectField("name");
  fields.printNullablePluralField("arguments", field.getArguments());
  fields.printNullablePluralField("directives", field.getDirectives());
  fields.printNullableSingularObjectField("selectionSet", field.getSelectionSet());

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitArgument(const Argument &argument) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitArgument(const Argument &argument) {
  NodeFieldPrinter fields(*this, "Argument", argument);
  fields.printSingularObjectField("name");
  fields.printSingularObjectField("value");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitFragmentSpread(const FragmentSpread &fragmentSpread) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitFragmentSpread(const FragmentSpread &fragmentSpread) {
  NodeFieldPrinter fields(*this, "FragmentSpread", fragmentSpread);
  fields.printSingularObjectField("name");
  fields.printNullablePluralField("directives", fragmentSpread.getDirectives());

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitInlineFragment(const InlineFragment &inlineFragment) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitInlineFragment(const InlineFragment &inlineFragment) {
  NodeFieldPrinter fields(*this, "InlineFragment", inlineFragment);
  fields.printNullableSingularObjectField("typeCondition", inlineFragment.getTypeCondition());
  fields.printNullablePluralField("directives", inlineFragment.getDirectives());
  fields.printSingularObjectField("selectionSet");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitFragmentDefinition(const FragmentDefinition &fragmentDefinition) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitFragmentDefinition(const FragmentDefinition &fragmentDefinition) {
  NodeFieldPrinter fields(*this, "FragmentDefinition", fragmentDefinition);

  fields.printSingularObjectField("name");
  fields.printSingularObjectField("typeCondition");
  fields.printNullablePluralField("directives", fragmentDefinition.getDirectives());
  fields.printSingularObjectField("selectionSet");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitVariable(const Variable &variable) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitVariable(const Variable &variable) {
  NodeFieldPrinter fields(*this, "Variable", variable);
  fields.printSingularObjectField("name");

  endVisitNode(fields.finishPrinting());
}

template <typename ValueNode>
void JsonVisitor::endVisitValueRepresentedAsString(const char *valueKind, const ValueNode &value) {
  NodeFieldPrinter fields(*this, valueKind, value);
  fields.printSingularPrimitiveField("value", value.getValue());

  printed_.back().emplace_back(fields.finishPrinting());
}

void JsonVisitor::endVisitIntValue(const IntValue &intValue) {
  endVisitValueRepresentedAsString("IntValue", intValue);
}

void JsonVisitor::endVisitFloatValue(const FloatValue &floatValue) {
  endVisitValueRepresentedAsString("FloatValue", floatValue);
}

void JsonVisitor::endVisitStringValue(const StringValue &stringValue) {
  endVisitValueRepresentedAsString("StringValue", stringValue);
}

void JsonVisitor::endVisitEnumValue(const EnumValue &enumValue) {
  endVisitValueRepresentedAsString("EnumValue", enumValue);
}

void JsonVisitor::endVisitNullValue(const NullValue &nullValue) {
  NodeFieldPrinter fields(*this, "NullValue", nullValue);

  printed_.back().emplace_back(fields.finishPrinting());
}

void JsonVisitor::endVisitBooleanValue(const BooleanValue &booleanValue) {
  NodeFieldPrinter fields(*this, "BooleanValue", booleanValue);
  fields.printSingularBooleanField(
    "value",
    booleanValue.getValue());

  printed_.back().emplace_back(fields.finishPrinting());
}

bool JsonVisitor::visitListValue(const ListValue &arrayValue) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitListValue(const ListValue &arrayValue) {
  NodeFieldPrinter fields(*this, "ListValue", arrayValue);
  fields.printPluralField("values", arrayValue.getValues());

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitObjectValue(const ObjectValue &objectValue) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitObjectValue(const ObjectValue &objectValue) {
  NodeFieldPrinter fields(*this, "ObjectValue", objectValue);
  fields.printPluralField("fields", objectValue.getFields());

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitObjectField(const ObjectField &objectField) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitObjectField(const ObjectField &objectField) {
  NodeFieldPrinter fields(*this, "ObjectField", objectField);
  fields.printSingularObjectField("name");
  fields.printSingularObjectField("value");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitDirective(const Directive &directive) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitDirective(const Directive &directive) {
  NodeFieldPrinter fields(*this, "Directive", directive);
  fields.printSingularObjectField("name");
  fields.printNullablePluralField("arguments", directive.getArguments());

  endVisitNode(fields.finishPrinting());
}

void JsonVisitor::endVisitName(const Name &name) {
  endVisitValueRepresentedAsString("Name", name);
}

bool JsonVisitor::visitNamedType(const NamedType &namedType) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitNamedType(const NamedType &namedType) {
  NodeFieldPrinter fields(*this, "NamedType", namedType);
  fields.printSingularObjectField("name");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitListType(const ListType &listType) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitListType(const ListType &listType) {
  NodeFieldPrinter fields(*this, "ListType", listType);
  fields.printSingularObjectField("type");

  endVisitNode(fields.finishPrinting());
}

bool JsonVisitor::visitNonNullType(const NonNullType &nonNullType) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitNonNullType(const NonNullType &nonNullType) {
  NodeFieldPrinter fields(*this, "NonNullType", nonNullType);
  fields.printSingularObjectField("type");

  endVisitNode(fields.finishPrinting());
}

std::string JsonVisitor::getResult() const {
  assert(printed_.size() == 1);
  assert(printed_[0].size() == 1);
  return printed_[0][0];
}

}
}
}
}
