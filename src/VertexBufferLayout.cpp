#define GLEW_STATIC
#include "headers/VertexBufferLayout.h"

#include <GL/glew.h>

#include <iostream>
#include <typeinfo>
VertexBufferLayout::VertexBufferLayout() : stride(0) {
  glGenVertexArrays(1, &vaId);
  glBindVertexArray(vaId);
}

VertexBufferLayout::~VertexBufferLayout() {
  glDeleteVertexArrays(1, &vaId);
}

template <typename T>
void VertexBufferLayout::Push(unsigned int count, unsigned int normalized) {
  glEnableVertexAttribArray(0);
  unsigned int type =
      typeid(T) == typeid(float) ? GL_FLOAT : typeid(T) == typeid(unsigned int) ? GL_UNSIGNED_INT : 0;
  elements.push_back({count, type, normalized, stride});
  stride += sizeof(T) * count;
}
template void VertexBufferLayout::Push<float>(unsigned int count, unsigned int normalized);
template void VertexBufferLayout::Push<unsigned int>(unsigned int count, unsigned int normalized);

void VertexBufferLayout::Generate() {
  if (generated) return;
  generated = true;
  Bind();
  for (int i = 0; i < elements.size(); i++) {
    auto elem = elements[i];
    const void* ptr = (const void*)elem.pointer;
    glVertexAttribPointer(i, elem.count, elem.type, elem.normalized, stride, ptr);
  }
}

void VertexBufferLayout::Bind() const {
  glBindVertexArray(vaId);
}
void VertexBufferLayout::Unbind() const {
  glBindVertexArray(0);
}
