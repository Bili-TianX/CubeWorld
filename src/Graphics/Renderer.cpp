#include "Renderer.hpp"

Renderer::Renderer(GLFWwindow *w) : window(w) {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    SPDLOG_ERROR("Unable to load GLAD");
    throw std::exception();
  }

  glfwSetWindowSizeCallback(window, [](auto w, auto width, auto height) {
    glViewport(0, 0, width, height);
  });

  SPDLOG_INFO("OpenGL Info:\n\tRenderer: {}\n\tVersion: {}\n\tVendor: {}",
              reinterpret_cast<const char *>(glGetString(GL_RENDERER)),
              reinterpret_cast<const char *>(glGetString(GL_VERSION)),
              reinterpret_cast<const char *>(glGetString(GL_VENDOR)));

  glClearColor(0, 0, 0, 1);

  shader = std::make_unique<Shader>();
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

void Renderer::clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BITS); }

#pragma clang diagnostic pop

void Renderer::display() { glfwSwapBuffers(window); }

void Renderer::draw(std::shared_ptr<Cube> cube) {
  shader->bind();

  // TODO

  shader->unbind();
}
