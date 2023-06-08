#include "Texture.hpp"

GLuint glGenTexture() {
  GLuint texture;

  glGenTextures(1, &texture);

  return texture;
}

Texture::Texture(const std::string &path) : BufferBase(glGenTexture()) {
  stbi_set_flip_vertically_on_load(true);

  int width, height, nrChannels;
  unsigned char *data =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

  if (!data) {
    SPDLOG_ERROR("Unable to load texture: {}", path);
    throw std::exception();
  }

  if (nrChannels != 4) {
    SPDLOG_ERROR("Texture is not in RGBA format");
    throw std::exception();
  }

  SPDLOG_INFO("Texture loaded: {}", path);

  bind();
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  unbind();

  free(data);
}

Texture::~Texture() { glDeleteTextures(1, &buffer); }

void Texture::bind() { glBindTexture(GL_TEXTURE_2D, buffer); }

void Texture::unbind() { glBindTexture(GL_TEXTURE_2D, NULL); }
