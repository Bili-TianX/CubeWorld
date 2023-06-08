#include "BufferBase.hpp"

BufferBase::BufferBase(GLuint buffer) : buffer(buffer) {}

BufferBase::~BufferBase() = default;

GLuint BufferBase::getBuffer() const { return buffer; }
