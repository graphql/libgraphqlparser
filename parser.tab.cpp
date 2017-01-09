// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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


// First part of user declarations.

#line 37 "parser.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hpp"

// User implementation prologue.

#line 51 "parser.tab.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 159 "parser.ypp" // lalr1.cc:413

#include "lexer.h"
#include "syntaxdefs.h"

#line 58 "parser.tab.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 144 "parser.tab.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  GraphQLParserImpl::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  GraphQLParserImpl::GraphQLParserImpl (bool enableSchema_yyarg, Node **outAST_yyarg, const char **outError_yyarg, void *scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      enableSchema (enableSchema_yyarg),
      outAST (outAST_yyarg),
      outError (outError_yyarg),
      scanner (scanner_yyarg)
  {}

  GraphQLParserImpl::~GraphQLParserImpl ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  GraphQLParserImpl::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  GraphQLParserImpl::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  GraphQLParserImpl::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  GraphQLParserImpl::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  GraphQLParserImpl::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  GraphQLParserImpl::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  GraphQLParserImpl::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  GraphQLParserImpl::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  GraphQLParserImpl::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  GraphQLParserImpl::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  GraphQLParserImpl::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  GraphQLParserImpl::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  GraphQLParserImpl::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  GraphQLParserImpl::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  GraphQLParserImpl::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  GraphQLParserImpl::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  GraphQLParserImpl::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  GraphQLParserImpl::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  GraphQLParserImpl::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  GraphQLParserImpl::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  GraphQLParserImpl::symbol_number_type
  GraphQLParserImpl::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  GraphQLParserImpl::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  GraphQLParserImpl::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  GraphQLParserImpl::stack_symbol_type&
  GraphQLParserImpl::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  GraphQLParserImpl::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 3: // "directive"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 400 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 4: // "enum"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 407 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 5: // "extend"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 414 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 6: // "false"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 421 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 7: // "fragment"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 428 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 8: // "implements"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 435 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 9: // "input"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 442 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 10: // "interface"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 449 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 11: // "mutation"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 456 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 12: // "null"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 463 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 13: // "query"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 470 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 14: // "on"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 477 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 15: // "scalar"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 484 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 16: // "schema"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 491 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 17: // "subscription"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 498 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 18: // "true"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 505 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 19: // "type"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 512 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 20: // "union"

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 519 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 33: // VARIABLE

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 526 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 34: // INTEGER

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 533 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 35: // FLOAT

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 540 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 36: // STRING

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 547 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 37: // IDENTIFIER

#line 291 "parser.ypp" // lalr1.cc:617
        { }
#line 554 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 39: // start

#line 293 "parser.ypp" // lalr1.cc:617
        { }
#line 561 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 40: // fragment_name

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 568 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 41: // name

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 575 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 42: // name_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 582 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 43: // document

#line 293 "parser.ypp" // lalr1.cc:617
        { }
#line 589 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 44: // definition_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definitionList); }
#line 596 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 45: // definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definition); }
#line 603 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 46: // schema_gate

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definition); }
#line 610 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 47: // operation_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.operationDefinition); }
#line 617 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 48: // operation_type

#line 292 "parser.ypp" // lalr1.cc:617
        { free((void *)(yysym.value.heapStr)); }
