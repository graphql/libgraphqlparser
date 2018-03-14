# libgraphqlparser

libgraphqlparser is a parser for
[GraphQL](http://facebook.github.io/graphql/), a query language
created by Facebook for describing data requirements on complex
application data models, implemented in C++11. It can be used on its
own in C++ code (or in C code via the pure C API defined in the `c`
subdirectory), or you can use it as the basis for an extension module
for your favorite programming language instead of writing your own
parser from scratch.

## Example

The provided `dump_json_ast` is a simple program that reads GraphQL
text on stdin and prints a JSON representation of the AST to stdout.

The `python` subdirectory contains an example Python binding for the
pure C API.

## Requirements

libgraphqlparser requires a C++ compiler that supports C++11. It
also requires Mac OS X or Linux.

To run tests, please download googletest from
https://github.com/google/googletest/archive/release-1.8.0.zip
and unzip it in the `test` subdirectory.

## Building libgraphqlparser

libgraphqlparser is built with [CMake](http://www.cmake.org/). If a
sufficiently-recent version of [Flex](http://flex.sourceforge.net/) and [Bison](http://www.gnu.org/software/bison/) are installed on your
system, it will use them; otherwise, it will rely on the checked-in
`parser.tab.{c,h}pp` and `lexer.{h,cpp}`.

To build libgraphqlparser from source:

```
$ # inside the project root:
$ cmake .
$ make
```

Then, to install it on your system:

```
$ make install
```

## How libgraphqlparser works

libgraphqlparser uses flex and bison to generate a C++ parser for
GraphQL. These tools work well but have idiosyncratic interfaces by
modern standards, so GraphQLParser.h provides a simple interface to
parse GraphQL.

In order to make it simpler to write code based around the GraphQL
AST, libgraphqlparser includes an extremely simple code generation
framework in the `ast/` subdirectory. This framework is used to build
the AST classes themselves, as well as a visitor over the AST. It may
be easier to understand the output of the generation steps directly
(i.e., Ast.h, Ast.cpp, and AstVisitor.h) rather than trying to read
the generation scripts. Simply building libgraphqlparser will cause
these files to be generated.

libgraphqlparser also uses the AST generation framework to build a
pure C API in the `c` subdirectory. This API can be used from C code,
and it should also simplify the task of creating bindings to other
programming languages.

## License
libgraphqlparser is MIT-licensed.

## Related Projects

- [graphql-parser (Ruby interface)](https://github.com/Shopify/graphql-parser)
- [py-graphqlparser (Python interface)](https://github.com/elastic-coders/py-graphqlparser)
- [graphql_parser (Elixir interface)](https://github.com/aarvay/graphql_parser)
- [graphql-parser-php (PHP interface)](https://github.com/dosten/graphql-parser-php)
- [graphql-libgraphqlparser (Ruby interface)](https://github.com/rmosolgo/graphql-libgraphqlparser-ruby)
