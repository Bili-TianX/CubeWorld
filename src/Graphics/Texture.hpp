#pragma once

#include "BufferBase.hpp"

class Texture final : public BufferBase {
 public:
  explicit Texture(const std::string &path);

  ~Texture() override;

  void bind() override;

  void unbind() override;
};
