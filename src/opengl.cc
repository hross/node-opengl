#include "opengl.h"
#include <stdio.h>
#include <errno.h>

using namespace v8;
using namespace node;

extern "C" void
init(Handle<Object> target)
{

  NODE_SET_METHOD(target, "clear", opengl::Clear);
  NODE_SET_METHOD(target, "enable", opengl::Enable);
  NODE_SET_METHOD(target, "disable", opengl::Disable);
  NODE_SET_METHOD(target, "begin", opengl::Begin);
  NODE_SET_METHOD(target, "end", opengl::End);
  NODE_SET_METHOD(target, "matrixMode", opengl::MatrixMode);

  NODE_SET_METHOD(target, "vertex3", opengl::Vertex3);
  NODE_SET_METHOD(target, "normal3", opengl::Normal3);

  NODE_SET_METHOD(target, "light", opengl::Light);

  NODE_SET_METHOD(target, "translate", opengl::Translate);
  NODE_SET_METHOD(target, "rotate", opengl::Rotate);
  NODE_SET_METHOD(target, "ortho", opengl::Ortho);

  /* glu* Functions */
  NODE_SET_METHOD(target, "perspective", opengl::Perspective);
  NODE_SET_METHOD(target, "lookAt", opengl::LookAt);

  /* glClear Constants */
  target->Set(String::New("COLOR_BUFFER_BIT"), Integer::New(GL_COLOR_BUFFER_BIT), ReadOnly);
  target->Set(String::New("DEPTH_BUFFER_BIT"), Integer::New(GL_DEPTH_BUFFER_BIT), ReadOnly);
  target->Set(String::New("ACCUM_BUFFER_BIT"), Integer::New(GL_ACCUM_BUFFER_BIT), ReadOnly);
  target->Set(String::New("STENCIL_BUFFER_BIT"), Integer::New(GL_STENCIL_BUFFER_BIT), ReadOnly);

  /* glEnable */
  target->Set(String::New("DEPTH_TEST"), Integer::New(GL_DEPTH_TEST), ReadOnly);
  target->Set(String::New("DITHER"), Integer::New(GL_DITHER), ReadOnly);
  target->Set(String::New("LIGHTING"), Integer::New(GL_LIGHTING), ReadOnly);
  target->Set(String::New("LIGHT0"), Integer::New(GL_LIGHT0), ReadOnly);
  target->Set(String::New("LIGHT1"), Integer::New(GL_LIGHT1), ReadOnly);
  target->Set(String::New("LIGHT2"), Integer::New(GL_LIGHT2), ReadOnly);
  target->Set(String::New("LIGHT3"), Integer::New(GL_LIGHT3), ReadOnly);
  target->Set(String::New("LIGHT4"), Integer::New(GL_LIGHT4), ReadOnly);
  target->Set(String::New("LIGHT5"), Integer::New(GL_LIGHT5), ReadOnly);
  target->Set(String::New("LIGHT6"), Integer::New(GL_LIGHT6), ReadOnly);

  /* glBegin */
  target->Set(String::New("POINTS"), Integer::New(GL_POINTS), ReadOnly);
  target->Set(String::New("LINES"), Integer::New(GL_LINES), ReadOnly);
  target->Set(String::New("LINE_STRIP"), Integer::New(GL_LINE_STRIP), ReadOnly);
  target->Set(String::New("LINE_LOOP"), Integer::New(GL_LINE_LOOP), ReadOnly);
  target->Set(String::New("TRIANGLES"), Integer::New(GL_TRIANGLES), ReadOnly);
  target->Set(String::New("TRIANGLE_STRIP"), Integer::New(GL_TRIANGLE_STRIP), ReadOnly);
  target->Set(String::New("TRIANGLE_FAN"), Integer::New(GL_TRIANGLE_FAN), ReadOnly);
  target->Set(String::New("QUADS"), Integer::New(GL_QUADS), ReadOnly);
  target->Set(String::New("QUAD_STRIP"), Integer::New(GL_QUAD_STRIP), ReadOnly);
  target->Set(String::New("POLYGON"), Integer::New(GL_POLYGON), ReadOnly);

  /* glMatrixMode */
  target->Set(String::New("MODELVIEW"), Integer::New(GL_MODELVIEW), ReadOnly);
  target->Set(String::New("PROJECTION"), Integer::New(GL_PROJECTION), ReadOnly);
  target->Set(String::New("TEXTURE"), Integer::New(GL_TEXTURE), ReadOnly);
  target->Set(String::New("COLOR"), Integer::New(GL_COLOR), ReadOnly);

  /* glLight */
  target->Set(String::New("AMBIENT"), Integer::New(GL_AMBIENT), ReadOnly);
  target->Set(String::New("DIFFUSE"), Integer::New(GL_DIFFUSE), ReadOnly);
  target->Set(String::New("SPECULAR"), Integer::New(GL_SPECULAR), ReadOnly);
  target->Set(String::New("POSITION"), Integer::New(GL_POSITION), ReadOnly);
  target->Set(String::New("SPOT_DIRECTION"), Integer::New(GL_SPOT_DIRECTION), ReadOnly);
  target->Set(String::New("SPOT_EXPONENT"), Integer::New(GL_SPOT_EXPONENT), ReadOnly);
  target->Set(String::New("SPOT_CUTOFF"), Integer::New(GL_SPOT_CUTOFF), ReadOnly);
  target->Set(String::New("CONSTANT_ATTENUATION"), Integer::New(GL_CONSTANT_ATTENUATION), ReadOnly);
  target->Set(String::New("LINEAR_ATTENUATION"), Integer::New(GL_LINEAR_ATTENUATION), ReadOnly);
  target->Set(String::New("QUADRATIC_ATTENUATION"), Integer::New(GL_QUADRATIC_ATTENUATION), ReadOnly);

} 

