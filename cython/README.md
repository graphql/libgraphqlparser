# libgraphql cython port

Python2.7+ (includes python3) class-based bindings to libgraphql

See usage example in `cython/visitor_example.py`

This bindings are still experimental.


## Build & Install

- build libgraphql as usual (python2.7 required for building)
- cd into `cython` folder
- you can now switch to python 3
- install cython
- run `LDFLAGS="-L../" CFLAGS="-I..//c -I../" python setup.py build`
- run `python setup.py install`


## Running

Make sure `libgraphql.so` is in your `LD_LIBRARY_PATH`


## Testing

- for now just run `python visitor_example.py <graphql query>`



## Known issues

- Only (lightly) tested on python3
- Unicode string handling not yet complete (a mixture of bytes and strings all over)
- Exceptions in the visitor's class callbacks are ignored


## TODO

- write automated tests
