#pragma once

#include "Cube.hpp"
#include "Shader.hpp"

class Renderer final {
 public:
  explicit Renderer(GLFWwindow *w);

  void clear();

  void draw(std::shared_ptr<Cube> cube);

  void display();

 private:
  GLFWwindow *window;

  std::unique_ptr<Shader> shader;
};
