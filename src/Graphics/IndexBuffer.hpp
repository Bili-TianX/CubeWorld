#pragma once

#include "BufferBase.hpp"

class IndexBuffer : public BufferBase {
 public:
  explicit IndexBuffer(const std::vector<GLuint> &indices);

  ~IndexBuffer() override;

  void bind() override;

  void unbind() override;

 private:
  unsigned int count;
};
