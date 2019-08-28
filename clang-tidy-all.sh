#!/bin/sh
# Copyright (c) Facebook, Inc. and its affiliates.
find . -name '*.cpp' | grep -v lexer | grep -v googletest | grep -v tab.cpp | xargs clang-tidy -p build
