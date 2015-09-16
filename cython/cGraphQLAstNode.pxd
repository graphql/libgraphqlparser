cdef extern from "GraphQLAstNode.h":
    struct GraphQLAstNode:
        pass

    void graphql_node_free(GraphQLAstNode* node)
