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
#line 113 "parser.ypp" // lalr1.cc:413

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

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 399 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 4: // "fragment"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 406 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 5: // "mutation"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 413 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 6: // "null"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 420 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 7: // "query"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 427 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 8: // "on"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 434 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 9: // "subscription"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 441 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 10: // "true"

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 448 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 23: // VARIABLE

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 455 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 24: // INTEGER

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 462 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 25: // FLOAT

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 469 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 26: // STRING

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 476 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 27: // IDENTIFIER

#line 210 "parser.ypp" // lalr1.cc:617
        { }
#line 483 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 29: // start

#line 212 "parser.ypp" // lalr1.cc:617
        { }
#line 490 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 30: // fragment_name

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 497 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 31: // name

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 504 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 32: // name_opt

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.name); }
#line 511 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 33: // document

#line 212 "parser.ypp" // lalr1.cc:617
        { }
#line 518 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 34: // definition_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definitionList); }
#line 525 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 35: // definition

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.definition); }
#line 532 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 36: // operation_definition

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.operationDefinition); }
#line 539 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 37: // operation_type

#line 211 "parser.ypp" // lalr1.cc:617
        { free((void *)(yysym.value.heapStr)); }
#line 546 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 38: // variable_definitions

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinitionList); }
#line 553 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 39: // variable_definition_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinitionList); }
#line 560 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 40: // variable

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variable); }
#line 567 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 41: // variable_definition

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.variableDefinition); }
#line 574 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 42: // default_value_opt

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 581 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 43: // default_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 588 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 44: // selection_set

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionSet); }
#line 595 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 45: // selection_set_opt

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionSet); }
#line 602 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 46: // selection_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selectionList); }
#line 609 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 47: // selection

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.selection); }
#line 616 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 48: // field

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.field); }
#line 623 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 49: // arguments

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 630 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 50: // arguments_opt

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 637 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 51: // argument_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argumentList); }
#line 644 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 52: // argument

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.argument); }
#line 651 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 53: // fragment_spread

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fragmentSpread); }
#line 658 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 54: // inline_fragment

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.inlineFragment); }
#line 665 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 55: // fragment_definition

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.fragmentDefinition); }
#line 672 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 56: // type_condition

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.namedType); }
#line 679 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 57: // value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 686 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 58: // int_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.intValue); }
#line 693 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 59: // float_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.floatValue); }
#line 700 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 60: // string_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.stringValue); }
#line 707 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 61: // value_const

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.value); }
#line 714 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 62: // boolean_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.booleanValue); }
#line 721 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 63: // null_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.nullValue); }
#line 728 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 64: // enum_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.enumValue); }
#line 735 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 65: // list_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.arrayValue); }
#line 742 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 66: // value_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.valueList); }
#line 749 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 67: // list_value_const

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.arrayValue); }
#line 756 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 68: // value_const_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.valueList); }
#line 763 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 69: // object_value

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectValue); }
#line 770 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 70: // object_field_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectFieldList); }
#line 777 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 71: // object_field

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectField); }
#line 784 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 72: // object_value_const

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectValue); }
#line 791 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 73: // object_field_const_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectFieldList); }
#line 798 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 74: // object_field_const

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.objectField); }
#line 805 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 75: // directives

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 812 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 76: // directives_opt

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 819 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 77: // directive_list

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directiveList); }
#line 826 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 78: // directive

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.directive); }
#line 833 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 79: // type

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.type); }
#line 840 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 80: // type_name

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.namedType); }
#line 847 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 81: // list_type

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.listType); }
#line 854 "parser.tab.cpp" // lalr1.cc:617
        break;

      case 82: // non_null_type

#line 213 "parser.ypp" // lalr1.cc:617
        { delete (yysym.value.nonNullType); }
#line 861 "parser.tab.cpp" // lalr1.cc:617
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

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 892 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 4: // "fragment"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 899 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 5: // "mutation"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 906 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 6: // "null"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 913 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 7: // "query"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 920 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 8: // "on"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 927 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 9: // "subscription"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 934 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 10: // "true"

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 941 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 23: // VARIABLE

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 948 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 24: // INTEGER

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 955 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 25: // FLOAT

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 962 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 26: // STRING

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 969 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 27: // IDENTIFIER

#line 215 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 976 "parser.tab.cpp" // lalr1.cc:636
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
#line 219 "parser.ypp" // lalr1.cc:859
    { *outAST = (yystack_[0].value.document); }
