#include "headers/IndexBuffer.h"

#define GLEW_STATIC
#include <GL/glew.h>

IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int count) {
  this->count = count;
  glGenBuffers(1, &ibId);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibId);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
  glDeleteBuffers(1, &ibId);
}

void IndexBuffer::Bind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibId);
}
void IndexBuffer::Unbind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}