#line 624 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 49: // variable_definitions

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinitionList); }
#line 631 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 50: // variable_definition_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinitionList); }
#line 638 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 51: // variable

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variable); }
#line 645 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 52: // variable_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinition); }
#line 652 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 53: // default_value_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 659 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 54: // default_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 666 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 55: // selection_set

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionSet); }
#line 673 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 56: // selection_set_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionSet); }
#line 680 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 57: // selection_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionList); }
#line 687 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 58: // selection

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selection); }
#line 694 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 59: // field

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.field); }
#line 701 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 60: // arguments

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 708 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 61: // arguments_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 715 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 62: // argument_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 722 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 63: // argument

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argument); }
#line 729 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 64: // fragment_spread

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fragmentSpread); }
#line 736 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 65: // inline_fragment

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inlineFragment); }
#line 743 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 66: // fragment_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fragmentDefinition); }
#line 750 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 67: // type_condition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.namedType); }
#line 757 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 68: // value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 764 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 69: // int_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.intValue); }
#line 771 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 70: // float_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.floatValue); }
#line 778 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 71: // string_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.stringValue); }
#line 785 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 72: // value_const

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 792 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 73: // boolean_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.booleanValue); }
#line 799 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 74: // null_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.nullValue); }
#line 806 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 75: // enum_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.enumValue); }
#line 813 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 76: // list_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.arrayValue); }
#line 820 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 77: // value_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.valueList); }
#line 827 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 78: // list_value_const

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.arrayValue); }
#line 834 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 79: // value_const_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.valueList); }
#line 841 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 80: // object_value

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectValue); }
#line 848 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 81: // object_field_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectFieldList); }
#line 855 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 82: // object_field

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectField); }
#line 862 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 83: // object_value_const

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectValue); }
#line 869 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 84: // object_field_const_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectFieldList); }
#line 876 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 85: // object_field_const

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectField); }
#line 883 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 86: // directives

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 890 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 87: // directives_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 897 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 88: // directive_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 904 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 89: // directive

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directive); }
#line 911 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 90: // type

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.type); }
#line 918 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 91: // type_name

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.namedType); }
#line 925 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 92: // list_type

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.listType); }
#line 932 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 93: // non_null_type

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.nonNullType); }
#line 939 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 94: // schema_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.schemaDefinition); }
#line 946 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 95: // operation_type_definition_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.operationTypeDefinitionList); }
#line 953 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 96: // operation_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.operationTypeDefinition); }
#line 960 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 97: // scalar_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.scalarTypeDefinition); }
#line 967 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 98: // object_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectTypeDefinition); }
#line 974 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 99: // implements_interfaces_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.typeNameList); }
#line 981 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 100: // type_name_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.typeNameList); }
#line 988 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 101: // field_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fieldDefinition); }
#line 995 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 102: // field_definition_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fieldDefinitionList); }
#line 1002 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 103: // arguments_definition_opt

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inputValueDefinitionList); }
#line 1009 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 104: // arguments_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inputValueDefinitionList); }
#line 1016 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 105: // input_value_definition_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inputValueDefinitionList); }
#line 1023 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 106: // input_value_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inputValueDefinition); }
#line 1030 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 107: // interface_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.interfaceTypeDefinition); }
#line 1037 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 108: // union_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.unionTypeDefinition); }
#line 1044 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 109: // union_members

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.typeNameList); }
#line 1051 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 110: // enum_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.enumTypeDefinition); }
#line 1058 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 111: // enum_value_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.enumValueDefinition); }
#line 1065 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 112: // enum_value_definition_list

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.enumValueDefinitionList); }
#line 1072 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 113: // input_object_type_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inputObjectTypeDefinition); }
#line 1079 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 114: // type_extension_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.typeExtensionDefinition); }
#line 1086 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 115: // directive_definition

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveDefinition); }
#line 1093 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 116: // directive_locations

#line 294 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.nameList); }
#line 1100 "parser.tab.cpp" // lalr1.cc:617
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  GraphQLParserImpl::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // "directive"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1131 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 4: // "enum"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1138 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 5: // "extend"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1145 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 6: // "false"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1152 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 7: // "fragment"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1159 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 8: // "implements"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1166 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 9: // "input"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1173 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 10: // "interface"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1180 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 11: // "mutation"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1187 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 12: // "null"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1194 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 13: // "query"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1201 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 14: // "on"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1208 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 15: // "scalar"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1215 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 16: // "schema"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1222 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 17: // "subscription"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1229 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 18: // "true"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1236 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 19: // "type"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1243 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 20: // "union"

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1250 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 33: // VARIABLE

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1257 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 34: // INTEGER

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1264 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 35: // FLOAT

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1271 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 36: // STRING

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1278 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 37: // IDENTIFIER

#line 296 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 1285 "parser.tab.cpp" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  GraphQLParserImpl::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  GraphQLParserImpl::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  GraphQLParserImpl::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  GraphQLParserImpl::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  GraphQLParserImpl::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  GraphQLParserImpl::debug_level_type
  GraphQLParserImpl::debug_level () const
  {
    return yydebug_;
  }

  void
  GraphQLParserImpl::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline GraphQLParserImpl::state_type
  GraphQLParserImpl::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  GraphQLParserImpl::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  GraphQLParserImpl::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  GraphQLParserImpl::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 300 "parser.ypp" // lalr1.cc:859
    { *outAST = (yystack_[0].value.document); }
#line 1505 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 305 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1511 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 306 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1517 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 307 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1523 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 308 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1529 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 309 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1535 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 310 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1541 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 311 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1547 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 312 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1553 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 313 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1559 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 314 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1565 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 315 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1571 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 316 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1577 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 317 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1583 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 318 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1589 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 319 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1595 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 320 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1601 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 321 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1607 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 322 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1613 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 326 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1619 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 330 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.name) = nullptr;}
#line 1625 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 336 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.document) = new Document(yylhs.location, (yystack_[0].value.definitionList)); }
#line 1631 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 339 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definitionList) = new std::vector<std::unique_ptr<Definition>>(); (yylhs.value.definitionList)->emplace_back((yystack_[0].value.definition)); }
#line 1637 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 340 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.definitionList)->emplace_back((yystack_[0].value.definition)); (yylhs.value.definitionList) = (yystack_[1].value.definitionList); }
#line 1643 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 343 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.operationDefinition)); }
#line 1649 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 344 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.fragmentDefinition)); }
#line 1655 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 345 "parser.ypp" // lalr1.cc:859
    {
            if (!enableSchema) {
              error(yylhs.location, "schema support disabled");
              // %destructor doesn't work with YYERROR. See
              // https://www.gnu.org/software/bison/manual/html_node/Destructor-Decl.html
              delete (yylhs.value.definition);
              YYERROR;
            }
            (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.definition));
          }
