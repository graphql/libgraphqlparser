#!/usr/bin/env python
# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from importlib import import_module

def load_lang(lang):
  lang2modulename = {
    'c': 'ast_c',
    'cimpl': 'ast_c_impl',
    'cvisitorimpl': 'ast_c_visitor_impl',
    'c++': 'ast_cxx',
    'c++impl': 'ast_cxx_impl',
    'c++visitor': 'ast_cxx_visitor',
    'js': 'ast_js',
    'ruby': 'ast_ruby',
    'ruby_impl': 'ast_ruby_impl'
   }
  module_name = lang2modulename.get(lang)
  if module_name is None:
    raise Exception('Unknown language ' + lang)

  return import_module(module_name).Printer()


def print_ast(lang_module, input_file):
  lang_module.start_file()
  line = input_file.readline()
  while line:
    line = line.strip()
    if line.startswith('#') or not line:
      line = input_file.readline()
      continue

    code, rest = line.split(None, 1)
    if code[0] == 'T':
      lang_module.start_type(rest)
      field_line = input_file.readline().strip()
      while field_line:
        if field_line.startswith('#'):
          field_line = input_file.readline().strip()
          continue
        field_kind, field_type, field_name = field_line.split()
        nullable = len(field_kind) > 1 and field_kind[1] == '?'
        if field_kind[0] == 'S':
          plural = False
        elif field_kind[0] == 'P':
          plural = True
        else:
          raise Error('Unknown field kind: ' + field_kind)
        lang_module.field(field_type, field_name, nullable, plural)
        field_line = input_file.readline().strip()
      lang_module.end_type(rest)
    elif code[0] == 'U':
      lang_module.start_union(rest)
      field_line = input_file.readline().strip()
      while field_line:
        option_code, option_type = field_line.split()
        if option_code != 'O':
          raise Error('Unknown code in union: ' + option_code)
        lang_module.union_option(option_type)
        field_line = input_file.readline().strip()
      lang_module.end_union(rest)
    line = input_file.readline()

  lang_module.end_file()
if __name__ == '__main__':
  import sys
  lang = sys.argv[1]
  filename = sys.argv[2]

  lang_module = load_lang(lang)

  print_ast(lang_module, open(filename, 'r'))
