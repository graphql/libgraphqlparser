// A Bison parser, made by GNU Bison 3.0.5.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file parser.tab.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 20 "parser.ypp" // lalr1.cc:394

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "Ast.h"

using facebook::graphql::ast::Node;
using facebook::graphql::ast::Name;
using facebook::graphql::ast::Definition;
using facebook::graphql::ast::Document;
using facebook::graphql::ast::OperationDefinition;
using facebook::graphql::ast::VariableDefinition;
using facebook::graphql::ast::Variable;
using facebook::graphql::ast::SelectionSet;
using facebook::graphql::ast::Selection;
using facebook::graphql::ast::Field;
using facebook::graphql::ast::Argument;
using facebook::graphql::ast::FragmentSpread;
using facebook::graphql::ast::InlineFragment;
using facebook::graphql::ast::FragmentDefinition;
using facebook::graphql::ast::Value;
using facebook::graphql::ast::IntValue;
using facebook::graphql::ast::FloatValue;
using facebook::graphql::ast::StringValue;
using facebook::graphql::ast::BooleanValue;
using facebook::graphql::ast::NullValue;
using facebook::graphql::ast::EnumValue;
using facebook::graphql::ast::ListValue;
using facebook::graphql::ast::ObjectValue;
using facebook::graphql::ast::ObjectField;
using facebook::graphql::ast::Directive;
using facebook::graphql::ast::Type;
using facebook::graphql::ast::NamedType;
using facebook::graphql::ast::ListType;
using facebook::graphql::ast::NonNullType;

// Experimental schema support.
using facebook::graphql::ast::SchemaDefinition;
using facebook::graphql::ast::ScalarTypeDefinition;
using facebook::graphql::ast::ObjectTypeDefinition;
using facebook::graphql::ast::InterfaceTypeDefinition;
using facebook::graphql::ast::UnionTypeDefinition;
using facebook::graphql::ast::EnumTypeDefinition;
using facebook::graphql::ast::InputObjectTypeDefinition;
using facebook::graphql::ast::TypeExtensionDefinition;
using facebook::graphql::ast::DirectiveDefinition;
using facebook::graphql::ast::SchemaDefinition;
using facebook::graphql::ast::OperationTypeDefinition;
using facebook::graphql::ast::ScalarTypeDefinition;
using facebook::graphql::ast::ObjectTypeDefinition;
using facebook::graphql::ast::FieldDefinition;
using facebook::graphql::ast::InputValueDefinition;
using facebook::graphql::ast::InterfaceTypeDefinition;
using facebook::graphql::ast::UnionTypeDefinition;
using facebook::graphql::ast::EnumTypeDefinition;
using facebook::graphql::ast::EnumValueDefinition;
using facebook::graphql::ast::InputObjectTypeDefinition;
using facebook::graphql::ast::TypeExtensionDefinition;
using facebook::graphql::ast::DirectiveDefinition;

