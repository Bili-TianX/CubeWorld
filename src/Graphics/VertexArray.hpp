#pragma once

#include "BufferBase.hpp"

class VertexArray final : public BufferBase {
 public:
  VertexArray();

  ~VertexArray() override;
  void bind() override;
  void unbind() override;
};
