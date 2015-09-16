cimport cGraphQLAstNode


cdef class GraphQLAstNode:

    def __dealloc__(self):
      if self._node is not NULL:
          cGraphQLAstNode.graphql_node_free(self._node)

    @staticmethod
    cdef create(cGraphQLAstNode.GraphQLAstNode *node_c):
        node = GraphQLAstNode()
        node._node = node_c
        return node
