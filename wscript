#!/usr/bin/env python

from os import popen

srcdir = '.'
blddir = 'build'
VERSION = '0.0.1'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')
  conf.env["CXXDEFINES"] = ["GL_GLEXT_PROTOTYPES"]
  conf.check_cfg(package='gl', mandatory=True, args='--cflags --libs')
  conf.check_cfg(package='glu', mandatory=True, args='--cflags --libs')

def build(bld):
  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  obj.target = "node-opengl"
  obj.source = ["src/opengl.cc"]
  obj.uselib = "GL"
  obj.uselib = "GLU"
