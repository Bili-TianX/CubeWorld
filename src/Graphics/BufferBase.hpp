#pragma once

class BufferBase {
 protected:
  GLuint buffer;

 public:
  explicit BufferBase(GLuint buffer);

  virtual ~BufferBase();

  [[nodiscard]] GLuint getBuffer() const;

  virtual void bind() = 0;

  virtual void unbind() = 0;
};