#line 1670 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 357 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.schemaDefinition)); }
#line 1676 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 358 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.scalarTypeDefinition)); }
#line 1682 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 359 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.objectTypeDefinition)); }
#line 1688 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 360 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.interfaceTypeDefinition)); }
#line 1694 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 361 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.unionTypeDefinition)); }
#line 1700 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 362 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.enumTypeDefinition)); }
#line 1706 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 363 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.inputObjectTypeDefinition)); }
#line 1712 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 364 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.typeExtensionDefinition)); }
#line 1718 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 365 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.directiveDefinition)); }
#line 1724 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 371 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, strdup("query"), nullptr, nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 1730 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 372 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[2].value.heapStr), (yystack_[1].value.name), nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 1736 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 373 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.heapStr), (yystack_[2].value.name), (yystack_[1].value.variableDefinitionList), nullptr, (yystack_[0].value.selectionSet)); }
#line 1742 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 374 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.heapStr), (yystack_[2].value.name), nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1748 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 375 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[4].value.heapStr), (yystack_[3].value.name), (yystack_[2].value.variableDefinitionList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1754 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 378 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1760 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 379 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1766 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 380 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1772 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 384 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 1778 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 388 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = new std::vector<std::unique_ptr<VariableDefinition>>(); (yylhs.value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); }
#line 1784 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 389 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 1790 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 392 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variable) = new Variable(yylhs.location, new Name(yystack_[0].location, strdup((yystack_[0].value.str)))); }
#line 1796 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 396 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinition) = new VariableDefinition(yylhs.location, (yystack_[3].value.variable), (yystack_[1].value.type), (yystack_[0].value.value)); }
#line 1802 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 400 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = nullptr; }
#line 1808 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 404 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = (yystack_[0].value.value); }
#line 1814 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 408 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = new SelectionSet(yylhs.location, (yystack_[1].value.selectionList)); }
#line 1820 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 412 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = nullptr; }
#line 1826 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 415 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionList) = new std::vector<std::unique_ptr<Selection>>(); (yylhs.value.selectionList)->emplace_back((yystack_[0].value.selection)); }
#line 1832 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 416 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.selectionList)->emplace_back((yystack_[0].value.selection)); (yylhs.value.selectionList) = (yystack_[1].value.selectionList); }
#line 1838 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 419 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.field)); }
#line 1844 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 420 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.fragmentSpread)); }
#line 1850 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 421 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.inlineFragment)); }
#line 1856 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 424 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, nullptr, (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1862 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 425 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, (yystack_[5].value.name), (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1868 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 428 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 1874 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 431 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = nullptr; }
#line 1880 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 432 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[0].value.argumentList); }
#line 1886 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 435 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = new std::vector<std::unique_ptr<Argument>>(); (yylhs.value.argumentList)->emplace_back((yystack_[0].value.argument)); }
#line 1892 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 436 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.argumentList)->emplace_back((yystack_[0].value.argument)); (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 1898 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 439 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argument) = new Argument(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1904 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 444 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentSpread) = new FragmentSpread(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.directiveList)); }
#line 1910 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 448 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1916 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 449 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1922 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 453 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentDefinition) = new FragmentDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1928 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 460 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.variable)); }
#line 1934 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 461 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1940 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 462 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1946 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 463 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1952 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 464 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1958 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 465 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.nullValue)); }
#line 1964 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 466 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1970 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 467 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1976 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 468 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1982 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 471 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.intValue) = new IntValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1988 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 474 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.floatValue) = new FloatValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1994 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 477 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.stringValue) = new StringValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2000 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 480 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 2006 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 481 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 2012 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 482 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 2018 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 483 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 2024 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 484 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.nullValue)); }
#line 2030 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 485 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 2036 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 486 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 2042 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 487 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 2048 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 490 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, true); }
#line 2054 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 491 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, false); }
#line 2060 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 494 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nullValue) = new NullValue(yylhs.location); }
#line 2066 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 497 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2072 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 498 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2078 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 499 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2084 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 500 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2090 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 501 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2096 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 502 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2102 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 503 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2108 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 504 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2114 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 505 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2120 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 506 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2126 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 507 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2132 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 111:
#line 508 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2138 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 112:
#line 509 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2144 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 113:
#line 510 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2150 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 114:
#line 511 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2156 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 115:
#line 512 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 2162 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 116:
#line 519 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 2168 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 117:
#line 520 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 2174 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 118:
#line 523 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 2180 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 119:
#line 524 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 2186 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 120:
#line 528 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 2192 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 121:
#line 529 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 2198 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 122:
#line 533 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 2204 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 123:
#line 534 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 2210 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 124:
#line 539 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 2216 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 125:
#line 540 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 2222 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 126:
#line 544 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 2228 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 127:
#line 545 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 2234 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 128:
#line 548 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 2240 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 129:
#line 552 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 2246 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 130:
#line 553 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 2252 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 131:
#line 557 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 2258 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 132:
#line 558 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 2264 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 133:
#line 561 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 2270 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 135:
#line 569 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = nullptr; }
#line 2276 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 137:
#line 573 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = new std::vector<std::unique_ptr<Directive>>(); (yylhs.value.directiveList)->emplace_back((yystack_[0].value.directive)); }
#line 2282 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 138:
#line 574 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.directiveList)->emplace_back((yystack_[0].value.directive)); (yylhs.value.directiveList) = (yystack_[1].value.directiveList); }
#line 2288 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 139:
#line 577 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directive) = new Directive(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.argumentList)); }
#line 2294 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 140:
#line 582 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.namedType)); }
#line 2300 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 141:
#line 583 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.listType)); }
#line 2306 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 142:
#line 584 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.nonNullType)); }
#line 2312 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 143:
#line 587 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.namedType) = new NamedType(yylhs.location, (yystack_[0].value.name)); }
#line 2318 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 144:
#line 590 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.listType) = new ListType(yylhs.location, (yystack_[1].value.type)); }
#line 2324 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 145:
#line 593 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.namedType)); }
#line 2330 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 146:
#line 594 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.listType)); }
#line 2336 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 147:
#line 599 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.schemaDefinition) = new SchemaDefinition(yylhs.location, (yystack_[3].value.directiveList), (yystack_[1].value.operationTypeDefinitionList)); }
#line 2342 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 148:
#line 603 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationTypeDefinitionList) = new std::vector<std::unique_ptr<OperationTypeDefinition>>(); (yylhs.value.operationTypeDefinitionList)->emplace_back((yystack_[0].value.operationTypeDefinition)); }
#line 2348 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 149:
#line 604 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.operationTypeDefinitionList)->emplace_back((yystack_[0].value.operationTypeDefinition)); (yylhs.value.operationTypeDefinitionList) = (yystack_[1].value.operationTypeDefinitionList); }
#line 2354 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 150:
#line 608 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationTypeDefinition) = new OperationTypeDefinition(yylhs.location, (yystack_[2].value.heapStr), (yystack_[0].value.namedType)); }
#line 2360 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 151:
#line 611 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.scalarTypeDefinition) = new ScalarTypeDefinition(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.directiveList)); }
#line 2366 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 152:
#line 614 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectTypeDefinition) = new ObjectTypeDefinition(yylhs.location, (yystack_[5].value.name), (yystack_[4].value.typeNameList), (yystack_[3].value.directiveList), (yystack_[1].value.fieldDefinitionList)); }
#line 2372 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 153:
#line 617 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.typeNameList) = nullptr; }
#line 2378 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 154:
#line 618 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.typeNameList) = (yystack_[0].value.typeNameList); }
#line 2384 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 155:
#line 621 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.typeNameList) = new std::vector<std::unique_ptr<NamedType>>(); (yylhs.value.typeNameList)->emplace_back((yystack_[0].value.namedType)); }
#line 2390 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 156:
#line 622 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.typeNameList)->emplace_back((yystack_[0].value.namedType)); (yylhs.value.typeNameList) = (yystack_[1].value.typeNameList); }
#line 2396 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 157:
#line 625 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fieldDefinition) = new FieldDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[3].value.inputValueDefinitionList), (yystack_[1].value.type), (yystack_[0].value.directiveList)); }
#line 2402 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 158:
#line 629 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fieldDefinitionList) = new std::vector<std::unique_ptr<FieldDefinition>>(); (yylhs.value.fieldDefinitionList)->emplace_back((yystack_[0].value.fieldDefinition)); }
#line 2408 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 159:
#line 630 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.fieldDefinitionList)->emplace_back((yystack_[0].value.fieldDefinition)); (yylhs.value.fieldDefinitionList) = (yystack_[1].value.fieldDefinitionList); }
#line 2414 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 160:
#line 633 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inputValueDefinitionList) = nullptr; }
#line 2420 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 161:
#line 634 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inputValueDefinitionList) = (yystack_[0].value.inputValueDefinitionList); }
#line 2426 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 162:
#line 637 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inputValueDefinitionList) = (yystack_[1].value.inputValueDefinitionList); }
#line 2432 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 163:
#line 640 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inputValueDefinitionList) = new std::vector<std::unique_ptr<InputValueDefinition>>(); (yylhs.value.inputValueDefinitionList)->emplace_back((yystack_[0].value.inputValueDefinition)); }
#line 2438 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 164:
#line 641 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.inputValueDefinitionList)->emplace_back((yystack_[0].value.inputValueDefinition)); (yylhs.value.inputValueDefinitionList) = (yystack_[1].value.inputValueDefinitionList); }
#line 2444 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 165:
#line 644 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inputValueDefinition) = new InputValueDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[2].value.type), (yystack_[1].value.value), (yystack_[0].value.directiveList)); }
#line 2450 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 166:
#line 646 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.interfaceTypeDefinition) = new InterfaceTypeDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[3].value.directiveList), (yystack_[1].value.fieldDefinitionList)); }
#line 2456 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 167:
#line 649 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.unionTypeDefinition) = new UnionTypeDefinition(yylhs.location, (yystack_[3].value.name), (yystack_[2].value.directiveList), (yystack_[0].value.typeNameList)); }
#line 2462 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 168:
#line 652 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.typeNameList) = new std::vector<std::unique_ptr<NamedType>>();  (yylhs.value.typeNameList)->emplace_back((yystack_[0].value.namedType)); }
#line 2468 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 169:
#line 653 "parser.ypp" // lalr1.cc:859
    { (yystack_[2].value.typeNameList)->emplace_back((yystack_[0].value.namedType)); (yylhs.value.typeNameList) = (yystack_[2].value.typeNameList); }
