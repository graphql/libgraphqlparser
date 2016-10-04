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


// Method invariant: printed_ contains strings for this node's children.
void JsonVisitor::printLocation(const yy::location &location)
{
  out_ << "{\"start\":" << location.begin.column
       << ",\"end\":" << location.end.column  << '}';
}

void JsonVisitor::startPrintingNode(const char *kind, const yy::location &location) {
  out_.str("");
  out_ << "{\"kind\":\"" << kind << "\",\"loc\":";
  printLocation(location);
  out_ << ',';
  return;
}

void JsonVisitor::printChildList(
    const std::vector<std::string>::const_iterator &childIterator,
    size_t numChildren) {
  out_ << '[';
  for (size_t ii = 0; ii < numChildren; ++ii) {
    if (ii != 0) {
      out_ << ',';
    }
    out_ << *(childIterator + ii);
  }
  out_ << ']';
}

void JsonVisitor::visitNode() {
  printed_.emplace_back();
}

void JsonVisitor::endVisitNode() {
  printed_.pop_back();
  printed_.back().emplace_back(out_.str());
}

bool JsonVisitor::visitDocument(const Document &document) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitDocument(const Document &document) {
  startPrintingNode("Document", document.getLocation());
  out_ << "\"definitions\":";

  const auto &children = printed_.back();
  printChildList(children.begin(), children.size());
  out_ << '}';
  printed_.pop_back();
  assert(printed_.empty());
}

bool JsonVisitor::visitOperationDefinition(const OperationDefinition &operationDefinition) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitOperationDefinition(const OperationDefinition &operationDefinition) {
  startPrintingNode("OperationDefinition", operationDefinition.getLocation());

  out_ << "\"operation\":\"" << operationDefinition.getOperation()
       << '\"';

  const auto &children = printed_.back();

  auto nextChild = children.begin();

  out_ << ",\"name\": "
       << (operationDefinition.getName() ? *nextChild++ : "null");

  out_ << ",\"variableDefinitions\":";
  const auto *variableDefinitions = operationDefinition.getVariableDefinitions();
  if (variableDefinitions != nullptr) {
    printChildList(nextChild, variableDefinitions->size());
    nextChild += variableDefinitions->size();
  } else {
    out_ << "null";
  }

  out_ << ",\"directives\":";
  const auto *directives = operationDefinition.getDirectives();
  if (directives != nullptr) {
    printChildList(nextChild, directives->size());
    nextChild += directives->size();
  } else {
    out_ << "null";
  }

  out_ << ",\"selectionSet\":" << *nextChild++;

  assert(nextChild == children.end());
  out_ << "}";

  endVisitNode();
}