Handle<Value> opengl::Clear(const Arguments& args) {
  HandleScope scope;

  if (!(args.Length() == 1 && args[0]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Clear(Number)")));
  }

  glClear((GLbitfield) args[0]->Int32Value());

  return Undefined();
}

Handle<Value> opengl::Enable(const Arguments& args) {
  HandleScope scope;

  if (!(args.Length() == 1 && args[0]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Enable(Number)")));
  }

  glEnable((GLenum) args[0]->Int32Value());

  return Undefined();
}

Handle<Value> opengl::Disable(const Arguments& args) {
  HandleScope scope;

  if (!(args.Length() == 1 && args[0]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Disable(Number)")));
  }

  glDisable((GLenum) args[0]->Int32Value());

  return Undefined();
}

Handle<Value> opengl::Begin(const Arguments& args) {
  HandleScope scope;

  if (!(args.Length() == 1 && args[0]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Begin(Number)")));
  }

  glBegin((GLenum) args[0]->Int32Value());

  return Undefined();
}

Handle<Value> opengl::End(const Arguments& args) {
  HandleScope scope;

  if (!(args.Length() == 0)) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected End()")));
  }

  glEnd();

  return Undefined();
}

Handle<Value> opengl::MatrixMode(const Arguments& args) {
  HandleScope scope;

  if (!(args.Length() == 1 && args[0]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected MatrixMode(Number)")));
  }

  glMatrixMode((GLenum) args[0]->Int32Value());

  return Undefined();
}

Handle<Value> opengl::Vertex3(const Arguments& args) {
  
  if (!(args.Length() == 1 && args[0]->IsArray())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Vertex3(Array)")));
  }

  // create vertex array
  Handle<Object> arr = args[0]->ToObject();
  GLdouble v[3];

  v[0] = arr->Get(String::New("0"))->NumberValue();
  v[1] = arr->Get(String::New("1"))->NumberValue();
  v[2] = arr->Get(String::New("2"))->NumberValue();

  glVertex3dv(v);

  return Undefined();
}

Handle<Value> opengl::Normal3(const Arguments& args) {
  
  if (!(args.Length() == 1 && args[0]->IsArray())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Normal3(Array)")));
  }

  // create vertex array
  Handle<Object> arr = args[0]->ToObject();
  GLdouble v[3];

  v[0] = arr->Get(String::New("0"))->NumberValue();
  v[1] = arr->Get(String::New("1"))->NumberValue();
  v[2] = arr->Get(String::New("2"))->NumberValue();

  glNormal3dv(v);

  return Undefined();
}

Handle<Value> opengl::Light(const Arguments& args) {

  if(!(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsArray())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Light(Number, Number, Array)")));
  }

  // create light array
  Handle<Object> arr = args[2]->ToObject();
  GLfloat l[3];

  l[0] = (float) arr->Get(String::New("0"))->NumberValue();
  l[1] = (float) arr->Get(String::New("1"))->NumberValue();
  l[2] = (float) arr->Get(String::New("2"))->NumberValue();

  glLightfv((GLenum) args[0]->Int32Value(), (GLenum) args[1]->Int32Value(), l);

  return Undefined();
}

Handle<Value> opengl::Translate(const Arguments& args) {

  if(!(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Translate(Number, Number, Number)")));
  }

  glTranslated((GLdouble) args[0]->NumberValue(), (GLdouble) args[1]->NumberValue(), (GLdouble) args[2]->NumberValue());

  return Undefined();
}

Handle<Value> opengl::Rotate(const Arguments& args) {

  if(!(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber() && args[3]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Rotate(Number, Number, Number, Number)")));
  }

  glRotated((GLdouble) args[0]->NumberValue(), (GLdouble) args[1]->NumberValue(), (GLdouble) args[2]->NumberValue(), (GLdouble) args[3]->NumberValue());

  return Undefined();
}

Handle<Value> opengl::Ortho(const Arguments& args) {

  if(!(args.Length() == 6 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber()
        && args[3]->IsNumber() && args[4]->IsNumber() && args[5]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Ortho(Number, Number, Number, Number, Number, Number)")));
  }

  glOrtho((GLdouble) args[0]->NumberValue(), (GLdouble) args[1]->NumberValue(), (GLdouble) args[2]->NumberValue(), (GLdouble) args[3]->NumberValue(), 
      (GLdouble) args[4]->NumberValue(), (GLdouble) args[5]->NumberValue());

  return Undefined();
}

Handle<Value> opengl::Perspective(const Arguments& args) {

  if(!(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber() && args[3]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected Perspective(Number, Number, Number, Number)")));
  }

  gluPerspective((GLdouble) args[0]->NumberValue(), (GLdouble) args[1]->NumberValue(), (GLdouble) args[2]->NumberValue(), (GLdouble) args[3]->NumberValue());

  return Undefined();
}


Handle<Value> opengl::LookAt(const Arguments& args) {

  if(!(args.Length() == 9 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber()
        && args[3]->IsNumber() && args[4]->IsNumber() && args[5]->IsNumber() && args[6]->IsNumber()
        && args[7]->IsNumber() && args[8]->IsNumber())) {
    return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected LookAt(Number, Number, Number, Number, Number, Number, Number, Number, Number)")));
  }

  gluLookAt((GLdouble) args[0]->NumberValue(), (GLdouble) args[1]->NumberValue(), (GLdouble) args[2]->NumberValue(), (GLdouble) args[3]->NumberValue(), 
      (GLdouble) args[4]->NumberValue(), (GLdouble) args[5]->NumberValue(), (GLdouble) args[6]->NumberValue(), (GLdouble) args[7]->NumberValue(), 
      (GLdouble) args[8]->NumberValue());

  return Undefined();
}



