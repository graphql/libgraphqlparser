This directory contains an example usage of the GraphQL parser and AST
library from Go. See [cgo's
documentation](https://github.com/golang/go/wiki/cgo), particularly
the "Function pointer callbacks" section, for explanation of the
mechanisms in use.

To build, first build the main GraphQLParser library in the parent
directory, and then set this directory to be your `GOPATH` and run `go
build`.
