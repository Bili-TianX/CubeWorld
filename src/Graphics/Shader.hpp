#pragma once

#include "BufferBase.hpp"

enum class ShaderType : unsigned int { VERTEX_SHADER, FRAGMENT_SHADER };

class Shader final : public BufferBase {
 private:
  static GLuint compileShader(ShaderType type, const std::string &source);

 public:
  Shader();

  ~Shader() override;

  void bind() override;

  void unbind() override;
};