bool JsonVisitor::visitVariableDefinition(const VariableDefinition &variableDefinition) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitVariableDefinition(const VariableDefinition &variableDefinition) {
  startPrintingNode("VariableDefinition", variableDefinition.getLocation());

  const auto &children = printed_.back();
  out_ << "\"variable\":" << children[0];
  out_ << ",\"type\":" << children[1];
  out_ << ",\"defaultValue\":";
  if (children.size() > 2) {
    assert(children.size() == 3);
    out_ << children[2];
  } else {
    assert(children.size() == 2);
    out_ << "null";
  }

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitSelectionSet(const SelectionSet &selectionSet) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitSelectionSet(const SelectionSet &selectionSet) {
  startPrintingNode("SelectionSet", selectionSet.getLocation());

  out_ << "\"selections\":";

  const auto &children = printed_.back();
  printChildList(children.begin(), children.size());

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitField(const Field &field) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitField(const Field &field) {
  startPrintingNode("Field", field.getLocation());

  const auto &children = printed_.back();
  auto nextChild = children.begin();

  out_ << "\"alias\":";
  if (field.getAlias() != nullptr) {
    out_ << *nextChild++;
  } else {
    out_ << "null";
  }

  out_ << ",\"name\":" << *nextChild++;

  out_ << ",\"arguments\":";
  const auto *arguments = field.getArguments();
  if (arguments != nullptr) {
    printChildList(nextChild, arguments->size());
    nextChild += arguments->size();
  } else {
    out_ << "null";
  }

  out_ << ",\"directives\":";
  const auto *directives = field.getDirectives();
  if (directives != nullptr) {
    printChildList(nextChild, directives->size());
    nextChild += directives->size();
  } else {
    out_ << "null";
  }

  out_ << ",\"selectionSet\":";
  if (field.getSelectionSet() != nullptr) {
    out_ << *nextChild++;
  } else {
    out_ << "null";
  }

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitArgument(const Argument &argument) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitArgument(const Argument &argument) {
  startPrintingNode("Argument", argument.getLocation());

  const auto &children = printed_.back();
  out_ << "\"name\":" << children[0] << ",\"value\":" << children[1];

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitFragmentSpread(const FragmentSpread &fragmentSpread) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitFragmentSpread(const FragmentSpread &fragmentSpread) {
  startPrintingNode("FragmentSpread", fragmentSpread.getLocation());

  const auto &children = printed_.back();
  out_ << "\"name\":" << children[0];

  out_ << ",\"directives\":";
  const auto *directives = fragmentSpread.getDirectives();
  if (directives != nullptr) {
    printChildList(children.begin() + 1, directives->size());
  } else {
    out_ << "null";
  }

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitInlineFragment(const InlineFragment &inlineFragment) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitInlineFragment(const InlineFragment &inlineFragment) {
  startPrintingNode("InlineFragment", inlineFragment.getLocation());

  const auto &children = printed_.back();

  auto nextChild = children.begin();
  if (inlineFragment.getTypeCondition() != nullptr) {
    out_ << "\"typeCondition\":" << *nextChild++ << ',';
  }

  out_ << "\"directives\":";
  const auto *directives = inlineFragment.getDirectives();
  if (directives != nullptr) {
    printChildList(nextChild, directives->size());
    nextChild += directives->size();
  } else {
    out_ << "null";
  }

  out_ << ",\"selectionSet\":" << *nextChild++;

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitFragmentDefinition(const FragmentDefinition &fragmentDefinition) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitFragmentDefinition(const FragmentDefinition &fragmentDefinition) {
  startPrintingNode("FragmentDefinition", fragmentDefinition.getLocation());

  const auto &children = printed_.back();

  out_ << "\"name\":" << children[0];
  out_ << ",\"typeCondition\":" << children[1];

  auto nextChild = children.begin() + 2;

  out_ << ",\"directives\":";
  const auto *directives = fragmentDefinition.getDirectives();
  if (directives != nullptr) {
    printChildList(nextChild, directives->size());
    nextChild += directives->size();
  } else {
    out_ << "null";
  }

  out_ << ",\"selectionSet\":" << *nextChild++;

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitVariable(const Variable &variable) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitVariable(const Variable &variable) {
  startPrintingNode("Variable", variable.getLocation());

  out_ << "\"name\":" << printed_.back()[0] << '}';

  endVisitNode();
}

template <typename ValueType>
void JsonVisitor::endVisitValueRepresentedAsString(const char *valueKind, const ValueType &value) {
  startPrintingNode(valueKind, value.getLocation());

  out_ << "\"value\":\"" << value.getValue() << "\"}";
  printed_.back().emplace_back(out_.str());
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

void JsonVisitor::endVisitBooleanValue(const BooleanValue &booleanValue) {
  startPrintingNode("BooleanValue", booleanValue.getLocation());

  out_ << "\"value\":" << (booleanValue.getValue() ? "true" : "false") << '}';
  printed_.back().emplace_back(out_.str());
}

bool JsonVisitor::visitListValue(const ListValue &arrayValue) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitListValue(const ListValue &arrayValue) {
  startPrintingNode("ListValue", arrayValue.getLocation());

  out_ << "\"values\":";
  printChildList(printed_.back().begin(), arrayValue.getValues().size());

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitObjectValue(const ObjectValue &objectValue) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitObjectValue(const ObjectValue &objectValue) {
  startPrintingNode("ObjectValue", objectValue.getLocation());

  out_ << "\"fields\":";
  printChildList(printed_.back().begin(), objectValue.getFields().size());

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitObjectField(const ObjectField &objectField) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitObjectField(const ObjectField &objectField) {
  startPrintingNode("ObjectField", objectField.getLocation());

  const auto &children = printed_.back();

  out_ << "\"name\":" << children[0] << ",\"value\":" << children[1];

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitDirective(const Directive &directive) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitDirective(const Directive &directive) {
  startPrintingNode("Directive", directive.getLocation());

  const auto &children = printed_.back();
  out_ << "\"name\":" << children[0];

  auto nextChild = children.begin() + 1;
  out_ << ",\"arguments\":";
  const auto *arguments = directive.getArguments();
  if (arguments != nullptr) {
    printChildList(nextChild, arguments->size());
  } else {
    out_ << "null";
  }

  out_ << '}';

  endVisitNode();
}

void JsonVisitor::endVisitName(const Name &name) {
  endVisitValueRepresentedAsString("Name", name);
}

bool JsonVisitor::visitNamedType(const NamedType &namedType) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitNamedType(const NamedType &namedType) {
  startPrintingNode("NamedType", namedType.getLocation());

  out_ << "\"name\":" << printed_.back()[0];

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitListType(const ListType &listType) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitListType(const ListType &listType) {
  startPrintingNode("ListType", listType.getLocation());

  out_ << "\"type\":" << printed_.back()[0];

  out_ << '}';

  endVisitNode();
}

bool JsonVisitor::visitNonNullType(const NonNullType &nonNullType) {
  visitNode();
  return true;
}

void JsonVisitor::endVisitNonNullType(const NonNullType &nonNullType) {
  startPrintingNode("NonNullType", nonNullType.getLocation());

  out_ << "\"type\":" << printed_.back()[0];

  out_ << '}';

  endVisitNode();
}

}
}
}
}
