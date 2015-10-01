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
#line 128 "parser.ypp" // lalr1.cc:413

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
    YYUSE (yysym.type_get ());
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

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 418 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 4: // "fragment"

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 425 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 5: // "mutation"

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 432 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 6: // "null"

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 439 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 7: // "query"

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 446 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 8: // "on"

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 453 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 9: // "true"

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 460 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 22: // VARIABLE

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 467 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 23: // INTEGER

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 474 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 24: // FLOAT

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 481 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 25: // STRING

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 488 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 26: // IDENTIFIER

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 495 "parser.tab.cpp" // lalr1.cc:636
        break;

      case 36: // operation_type

#line 223 "parser.ypp" // lalr1.cc:636
        { yyoutput << (yysym.value.str); }
#line 502 "parser.tab.cpp" // lalr1.cc:636
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
#line 227 "parser.ypp" // lalr1.cc:859
    { *outAST = (yystack_[0].value.document); }
#line 722 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 232 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 728 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 233 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 734 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 234 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 740 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 235 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 746 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 236 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 752 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 237 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 758 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 238 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 764 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 242 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.name) = new Name(yystack_[0].location, strdup((yystack_[0].value.str))); }
#line 770 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 246 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.name) = nullptr;}
#line 776 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 252 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.document) = new Document(yylhs.location, (yystack_[0].value.definitionList)); }
#line 782 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 255 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definitionList) = new std::vector<std::unique_ptr<Definition>>(); (yylhs.value.definitionList)->emplace_back((yystack_[0].value.definition)); }
#line 788 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 256 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.definitionList)->emplace_back((yystack_[0].value.definition)); (yylhs.value.definitionList) = (yystack_[1].value.definitionList); }
#line 794 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 259 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.operationDefinition)); }
#line 800 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 260 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.definition) = static_cast<Definition *>((yystack_[0].value.fragmentDefinition));}
#line 806 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 266 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, strdup("query"), nullptr, nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 812 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 267 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[2].value.str), (yystack_[1].value.name), nullptr, nullptr, (yystack_[0].value.selectionSet)); }
#line 818 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 268 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.str), (yystack_[2].value.name), (yystack_[1].value.variableDefinitionList), nullptr, (yystack_[0].value.selectionSet)); }
#line 824 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 269 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[3].value.str), (yystack_[2].value.name), nullptr, (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 830 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 270 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.operationDefinition) = new OperationDefinition(yylhs.location, (yystack_[4].value.str), (yystack_[3].value.name), (yystack_[2].value.variableDefinitionList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 836 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 273 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.str) = strdup((yystack_[0].value.str)); }
#line 842 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 274 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.str) = strdup((yystack_[0].value.str)); }
#line 848 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 278 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 854 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 282 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinitionList) = new std::vector<std::unique_ptr<VariableDefinition>>(); (yylhs.value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); }
#line 860 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 283 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.variableDefinitionList)->emplace_back((yystack_[0].value.variableDefinition)); (yylhs.value.variableDefinitionList) = (yystack_[1].value.variableDefinitionList); }
#line 866 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 286 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variable) = new Variable(yylhs.location, new Name(yystack_[0].location, strdup((yystack_[0].value.str)))); }
#line 872 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 290 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.variableDefinition) = new VariableDefinition(yylhs.location, (yystack_[3].value.variable), (yystack_[1].value.type), (yystack_[0].value.value)); }
#line 878 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 294 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = nullptr; }
#line 884 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 298 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = (yystack_[0].value.value); }
#line 890 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 302 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = new SelectionSet(yylhs.location, (yystack_[1].value.selectionList)); }
#line 896 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 306 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionSet) = nullptr; }
#line 902 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 309 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selectionList) = new std::vector<std::unique_ptr<Selection>>(); (yylhs.value.selectionList)->emplace_back((yystack_[0].value.selection)); }
#line 908 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 310 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.selectionList)->emplace_back((yystack_[0].value.selection)); (yylhs.value.selectionList) = (yystack_[1].value.selectionList); }
#line 914 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 313 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.field)); }
#line 920 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 314 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.fragmentSpread)); }
#line 926 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 315 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.selection) = static_cast<Selection *>((yystack_[0].value.inlineFragment)); }
#line 932 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 318 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, nullptr, (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 938 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 319 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.field) = new Field(yylhs.location, (yystack_[5].value.name), (yystack_[3].value.name), (yystack_[2].value.argumentList), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 944 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 322 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 950 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 325 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = nullptr; }
#line 956 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 326 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = (yystack_[0].value.argumentList); }
#line 962 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 329 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argumentList) = new std::vector<std::unique_ptr<Argument>>(); (yylhs.value.argumentList)->emplace_back((yystack_[0].value.argument)); }
#line 968 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 330 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.argumentList)->emplace_back((yystack_[0].value.argument)); (yylhs.value.argumentList) = (yystack_[1].value.argumentList); }
#line 974 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 333 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.argument) = new Argument(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 980 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 338 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentSpread) = new FragmentSpread(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.directiveList)); }
#line 986 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 342 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.inlineFragment) = new InlineFragment(yylhs.location, (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 992 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 346 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.fragmentDefinition) = new FragmentDefinition(yylhs.location, (yystack_[4].value.name), (yystack_[2].value.namedType), (yystack_[1].value.directiveList), (yystack_[0].value.selectionSet)); }
#line 998 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 353 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.variable)); }
#line 1004 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 354 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1010 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 355 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1016 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 356 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1022 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 357 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1028 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 358 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1034 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 359 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1040 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 360 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1046 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 363 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.intValue) = new IntValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1052 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 366 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.floatValue) = new FloatValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1058 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 369 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.stringValue) = new StringValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1064 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 372 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.intValue)); }
#line 1070 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 373 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.floatValue)); }
#line 1076 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 374 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.stringValue)); }
#line 1082 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 375 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.booleanValue)); }
#line 1088 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 376 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.enumValue)); }
#line 1094 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 377 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.arrayValue)); }
#line 1100 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 378 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.value) = static_cast<Value *>((yystack_[0].value.objectValue)); }
#line 1106 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 381 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, true); }
#line 1112 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 382 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.booleanValue) = new BooleanValue(yylhs.location, false); }
#line 1118 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 385 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1124 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 386 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1130 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 387 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1136 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 388 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1142 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 389 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.enumValue) = new EnumValue(yylhs.location, strdup((yystack_[0].value.str))); }
#line 1148 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 396 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 1154 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 397 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 1160 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 400 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 1166 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 401 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 1172 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 405 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, new std::vector<std::unique_ptr<Value>>()); }
#line 1178 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 406 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arrayValue) = new ArrayValue(yylhs.location, (yystack_[1].value.valueList)); }
#line 1184 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 410 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.valueList) = new std::vector<std::unique_ptr<Value>>(); (yylhs.value.valueList)->emplace_back((yystack_[0].value.value)); }
#line 1190 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 411 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.valueList)->emplace_back((yystack_[0].value.value)); (yylhs.value.valueList) = (yystack_[1].value.valueList); }
#line 1196 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 416 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 1202 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 417 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 1208 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 421 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 1214 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 422 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 1220 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 425 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1226 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 429 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, new std::vector<std::unique_ptr<ObjectField>>()); }
#line 1232 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 430 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectValue) = new ObjectValue(yylhs.location, (yystack_[1].value.objectFieldList)); }
#line 1238 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 434 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectFieldList) = new std::vector<std::unique_ptr<ObjectField>>(); (yylhs.value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); }
#line 1244 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 435 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.objectFieldList)->emplace_back((yystack_[0].value.objectField)); (yylhs.value.objectFieldList) = (yystack_[1].value.objectFieldList); }
#line 1250 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 438 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.objectField) = new ObjectField(yylhs.location, (yystack_[2].value.name), (yystack_[0].value.value)); }
#line 1256 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 446 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = nullptr; }
#line 1262 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 450 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directiveList) = new std::vector<std::unique_ptr<Directive>>(); (yylhs.value.directiveList)->emplace_back((yystack_[0].value.directive)); }
#line 1268 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 451 "parser.ypp" // lalr1.cc:859
    { (yystack_[1].value.directiveList)->emplace_back((yystack_[0].value.directive)); (yylhs.value.directiveList) = (yystack_[1].value.directiveList); }
