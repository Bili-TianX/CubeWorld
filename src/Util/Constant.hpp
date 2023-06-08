#pragma once

class Constant final {
 public:
  Constant() = delete;

  ~Constant() = delete;

  const static std::string VERTEX_SHADER_SOURCE;
  const static std::string FRAGMENT_SHADER_SOURCE;
};
