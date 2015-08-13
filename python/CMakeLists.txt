
IF (CTYPESGEN_FOUND)
  ADD_CUSTOM_COMMAND(
    OUTPUT GraphQLParser.py
    COMMAND ctypesgen.py ../c/*.h -o GraphQLParser.py -l graphqlparser -L .. 2>&1 > /dev/null
    DEPENDS ../c/GraphQLAstForEachConcreteType.h ../c/GraphQLAst.h
    )
  ADD_CUSTOM_TARGET(
    graphql-parser-python
    ALL
    DEPENDS GraphQLParser.py)
ELSE()
  MESSAGE(WARNING "ctypesgen.py not found; install with pip or easy_install if you want to run pythontest.py.")
ENDIF()
