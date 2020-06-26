#include "headers/VertexBuffer.h"

#define GLEW_STATIC
#include <GL/glew.h>
VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
  glGenBuffers(1, &vbId);
  glBindBuffer(GL_ARRAY_BUFFER, vbId);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
  glDeleteBuffers(1, &vbId);
}

void VertexBuffer::Bind() const {
  glBindBuffer(GL_ARRAY_BUFFER, vbId);
}
void VertexBuffer::Unbind() const {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}