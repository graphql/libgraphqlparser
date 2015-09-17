from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

setup(
    name='graphql',
    ext_modules=cythonize([
        Extension("GraphQLAstNode",
                  ["GraphQLAstNode.pyx"],
                  libraries=['graphqlparser']),
        Extension("GraphQLParser",
                  ["GraphQLParser.pyx"],
                  libraries=['graphqlparser']),
        Extension("GraphQLAstVisitor",
                  ["GraphQLAstVisitor.pyx"],
                  libraries=['graphqlparser']),
        Extension("GraphQLAst",
                  ["GraphQLAst.pyx"],
                  libraries=['graphqlparser'])
    ])
)
