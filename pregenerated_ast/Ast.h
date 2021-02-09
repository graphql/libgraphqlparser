/**
 * Copyright 2019-present GraphQL Foundation
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
/** @generated */
#pragma once

#include "AstNode.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace facebook {
namespace graphql {
namespace ast {

// The parser uses strdup to move from yytext to the heap, so we need
// to use free instead of delete.
struct CDeleter {
  void operator()(const char *p) const { free((void *)p); }
};

class Definition;
class Document;
class OperationDefinition;
class VariableDefinition;
class SelectionSet;
class Selection;
class Field;
class Argument;
class FragmentSpread;
class InlineFragment;
class FragmentDefinition;
class Value;
class Variable;
class IntValue;
class FloatValue;
class StringValue;
class BooleanValue;
class NullValue;
class EnumValue;
class ListValue;
class ObjectValue;
class ObjectField;
class Directive;
class Type;
class NamedType;
class ListType;
class NonNullType;
class Name;
class SchemaDefinition;
class OperationTypeDefinition;
class ScalarTypeDefinition;
class ObjectTypeDefinition;
class FieldDefinition;
class InputValueDefinition;
class InterfaceTypeDefinition;
class UnionTypeDefinition;
class EnumTypeDefinition;
class EnumValueDefinition;
class InputObjectTypeDefinition;
class TypeExtensionDefinition;
class DirectiveDefinition;

class Definition : public Node {
 public:
  explicit Definition(
      const yy::location &location

  )
  : Node(location)

  {}
};

class Document : public Node {
  std::unique_ptr<std::vector<std::unique_ptr<Definition>>> definitions_;
 public:
  explicit Document(
      const yy::location &location,
      std::vector<std::unique_ptr<Definition>> * definitions
  )
  : Node(location),
    definitions_(definitions)
  {}

  ~Document() {}

  Document(const Document&) = delete;
  Document& operator=(const Document&) = delete;