#line 2474 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 170:
#line 656 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumTypeDefinition) = new EnumTypeDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[3].value.directiveList), (yystack_[1].value.enumValueDefinitionList)); }
#line 2480 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 171:
#line 659 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValueDefinition) = new EnumValueDefinition(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.directiveList)); }
#line 2486 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 172:
#line 663 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValueDefinitionList) = new std::vector<std::unique_ptr<EnumValueDefinition>>(); (yylhs.value.enumValueDefinitionList)->emplace_back((yystack_[0].value.enumValueDefinition)); }
#line 2492 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 173:
#line 664 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.enumValueDefinitionList)->emplace_back((yystack_[0].value.enumValueDefinition)); (yylhs.value.enumValueDefinitionList) = (yystack_[1].value.enumValueDefinitionList); }
#line 2498 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 174:
#line 667 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inputObjectTypeDefinition) = new InputObjectTypeDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[3].value.directiveList), (yystack_[1].value.inputValueDefinitionList)); }
#line 2504 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 175:
#line 670 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.typeExtensionDefinition) = new TypeExtensionDefinition(yylhs.location, (yystack_[0].value.objectTypeDefinition)); }
#line 2510 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 176:
#line 673 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveDefinition) = new DirectiveDefinition(yylhs.location, (yystack_[3].value.name), (yystack_[2].value.inputValueDefinitionList), (yystack_[0].value.nameList)); }
#line 2516 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 177:
#line 677 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nameList) = new std::vector<std::unique_ptr<Name>>(); (yylhs.value.nameList)->emplace_back((yystack_[0].value.name)); }
#line 2522 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 178:
#line 678 "parser.ypp" // lalr1.cc:859
    { (yystack_[2].value.nameList)->emplace_back((yystack_[0].value.name)); (yylhs.value.nameList) = (yystack_[2].value.nameList); }
