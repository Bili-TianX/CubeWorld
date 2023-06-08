#include "Window.hpp"

#include "../Game.hpp"

Window::Window() {
  if (!glfwInit()) {
    SPDLOG_ERROR("Unable to init GLFW");
    throw std::exception();
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(1280, 720, "Cube World", nullptr, nullptr);

  if (!window) {
    SPDLOG_ERROR("Unable to create window");
    throw std::exception();
  }

  glfwMakeContextCurrent(window);

  glfwSetWindowCloseCallback(
      window, [](auto w) { Game::getInstance().lock()->stop(); });

  renderer = std::make_shared<Renderer>(window);
}

Window::~Window() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

std::weak_ptr<Renderer> Window::getRenderer() const { return renderer; }
