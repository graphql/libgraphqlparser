# Copyright (c) 2015, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from casing import snake

from license import C_LICENSE_COMMENT

from ast_c import struct_name

class Printer(object):
  '''Printer for Ruby wrapper's C header.
  '''

  def __init__(self):
      pass

  def start_file(self):
    print C_LICENSE_COMMENT + '''/** @generated */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <ruby.h>

void init_graphql(void);

'''

  def end_file(self):
    print '''

#ifdef __cplusplus
}
#endif
'''

  def start_type(self, name):
    print 'struct ' + struct_name(name) + ';'
    print 'extern const rb_data_type_t %s_type;' % snake(name)
    print 'extern VALUE %s_class;' % snake(name)
    print 'extern ID visit_%s_id;' % snake(name)
    print 'extern ID end_visit_%s_id;' % snake(name)

  def field(self, type, name, nullable, plural):
    pass

  def end_type(self, name):
    print

  def start_union(self, name):
    print 'struct ' + struct_name(name) + ';'
    print 'extern const rb_data_type_t %s_type;' % snake(name)
    print 'extern VALUE %s_class;' % snake(name)

  def union_option(self, option):
    pass

  def end_union(self, name):
    print
