#include "IndexBuffer.hpp"

GLuint glGenBuffer() {
  GLuint buffer;
  glGenBuffers(1, &buffer);
  return buffer;
}

IndexBuffer::IndexBuffer(const std::vector<GLuint> &indices)
    : BufferBase(glGenBuffer()), count(indices.size()) {
  bind();

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices.data(),
               GL_STATIC_DRAW);

  unbind();
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &buffer); }

void IndexBuffer::bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer); }

void IndexBuffer::unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL); }
