/**
 * Copyright 2019-present GraphQL Foundation
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
/** @generated */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif


struct GraphQLAstDefinition;

struct GraphQLAstDocument;
int GraphQLAstDocument_get_definitions_size(const struct GraphQLAstDocument *node);

struct GraphQLAstOperationDefinition;
const char * GraphQLAstOperationDefinition_get_operation(const struct GraphQLAstOperationDefinition *node);
const struct GraphQLAstName * GraphQLAstOperationDefinition_get_name(const struct GraphQLAstOperationDefinition *node);
int GraphQLAstOperationDefinition_get_variable_definitions_size(const struct GraphQLAstOperationDefinition *node);
int GraphQLAstOperationDefinition_get_directives_size(const struct GraphQLAstOperationDefinition *node);
const struct GraphQLAstSelectionSet * GraphQLAstOperationDefinition_get_selection_set(const struct GraphQLAstOperationDefinition *node);

struct GraphQLAstVariableDefinition;
const struct GraphQLAstVariable * GraphQLAstVariableDefinition_get_variable(const struct GraphQLAstVariableDefinition *node);
const struct GraphQLAstType * GraphQLAstVariableDefinition_get_type(const struct GraphQLAstVariableDefinition *node);
const struct GraphQLAstValue * GraphQLAstVariableDefinition_get_default_value(const struct GraphQLAstVariableDefinition *node);

struct GraphQLAstSelectionSet;
int GraphQLAstSelectionSet_get_selections_size(const struct GraphQLAstSelectionSet *node);

struct GraphQLAstSelection;

struct GraphQLAstField;
const struct GraphQLAstName * GraphQLAstField_get_alias(const struct GraphQLAstField *node);
const struct GraphQLAstName * GraphQLAstField_get_name(const struct GraphQLAstField *node);
int GraphQLAstField_get_arguments_size(const struct GraphQLAstField *node);
int GraphQLAstField_get_directives_size(const struct GraphQLAstField *node);
const struct GraphQLAstSelectionSet * GraphQLAstField_get_selection_set(const struct GraphQLAstField *node);

struct GraphQLAstArgument;
const struct GraphQLAstName * GraphQLAstArgument_get_name(const struct GraphQLAstArgument *node);
const struct GraphQLAstValue * GraphQLAstArgument_get_value(const struct GraphQLAstArgument *node);

struct GraphQLAstFragmentSpread;
const struct GraphQLAstName * GraphQLAstFragmentSpread_get_name(const struct GraphQLAstFragmentSpread *node);
int GraphQLAstFragmentSpread_get_directives_size(const struct GraphQLAstFragmentSpread *node);

struct GraphQLAstInlineFragment;
const struct GraphQLAstNamedType * GraphQLAstInlineFragment_get_type_condition(const struct GraphQLAstInlineFragment *node);
int GraphQLAstInlineFragment_get_directives_size(const struct GraphQLAstInlineFragment *node);
const struct GraphQLAstSelectionSet * GraphQLAstInlineFragment_get_selection_set(const struct GraphQLAstInlineFragment *node);

struct GraphQLAstFragmentDefinition;
const struct GraphQLAstName * GraphQLAstFragmentDefinition_get_name(const struct GraphQLAstFragmentDefinition *node);
const struct GraphQLAstNamedType * GraphQLAstFragmentDefinition_get_type_condition(const struct GraphQLAstFragmentDefinition *node);
int GraphQLAstFragmentDefinition_get_directives_size(const struct GraphQLAstFragmentDefinition *node);
const struct GraphQLAstSelectionSet * GraphQLAstFragmentDefinition_get_selection_set(const struct GraphQLAstFragmentDefinition *node);

struct GraphQLAstValue;

struct GraphQLAstVariable;
const struct GraphQLAstName * GraphQLAstVariable_get_name(const struct GraphQLAstVariable *node);

struct GraphQLAstIntValue;
const char * GraphQLAstIntValue_get_value(const struct GraphQLAstIntValue *node);

struct GraphQLAstFloatValue;
const char * GraphQLAstFloatValue_get_value(const struct GraphQLAstFloatValue *node);

struct GraphQLAstStringValue;
const char * GraphQLAstStringValue_get_value(const struct GraphQLAstStringValue *node);

struct GraphQLAstBooleanValue;
int GraphQLAstBooleanValue_get_value(const struct GraphQLAstBooleanValue *node);

struct GraphQLAstNullValue;

struct GraphQLAstEnumValue;
const char * GraphQLAstEnumValue_get_value(const struct GraphQLAstEnumValue *node);

struct GraphQLAstListValue;
int GraphQLAstListValue_get_values_size(const struct GraphQLAstListValue *node);

struct GraphQLAstObjectValue;
int GraphQLAstObjectValue_get_fields_size(const struct GraphQLAstObjectValue *node);

struct GraphQLAstObjectField;
const struct GraphQLAstName * GraphQLAstObjectField_get_name(const struct GraphQLAstObjectField *node);
const struct GraphQLAstValue * GraphQLAstObjectField_get_value(const struct GraphQLAstObjectField *node);

struct GraphQLAstDirective;
const struct GraphQLAstName * GraphQLAstDirective_get_name(const struct GraphQLAstDirective *node);
int GraphQLAstDirective_get_arguments_size(const struct GraphQLAstDirective *node);

struct GraphQLAstType;

struct GraphQLAstNamedType;
const struct GraphQLAstName * GraphQLAstNamedType_get_name(const struct GraphQLAstNamedType *node);

struct GraphQLAstListType;
const struct GraphQLAstType * GraphQLAstListType_get_type(const struct GraphQLAstListType *node);