union yystype {                                         \
    const char *str;                                    \
    const char *heapStr;                                \
    Name *name;                                         \
    Definition *definition;                             \
    Document *document;                                 \
    OperationDefinition *operationDefinition;           \
    VariableDefinition *variableDefinition;             \
    Variable *variable;                                 \
    SelectionSet *selectionSet;                     \
    Selection *selection;                           \
    Field *field;                                   \
    Argument *argument;                             \
    FragmentSpread *fragmentSpread;                 \
    InlineFragment *inlineFragment;                 \
    FragmentDefinition *fragmentDefinition;         \
    Value *value;                                   \
    IntValue *intValue;                             \
    FloatValue *floatValue;                         \
    StringValue *stringValue;                       \
    BooleanValue *booleanValue;                     \
    NullValue *nullValue;                           \
    EnumValue *enumValue;                           \
    ListValue *arrayValue;                          \
    ObjectValue *objectValue;                       \
    ObjectField *objectField;                       \
    Directive *directive;                           \
    Type *type;                                     \
    NamedType *namedType;                           \
    ListType *listType;                             \
    NonNullType *nonNullType;                       \
    \
    std::vector<std::unique_ptr<Definition>> *definitionList;       \
    std::vector<std::unique_ptr<VariableDefinition>> *variableDefinitionList; \
    std::vector<std::unique_ptr<Selection>> *selectionList;         \
    std::vector<std::unique_ptr<Field>> *fieldList;                 \
    std::vector<std::unique_ptr<Argument>> *argumentList;           \
    std::vector<std::unique_ptr<Value>> *valueList;                 \
    std::vector<std::unique_ptr<ObjectField>> *objectFieldList;     \
    std::vector<std::unique_ptr<Directive>> *directiveList;         \
                                                                    \
    SchemaDefinition *schemaDefinition;                             \
    ScalarTypeDefinition *scalarTypeDefinition;                     \
    ObjectTypeDefinition *objectTypeDefinition;                     \
    InterfaceTypeDefinition *interfaceTypeDefinition;               \
    UnionTypeDefinition *unionTypeDefinition;                       \
    EnumTypeDefinition *enumTypeDefinition;                         \
    InputObjectTypeDefinition *inputObjectTypeDefinition;           \
    TypeExtensionDefinition *typeExtensionDefinition;               \
    DirectiveDefinition *directiveDefinition;                       \
    OperationTypeDefinition *operationTypeDefinition;               \
    InputValueDefinition *inputValueDefinition;                     \
    FieldDefinition *fieldDefinition;                               \
    EnumValueDefinition *enumValueDefinition;                       \
    \
    std::vector<std::unique_ptr<OperationTypeDefinition>> *operationTypeDefinitionList; \
    std::vector<std::unique_ptr<NamedType>> *typeNameList;          \
    std::vector<std::unique_ptr<InputValueDefinition>> *inputValueDefinitionList; \
    std::vector<std::unique_ptr<FieldDefinition>> *fieldDefinitionList; \
    std::vector<std::unique_ptr<Name>> *nameList;          \
    std::vector<std::unique_ptr<EnumValueDefinition>> *enumValueDefinitionList; \
};

#define YYSTYPE union yystype
#define YYLTYPE yy::location


#line 175 "parser.tab.hpp" // lalr1.cc:394


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 247 "parser.tab.hpp" // lalr1.cc:394





  /// A Bison parser.
  class GraphQLParserImpl
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_EOF = 0,
        TOK_DIRECTIVE = 258,
        TOK_ENUM = 259,
        TOK_EXTEND = 260,
        TOK_FALSE = 261,
        TOK_FRAGMENT = 262,
        TOK_IMPLEMENTS = 263,
        TOK_INPUT = 264,
        TOK_INTERFACE = 265,
        TOK_MUTATION = 266,
        TOK_NULL = 267,
        TOK_QUERY = 268,
        TOK_ON = 269,
        TOK_SCALAR = 270,
        TOK_SCHEMA = 271,
        TOK_SUBSCRIPTION = 272,
        TOK_TRUE = 273,
        TOK_TYPE = 274,
        TOK_UNION = 275,
        TOK_BANG = 276,
        TOK_LPAREN = 277,
        TOK_RPAREN = 278,
        TOK_ELLIPSIS = 279,
        TOK_COLON = 280,
        TOK_EQUAL = 281,
        TOK_AT = 282,
        TOK_LBRACKET = 283,
        TOK_RBRACKET = 284,
        TOK_LBRACE = 285,
        TOK_PIPE = 286,
        TOK_RBRACE = 287,
        TOK_VARIABLE = 288,
        TOK_INTEGER = 289,
        TOK_FLOAT = 290,
        TOK_STRING = 291,
        TOK_IDENTIFIER = 292
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    const location_type& l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;


    /// Build a parser object.
    GraphQLParserImpl (bool enableSchema_yyarg, Node **outAST_yyarg, const char **outError_yyarg, void *scanner_yyarg);
    virtual ~GraphQLParserImpl ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    GraphQLParserImpl (const GraphQLParserImpl&);
    GraphQLParserImpl& operator= (const GraphQLParserImpl&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Copy construct.
      stack_symbol_type (const stack_symbol_type& that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 955,     ///< Last index in yytable_.
      yynnts_ = 79,  ///< Number of nonterminal symbols.
      yyfinal_ = 74, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 38  ///< Number of tokens.
    };


    // User arguments.
    bool enableSchema;
    Node **outAST;
    const char **outError;
    void *scanner;
  };



} // yy
#line 642 "parser.tab.hpp" // lalr1.cc:394




#endif // !YY_YY_PARSER_TAB_HPP_INCLUDED
