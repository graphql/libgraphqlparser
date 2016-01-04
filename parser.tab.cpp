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
#line 129 "parser.ypp" // lalr1.cc:413

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
  GraphQLParserImpl::GraphQLParserImpl (Node **outAST_yyarg, const char **outError_yyarg, void *scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
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
            case 3: // "false"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 399 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 4: // "fragment"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 406 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 5: // "mutation"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 413 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 6: // "null"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 420 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 7: // "query"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 427 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 8: // "on"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 434 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 9: // "true"

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 441 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 22: // VARIABLE

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 448 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 23: // INTEGER

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 455 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 24: // FLOAT

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 462 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 25: // STRING

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 469 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 26: // IDENTIFIER

#line 224 "parser.ypp" // lalr1.cc:617
        { }
#line 476 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 28: // start

#line 226 "parser.ypp" // lalr1.cc:617
        { }
#line 483 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 29: // fragment_name

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 490 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 30: // name

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 497 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 31: // name_opt

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 504 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 32: // document

#line 226 "parser.ypp" // lalr1.cc:617
        { }
#line 511 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 33: // definition_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definitionList); }
#line 518 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 34: // definition

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definition); }
#line 525 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 35: // operation_definition

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.operationDefinition); }
#line 532 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 36: // operation_type

#line 225 "parser.ypp" // lalr1.cc:617
        { free((void *)(yysym.value.heapStr)); }
#line 539 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 37: // variable_definitions

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinitionList); }
#line 546 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 38: // variable_definition_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinitionList); }
#line 553 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 39: // variable

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variable); }
#line 560 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 40: // variable_definition

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinition); }
#line 567 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 41: // default_value_opt

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 574 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 42: // default_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 581 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 43: // selection_set

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionSet); }
#line 588 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 44: // selection_set_opt

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionSet); }
#line 595 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 45: // selection_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionList); }
#line 602 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 46: // selection

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selection); }
#line 609 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 47: // field

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.field); }
#line 616 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 48: // arguments

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 623 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 49: // arguments_opt

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 630 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 50: // argument_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 637 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 51: // argument

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argument); }
#line 644 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 52: // fragment_spread

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fragmentSpread); }
#line 651 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 53: // inline_fragment

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inlineFragment); }
#line 658 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 54: // fragment_definition

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fragmentDefinition); }
#line 665 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 55: // type_condition

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.namedType); }
#line 672 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 56: // value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 679 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 57: // int_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.intValue); }
#line 686 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 58: // float_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.floatValue); }
#line 693 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 59: // string_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.stringValue); }
#line 700 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 60: // value_const

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 707 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 61: // boolean_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.booleanValue); }
#line 714 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 62: // enum_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.enumValue); }
#line 721 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 63: // array_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.arrayValue); }
#line 728 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 64: // value_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.valueList); }
#line 735 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 65: // array_value_const

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.arrayValue); }
#line 742 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 66: // value_const_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.valueList); }
#line 749 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 67: // object_value

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectValue); }
#line 756 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 68: // object_field_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectFieldList); }
#line 763 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 69: // object_field

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectField); }
#line 770 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 70: // object_value_const

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectValue); }
#line 777 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 71: // object_field_const_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectFieldList); }
#line 784 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 72: // object_field_const

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectField); }
#line 791 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 73: // directives

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 798 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 74: // directives_opt

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 805 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 75: // directive_list

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 812 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 76: // directive

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directive); }
#line 819 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 77: // type

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.type); }
#line 826 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 78: // type_name

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.namedType); }
#line 833 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 79: // list_type

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.listType); }
#line 840 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 80: // non_null_type

#line 227 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.nonNullType); }
#line 847 "parser.tab.cpp" // lalr1.cc:617
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
            case 3: // "false"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 878 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 4: // "fragment"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 885 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 5: // "mutation"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 892 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 6: // "null"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 899 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 7: // "query"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 906 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 8: // "on"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 913 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 9: // "true"

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 920 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 22: // VARIABLE

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 927 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 23: // INTEGER

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 934 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 24: // FLOAT

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 941 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 25: // STRING

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 948 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 26: // IDENTIFIER

#line 229 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 955 "parser.tab.cpp" // lalr1.cc:636
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
#line 233 "parser.ypp" // lalr1.cc:859
    { *outAST = (yystack_[0].value.document); }
