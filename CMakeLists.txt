CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(libgraphqlparser C CXX)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

IF(UNIX)
  SET(FLEX_COMPILE_FLAGS "--header-file=lexer.h") 
ELSEIF(WIN32)
  # If we're building this with vcpkg on Windows, let portfile.cmake tell us where it
  # stored these tools. Otherwise these variables should be empty and we'll fall back
  # to the normal CMake FIND_PACKAGE logic for each of these programs.
  SET(CMAKE_PROGRAM_PATH
    "${VCPKG_DOWNLOADS_PYTHON2_DIR}"
	"${VCPKG_DOWNLOADS_FLEX_DIR}"
	"${VCPKG_DOWNLOADS_BISON_DIR}"
	"${CMAKE_PROGRAM_PATH}")

  SET(FLEX_COMPILE_FLAGS "--header-file=lexer.h --wincompat")

  # Let CMake figure out the exports for the SHARED library (DLL) on Windows.
  SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
ENDIF()

INCLUDE(version)

FIND_PACKAGE(PythonInterp 2 REQUIRED)
IF (NOT PYTHON_VERSION_MAJOR EQUAL 2)
  MESSAGE(FATAL_ERROR "Python 2 is required.")
ENDIF()

IF(UNIX)
  SET(FLEX_COMPILE_FLAGS "--header-file=lexer.h") 
ELSEIF(WIN32)
  SET(FLEX_COMPILE_FLAGS "--header-file=lexer.h --wincompat") 
ENDIF()

FIND_PROGRAM(CTYPESGEN_FOUND ctypesgen.py)

FIND_PACKAGE(BISON 3)
FIND_PACKAGE(FLEX)
IF (BISON_FOUND)
  BISON_TARGET(graphqlparser parser.ypp ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp)
ENDIF()

IF(FLEX_FOUND)
  FLEX_TARGET(GraphQLScanner lexer.lpp ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp COMPILE_FLAGS ${FLEX_COMPILE_FLAGS})
  IF (BISON_FOUND)
    ADD_FLEX_BISON_DEPENDENCY(GraphQLScanner graphqlparser)
  ENDIF()
ENDIF()

FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/c)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY(graphqlparser SHARED
  JsonVisitor.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/Ast.h
  ${CMAKE_CURRENT_BINARY_DIR}/Ast.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/AstVisitor.h
  ${CMAKE_CURRENT_BINARY_DIR}/c/GraphQLAst.h
  ${CMAKE_CURRENT_BINARY_DIR}/c/GraphQLAst.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/c/GraphQLAstForEachConcreteType.h
  ${CMAKE_CURRENT_BINARY_DIR}/JsonVisitor.h.inc
  ${CMAKE_CURRENT_BINARY_DIR}/JsonVisitor.cpp.inc
  c/GraphQLAstNode.cpp
  c/GraphQLAstToJSON.cpp
  c/GraphQLAstVisitor.h
  c/GraphQLAstVisitor.cpp
  c/GraphQLParser.cpp
  parser.tab.cpp
  parser.tab.hpp
  lexer.cpp
  lexer.h
  GraphQLParser.cpp)

# Enable this and remove CMAKE_CXX_FLAGS fiddle above when we are able
# to upgrade to CMake 2.8.12. Blocker seems to be Travis CI being on
# Ubuntu Precise; Trusty has 2.8.12.
# TARGET_COMPILE_OPTIONS(graphqlparser PUBLIC -std=gnu++11)

ADD_EXECUTABLE(dump_json_ast dump_json_ast.cpp)
TARGET_LINK_LIBRARIES(dump_json_ast graphqlparser)

FUNCTION(GENERATE_AST_FILE FILE_TYPE FILE_RELATIVE_PATH)
  ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${FILE_RELATIVE_PATH}
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/ast/ast.py ${FILE_TYPE} ${CMAKE_CURRENT_SOURCE_DIR}/ast/ast.ast > ${CMAKE_CURRENT_BINARY_DIR}/${FILE_RELATIVE_PATH}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/ast/ast.ast ${CMAKE_CURRENT_SOURCE_DIR}/ast/ast.py ${CMAKE_CURRENT_SOURCE_DIR}/ast/${FILE_TYPE}.py)
ENDFUNCTION(GENERATE_AST_FILE)

GENERATE_AST_FILE(cxx Ast.h)

GENERATE_AST_FILE(cxx_visitor AstVisitor.h)

GENERATE_AST_FILE(cxx_impl Ast.cpp)

GENERATE_AST_FILE(c c/GraphQLAst.h)

GENERATE_AST_FILE(c_impl c/GraphQLAst.cpp)

GENERATE_AST_FILE(c_visitor_impl c/GraphQLAstForEachConcreteType.h)

GENERATE_AST_FILE(cxx_json_visitor_header JsonVisitor.h.inc)

GENERATE_AST_FILE(cxx_json_visitor_impl JsonVisitor.cpp.inc)

ADD_SUBDIRECTORY(python)

OPTION(test "Build tests." OFF)

INSTALL(DIRECTORY c ${CMAKE_CURRENT_BINARY_DIR}/c DESTINATION include/graphqlparser
  FILES_MATCHING PATTERN "*.h"
  PATTERN "build" EXCLUDE)

INSTALL(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/Ast.h
  AstNode.h
  ${CMAKE_CURRENT_BINARY_DIR}/AstVisitor.h
  GraphQLParser.h
  JsonVisitor.h
  lexer.h
  location.hh
  parser.tab.hpp
  position.hh
  stack.hh
  syntaxdefs.h
  DESTINATION include/graphqlparser)

INSTALL(TARGETS graphqlparser
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

if (UNIX)
  # generate pkgconfig file
  include(FindPkgConfig QUIET)
  if(PKG_CONFIG_FOUND)
    # generate .pc and install
    configure_file("libgraphqlparser.pc.in" "libgraphqlparser.pc" @ONLY)
    install(FILES       "${CMAKE_CURRENT_BINARY_DIR}/libgraphqlparser.pc"
            DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig")
  endif()

  IF (test)
    ADD_SUBDIRECTORY(test)

    if(UNIX)
      # setup valgrind
      ADD_CUSTOM_TARGET(memcheck
        valgrind --leak-check=full --suppressions=./test/valgrind.supp --dsymutil=yes --error-exitcode=1 ./test/runTests  >/dev/null
      )
    endif()

  ENDIF()
endif()
