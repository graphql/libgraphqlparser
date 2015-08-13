CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(libgraphqlparser C CXX)

FIND_PACKAGE(PythonInterp)
IF (NOT PYTHON_VERSION_MAJOR EQUAL 2)
  MESSAGE(FATAL_ERROR "Python 2 is required.")
ENDIF()

FIND_PROGRAM(CTYPESGEN_FOUND ctypesgen.py)

FIND_PACKAGE(BISON 3)
FIND_PACKAGE(FLEX)
IF (BISON_FOUND)
  BISON_TARGET(graphqlparser parser.ypp parser.tab.cpp)
ENDIF()

IF(FLEX_FOUND)
  FLEX_TARGET(GraphQLScanner lexer.lpp lexer.cpp COMPILE_FLAGS "--header-file=lexer.h")
  IF (BISON_FOUND)
    ADD_FLEX_BISON_DEPENDENCY(GraphQLScanner graphqlparser)
  ENDIF()
ENDIF()

ADD_LIBRARY(graphqlparser SHARED
  Ast.cpp
  JsonVisitor.cpp Ast.h AstVisitor.h
  c/GraphQLAst.h
  c/GraphQLAst.cpp
  c/GraphQLAstNode.cpp
  c/GraphQLAstForEachConcreteType.h
  c/GraphQLAstVisitor.h
  c/GraphQLAstVisitor.cpp
  c/GraphQLParser.cpp
  parser.tab.cpp parser.tab.hpp
  lexer.cpp
  GraphQLParser.cpp)

TARGET_COMPILE_FEATURES(graphqlparser PUBLIC cxx_auto_type cxx_override)

ADD_EXECUTABLE(dump_json_ast dump_json_ast.cpp)
TARGET_LINK_LIBRARIES(dump_json_ast graphqlparser)

ADD_CUSTOM_COMMAND(
  OUTPUT Ast.h
  COMMAND python ./ast/ast.py c++ ./ast/ast.ast > Ast.h
  DEPENDS ./ast/ast.ast
  )

ADD_CUSTOM_COMMAND(
  OUTPUT AstVisitor.h
  COMMAND python ./ast/ast.py c++visitor ./ast/ast.ast > AstVisitor.h
  DEPENDS ./ast/ast.ast
  )

ADD_CUSTOM_COMMAND(
  OUTPUT Ast.cpp
  COMMAND python ./ast/ast.py c++impl ./ast/ast.ast > Ast.cpp
  DEPENDS ./ast/ast.ast
  )

ADD_CUSTOM_COMMAND(
  OUTPUT c/GraphQLAst.h
  COMMAND python ./ast/ast.py c ./ast/ast.ast > c/GraphQLAst.h
  DEPENDS ./ast/ast.ast
  )

ADD_CUSTOM_COMMAND(
  OUTPUT c/GraphQLAst.cpp
  COMMAND python ./ast/ast.py cimpl ./ast/ast.ast > c/GraphQLAst.cpp
  DEPENDS ./ast/ast.ast
  )

ADD_CUSTOM_COMMAND(
  OUTPUT c/GraphQLAstForEachConcreteType.h
  COMMAND python ./ast/ast.py cvisitorimpl ./ast/ast.ast > c/GraphQLAstForEachConcreteType.h
  DEPENDS ./ast/ast.ast
  )

ADD_SUBDIRECTORY(python)

OPTION(test "Build tests." OFF)

IF (test)
  ADD_SUBDIRECTORY(test)
ENDIF()