#line 1196 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 224 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1202 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 225 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1208 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 226 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1214 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 227 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1220 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 228 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1226 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 229 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1232 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 230 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1238 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 231 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1244 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 235 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 1250 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 239 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.name) = nullptr;}
#line 1256 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 245 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.document) = new Document(yylhs.location, (yystack_[0].value.definitionList)); }
#line 1262 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 248 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definitionList) = new std::vector<std::unique_ptr<Definition>>(); (yylhs.value.definitionList)->emplace_back((yystack_[0].value.definition)); }
#line 1268 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 249 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.definitionList)->emplace_back((yystack_[0].value.definition)); (yylhs.value.definitionList) = (yystack_[1].value.definitionList); }
#line 1274 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 252 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.operationDefinition)); }
#line 1280 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 253 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.fragmentDefinition));}
#line 1286 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 259 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, strdup("query"), nullptr, nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 1292 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 260 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[2].value.heapStr), (yystack_[1].value.name), nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 1298 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 261 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.heapStr), (yystack_[2].value.name), (yystack_[1].value.variableDefinitionList), nullptr, (yystack_[0].value.selectionSet)); }
#line 1304 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 262 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.heapStr), (yystack_[2].value.name), nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1310 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 263 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[4].value.heapStr), (yystack_[3].value.name), (yystack_[2].value.variableDefinitionList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1316 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 266 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1322 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 267 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1328 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 268 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.heapStr) = strdup((yystack_[0].value.str)); }
#line 1334 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 272 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 1340 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 276 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = new std::vector<std::unique_ptr<VariableDefinition>>(); (yylhs.value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); }
#line 1346 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 277 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 1352 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 280 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variable) = new Variable(yylhs.location, new Name(yystack_[0].location, strdup((yystack_[0].value.str)))); }
#line 1358 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 284 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinition) = new VariableDefinition(yylhs.location, (yystack_[3].value.variable), (yystack_[1].value.type), (yystack_[0].value.value)); }
#line 1364 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 288 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = nullptr; }
#line 1370 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 292 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = (yystack_[0].value.value); }
#line 1376 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 296 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = new SelectionSet(yylhs.location, (yystack_[1].value.selectionList)); }
#line 1382 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 300 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = nullptr; }
#line 1388 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 303 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionList) = new std::vector<std::unique_ptr<Selection>>(); (yylhs.value.selectionList)->emplace_back((yystack_[0].value.selection)); }
#line 1394 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 304 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.selectionList)->emplace_back((yystack_[0].value.selection)); (yylhs.value.selectionList) = (yystack_[1].value.selectionList); }
#line 1400 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 307 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.field)); }
#line 1406 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 308 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.fragmentSpread)); }
#line 1412 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 309 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.inlineFragment)); }
#line 1418 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 312 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, nullptr, (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1424 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 313 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, (yystack_[5].value.name), (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1430 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 316 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 1436 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 319 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = nullptr; }
#line 1442 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 320 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[0].value.argumentList); }
#line 1448 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 323 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = new std::vector<std::unique_ptr<Argument>>(); (yylhs.value.argumentList)->emplace_back((yystack_[0].value.argument)); }
#line 1454 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 324 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.argumentList)->emplace_back((yystack_[0].value.argument)); (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 1460 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 327 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argument) = new Argument(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1466 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 332 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentSpread) = new FragmentSpread(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.directiveList)); }
#line 1472 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 336 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1478 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 337 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1484 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 341 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentDefinition) = new FragmentDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 1490 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 348 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.variable)); }
#line 1496 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 349 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1502 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 350 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1508 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 351 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1514 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 352 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1520 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 353 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.nullValue)); }
#line 1526 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 354 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1532 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 355 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1538 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 356 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1544 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 359 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.intValue) = new IntValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1550 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 362 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.floatValue) = new FloatValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1556 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 365 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.stringValue) = new StringValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1562 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 368 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1568 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 369 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1574 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 370 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1580 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 371 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1586 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 372 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.nullValue)); }
#line 1592 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 373 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1598 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 374 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1604 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 375 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1610 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 378 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, true); }
#line 1616 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 379 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, false); }
#line 1622 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 382 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nullValue) = new NullValue(yylhs.location); }
#line 1628 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 385 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1634 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 386 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1640 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 387 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1646 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 388 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1652 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 389 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1658 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 390 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1664 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 397 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 1670 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 398 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 1676 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 401 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 1682 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 402 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 1688 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 406 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 1694 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 407 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ListValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 1700 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 411 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 1706 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 412 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 1712 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 417 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 1718 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 418 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 1724 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 422 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 1730 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 423 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 1736 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 426 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1742 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 430 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 1748 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 431 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 1754 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 435 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 1760 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 436 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 1766 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 439 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1772 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 447 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = nullptr; }
#line 1778 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 451 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = new std::vector<std::unique_ptr<Directive>>(); (yylhs.value.directiveList)->emplace_back((yystack_[0].value.directive)); }
#line 1784 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 452 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.directiveList)->emplace_back((yystack_[0].value.directive)); (yylhs.value.directiveList) = (yystack_[1].value.directiveList); }
#line 1790 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 455 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directive) = new Directive(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.argumentList)); }
#line 1796 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 460 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.namedType)); }
#line 1802 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 111:
#line 461 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.listType)); }
#line 1808 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 112:
#line 462 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.nonNullType)); }
#line 1814 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 113:
#line 465 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.namedType) = new NamedType(yylhs.location, (yystack_[0].value.name)); }
#line 1820 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 114:
#line 468 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.listType) = new ListType(yylhs.location, (yystack_[1].value.type)); }
#line 1826 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 115:
#line 471 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.namedType)); }
#line 1832 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 116:
#line 472 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.listType)); }
#line 1838 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 1842 "parser.tab.cpp" // lalr1.cc:859
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


  const signed char GraphQLParserImpl::yypact_ninf_ = -105;

  const signed char GraphQLParserImpl::yytable_ninf_ = -1;

  const short int
  GraphQLParserImpl::yypact_[] =
  {
       8,   403,  -105,  -105,  -105,   274,     9,  -105,     8,  -105,
    -105,   395,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,    21,  -105,   286,  -105,    73,   249,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,    56,   395,   395,   395,    17,
    -105,    18,    17,  -105,   395,   395,  -105,    17,  -105,  -105,
      24,    70,  -105,    18,  -105,    17,  -105,    17,    39,  -105,
    -105,  -105,    40,   301,  -105,    39,    18,  -105,    -9,    44,
    -105,  -105,    18,  -105,    18,    18,  -105,   149,  -105,  -105,
      17,  -105,  -105,  -105,  -105,   312,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,    91,   328,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,    18,   312,    48,    49,    55,  -105,  -105,
    -105,   118,  -105,    57,   337,  -105,  -105,    51,   224,  -105,
    -105,  -105,  -105,  -105,  -105,   149,  -105,  -105,  -105,   174,
     362,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,   199,  -105,    65,   370,  -105,  -105,  -105,
     224,  -105,  -105,  -105
  };

  const unsigned char
  GraphQLParserImpl::yydefact_[] =
  {
       0,     0,    26,    25,    27,     0,     0,     2,    15,    16,
      18,    13,    20,    19,     4,     5,     6,     7,     8,     9,
      10,     3,     0,    12,   105,    11,    47,     0,    39,    41,
      42,    43,     1,    17,    14,     0,     0,     0,     0,   105,
     106,     0,   104,   107,     0,     0,    48,   105,    36,    40,
       0,     0,    21,     0,   113,   105,    56,   105,    47,    52,
      54,   108,     0,     0,    49,    47,    37,    31,     0,     0,
      29,    22,     0,    23,     0,     0,   109,     0,    46,    50,
     105,    38,    44,    28,    30,     0,    24,    55,    53,    78,
      81,    82,    79,    84,    83,    85,    77,     0,     0,    66,
      67,    68,    80,    57,    51,    58,    59,    60,    61,    62,
      63,    64,    65,    37,     0,    33,   110,   111,   112,    86,
      88,     0,    94,     0,     0,    96,    45,     0,     0,    32,
      34,   115,   116,    87,    89,     0,    95,    97,   114,     0,
       0,    69,    70,    71,    35,    72,    73,    74,    75,    76,
      98,    90,    92,     0,    99,     0,     0,   101,    91,    93,
       0,   100,   102,   103
  };

  const signed char
  GraphQLParserImpl::yypgoto_[] =
  {
    -105,  -105,     7,    -5,  -105,  -105,  -105,    81,  -105,  -105,
    -105,  -105,   -43,    13,  -105,  -105,   -30,   -22,  -105,    75,
    -105,  -105,   -39,  -105,    29,  -105,  -105,  -105,    66,   -94,
    -104,   -91,   -82,   -86,   -78,   -76,   -74,  -105,  -105,  -105,
    -105,  -105,  -105,   -20,  -105,  -105,   -51,   -19,   -37,  -105,
      64,    -7,   -84,  -105,  -105
  };

  const short int
  GraphQLParserImpl::yydefgoto_[] =
  {
      -1,     6,    25,    54,    35,     7,     8,     9,    10,    11,
      51,    68,   103,    70,   129,   130,    12,    82,    27,    28,
      29,    46,    47,    63,    64,    30,    31,    13,    55,   104,
     105,   106,   107,   144,   108,   109,   110,   111,   121,   148,
     153,   112,   124,   125,   149,   156,   157,    40,    41,    42,
      43,   115,    56,   117,   118
  };

  const unsigned char
  GraphQLParserImpl::yytable_[] =
  {
      26,   116,    59,   120,    83,    52,    34,    69,    22,    32,
      66,    60,     1,     2,    67,     3,    53,     4,    74,    76,
      75,    71,    26,    73,   141,    69,    80,   134,     5,    36,
     116,    39,    72,    58,    38,   141,    81,   142,     5,    62,
      65,   150,    86,   113,    87,    88,   143,    67,   142,   141,
     145,    44,   146,   152,   147,    77,   141,   143,    62,    85,
     131,   145,   142,   146,   128,   147,   132,   159,    50,   142,
     138,   143,   135,    38,   163,   145,     5,   146,   143,   147,
     160,    84,   145,    81,   146,    44,   147,    38,    45,    33,
       5,   126,    79,   123,    89,    90,    91,    92,    93,    94,
      95,    96,    49,    57,   137,   162,    61,   127,     0,    97,
     119,    98,     0,     0,    67,    99,   100,   101,   102,   123,
       0,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,   155,    97,   133,    98,     0,
       0,    67,    99,   100,   101,   102,     0,     0,     0,     0,
       0,   155,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,    97,     0,    98,
       0,     0,    67,    99,   100,   101,   102,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,   139,   151,   140,     0,     0,     0,    99,   100,
     101,   102,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,   139,   158,   140,
       0,     0,     0,    99,   100,   101,   102,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,   139,     0,   140,     0,     0,     0,    99,   100,
     101,   102,    14,    15,    16,    17,    18,    23,    19,    20,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,    21,    14,    15,    16,
      17,    18,    23,    19,    20,     0,     0,     0,    24,    14,
      15,    16,    17,    18,    37,    19,    20,     0,     0,     0,
       0,    21,     0,    38,    14,    15,    16,    17,    18,    23,
      19,    20,     0,    21,    78,    14,    15,    16,    17,    18,
      23,    19,    20,     0,     0,     0,     0,     0,    21,     0,
     114,    14,    15,    16,    17,    18,    23,    19,    20,    21,
      14,    15,    16,    17,    18,    23,    19,    20,     0,     0,
     122,     0,     0,     0,     0,    21,     0,     0,     0,   136,
       0,     0,     0,     0,    21,    14,    15,    16,    17,    18,
      23,    19,    20,    14,    15,    16,    17,    18,    23,    19,
      20,     0,     0,     0,   154,     0,     0,     0,     0,    21,
       0,     0,   161,     0,     0,     0,     0,    21,    14,    15,
      16,    17,    18,    23,    19,    20,    14,    15,    16,    17,
      18,     0,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
      21
  };

  const short int
  GraphQLParserImpl::yycheck_[] =
  {
       5,    85,    39,    97,    13,    35,    11,    50,     1,     0,
      47,    41,     4,     5,    23,     7,    35,     9,    55,    58,
      57,    51,    27,    53,   128,    68,    65,   121,    20,     8,
     114,    24,    51,    38,    17,   139,    66,   128,    20,    44,
      45,   135,    72,    80,    74,    75,   128,    23,   139,   153,
     128,    12,   128,   139,   128,    15,   160,   139,    63,    15,
      11,   139,   153,   139,    16,   139,    11,   153,    12,   160,
      19,   153,    15,    17,   160,   153,    20,   153,   160,   153,
      15,    68,   160,   113,   160,    12,   160,    17,    15,     8,
      20,   113,    63,    98,     3,     4,     5,     6,     7,     8,
       9,    10,    27,    37,   124,   156,    42,   114,    -1,    18,
      19,    20,    -1,    -1,    23,    24,    25,    26,    27,   124,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    18,    19,    20,    -1,
      -1,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,   156,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    24,    25,
      26,    27,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    27,    -1,    17,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    27,    13,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      18,     3,     4,     5,     6,     7,     8,     9,    10,    27,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    27,     3,     4,     5,     6,     7,
       8,     9,    10,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27
  };

  const unsigned char
  GraphQLParserImpl::yystos_[] =
  {
       0,     4,     5,     7,     9,    20,    29,    33,    34,    35,
      36,    37,    44,    55,     3,     4,     5,     6,     7,     9,
      10,    27,    30,     8,    14,    30,    31,    46,    47,    48,
      53,    54,     0,    35,    31,    32,     8,     8,    17,    30,
      75,    76,    77,    78,    12,    15,    49,    50,    22,    47,
      12,    38,    44,    75,    31,    56,    80,    56,    31,    76,
      44,    78,    31,    51,    52,    31,    76,    23,    39,    40,
      41,    44,    75,    44,    76,    76,    50,    15,    13,    52,
      50,    44,    45,    13,    41,    15,    44,    44,    44,     3,
       4,     5,     6,     7,     8,     9,    10,    18,    20,    24,
      25,    26,    27,    40,    57,    58,    59,    60,    62,    63,
      64,    65,    69,    76,    18,    79,    80,    81,    82,    19,
      57,    66,    22,    31,    70,    71,    45,    79,    16,    42,
      43,    11,    11,    19,    57,    15,    22,    71,    19,    18,
      20,    58,    59,    60,    61,    62,    63,    64,    67,    72,
      57,    19,    61,    68,    22,    31,    73,    74,    19,    61,
      15,    22,    74,    61
  };

  const unsigned char
  GraphQLParserImpl::yyr1_[] =
  {
       0,    28,    29,    30,    30,    30,    30,    30,    30,    30,
      30,    31,    31,    32,    32,    33,    34,    34,    35,    35,
      36,    36,    36,    36,    36,    37,    37,    37,    38,    39,
      39,    40,    41,    42,    42,    43,    44,    45,    45,    46,
      46,    47,    47,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    53,    54,    54,    55,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    75,    76,    76,    77,    77,    78,
      79,    79,    79,    80,    81,    82,    82
  };

  const unsigned char
  GraphQLParserImpl::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     2,     1,     1,
       1,     3,     4,     4,     5,     1,     1,     1,     3,     1,
       2,     1,     4,     0,     1,     2,     3,     0,     1,     1,
       2,     1,     1,     1,     4,     6,     3,     0,     1,     1,
       2,     3,     3,     5,     3,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       2,     3,     1,     2,     2,     3,     1,     2,     3,     2,
       3,     1,     2,     3,     1,     0,     1,     1,     2,     3,
       1,     1,     1,     1,     3,     2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const GraphQLParserImpl::yytname_[] =
  {
  "EOF", "error", "$undefined", "\"false\"", "\"fragment\"",
  "\"mutation\"", "\"null\"", "\"query\"", "\"on\"", "\"subscription\"",
  "\"true\"", "\"!\"", "\"(\"", "\")\"", "\"...\"", "\":\"", "\"=\"",
  "\"@\"", "\"[\"", "\"]\"", "\"{\"", "\"|\"", "\"}\"", "VARIABLE",
  "INTEGER", "FLOAT", "STRING", "IDENTIFIER", "$accept", "start",
  "fragment_name", "name", "name_opt", "document", "definition_list",
  "definition", "operation_definition", "operation_type",
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
  "list_type", "non_null_type", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  GraphQLParserImpl::yyrline_[] =
  {
       0,   219,   219,   224,   225,   226,   227,   228,   229,   230,
     231,   234,   235,   239,   240,   245,   248,   249,   252,   253,
     259,   260,   261,   262,   263,   266,   267,   268,   272,   276,
     277,   280,   284,   288,   289,   292,   296,   300,   301,   303,
     304,   307,   308,   309,   312,   313,   316,   319,   320,   323,
     324,   327,   332,   336,   337,   341,   344,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   359,   362,   365,   368,
     369,   370,   371,   372,   373,   374,   375,   378,   379,   382,
     385,   386,   387,   388,   389,   390,   397,   398,   401,   402,
     406,   407,   411,   412,   417,   418,   422,   423,   426,   430,
     431,   435,   436,   439,   444,   447,   448,   451,   452,   455,
     460,   461,   462,   465,   468,   471,   472
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
      25,    26,    27
    };
    const unsigned int user_token_number_max_ = 282;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2448 "parser.tab.cpp" // lalr1.cc:1167
#line 474 "parser.ypp" // lalr1.cc:1168

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
