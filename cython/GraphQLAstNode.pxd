cimport cGraphQLAstNode

cdef class GraphQLAstNode:

    cdef cGraphQLAstNode.GraphQLAstNode* _node

    @staticmethod
    cdef create(cGraphQLAstNode.GraphQLAstNode* node_c)
