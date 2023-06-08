#include "VertexArray.hpp"

GLuint glGenVertexArray() {
  GLuint vao;
  glGenVertexArrays(1, &vao);
  return vao;
}

VertexArray::VertexArray() : BufferBase(glGenVertexArray()) {}

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &buffer); }

void VertexArray::bind() { glBindVertexArray(buffer); }

void VertexArray::unbind() { glBindVertexArray(NULL); }
