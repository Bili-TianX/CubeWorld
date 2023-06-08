#pragma once

#include "../Graphics/Renderer.hpp"

class Window final {
 public:
  Window();

  ~Window();

  [[nodiscard]] std::weak_ptr<Renderer> getRenderer() const;

 private:
  GLFWwindow *window;

  std::shared_ptr<Renderer> renderer;
};