  const std::vector<std::unique_ptr<Definition>>& getDefinitions() const
  { return *definitions_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class OperationDefinition : public Definition {
  std::unique_ptr<const char, CDeleter> operation_;
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<VariableDefinition>>> variableDefinitions_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<SelectionSet> selectionSet_;
 public:
  explicit OperationDefinition(
      const yy::location &location,
      const char * operation,
      Name * name,
      std::vector<std::unique_ptr<VariableDefinition>> * variableDefinitions,
      std::vector<std::unique_ptr<Directive>> * directives,
      SelectionSet * selectionSet
  )
  : Definition(location),
    operation_(operation),
    name_(name),
    variableDefinitions_(variableDefinitions),
    directives_(directives),
    selectionSet_(selectionSet)
  {}

  ~OperationDefinition() {}

  OperationDefinition(const OperationDefinition&) = delete;
  OperationDefinition& operator=(const OperationDefinition&) = delete;

  const char * getOperation() const
  { return operation_.get(); }

  const Name* getName() const
  { return name_.get(); }

  const std::vector<std::unique_ptr<VariableDefinition>>* getVariableDefinitions() const
  { return variableDefinitions_.get(); }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const SelectionSet& getSelectionSet() const
  { return *selectionSet_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class VariableDefinition : public Node {
  std::unique_ptr<Variable> variable_;
  std::unique_ptr<Type> type_;
  std::unique_ptr<Value> defaultValue_;
 public:
  explicit VariableDefinition(
      const yy::location &location,
      Variable * variable,
      Type * type,
      Value * defaultValue
  )
  : Node(location),
    variable_(variable),
    type_(type),
    defaultValue_(defaultValue)
  {}

  ~VariableDefinition() {}

  VariableDefinition(const VariableDefinition&) = delete;
  VariableDefinition& operator=(const VariableDefinition&) = delete;

  const Variable& getVariable() const
  { return *variable_; }

  const Type& getType() const
  { return *type_; }

  const Value* getDefaultValue() const
  { return defaultValue_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class SelectionSet : public Node {
  std::unique_ptr<std::vector<std::unique_ptr<Selection>>> selections_;
 public:
  explicit SelectionSet(
      const yy::location &location,
      std::vector<std::unique_ptr<Selection>> * selections
  )
  : Node(location),
    selections_(selections)
  {}

  ~SelectionSet() {}

  SelectionSet(const SelectionSet&) = delete;
  SelectionSet& operator=(const SelectionSet&) = delete;

  const std::vector<std::unique_ptr<Selection>>& getSelections() const
  { return *selections_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class Selection : public Node {
 public:
  explicit Selection(
      const yy::location &location

  )
  : Node(location)

  {}
};

class Field : public Selection {
  std::unique_ptr<Name> alias_;
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Argument>>> arguments_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<SelectionSet> selectionSet_;
 public:
  explicit Field(
      const yy::location &location,
      Name * alias,
      Name * name,
      std::vector<std::unique_ptr<Argument>> * arguments,
      std::vector<std::unique_ptr<Directive>> * directives,
      SelectionSet * selectionSet
  )
  : Selection(location),
    alias_(alias),
    name_(name),
    arguments_(arguments),
    directives_(directives),
    selectionSet_(selectionSet)
  {}

  ~Field() {}

  Field(const Field&) = delete;
  Field& operator=(const Field&) = delete;

  const Name* getAlias() const
  { return alias_.get(); }

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Argument>>* getArguments() const
  { return arguments_.get(); }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const SelectionSet* getSelectionSet() const
  { return selectionSet_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class Argument : public Node {
  std::unique_ptr<Name> name_;
  std::unique_ptr<Value> value_;
 public:
  explicit Argument(
      const yy::location &location,
      Name * name,
      Value * value
  )
  : Node(location),
    name_(name),
    value_(value)
  {}

  ~Argument() {}

  Argument(const Argument&) = delete;
  Argument& operator=(const Argument&) = delete;

  const Name& getName() const
  { return *name_; }

  const Value& getValue() const
  { return *value_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class FragmentSpread : public Selection {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
 public:
  explicit FragmentSpread(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives
  )
  : Selection(location),
    name_(name),
    directives_(directives)
  {}

  ~FragmentSpread() {}

  FragmentSpread(const FragmentSpread&) = delete;
  FragmentSpread& operator=(const FragmentSpread&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class InlineFragment : public Selection {
  std::unique_ptr<NamedType> typeCondition_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<SelectionSet> selectionSet_;
 public:
  explicit InlineFragment(
      const yy::location &location,
      NamedType * typeCondition,
      std::vector<std::unique_ptr<Directive>> * directives,
      SelectionSet * selectionSet
  )
  : Selection(location),
    typeCondition_(typeCondition),
    directives_(directives),
    selectionSet_(selectionSet)
  {}

  ~InlineFragment() {}

  InlineFragment(const InlineFragment&) = delete;
  InlineFragment& operator=(const InlineFragment&) = delete;

  const NamedType* getTypeCondition() const
  { return typeCondition_.get(); }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const SelectionSet& getSelectionSet() const
  { return *selectionSet_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class FragmentDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<NamedType> typeCondition_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<SelectionSet> selectionSet_;
 public:
  explicit FragmentDefinition(
      const yy::location &location,
      Name * name,
      NamedType * typeCondition,
      std::vector<std::unique_ptr<Directive>> * directives,
      SelectionSet * selectionSet
  )
  : Definition(location),
    name_(name),
    typeCondition_(typeCondition),
    directives_(directives),
    selectionSet_(selectionSet)
  {}

  ~FragmentDefinition() {}

  FragmentDefinition(const FragmentDefinition&) = delete;
  FragmentDefinition& operator=(const FragmentDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const NamedType& getTypeCondition() const
  { return *typeCondition_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const SelectionSet& getSelectionSet() const
  { return *selectionSet_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class Value : public Node {
 public:
  explicit Value(
      const yy::location &location

  )
  : Node(location)

  {}
};

class Variable : public Value {
  std::unique_ptr<Name> name_;
 public:
  explicit Variable(
      const yy::location &location,
      Name * name
  )
  : Value(location),
    name_(name)
  {}

  ~Variable() {}

  Variable(const Variable&) = delete;
  Variable& operator=(const Variable&) = delete;

  const Name& getName() const
  { return *name_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class IntValue : public Value {
  std::unique_ptr<const char, CDeleter> value_;
 public:
  explicit IntValue(
      const yy::location &location,
      const char * value
  )
  : Value(location),
    value_(value)
  {}

  ~IntValue() {}

  IntValue(const IntValue&) = delete;
  IntValue& operator=(const IntValue&) = delete;

  const char * getValue() const
  { return value_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class FloatValue : public Value {
  std::unique_ptr<const char, CDeleter> value_;
 public:
  explicit FloatValue(
      const yy::location &location,
      const char * value
  )
  : Value(location),
    value_(value)
  {}

  ~FloatValue() {}

  FloatValue(const FloatValue&) = delete;
  FloatValue& operator=(const FloatValue&) = delete;

  const char * getValue() const
  { return value_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class StringValue : public Value {
  std::unique_ptr<const char, CDeleter> value_;
 public:
  explicit StringValue(
      const yy::location &location,
      const char * value
  )
  : Value(location),
    value_(value)
  {}

  ~StringValue() {}

  StringValue(const StringValue&) = delete;
  StringValue& operator=(const StringValue&) = delete;

  const char * getValue() const
  { return value_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class BooleanValue : public Value {
  bool value_;
 public:
  explicit BooleanValue(
      const yy::location &location,
      bool value
  )
  : Value(location),
    value_(value)
  {}

  ~BooleanValue() {}

  BooleanValue(const BooleanValue&) = delete;
  BooleanValue& operator=(const BooleanValue&) = delete;

  bool getValue() const
  { return value_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class NullValue : public Value {
 public:
  explicit NullValue(
      const yy::location &location

  )
  : Value(location)

  {}

  ~NullValue() {}

  NullValue(const NullValue&) = delete;
  NullValue& operator=(const NullValue&) = delete;

  void accept(visitor::AstVisitor *visitor) const override;
};


class EnumValue : public Value {
  std::unique_ptr<const char, CDeleter> value_;
 public:
  explicit EnumValue(
      const yy::location &location,
      const char * value
  )
  : Value(location),
    value_(value)
  {}

  ~EnumValue() {}

  EnumValue(const EnumValue&) = delete;
  EnumValue& operator=(const EnumValue&) = delete;

  const char * getValue() const
  { return value_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class ListValue : public Value {
  std::unique_ptr<std::vector<std::unique_ptr<Value>>> values_;
 public:
  explicit ListValue(
      const yy::location &location,
      std::vector<std::unique_ptr<Value>> * values
  )
  : Value(location),
    values_(values)
  {}

  ~ListValue() {}

  ListValue(const ListValue&) = delete;
  ListValue& operator=(const ListValue&) = delete;

  const std::vector<std::unique_ptr<Value>>& getValues() const
  { return *values_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class ObjectValue : public Value {
  std::unique_ptr<std::vector<std::unique_ptr<ObjectField>>> fields_;
 public:
  explicit ObjectValue(
      const yy::location &location,
      std::vector<std::unique_ptr<ObjectField>> * fields
  )
  : Value(location),
    fields_(fields)
  {}

  ~ObjectValue() {}

  ObjectValue(const ObjectValue&) = delete;
  ObjectValue& operator=(const ObjectValue&) = delete;

  const std::vector<std::unique_ptr<ObjectField>>& getFields() const
  { return *fields_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class ObjectField : public Node {
  std::unique_ptr<Name> name_;
  std::unique_ptr<Value> value_;
 public:
  explicit ObjectField(
      const yy::location &location,
      Name * name,
      Value * value
  )
  : Node(location),
    name_(name),
    value_(value)
  {}

  ~ObjectField() {}

  ObjectField(const ObjectField&) = delete;
  ObjectField& operator=(const ObjectField&) = delete;

  const Name& getName() const
  { return *name_; }

  const Value& getValue() const
  { return *value_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class Directive : public Node {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Argument>>> arguments_;
 public:
  explicit Directive(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Argument>> * arguments
  )
  : Node(location),
    name_(name),
    arguments_(arguments)
  {}

  ~Directive() {}

  Directive(const Directive&) = delete;
  Directive& operator=(const Directive&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Argument>>* getArguments() const
  { return arguments_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class Type : public Node {
 public:
  explicit Type(
      const yy::location &location

  )
  : Node(location)

  {}
};

class NamedType : public Type {
  std::unique_ptr<Name> name_;
 public:
  explicit NamedType(
      const yy::location &location,
      Name * name
  )
  : Type(location),
    name_(name)
  {}

  ~NamedType() {}

  NamedType(const NamedType&) = delete;
  NamedType& operator=(const NamedType&) = delete;

  const Name& getName() const
  { return *name_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class ListType : public Type {
  std::unique_ptr<Type> type_;
 public:
  explicit ListType(
      const yy::location &location,
      Type * type
  )
  : Type(location),
    type_(type)
  {}

  ~ListType() {}

  ListType(const ListType&) = delete;
  ListType& operator=(const ListType&) = delete;

  const Type& getType() const
  { return *type_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class NonNullType : public Type {
  std::unique_ptr<Type> type_;
 public:
  explicit NonNullType(
      const yy::location &location,
      Type * type
  )
  : Type(location),
    type_(type)
  {}

  ~NonNullType() {}

  NonNullType(const NonNullType&) = delete;
  NonNullType& operator=(const NonNullType&) = delete;

  const Type& getType() const
  { return *type_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class Name : public Node {
  std::unique_ptr<const char, CDeleter> value_;
 public:
  explicit Name(
      const yy::location &location,
      const char * value
  )
  : Node(location),
    value_(value)
  {}

  ~Name() {}

  Name(const Name&) = delete;
  Name& operator=(const Name&) = delete;

  const char * getValue() const
  { return value_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class SchemaDefinition : public Definition {
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<std::vector<std::unique_ptr<OperationTypeDefinition>>> operationTypes_;
 public:
  explicit SchemaDefinition(
      const yy::location &location,
      std::vector<std::unique_ptr<Directive>> * directives,
      std::vector<std::unique_ptr<OperationTypeDefinition>> * operationTypes
  )
  : Definition(location),
    directives_(directives),
    operationTypes_(operationTypes)
  {}

  ~SchemaDefinition() {}

  SchemaDefinition(const SchemaDefinition&) = delete;
  SchemaDefinition& operator=(const SchemaDefinition&) = delete;

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const std::vector<std::unique_ptr<OperationTypeDefinition>>& getOperationTypes() const
  { return *operationTypes_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class OperationTypeDefinition : public Node {
  std::unique_ptr<const char, CDeleter> operation_;
  std::unique_ptr<NamedType> type_;
 public:
  explicit OperationTypeDefinition(
      const yy::location &location,
      const char * operation,
      NamedType * type
  )
  : Node(location),
    operation_(operation),
    type_(type)
  {}

  ~OperationTypeDefinition() {}

  OperationTypeDefinition(const OperationTypeDefinition&) = delete;
  OperationTypeDefinition& operator=(const OperationTypeDefinition&) = delete;

  const char * getOperation() const
  { return operation_.get(); }

  const NamedType& getType() const
  { return *type_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class ScalarTypeDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
 public:
  explicit ScalarTypeDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives
  )
  : Definition(location),
    name_(name),
    directives_(directives)
  {}

  ~ScalarTypeDefinition() {}

  ScalarTypeDefinition(const ScalarTypeDefinition&) = delete;
  ScalarTypeDefinition& operator=(const ScalarTypeDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class ObjectTypeDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<NamedType>>> interfaces_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<std::vector<std::unique_ptr<FieldDefinition>>> fields_;
 public:
  explicit ObjectTypeDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<NamedType>> * interfaces,
      std::vector<std::unique_ptr<Directive>> * directives,
      std::vector<std::unique_ptr<FieldDefinition>> * fields
  )
  : Definition(location),
    name_(name),
    interfaces_(interfaces),
    directives_(directives),
    fields_(fields)
  {}

  ~ObjectTypeDefinition() {}

  ObjectTypeDefinition(const ObjectTypeDefinition&) = delete;
  ObjectTypeDefinition& operator=(const ObjectTypeDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<NamedType>>* getInterfaces() const
  { return interfaces_.get(); }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const std::vector<std::unique_ptr<FieldDefinition>>& getFields() const
  { return *fields_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class FieldDefinition : public Node {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<InputValueDefinition>>> arguments_;
  std::unique_ptr<Type> type_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
 public:
  explicit FieldDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<InputValueDefinition>> * arguments,
      Type * type,
      std::vector<std::unique_ptr<Directive>> * directives
  )
  : Node(location),
    name_(name),
    arguments_(arguments),
    type_(type),
    directives_(directives)
  {}

  ~FieldDefinition() {}

  FieldDefinition(const FieldDefinition&) = delete;
  FieldDefinition& operator=(const FieldDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<InputValueDefinition>>* getArguments() const
  { return arguments_.get(); }

  const Type& getType() const
  { return *type_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class InputValueDefinition : public Node {
  std::unique_ptr<Name> name_;
  std::unique_ptr<Type> type_;
  std::unique_ptr<Value> defaultValue_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
 public:
  explicit InputValueDefinition(
      const yy::location &location,
      Name * name,
      Type * type,
      Value * defaultValue,
      std::vector<std::unique_ptr<Directive>> * directives
  )
  : Node(location),
    name_(name),
    type_(type),
    defaultValue_(defaultValue),
    directives_(directives)
  {}

  ~InputValueDefinition() {}

  InputValueDefinition(const InputValueDefinition&) = delete;
  InputValueDefinition& operator=(const InputValueDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const Type& getType() const
  { return *type_; }

  const Value* getDefaultValue() const
  { return defaultValue_.get(); }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class InterfaceTypeDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<std::vector<std::unique_ptr<FieldDefinition>>> fields_;
 public:
  explicit InterfaceTypeDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives,
      std::vector<std::unique_ptr<FieldDefinition>> * fields
  )
  : Definition(location),
    name_(name),
    directives_(directives),
    fields_(fields)
  {}

  ~InterfaceTypeDefinition() {}

  InterfaceTypeDefinition(const InterfaceTypeDefinition&) = delete;
  InterfaceTypeDefinition& operator=(const InterfaceTypeDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const std::vector<std::unique_ptr<FieldDefinition>>& getFields() const
  { return *fields_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class UnionTypeDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<std::vector<std::unique_ptr<NamedType>>> types_;
 public:
  explicit UnionTypeDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives,
      std::vector<std::unique_ptr<NamedType>> * types
  )
  : Definition(location),
    name_(name),
    directives_(directives),
    types_(types)
  {}

  ~UnionTypeDefinition() {}

  UnionTypeDefinition(const UnionTypeDefinition&) = delete;
  UnionTypeDefinition& operator=(const UnionTypeDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const std::vector<std::unique_ptr<NamedType>>& getTypes() const
  { return *types_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class EnumTypeDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<std::vector<std::unique_ptr<EnumValueDefinition>>> values_;
 public:
  explicit EnumTypeDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives,
      std::vector<std::unique_ptr<EnumValueDefinition>> * values
  )
  : Definition(location),
    name_(name),
    directives_(directives),
    values_(values)
  {}

  ~EnumTypeDefinition() {}

  EnumTypeDefinition(const EnumTypeDefinition&) = delete;
  EnumTypeDefinition& operator=(const EnumTypeDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const std::vector<std::unique_ptr<EnumValueDefinition>>& getValues() const
  { return *values_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class EnumValueDefinition : public Node {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
 public:
  explicit EnumValueDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives
  )
  : Node(location),
    name_(name),
    directives_(directives)
  {}

  ~EnumValueDefinition() {}

  EnumValueDefinition(const EnumValueDefinition&) = delete;
  EnumValueDefinition& operator=(const EnumValueDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  void accept(visitor::AstVisitor *visitor) const override;
};


class InputObjectTypeDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<Directive>>> directives_;
  std::unique_ptr<std::vector<std::unique_ptr<InputValueDefinition>>> fields_;
 public:
  explicit InputObjectTypeDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<Directive>> * directives,
      std::vector<std::unique_ptr<InputValueDefinition>> * fields
  )
  : Definition(location),
    name_(name),
    directives_(directives),
    fields_(fields)
  {}

  ~InputObjectTypeDefinition() {}

  InputObjectTypeDefinition(const InputObjectTypeDefinition&) = delete;
  InputObjectTypeDefinition& operator=(const InputObjectTypeDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<Directive>>* getDirectives() const
  { return directives_.get(); }

  const std::vector<std::unique_ptr<InputValueDefinition>>& getFields() const
  { return *fields_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class TypeExtensionDefinition : public Definition {
  std::unique_ptr<ObjectTypeDefinition> definition_;
 public:
  explicit TypeExtensionDefinition(
      const yy::location &location,
      ObjectTypeDefinition * definition
  )
  : Definition(location),
    definition_(definition)
  {}

  ~TypeExtensionDefinition() {}

  TypeExtensionDefinition(const TypeExtensionDefinition&) = delete;
  TypeExtensionDefinition& operator=(const TypeExtensionDefinition&) = delete;

  const ObjectTypeDefinition& getDefinition() const
  { return *definition_; }

  void accept(visitor::AstVisitor *visitor) const override;
};


class DirectiveDefinition : public Definition {
  std::unique_ptr<Name> name_;
  std::unique_ptr<std::vector<std::unique_ptr<InputValueDefinition>>> arguments_;
  std::unique_ptr<std::vector<std::unique_ptr<Name>>> locations_;
 public:
  explicit DirectiveDefinition(
      const yy::location &location,
      Name * name,
      std::vector<std::unique_ptr<InputValueDefinition>> * arguments,
      std::vector<std::unique_ptr<Name>> * locations
  )
  : Definition(location),
    name_(name),
    arguments_(arguments),
    locations_(locations)
  {}

  ~DirectiveDefinition() {}

  DirectiveDefinition(const DirectiveDefinition&) = delete;
  DirectiveDefinition& operator=(const DirectiveDefinition&) = delete;

  const Name& getName() const
  { return *name_; }

  const std::vector<std::unique_ptr<InputValueDefinition>>* getArguments() const
  { return arguments_.get(); }

  const std::vector<std::unique_ptr<Name>>& getLocations() const
  { return *locations_; }

  void accept(visitor::AstVisitor *visitor) const override;
};



}
}
}
