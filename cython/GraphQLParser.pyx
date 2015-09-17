cimport cGraphQLParser
cimport cGraphQLAstNode
cimport cGraphQLAst
cimport GraphQLAstNode


class GraphQLParseError(Exception):
    pass


def graphql_parse_string(text):
    cdef char* error_c = NULL
    cdef char* text_c
    cdef cGraphQLAstNode.GraphQLAstNode* node_c
    byte_string = text.encode()
    text_c = byte_string
    node_c = cGraphQLParser.graphql_parse_string(text_c, &error_c)
    if node_c is NULL:
        mesg = error_c.decode() if error_c is not NULL else None
        raise GraphQLParseError(mesg)
    return GraphQLAstNode.GraphQLAstNode.create(node_c)