#line 2528 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 2532 "parser.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  GraphQLParserImpl::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  GraphQLParserImpl::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int GraphQLParserImpl::yypact_ninf_ = -228;

  const signed char GraphQLParserImpl::yytable_ninf_ = -1;

  const short int
  GraphQLParserImpl::yypact_[] =
  {
     198,   -11,   895,     6,   918,   895,   895,  -228,  -228,   895,
      13,  -228,   895,   895,   440,    50,  -228,   198,  -228,  -228,
    -228,   895,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,   895,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,    13,  -228,    58,    13,    13,    13,
     895,  -228,    44,    13,  -228,    79,    13,   475,    74,   405,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,    76,    54,    52,
     895,    65,    67,  -228,    94,   100,  -228,   895,    13,    84,
     895,    13,    89,   895,   895,  -228,    13,  -228,  -228,    87,
      88,  -228,    89,   895,   109,  -228,   895,  -228,    13,  -228,
     895,   895,  -228,    99,    68,  -228,  -228,   895,    95,   895,
      13,  -228,  -228,   101,   510,  -228,    94,    89,  -228,    -9,
     103,  -228,  -228,    89,  -228,   104,   545,  -228,   895,    13,
    -228,   580,    89,   615,    54,  -228,   650,   895,  -228,  -228,
    -228,   895,  -228,   102,    89,   265,  -228,  -228,    13,  -228,
    -228,  -228,  -228,   685,  -228,   685,  -228,  -228,  -228,   106,
    -228,  -228,  -228,  -228,  -228,   105,  -228,  -228,  -228,   720,
     895,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
     150,   755,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,    89,   685,   112,   110,
     111,  -228,   112,   895,   685,  -228,  -228,  -228,  -228,   228,
    -228,   115,   790,  -228,  -228,   113,   370,  -228,  -228,  -228,
    -228,    13,  -228,    13,  -228,  -228,   265,  -228,  -228,  -228,
     300,   825,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,   335,  -228,   118,   860,
    -228,  -228,  -228,   370,  -228,  -228,  -228
  };

  const unsigned char
  GraphQLParserImpl::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,    46,    45,     0,
     135,    47,     0,     0,     0,     0,     2,    25,    26,    30,
      28,    23,    40,    29,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    22,    15,    16,    17,    18,
      19,    20,     8,    21,   135,   175,     0,   135,   135,   135,
       0,   136,     0,   134,   137,   153,   135,   135,    67,     0,
      59,    61,    62,    63,     1,    27,    24,     0,   160,     0,
       0,     0,     0,   151,    67,     0,   138,     0,   135,     0,
       0,   135,     0,     0,     0,    68,   135,    56,    60,     0,
       0,    41,     0,     0,     0,   161,     0,   143,   135,    76,
       0,     0,   139,     0,     0,   148,   155,   154,     0,     0,
     135,    72,    74,     0,     0,    69,    67,    57,    51,     0,
       0,    49,    42,     0,    43,     0,     0,   163,     0,   135,
     172,     0,     0,     0,   160,   158,     0,     0,   147,   149,
     156,     0,   168,   167,     0,     0,    66,    70,   135,    58,
      64,    48,    50,     0,    44,     0,   162,   164,   177,   176,
     171,   170,   173,    75,   174,     0,   166,   159,   150,     0,
       0,    73,   100,   101,   102,    98,   103,   105,   106,   107,
     108,    99,   110,   109,   111,   112,   113,    97,   114,   115,
       0,     0,    86,    87,    88,   104,    77,    71,    78,    79,
      80,    81,    82,    83,    84,    85,    57,     0,    53,   140,
     141,   142,    53,     0,     0,   152,   169,   116,   118,     0,
     124,     0,     0,   126,    65,     0,     0,    52,    54,   145,
     146,   135,   178,   135,   117,   119,     0,   125,   127,   144,
       0,     0,    89,    90,    91,    55,    92,    93,    94,    95,
      96,   165,   157,   128,   120,   122,     0,   129,     0,     0,
     131,   121,   123,     0,   130,   132,   133
  };

  const short int
  GraphQLParserImpl::yypgoto_[] =
  {
    -228,  -228,     1,    -2,  -228,  -228,  -228,   128,  -228,  -228,
     -52,  -228,  -228,   -84,    17,   -87,  -228,   -64,   -69,  -228,
      81,  -228,  -228,   -82,  -228,    24,  -228,  -228,  -228,    61,
    -194,  -227,  -218,  -193,  -224,  -189,  -180,  -161,  -228,  -228,
    -228,  -228,  -228,  -228,   -61,  -228,  -228,   -97,   -12,   -37,
    -228,   119,  -164,   -53,  -228,  -228,  -228,  -228,    59,  -228,
     171,  -228,  -228,  -138,    25,    31,  -228,    71,   -29,  -228,
    -228,  -228,  -228,    47,  -228,  -228,  -228,  -228,  -228
  };

  const short int
  GraphQLParserImpl::yydefgoto_[] =
  {
      -1,    15,    53,   107,    77,    16,    17,    18,    19,    20,
      21,   100,   129,   206,   131,   237,   238,    22,   160,    69,
      70,    71,    95,    96,   124,   125,    72,    73,    23,   108,
     207,   208,   209,   210,   255,   211,   212,   213,   214,   229,
     259,   266,   215,   232,   233,   260,   269,   270,    61,    62,
      63,    64,   218,   219,   220,   221,    24,   114,   115,    25,
      26,    88,   117,   145,   146,   104,   105,   136,   137,    27,
      28,   153,    29,   140,   141,    30,    31,    32,   169
  };

  const unsigned short int
  GraphQLParserImpl::yytable_[] =
  {
      54,   222,   112,    57,    58,    56,   228,    59,   177,   252,
      65,    66,    68,   101,   161,   130,    33,    79,   253,    76,
      81,    82,    83,   252,   128,    12,   265,   109,   122,    89,
      92,    78,   253,   113,   116,   245,   132,   109,   134,   252,
      60,   177,   272,   254,   158,   130,   252,   256,   253,   276,
      74,   118,   263,   235,   121,   253,   257,   254,    84,   127,
     243,   256,   113,   159,   150,   102,   152,    68,    91,   164,
     257,   142,    80,   254,    85,   258,   103,   256,   173,     7,
     254,     8,   106,   154,   256,    11,   257,    87,   133,   258,
     181,   123,   126,   257,   178,   110,    93,   111,    99,    94,
     148,   135,   170,    60,   139,   258,    14,   167,   135,   144,
     119,     7,   258,     8,   167,    60,    93,    11,    14,    14,
     128,   216,   123,   138,   147,   151,   155,   226,   163,   165,
     224,   239,   240,   180,   135,   241,   168,   223,   236,   139,
     246,   135,   249,   273,   144,    75,   162,   234,   157,   144,
      98,   120,   159,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   248,   275,   149,    55,   175,   179,   144,   200,   227,
     201,   143,    86,   128,   202,   203,   204,   205,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
       0,     1,     2,     3,   261,     4,   262,     5,     6,     7,
       0,     8,     0,     9,    10,    11,     0,    12,    13,     0,
       0,   242,     0,     0,     0,     0,     0,     0,    14,     0,
     231,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   268,
       0,     0,     0,     0,     0,     0,   200,   244,   201,     0,
       0,   128,   202,   203,   204,   205,     0,   268,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,     0,     0,     0,
       0,     0,     0,   200,     0,   201,     0,     0,   128,   202,
     203,   204,   205,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,   250,   264,
     251,     0,     0,     0,   202,   203,   204,   205,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,     0,     0,     0,
       0,     0,     0,   250,   271,   251,     0,     0,     0,   202,
     203,   204,   205,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,   250,     0,
     251,     0,     0,     0,   202,   203,   204,   205,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,    67,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    90,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,   217,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,     0,     0,
       0,     0,    52,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,     0,     0,     0,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    52,    46,    47,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52
  };

  const short int
  GraphQLParserImpl::yycheck_[] =
  {
       2,   165,    84,     5,     6,     4,   200,     9,   146,   236,
      12,    13,    14,    77,    23,    99,    27,    54,   236,    21,
      57,    58,    59,   250,    33,    19,   250,    80,    92,    66,
      67,    33,   250,    85,    87,   229,   100,    90,   102,   266,
      27,   179,   266,   236,   126,   129,   273,   236,   266,   273,
       0,    88,   246,   217,    91,   273,   236,   250,    60,    96,
     224,   250,   114,   127,   117,    77,   119,    69,    67,   133,
     250,   108,    14,   266,    30,   236,    22,   266,   142,    11,
     273,    13,    30,   120,   273,    17,   266,     8,   100,   250,
     154,    93,    94,   273,   147,    30,    22,    30,    22,    25,
      32,   103,   139,    27,   106,   266,    30,   136,   110,   111,
      26,    11,   273,    13,   143,    27,    22,    17,    30,    30,
      33,   158,   124,    14,    25,    30,    25,   180,    25,    25,
      25,    21,    21,    31,   136,   222,   138,    31,    26,   141,
      25,   143,    29,    25,   146,    17,   129,   216,   124,   151,
      69,    90,   216,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   232,   269,   114,     3,   144,   151,   179,    28,    29,
      30,   110,    63,    33,    34,    35,    36,    37,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,     3,     4,     5,   241,     7,   243,     9,    10,    11,
      -1,    13,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
     232,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    33,    34,    35,    36,    37,    -1,   269,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    -1,    34,    35,    36,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    36,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37
  };

  const unsigned char
  GraphQLParserImpl::yystos_[] =
  {
       0,     3,     4,     5,     7,     9,    10,    11,    13,    15,
      16,    17,    19,    20,    30,    39,    43,    44,    45,    46,
      47,    48,    55,    66,    94,    97,    98,   107,   108,   110,
     113,   114,   115,    27,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    37,    40,    41,    98,    40,    41,    41,    41,
      27,    86,    87,    88,    89,    41,    41,    24,    41,    57,
      58,    59,    64,    65,     0,    45,    41,    42,    41,    87,
      14,    87,    87,    87,    41,    30,    89,     8,    99,    87,
      14,    40,    87,    22,    25,    60,    61,    32,    58,    22,
      49,    55,    86,    22,   103,   104,    30,    41,    67,    91,
      30,    30,    61,    48,    95,    96,    91,   100,    87,    26,
      67,    87,    55,    41,    62,    63,    41,    87,    33,    50,
      51,    52,    55,    86,    55,    41,   105,   106,    14,    41,
     111,   112,    87,   105,    41,   101,   102,    25,    32,    96,
      91,    30,    91,   109,    87,    25,    23,    63,    61,    55,
      56,    23,    52,    25,    55,    25,    23,   106,    41,   116,
      87,    32,   111,    55,    32,   103,    32,   101,    91,   102,
      31,    55,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      28,    30,    34,    35,    36,    37,    51,    68,    69,    70,
      71,    73,    74,    75,    76,    80,    87,    28,    90,    91,
      92,    93,    90,    31,    25,    32,    91,    29,    68,    77,
      32,    41,    81,    82,    56,    90,    26,    53,    54,    21,
      21,    53,    41,    90,    29,    68,    25,    32,    82,    29,
      28,    30,    69,    70,    71,    72,    73,    74,    75,    78,
      83,    87,    87,    68,    29,    72,    79,    32,    41,    84,
      85,    29,    72,    25,    32,    85,    72
  };

  const unsigned char
  GraphQLParserImpl::yyr1_[] =
  {
       0,    38,    39,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    48,    49,    50,
      50,    51,    52,    53,    53,    54,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    59,    60,    61,    61,    62,
      62,    63,    64,    65,    65,    66,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    83,
      83,    84,    84,    85,    86,    87,    87,    88,    88,    89,
      90,    90,    90,    91,    92,    93,    93,    94,    95,    95,
      96,    97,    98,    99,    99,   100,   100,   101,   102,   102,
     103,   103,   104,   105,   105,   106,   107,   108,   109,   109,
     110,   111,   112,   112,   113,   114,   115,   116,   116
  };

  const unsigned char
  GraphQLParserImpl::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     5,     1,     1,     1,     3,     1,
       2,     1,     4,     0,     1,     2,     3,     0,     1,     1,
       2,     1,     1,     1,     4,     6,     3,     0,     1,     1,
       2,     3,     3,     5,     3,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       2,     3,     1,     2,     2,     3,     1,     2,     3,     2,
       3,     1,     2,     3,     1,     0,     1,     1,     2,     3,
       1,     1,     1,     1,     3,     2,     2,     5,     1,     2,
       3,     3,     7,     0,     2,     1,     2,     5,     1,     2,
       0,     1,     3,     1,     2,     5,     6,     5,     1,     3,
       6,     2,     1,     2,     6,     2,     6,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const GraphQLParserImpl::yytname_[] =
  {
  "EOF", "error", "$undefined", "\"directive\"", "\"enum\"", "\"extend\"",
  "\"false\"", "\"fragment\"", "\"implements\"", "\"input\"",
  "\"interface\"", "\"mutation\"", "\"null\"", "\"query\"", "\"on\"",
  "\"scalar\"", "\"schema\"", "\"subscription\"", "\"true\"", "\"type\"",
  "\"union\"", "\"!\"", "\"(\"", "\")\"", "\"...\"", "\":\"", "\"=\"",
  "\"@\"", "\"[\"", "\"]\"", "\"{\"", "\"|\"", "\"}\"", "VARIABLE",
  "INTEGER", "FLOAT", "STRING", "IDENTIFIER", "$accept", "start",
  "fragment_name", "name", "name_opt", "document", "definition_list",
  "definition", "schema_gate", "operation_definition", "operation_type",
  "variable_definitions", "variable_definition_list", "variable",
  "variable_definition", "default_value_opt", "default_value",
  "selection_set", "selection_set_opt", "selection_list", "selection",
  "field", "arguments", "arguments_opt", "argument_list", "argument",
  "fragment_spread", "inline_fragment", "fragment_definition",
  "type_condition", "value", "int_value", "float_value", "string_value",
  "value_const", "boolean_value", "null_value", "enum_value", "list_value",
  "value_list", "list_value_const", "value_const_list", "object_value",
  "object_field_list", "object_field", "object_value_const",
  "object_field_const_list", "object_field_const", "directives",
  "directives_opt", "directive_list", "directive", "type", "type_name",
  "list_type", "non_null_type", "schema_definition",
  "operation_type_definition_list", "operation_type_definition",
  "scalar_type_definition", "object_type_definition",
  "implements_interfaces_opt", "type_name_list", "field_definition",
  "field_definition_list", "arguments_definition_opt",
  "arguments_definition", "input_value_definition_list",
  "input_value_definition", "interface_type_definition",
  "union_type_definition", "union_members", "enum_type_definition",
  "enum_value_definition", "enum_value_definition_list",
  "input_object_type_definition", "type_extension_definition",
  "directive_definition", "directive_locations", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  GraphQLParserImpl::yyrline_[] =
  {
       0,   300,   300,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   325,   326,   330,   331,   336,   339,   340,   343,   344,
     345,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     371,   372,   373,   374,   375,   378,   379,   380,   384,   388,
     389,   392,   396,   400,   401,   404,   408,   412,   413,   415,
     416,   419,   420,   421,   424,   425,   428,   431,   432,   435,
     436,   439,   444,   448,   449,   453,   456,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   471,   474,   477,   480,
     481,   482,   483,   484,   485,   486,   487,   490,   491,   494,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   519,   520,   523,   524,
     528,   529,   533,   534,   539,   540,   544,   545,   548,   552,
     553,   557,   558,   561,   566,   569,   570,   573,   574,   577,
     582,   583,   584,   587,   590,   593,   594,   599,   603,   604,
     608,   611,   614,   617,   618,   621,   622,   625,   629,   630,
     633,   634,   637,   640,   641,   644,   646,   649,   652,   653,
     656,   659,   663,   664,   667,   670,   673,   677,   678
  };

  // Print the state stack on the debug stream.
  void
  GraphQLParserImpl::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  GraphQLParserImpl::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  GraphQLParserImpl::token_number_type
  GraphQLParserImpl::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
    };
    const unsigned int user_token_number_max_ = 292;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 3310 "parser.tab.cpp" // lalr1.cc:1167
#line 681 "parser.ypp" // lalr1.cc:1168


void yy::GraphQLParserImpl::error(const yy::location &loc, const std::string &str) {
  std::ostringstream out;
  out << loc << ": " << str;
  if (outError) {
    *outError = strdup(out.str().c_str());
  }
}

/* Workaround for syntax_error ctor being marked inline, which causes link
   errors if used from lexer.lpp. */
yy::GraphQLParserImpl::syntax_error make_error(const yy::location &loc, const std::string &str) {
  return yy::GraphQLParserImpl::syntax_error(loc, str);
}
