#include "Shader.hpp"

GLuint Shader::compileShader(ShaderType type, const std::string &source) {
  GLenum value;

  if (type == ShaderType::VERTEX_SHADER) {
    value = GL_VERTEX_SHADER;
  } else if (type == ShaderType::FRAGMENT_SHADER) {
    value = GL_FRAGMENT_SHADER;
  } else {
    SPDLOG_ERROR("Unknown shader type: {:x}", static_cast<unsigned int>(type));
    throw std::exception();
  }

  auto shader = glCreateShader(value);
  const GLchar *sources[] = {source.c_str()};
  glShaderSource(shader, 1, sources, nullptr);
  glCompileShader(shader);

  int result;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    int length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    char *message = (char *)calloc(length, sizeof(char));
    glGetShaderInfoLog(shader, length, &length, message);
    SPDLOG_ERROR("Unable to compile shader: {}", message);
    free(message);
    throw std::exception();
  }

  return shader;
}

Shader::Shader() : BufferBase(glCreateProgram()) {
  auto vertex_shader =
      compileShader(ShaderType::VERTEX_SHADER, Constant::VERTEX_SHADER_SOURCE);
  auto fragment_shader = compileShader(ShaderType::FRAGMENT_SHADER,
                                       Constant::FRAGMENT_SHADER_SOURCE);

  glAttachShader(buffer, vertex_shader);
  glAttachShader(buffer, fragment_shader);

  glLinkProgram(buffer);

  int success;
  glGetProgramiv(buffer, GL_LINK_STATUS, &success);
  if (!success) {
    int length;
    glGetProgramiv(buffer, GL_INFO_LOG_LENGTH, &length);
    char *message = (char *)calloc(length, sizeof(char));
    glGetProgramInfoLog(buffer, length, &length, message);
    SPDLOG_ERROR("Unable to link program: {}", message);
    free(message);
    throw std::exception();
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

Shader::~Shader() { glDeleteProgram(buffer); }

void Shader::bind() { glUseProgram(buffer); }

void Shader::unbind() { glUseProgram(NULL); }