struct GraphQLAstNonNullType;
const struct GraphQLAstType * GraphQLAstNonNullType_get_type(const struct GraphQLAstNonNullType *node);

struct GraphQLAstName;
const char * GraphQLAstName_get_value(const struct GraphQLAstName *node);

struct GraphQLAstSchemaDefinition;
int GraphQLAstSchemaDefinition_get_directives_size(const struct GraphQLAstSchemaDefinition *node);
int GraphQLAstSchemaDefinition_get_operation_types_size(const struct GraphQLAstSchemaDefinition *node);

struct GraphQLAstOperationTypeDefinition;
const char * GraphQLAstOperationTypeDefinition_get_operation(const struct GraphQLAstOperationTypeDefinition *node);
const struct GraphQLAstNamedType * GraphQLAstOperationTypeDefinition_get_type(const struct GraphQLAstOperationTypeDefinition *node);

struct GraphQLAstScalarTypeDefinition;
const struct GraphQLAstName * GraphQLAstScalarTypeDefinition_get_name(const struct GraphQLAstScalarTypeDefinition *node);
int GraphQLAstScalarTypeDefinition_get_directives_size(const struct GraphQLAstScalarTypeDefinition *node);

struct GraphQLAstObjectTypeDefinition;
const struct GraphQLAstName * GraphQLAstObjectTypeDefinition_get_name(const struct GraphQLAstObjectTypeDefinition *node);
int GraphQLAstObjectTypeDefinition_get_interfaces_size(const struct GraphQLAstObjectTypeDefinition *node);
int GraphQLAstObjectTypeDefinition_get_directives_size(const struct GraphQLAstObjectTypeDefinition *node);
int GraphQLAstObjectTypeDefinition_get_fields_size(const struct GraphQLAstObjectTypeDefinition *node);

struct GraphQLAstFieldDefinition;
const struct GraphQLAstName * GraphQLAstFieldDefinition_get_name(const struct GraphQLAstFieldDefinition *node);
int GraphQLAstFieldDefinition_get_arguments_size(const struct GraphQLAstFieldDefinition *node);
const struct GraphQLAstType * GraphQLAstFieldDefinition_get_type(const struct GraphQLAstFieldDefinition *node);
int GraphQLAstFieldDefinition_get_directives_size(const struct GraphQLAstFieldDefinition *node);

struct GraphQLAstInputValueDefinition;
const struct GraphQLAstName * GraphQLAstInputValueDefinition_get_name(const struct GraphQLAstInputValueDefinition *node);
const struct GraphQLAstType * GraphQLAstInputValueDefinition_get_type(const struct GraphQLAstInputValueDefinition *node);
const struct GraphQLAstValue * GraphQLAstInputValueDefinition_get_default_value(const struct GraphQLAstInputValueDefinition *node);
int GraphQLAstInputValueDefinition_get_directives_size(const struct GraphQLAstInputValueDefinition *node);

struct GraphQLAstInterfaceTypeDefinition;
const struct GraphQLAstName * GraphQLAstInterfaceTypeDefinition_get_name(const struct GraphQLAstInterfaceTypeDefinition *node);
int GraphQLAstInterfaceTypeDefinition_get_directives_size(const struct GraphQLAstInterfaceTypeDefinition *node);
int GraphQLAstInterfaceTypeDefinition_get_fields_size(const struct GraphQLAstInterfaceTypeDefinition *node);

struct GraphQLAstUnionTypeDefinition;
const struct GraphQLAstName * GraphQLAstUnionTypeDefinition_get_name(const struct GraphQLAstUnionTypeDefinition *node);
int GraphQLAstUnionTypeDefinition_get_directives_size(const struct GraphQLAstUnionTypeDefinition *node);
int GraphQLAstUnionTypeDefinition_get_types_size(const struct GraphQLAstUnionTypeDefinition *node);

struct GraphQLAstEnumTypeDefinition;
const struct GraphQLAstName * GraphQLAstEnumTypeDefinition_get_name(const struct GraphQLAstEnumTypeDefinition *node);
int GraphQLAstEnumTypeDefinition_get_directives_size(const struct GraphQLAstEnumTypeDefinition *node);
int GraphQLAstEnumTypeDefinition_get_values_size(const struct GraphQLAstEnumTypeDefinition *node);

struct GraphQLAstEnumValueDefinition;
const struct GraphQLAstName * GraphQLAstEnumValueDefinition_get_name(const struct GraphQLAstEnumValueDefinition *node);
int GraphQLAstEnumValueDefinition_get_directives_size(const struct GraphQLAstEnumValueDefinition *node);

struct GraphQLAstInputObjectTypeDefinition;
const struct GraphQLAstName * GraphQLAstInputObjectTypeDefinition_get_name(const struct GraphQLAstInputObjectTypeDefinition *node);
int GraphQLAstInputObjectTypeDefinition_get_directives_size(const struct GraphQLAstInputObjectTypeDefinition *node);
int GraphQLAstInputObjectTypeDefinition_get_fields_size(const struct GraphQLAstInputObjectTypeDefinition *node);

struct GraphQLAstTypeExtensionDefinition;
const struct GraphQLAstObjectTypeDefinition * GraphQLAstTypeExtensionDefinition_get_definition(const struct GraphQLAstTypeExtensionDefinition *node);

struct GraphQLAstDirectiveDefinition;
const struct GraphQLAstName * GraphQLAstDirectiveDefinition_get_name(const struct GraphQLAstDirectiveDefinition *node);
int GraphQLAstDirectiveDefinition_get_arguments_size(const struct GraphQLAstDirectiveDefinition *node);
int GraphQLAstDirectiveDefinition_get_locations_size(const struct GraphQLAstDirectiveDefinition *node);



#ifdef __cplusplus
}
#endif