#line 1274 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 454 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.directive) = new Directive(yylhs.location, (yystack_[1].value.name), (yystack_[0].value.argumentList)); }
#line 1280 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 459 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.namedType)); }
#line 1286 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 460 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.listType)); }
#line 1292 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 461 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.type) = static_cast<Type *>((yystack_[0].value.nonNullType)); }
#line 1298 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 464 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.namedType) = new NamedType(yylhs.location, (yystack_[0].value.name)); }
#line 1304 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 467 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.listType) = new ListType(yylhs.location, (yystack_[1].value.type)); }
#line 1310 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 470 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.namedType)); }
#line 1316 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 471 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.nonNullType) = new NonNullType(yylhs.location, (yystack_[1].value.listType)); }
#line 1322 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 1326 "parser.tab.cpp" // lalr1.cc:859
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


  const signed char GraphQLParserImpl::yypact_ninf_ = -117;

  const signed char GraphQLParserImpl::yytable_ninf_ = -1;

  const short int
  GraphQLParserImpl::yypact_[] =
  {
      47,     5,  -117,  -117,   226,    24,  -117,    47,  -117,  -117,
     329,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
      17,  -117,   336,  -117,    61,   202,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,    70,   329,   329,    10,   329,   329,  -117,
      10,  -117,  -117,    27,   329,    71,  -117,    13,    10,  -117,
    -117,    10,  -117,    10,  -117,  -117,    48,   237,  -117,    52,
      13,  -117,    43,    59,  -117,    52,  -117,    13,  -117,  -117,
      13,    13,   123,  -117,  -117,    10,  -117,  -117,  -117,  -117,
     250,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,    75,   265,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,    13,   250,    76,    85,
      86,  -117,  -117,  -117,    99,  -117,    91,   274,  -117,  -117,
      67,   195,  -117,  -117,  -117,  -117,  -117,  -117,   123,  -117,
    -117,  -117,   147,   298,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,   171,  -117,    95,   305,  -117,
    -117,  -117,   195,  -117,  -117,  -117
  };

  const unsigned char
  GraphQLParserImpl::yydefact_[] =
  {
       0,     0,    25,    24,     0,     0,     2,    14,    15,    17,
      12,    19,    18,     4,     5,     6,     7,     8,     9,     3,
       0,    11,     0,    10,    45,     0,    37,    39,    40,    41,
       1,    16,    13,     0,     0,     0,    98,     0,     0,    46,
      98,    34,    38,     0,     0,     0,    20,     0,    97,   100,
     106,    98,    53,    98,    99,    50,     0,     0,    47,    45,
      35,    29,     0,     0,    27,    45,    21,     0,    22,   101,
       0,     0,     0,    44,    48,    98,    36,    42,    26,    28,
       0,   102,    23,    52,    51,    73,    75,    76,    78,    77,
      72,     0,     0,    62,    63,    64,    74,    54,    49,    55,
      56,    57,    58,    59,    60,    61,    35,     0,    31,   103,
     104,   105,    79,    81,     0,    87,     0,     0,    89,    43,
       0,     0,    30,    32,   108,   109,    80,    82,     0,    88,
      90,   107,     0,     0,    65,    66,    67,    33,    68,    69,
      70,    71,    91,    83,    85,     0,    92,     0,     0,    94,
      84,    86,     0,    93,    95,    96
  };

  const signed char
  GraphQLParserImpl::yypgoto_[] =
  {
    -117,  -117,     1,    -4,  -117,  -117,  -117,   103,  -117,  -117,
    -117,  -117,   -40,    49,  -117,  -117,   -32,     6,  -117,    89,
    -117,  -117,    -1,  -117,    58,  -117,  -117,  -117,    84,   -87,
    -116,  -102,   -84,   -85,   -76,   -75,  -117,  -117,  -117,  -117,
    -117,  -117,     3,  -117,  -117,   -15,    26,   -33,  -117,    87,
      29,   -63,  -117,  -117
  };

  const short int
  GraphQLParserImpl::yydefgoto_[] =
  {
      -1,     5,    23,    50,    33,     6,     7,     8,     9,    10,
      45,    62,    97,    64,   122,   123,    11,    77,    25,    26,
      27,    39,    40,    57,    58,    28,    29,    12,    51,    98,
      99,   100,   101,   137,   102,   103,   104,   114,   140,   145,
     105,   117,   118,   141,   148,   149,    54,    55,    48,    49,
     108,    52,   110,   111
  };

  const unsigned char
  GraphQLParserImpl::yytable_[] =
  {
      24,    46,    20,    63,   113,   134,    32,    60,    13,    14,
      15,    16,    17,    66,    18,    68,   134,   109,    70,   135,
      71,    24,    63,    36,    30,    34,    44,   127,    76,   134,
     135,    19,     4,    56,    59,    82,   134,   136,    83,    84,
      65,   142,   106,   135,   109,   138,   139,   144,   136,    61,
     135,     1,     2,    56,     3,    78,   138,   139,    75,    47,
     151,   136,    72,    37,    81,    61,     4,   155,   136,   138,
     139,    67,    37,    80,    76,    38,   138,   139,    85,    86,
      87,    43,    88,    89,    90,   131,    44,    44,   116,     4,
       4,   121,    91,   112,    92,   124,   125,    61,    93,    94,
      95,    96,    85,    86,    87,   128,    88,    89,    90,   152,
      31,    79,   119,   116,    42,    74,    91,   126,    92,    53,
     130,    61,    93,    94,    95,    96,    85,    86,    87,   147,
      88,    89,    90,   154,     0,    69,   120,     0,     0,     0,
      91,     0,    92,     0,   147,    61,    93,    94,    95,    96,
      85,    86,    87,     0,    88,    89,    90,     0,     0,     0,
       0,     0,     0,     0,   132,   143,   133,     0,     0,     0,
      93,    94,    95,    96,    85,    86,    87,     0,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,   132,   150,
     133,     0,     0,     0,    93,    94,    95,    96,    85,    86,
      87,     0,    88,    89,    90,    13,    14,    15,    16,    17,
      21,    18,   132,     0,   133,    22,     0,     0,    93,    94,
      95,    96,     0,    41,     0,     0,     0,     0,    19,    13,
      14,    15,    16,    17,    21,    18,     0,     0,     0,    22,
      13,    14,    15,    16,    17,    21,    18,     0,     0,    73,
       0,     0,    19,    13,    14,    15,    16,    17,    21,    18,
       0,     0,     0,    19,     0,     0,     0,   107,    13,    14,
      15,    16,    17,    21,    18,     0,    19,    13,    14,    15,
      16,    17,    21,    18,     0,     0,   115,     0,     0,     0,
       0,    19,     0,     0,     0,   129,     0,     0,     0,     0,
      19,    13,    14,    15,    16,    17,    21,    18,    13,    14,
      15,    16,    17,    21,    18,     0,     0,     0,     0,   146,
       0,     0,     0,     0,    19,     0,   153,     0,     0,     0,
       0,    19,    13,    14,    15,    16,    17,    21,    18,    13,
      14,    15,    16,    17,    35,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    19
  };

  const short int
  GraphQLParserImpl::yycheck_[] =
  {
       4,    33,     1,    43,    91,   121,    10,    40,     3,     4,
       5,     6,     7,    45,     9,    47,   132,    80,    51,   121,
      53,    25,    62,    22,     0,     8,    16,   114,    60,   145,
     132,    26,    19,    37,    38,    67,   152,   121,    70,    71,
      44,   128,    75,   145,   107,   121,   121,   132,   132,    22,
     152,     4,     5,    57,     7,    12,   132,   132,    59,    33,
     145,   145,    14,    11,    65,    22,    19,   152,   152,   145,
     145,    45,    11,    14,   106,    14,   152,   152,     3,     4,
       5,    11,     7,     8,     9,    18,    16,    16,    92,    19,
      19,    15,    17,    18,    19,    10,    10,    22,    23,    24,
      25,    26,     3,     4,     5,    14,     7,     8,     9,    14,
       7,    62,   106,   117,    25,    57,    17,    18,    19,    35,
     117,    22,    23,    24,    25,    26,     3,     4,     5,   133,
       7,     8,     9,   148,    -1,    48,   107,    -1,    -1,    -1,
      17,    -1,    19,    -1,   148,    22,    23,    24,    25,    26,
       3,     4,     5,    -1,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,     3,     4,     5,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    25,    26,     3,     4,
       5,    -1,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,    17,    -1,    19,    13,    -1,    -1,    23,    24,
      25,    26,    -1,    21,    -1,    -1,    -1,    -1,    26,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    26,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    17,     3,     4,
       5,     6,     7,     8,     9,    -1,    26,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,     3,     4,     5,     6,     7,     8,     9,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,    -1,    21,    -1,    -1,    -1,
      -1,    26,     3,     4,     5,     6,     7,     8,     9,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    26
  };

  const unsigned char
  GraphQLParserImpl::yystos_[] =
  {
       0,     4,     5,     7,    19,    28,    32,    33,    34,    35,
      36,    43,    54,     3,     4,     5,     6,     7,     9,    26,
      29,     8,    13,    29,    30,    45,    46,    47,    52,    53,
       0,    34,    30,    31,     8,     8,    29,    11,    14,    48,
      49,    21,    46,    11,    16,    37,    43,    73,    75,    76,
      30,    55,    78,    55,    73,    74,    30,    50,    51,    30,
      74,    22,    38,    39,    40,    30,    43,    73,    43,    76,
      74,    74,    14,    12,    51,    49,    43,    44,    12,    40,
      14,    49,    43,    43,    43,     3,     4,     5,     7,     8,
       9,    17,    19,    23,    24,    25,    26,    39,    56,    57,
      58,    59,    61,    62,    63,    67,    74,    17,    77,    78,
      79,    80,    18,    56,    64,    21,    30,    68,    69,    44,
      77,    15,    41,    42,    10,    10,    18,    56,    14,    21,
      69,    18,    17,    19,    57,    58,    59,    60,    61,    62,
      65,    70,    56,    18,    60,    66,    21,    30,    71,    72,
      18,    60,    14,    21,    72,    60
  };

  const unsigned char
  GraphQLParserImpl::yyr1_[] =
  {
       0,    27,    28,    29,    29,    29,    29,    29,    29,    29,
      30,    30,    31,    31,    32,    33,    33,    34,    34,    35,
      35,    35,    35,    35,    36,    36,    37,    38,    38,    39,
      40,    41,    41,    42,    43,    44,    44,    45,    45,    46,
      46,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      52,    53,    54,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    58,    59,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    70,    70,    71,    71,    72,    73,    74,    74,
      75,    75,    76,    77,    77,    77,    78,    79,    80,    80
  };

  const unsigned char
  GraphQLParserImpl::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     2,     1,     1,     1,
       3,     4,     4,     5,     1,     1,     3,     1,     2,     1,
       4,     0,     1,     2,     3,     0,     1,     1,     2,     1,
       1,     1,     4,     6,     3,     0,     1,     1,     2,     3,
       3,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     2,     3,     1,     2,     2,     3,     1,
       2,     3,     2,     3,     1,     2,     3,     1,     0,     1,
       1,     2,     3,     1,     1,     1,     1,     3,     2,     2
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
       0,   227,   227,   232,   233,   234,   235,   236,   237,   238,
     241,   242,   246,   247,   252,   255,   256,   259,   260,   266,
     267,   268,   269,   270,   273,   274,   278,   282,   283,   286,
     290,   294,   295,   298,   302,   306,   307,   309,   310,   313,
     314,   315,   318,   319,   322,   325,   326,   329,   330,   333,
     338,   342,   346,   349,   353,   354,   355,   356,   357,   358,
     359,   360,   363,   366,   369,   372,   373,   374,   375,   376,
     377,   378,   381,   382,   385,   386,   387,   388,   389,   396,
     397,   400,   401,   405,   406,   410,   411,   416,   417,   421,
     422,   425,   429,   430,   434,   435,   438,   443,   446,   447,
     450,   451,   454,   459,   460,   461,   464,   467,   470,   471
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
#line 1911 "parser.tab.cpp" // lalr1.cc:1167
#line 473 "parser.ypp" // lalr1.cc:1168

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
