/**
 * Copyright 2019-present GraphQL Foundation
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
/** @generated */

#include "Ast.h"
#include "AstVisitor.h"

namespace facebook {
namespace graphql {
namespace ast {

void Document::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitDocument(*this)) {

    { for (const auto &x : *definitions_) { x->accept(visitor); } }
  }
  visitor->endVisitDocument(*this);
}

void OperationDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitOperationDefinition(*this)) {

    if (name_) { name_->accept(visitor); }
    if (variableDefinitions_) { for (const auto &x : *variableDefinitions_) { x->accept(visitor); } }
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    selectionSet_->accept(visitor);
  }
  visitor->endVisitOperationDefinition(*this);
}

void VariableDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitVariableDefinition(*this)) {

    variable_->accept(visitor);
    type_->accept(visitor);
    if (defaultValue_) { defaultValue_->accept(visitor); }
  }
  visitor->endVisitVariableDefinition(*this);
}

void SelectionSet::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitSelectionSet(*this)) {

    { for (const auto &x : *selections_) { x->accept(visitor); } }
  }
  visitor->endVisitSelectionSet(*this);
}

void Field::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitField(*this)) {

    if (alias_) { alias_->accept(visitor); }
    name_->accept(visitor);
    if (arguments_) { for (const auto &x : *arguments_) { x->accept(visitor); } }
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    if (selectionSet_) { selectionSet_->accept(visitor); }
  }
  visitor->endVisitField(*this);
}

void Argument::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitArgument(*this)) {

    name_->accept(visitor);
    value_->accept(visitor);
  }
  visitor->endVisitArgument(*this);
}

void FragmentSpread::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitFragmentSpread(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
  }
  visitor->endVisitFragmentSpread(*this);
}

void InlineFragment::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitInlineFragment(*this)) {

    if (typeCondition_) { typeCondition_->accept(visitor); }
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    selectionSet_->accept(visitor);
  }
  visitor->endVisitInlineFragment(*this);
}

void FragmentDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitFragmentDefinition(*this)) {

    name_->accept(visitor);
    typeCondition_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    selectionSet_->accept(visitor);
  }
  visitor->endVisitFragmentDefinition(*this);
}

void Variable::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitVariable(*this)) {

    name_->accept(visitor);
  }
  visitor->endVisitVariable(*this);
}

void IntValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitIntValue(*this)) {

  }
  visitor->endVisitIntValue(*this);
}

void FloatValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitFloatValue(*this)) {

  }
  visitor->endVisitFloatValue(*this);
}

void StringValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitStringValue(*this)) {

  }
  visitor->endVisitStringValue(*this);
}

void BooleanValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitBooleanValue(*this)) {

  }
  visitor->endVisitBooleanValue(*this);
}

void NullValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitNullValue(*this)) {

  }
  visitor->endVisitNullValue(*this);
}

void EnumValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitEnumValue(*this)) {

  }
  visitor->endVisitEnumValue(*this);
}

void ListValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitListValue(*this)) {

    { for (const auto &x : *values_) { x->accept(visitor); } }
  }
  visitor->endVisitListValue(*this);
}

void ObjectValue::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitObjectValue(*this)) {

    { for (const auto &x : *fields_) { x->accept(visitor); } }
  }
  visitor->endVisitObjectValue(*this);
}

void ObjectField::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitObjectField(*this)) {

    name_->accept(visitor);
    value_->accept(visitor);
  }
  visitor->endVisitObjectField(*this);
}

void Directive::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitDirective(*this)) {

    name_->accept(visitor);
    if (arguments_) { for (const auto &x : *arguments_) { x->accept(visitor); } }
  }
  visitor->endVisitDirective(*this);
}

void NamedType::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitNamedType(*this)) {

    name_->accept(visitor);
  }
  visitor->endVisitNamedType(*this);
}

void ListType::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitListType(*this)) {

    type_->accept(visitor);
  }
  visitor->endVisitListType(*this);
}

void NonNullType::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitNonNullType(*this)) {

    type_->accept(visitor);
  }
  visitor->endVisitNonNullType(*this);
}

void Name::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitName(*this)) {

  }
  visitor->endVisitName(*this);
}

void SchemaDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitSchemaDefinition(*this)) {

    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    { for (const auto &x : *operationTypes_) { x->accept(visitor); } }
  }
  visitor->endVisitSchemaDefinition(*this);
}

void OperationTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitOperationTypeDefinition(*this)) {

    type_->accept(visitor);
  }
  visitor->endVisitOperationTypeDefinition(*this);
}

void ScalarTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitScalarTypeDefinition(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
  }
  visitor->endVisitScalarTypeDefinition(*this);
}

void ObjectTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitObjectTypeDefinition(*this)) {

    name_->accept(visitor);
    if (interfaces_) { for (const auto &x : *interfaces_) { x->accept(visitor); } }
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    { for (const auto &x : *fields_) { x->accept(visitor); } }
  }
  visitor->endVisitObjectTypeDefinition(*this);
}

void FieldDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitFieldDefinition(*this)) {

    name_->accept(visitor);
    if (arguments_) { for (const auto &x : *arguments_) { x->accept(visitor); } }
    type_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
  }
  visitor->endVisitFieldDefinition(*this);
}

void InputValueDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitInputValueDefinition(*this)) {

    name_->accept(visitor);
    type_->accept(visitor);
    if (defaultValue_) { defaultValue_->accept(visitor); }
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
  }
  visitor->endVisitInputValueDefinition(*this);
}

void InterfaceTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitInterfaceTypeDefinition(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    { for (const auto &x : *fields_) { x->accept(visitor); } }
  }
  visitor->endVisitInterfaceTypeDefinition(*this);
}

void UnionTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitUnionTypeDefinition(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    { for (const auto &x : *types_) { x->accept(visitor); } }
  }
  visitor->endVisitUnionTypeDefinition(*this);
}

void EnumTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitEnumTypeDefinition(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    { for (const auto &x : *values_) { x->accept(visitor); } }
  }
  visitor->endVisitEnumTypeDefinition(*this);
}

void EnumValueDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitEnumValueDefinition(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
  }
  visitor->endVisitEnumValueDefinition(*this);
}

void InputObjectTypeDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitInputObjectTypeDefinition(*this)) {

    name_->accept(visitor);
    if (directives_) { for (const auto &x : *directives_) { x->accept(visitor); } }
    { for (const auto &x : *fields_) { x->accept(visitor); } }
  }
  visitor->endVisitInputObjectTypeDefinition(*this);
}

void TypeExtensionDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitTypeExtensionDefinition(*this)) {

    definition_->accept(visitor);
  }
  visitor->endVisitTypeExtensionDefinition(*this);
}

void DirectiveDefinition::accept(visitor::AstVisitor *visitor) const {
  if (visitor->visitDirectiveDefinition(*this)) {

    name_->accept(visitor);
    if (arguments_) { for (const auto &x : *arguments_) { x->accept(visitor); } }
    { for (const auto &x : *locations_) { x->accept(visitor); } }
  }
  visitor->endVisitDirectiveDefinition(*this);
}

}  // namespace ast
}  // namespace graphql
}  // namespace facebook