#line 1175 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 238 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1181 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 239 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1187 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 240 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1193 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 241 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1199 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 242 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1205 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 243 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1211 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 244 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1217 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 248 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1223 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 252 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.name) = nullptr;}
#line 1229 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 258 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.document) = new Document(yylhs.location, (yystack_[0].value.definitionList)); }
#line 1235 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 261 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definitionList) = new std::vector<std::unique_ptr<Definition>>(); (yylhs.value.definitionList)->emplace_back((yystack_[0].value.definition)); }
#line 1241 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 262 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.definitionList)->emplace_back((yystack_[0].value.definition)); (yylhs.value.definitionList) = (yystack_[1].value.definitionList); }
#line 1247 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 265 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.operationDefinition)); }
#line 1253 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 266 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.fragmentDefinition));}
#line 1259 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 272 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, strdup("query"), nullptr, nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 1265 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 273 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[2].value.heapStr), (yystack_[1].value.name), nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 1271 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 274 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.heapStr), (yystack_[2].value.name), (yystack_[1].value.variableDefinitionList), nullptr, (yystack_[0].value.selectionSet)); }
#line 1277 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 275 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.heapStr), (yystack_[2].value.name), nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1283 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 276 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[4].value.heapStr), (yystack_[3].value.name), (yystack_[2].value.variableDefinitionList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1289 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 279 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1295 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 280 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1301 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 284 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 1307 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 288 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = new std::vector<std::unique_ptr<VariableDefinition>>(); (yylhs.value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); }
#line 1313 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 289 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 1319 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 292 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variable) = new Variable(yylhs.location, new Name(yystack_[0].location, strdup((yystack_[0].value.str)))); }
#line 1325 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 296 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinition) = new VariableDefinition(yylhs.location, (yystack_[3].value.variable), (yystack_[1].value.type), (yystack_[0].value.value)); }
#line 1331 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 300 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = nullptr; }
#line 1337 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 304 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = (yystack_[0].value.value); }
#line 1343 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 308 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = new SelectionSet(yylhs.location, (yystack_[1].value.selectionList)); }
#line 1349 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 312 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = nullptr; }
#line 1355 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 315 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionList) = new std::vector<std::unique_ptr<Selection>>(); (yylhs.value.selectionList)->emplace_back((yystack_[0].value.selection)); }
#line 1361 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 316 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.selectionList)->emplace_back((yystack_[0].value.selection)); (yylhs.value.selectionList) = (yystack_[1].value.selectionList); }
#line 1367 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 319 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.field)); }
#line 1373 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 320 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.fragmentSpread)); }
#line 1379 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 321 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.inlineFragment)); }
#line 1385 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 324 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, nullptr, (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1391 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 325 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, (yystack_[5].value.name), (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1397 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 328 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 1403 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 331 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = nullptr; }
#line 1409 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 332 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[0].value.argumentList); }
#line 1415 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 335 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = new std::vector<std::unique_ptr<Argument>>(); (yylhs.value.argumentList)->emplace_back((yystack_[0].value.argument)); }
#line 1421 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 336 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.argumentList)->emplace_back((yystack_[0].value.argument)); (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 1427 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 339 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argument) = new Argument(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1433 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 344 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentSpread) = new FragmentSpread(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.directiveList)); }
#line 1439 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 348 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1445 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 349 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1451 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 353 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentDefinition) = new FragmentDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1457 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 360 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.variable)); }
#line 1463 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 361 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1469 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 362 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1475 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 363 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1481 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 364 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1487 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 365 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1493 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 366 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1499 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 367 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1505 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 370 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.intValue) = new IntValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1511 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 373 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.floatValue) = new FloatValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1517 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 376 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.stringValue) = new StringValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1523 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 379 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1529 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 380 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1535 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 381 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1541 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 382 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1547 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 383 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1553 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 384 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1559 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 385 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1565 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 388 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, true); }
#line 1571 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 389 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, false); }
#line 1577 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 392 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1583 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 393 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1589 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 394 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1595 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 395 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1601 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 396 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1607 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 403 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 1613 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 404 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 1619 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 407 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 1625 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 408 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 1631 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 412 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 1637 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 413 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 1643 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 417 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 1649 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 418 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 1655 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 423 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 1661 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 424 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 1667 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 428 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 1673 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 429 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 1679 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 432 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1685 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 436 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 1691 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 437 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 1697 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 441 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 1703 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 442 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 1709 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 445 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1715 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 453 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = nullptr; }
#line 1721 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 457 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = new std::vector<std::unique_ptr<Directive>>(); (yylhs.value.directiveList)->emplace_back((yystack_[0].value.directive)); }
#line 1727 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 458 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.directiveList)->emplace_back((yystack_[0].value.directive)); (yylhs.value.directiveList) = (yystack_[1].value.directiveList); }
#line 1733 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 461 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directive) = new Directive(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.argumentList)); }
#line 1739 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 466 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.namedType)); }
#line 1745 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 467 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.listType)); }
#line 1751 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 468 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.nonNullType)); }
#line 1757 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 471 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.namedType) = new NamedType(yylhs.location, (yystack_[0].value.name)); }
#line 1763 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 474 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.listType) = new ListType(yylhs.location, (yystack_[1].value.type)); }
#line 1769 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 477 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.namedType)); }
#line 1775 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 478 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.listType)); }
#line 1781 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 1785 "parser.tab.cpp" // lalr1.cc:859
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


  const signed char GraphQLParserImpl::yypact_ninf_ = -124;

  const signed char GraphQLParserImpl::yytable_ninf_ = -1;

  const short int
  GraphQLParserImpl::yypact_[] =
  {
      46,   355,  -124,  -124,   233,    13,  -124,    46,  -124,  -124,
     348,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      10,  -124,   244,  -124,    53,   209,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,    47,   348,   348,   348,    30,  -124,     8,
      30,  -124,   348,   348,  -124,    30,  -124,  -124,    33,    55,
    -124,     8,  -124,    30,  -124,    30,    48,  -124,  -124,  -124,
      56,   259,  -124,    48,     8,  -124,    40,    58,  -124,  -124,
       8,  -124,     8,     8,  -124,   130,  -124,  -124,    30,  -124,
    -124,  -124,  -124,   269,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,    78,   284,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     8,   269,
      60,    67,    68,  -124,  -124,  -124,   102,  -124,    70,   293,
    -124,  -124,    71,   202,  -124,  -124,  -124,  -124,  -124,  -124,
     130,  -124,  -124,  -124,   154,   317,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,   178,  -124,    74,
     324,  -124,  -124,  -124,   202,  -124,  -124,  -124
  };

  const unsigned char
  GraphQLParserImpl::yydefact_[] =
  {
       0,     0,    25,    24,     0,     0,     2,    14,    15,    17,
      12,    19,    18,     4,     5,     6,     7,     8,     9,     3,
       0,    11,    99,    10,    45,     0,    37,    39,    40,    41,
       1,    16,    13,     0,     0,     0,     0,    99,   100,     0,
      98,   101,     0,     0,    46,    99,    34,    38,     0,     0,
      20,     0,   107,    99,    54,    99,    45,    50,    52,   102,
       0,     0,    47,    45,    35,    29,     0,     0,    27,    21,
       0,    22,     0,     0,   103,     0,    44,    48,    99,    36,
      42,    26,    28,     0,    23,    53,    51,    74,    76,    77,
      79,    78,    73,     0,     0,    63,    64,    65,    75,    55,
      49,    56,    57,    58,    59,    60,    61,    62,    35,     0,
      31,   104,   105,   106,    80,    82,     0,    88,     0,     0,
      90,    43,     0,     0,    30,    32,   109,   110,    81,    83,
       0,    89,    91,   108,     0,     0,    66,    67,    68,    33,
      69,    70,    71,    72,    92,    84,    86,     0,    93,     0,
       0,    95,    85,    87,     0,    94,    96,    97
  };

  const signed char
  GraphQLParserImpl::yypgoto_[] =
  {
    -124,  -124,    11,    -4,  -124,  -124,  -124,    84,  -124,  -124,
    -124,  -124,   -41,    26,  -124,  -124,   -29,   -15,  -124,    69,
    -124,  -124,   -48,  -124,    37,  -124,  -124,  -124,    64,   -90,
    -118,  -100,   -86,  -123,   -78,   -74,  -124,  -124,  -124,  -124,
    -124,  -124,   -11,  -124,  -124,   -38,   -19,   -36,  -124,    73,
       5,   -81,  -124,  -124
  };

  const short int
  GraphQLParserImpl::yydefgoto_[] =
  {
      -1,     5,    23,    52,    33,     6,     7,     8,     9,    10,
      49,    66,    99,    68,   124,   125,    11,    80,    25,    26,
      27,    44,    45,    61,    62,    28,    29,    12,    53,   100,
     101,   102,   103,   139,   104,   105,   106,   116,   142,   147,
     107,   119,   120,   143,   150,   151,    38,    39,    40,    41,
     110,    54,   112,   113
  };

  const unsigned char
  GraphQLParserImpl::yytable_[] =
  {
      24,    57,   111,   115,    50,   136,    32,    67,    74,    64,
      58,   146,    20,    30,    51,    78,   136,    72,    34,    73,
      69,    24,    71,   137,   153,    67,   129,     4,   111,   136,
      70,   157,    56,    37,   137,    79,   136,   138,    60,    63,
     144,    84,   108,    85,    86,   140,    36,   137,   138,   141,
       1,     2,    81,     3,   137,    65,   140,    60,    48,    42,
     141,   138,    65,    36,    42,     4,     4,    43,   138,   140,
      75,    36,    83,   141,     4,   123,   140,   126,   127,    79,
     141,    87,    88,    89,   130,    90,    91,    92,   154,   133,
     118,    31,    82,   121,    47,    93,   114,    94,    77,    55,
      65,    95,    96,    97,    98,    87,    88,    89,   132,    90,
      91,    92,   156,    59,   122,   118,     0,     0,     0,    93,
     128,    94,     0,     0,    65,    95,    96,    97,    98,     0,
       0,   149,     0,    87,    88,    89,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,   149,    93,     0,    94,
       0,     0,    65,    95,    96,    97,    98,    87,    88,    89,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,   134,   145,   135,     0,     0,     0,    95,    96,    97,
      98,    87,    88,    89,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,   134,   152,   135,     0,     0,
       0,    95,    96,    97,    98,    87,    88,    89,     0,    90,
      91,    92,    13,    14,    15,    16,    17,    21,    18,   134,
       0,   135,    22,     0,     0,    95,    96,    97,    98,     0,
      46,     0,     0,     0,     0,    19,    13,    14,    15,    16,
      17,    21,    18,     0,     0,     0,    22,    13,    14,    15,
      16,    17,    35,    18,     0,     0,     0,     0,     0,    19,
      36,     0,    13,    14,    15,    16,    17,    21,    18,     0,
      19,    76,    13,    14,    15,    16,    17,    21,    18,     0,
       0,     0,     0,     0,     0,    19,   109,    13,    14,    15,
      16,    17,    21,    18,     0,    19,    13,    14,    15,    16,
      17,    21,    18,     0,     0,   117,     0,     0,     0,     0,
      19,     0,     0,     0,   131,     0,     0,     0,     0,    19,
      13,    14,    15,    16,    17,    21,    18,    13,    14,    15,
      16,    17,    21,    18,     0,     0,     0,     0,   148,     0,
       0,     0,     0,    19,     0,   155,     0,     0,     0,     0,
      19,    13,    14,    15,    16,    17,    21,    18,    13,    14,
      15,    16,    17,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    19
  };

  const short int
  GraphQLParserImpl::yycheck_[] =
  {
       4,    37,    83,    93,    33,   123,    10,    48,    56,    45,
      39,   134,     1,     0,    33,    63,   134,    53,     8,    55,
      49,    25,    51,   123,   147,    66,   116,    19,   109,   147,
      49,   154,    36,    22,   134,    64,   154,   123,    42,    43,
     130,    70,    78,    72,    73,   123,    16,   147,   134,   123,
       4,     5,    12,     7,   154,    22,   134,    61,    11,    11,
     134,   147,    22,    16,    11,    19,    19,    14,   154,   147,
      14,    16,    14,   147,    19,    15,   154,    10,    10,   108,
     154,     3,     4,     5,    14,     7,     8,     9,    14,    18,
      94,     7,    66,   108,    25,    17,    18,    19,    61,    35,
      22,    23,    24,    25,    26,     3,     4,     5,   119,     7,
       8,     9,   150,    40,   109,   119,    -1,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    -1,
      -1,   135,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    17,    -1,    19,
      -1,    -1,    22,    23,    24,    25,    26,     3,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    -1,    -1,    23,    24,    25,
      26,     3,     4,     5,    -1,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,
      -1,    23,    24,    25,    26,     3,     4,     5,    -1,     7,
       8,     9,     3,     4,     5,     6,     7,     8,     9,    17,
      -1,    19,    13,    -1,    -1,    23,    24,    25,    26,    -1,
      21,    -1,    -1,    -1,    -1,    26,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    26,
      16,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      26,    12,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    17,     3,     4,     5,
       6,     7,     8,     9,    -1,    26,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,
       3,     4,     5,     6,     7,     8,     9,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    -1,    21,    -1,    -1,    -1,    -1,
      26,     3,     4,     5,     6,     7,     8,     9,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    26
  };

  const unsigned char
  GraphQLParserImpl::yystos_[] =
  {
       0,     4,     5,     7,    19,    28,    32,    33,    34,    35,
      36,    43,    54,     3,     4,     5,     6,     7,     9,    26,
      29,     8,    13,    29,    30,    45,    46,    47,    52,    53,
       0,    34,    30,    31,     8,     8,    16,    29,    73,    74,
      75,    76,    11,    14,    48,    49,    21,    46,    11,    37,
      43,    73,    30,    55,    78,    55,    30,    74,    43,    76,
      30,    50,    51,    30,    74,    22,    38,    39,    40,    43,
      73,    43,    74,    74,    49,    14,    12,    51,    49,    43,
      44,    12,    40,    14,    43,    43,    43,     3,     4,     5,
       7,     8,     9,    17,    19,    23,    24,    25,    26,    39,
      56,    57,    58,    59,    61,    62,    63,    67,    74,    17,
      77,    78,    79,    80,    18,    56,    64,    21,    30,    68,
      69,    44,    77,    15,    41,    42,    10,    10,    18,    56,
      14,    21,    69,    18,    17,    19,    57,    58,    59,    60,
      61,    62,    65,    70,    56,    18,    60,    66,    21,    30,
      71,    72,    18,    60,    14,    21,    72,    60
  };

  const unsigned char
  GraphQLParserImpl::yyr1_[] =
  {
       0,    27,    28,    29,    29,    29,    29,    29,    29,    29,
      30,    30,    31,    31,    32,    33,    33,    34,    34,    35,
      35,    35,    35,    35,    36,    36,    37,    38,    38,    39,
      40,    41,    41,    42,    43,    44,    44,    45,    45,    46,
      46,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      52,    53,    53,    54,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    58,    59,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    73,    74,
      74,    75,    75,    76,    77,    77,    77,    78,    79,    80,
      80
  };

  const unsigned char
  GraphQLParserImpl::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     2,     1,     1,     1,
       3,     4,     4,     5,     1,     1,     3,     1,     2,     1,
       4,     0,     1,     2,     3,     0,     1,     1,     2,     1,
       1,     1,     4,     6,     3,     0,     1,     1,     2,     3,
       3,     5,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     2,     2,     3,     1,     2,     2,     3,
       1,     2,     3,     2,     3,     1,     2,     3,     1,     0,
       1,     1,     2,     3,     1,     1,     1,     1,     3,     2,
       2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const GraphQLParserImpl::yytname_[] =
  {
  "EOF", "error", "$undefined", "\"false\"", "\"fragment\"",
  "\"mutation\"", "\"null\"", "\"query\"", "\"on\"", "\"true\"", "\"!\"",
  "\"(\"", "\")\"", "\"...\"", "\":\"", "\"=\"", "\"@\"", "\"[\"", "\"]\"",
  "\"{\"", "\"|\"", "\"}\"", "VARIABLE", "INTEGER", "FLOAT", "STRING",
  "IDENTIFIER", "$accept", "start", "fragment_name", "name", "name_opt",
  "document", "definition_list", "definition", "operation_definition",
  "operation_type", "variable_definitions", "variable_definition_list",
  "variable", "variable_definition", "default_value_opt", "default_value",
  "selection_set", "selection_set_opt", "selection_list", "selection",
  "field", "arguments", "arguments_opt", "argument_list", "argument",
  "fragment_spread", "inline_fragment", "fragment_definition",
  "type_condition", "value", "int_value", "float_value", "string_value",
  "value_const", "boolean_value", "enum_value", "array_value",
  "value_list", "array_value_const", "value_const_list", "object_value",
  "object_field_list", "object_field", "object_value_const",
  "object_field_const_list", "object_field_const", "directives",
  "directives_opt", "directive_list", "directive", "type", "type_name",
  "list_type", "non_null_type", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  GraphQLParserImpl::yyrline_[] =
  {
       0,   233,   233,   238,   239,   240,   241,   242,   243,   244,
     247,   248,   252,   253,   258,   261,   262,   265,   266,   272,
     273,   274,   275,   276,   279,   280,   284,   288,   289,   292,
     296,   300,   301,   304,   308,   312,   313,   315,   316,   319,
     320,   321,   324,   325,   328,   331,   332,   335,   336,   339,
     344,   348,   349,   353,   356,   360,   361,   362,   363,   364,
     365,   366,   367,   370,   373,   376,   379,   380,   381,   382,
     383,   384,   385,   388,   389,   392,   393,   394,   395,   396,
     403,   404,   407,   408,   412,   413,   417,   418,   423,   424,
     428,   429,   432,   436,   437,   441,   442,   445,   450,   453,
     454,   457,   458,   461,   466,   467,   468,   471,   474,   477,
     478
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
      25,    26
    };
    const unsigned int user_token_number_max_ = 281;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2377 "parser.tab.cpp" // lalr1.cc:1167
#line 480 "parser.ypp" // lalr1.cc:1168

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
