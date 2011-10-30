#ifndef NODE_OPENGL_H_
#define NODE_OPENGL_H_

#include <node.h>
#include <v8.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace v8;

namespace opengl {

  static Handle<Value> Clear(const Arguments& args);
  static Handle<Value> Enable(const Arguments& args);
  static Handle<Value> Disable(const Arguments& args);
  static Handle<Value> Begin(const Arguments& args);
  static Handle<Value> End(const Arguments& args);
  static Handle<Value> MatrixMode(const Arguments& args);

  static Handle<Value> Vertex3(const Arguments& args);
  static Handle<Value> Normal3(const Arguments& args);

  static Handle<Value> Light(const Arguments& args);

  static Handle<Value> Translate(const Arguments& args);
  static Handle<Value> Rotate(const Arguments& args);
  static Handle<Value> Ortho(const Arguments& args);

  static Handle<Value> Perspective(const Arguments& args);
  static Handle<Value> LookAt(const Arguments& args);
}

#endif
