cdef extern from "GraphQLParser.h":
    struct GraphQLAstNode:
      pass

    GraphQLAstNode* graphql_parse_string(char* text, char** error)
