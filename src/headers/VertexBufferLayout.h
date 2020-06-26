#pragma once
#include <GL/glew.h>

#include <vector>

using namespace std;
struct VertexBufferLayoutElement {
  unsigned int count, type, normalized, pointer;
};

class VertexBufferLayout {
 private:
  bool generated;
  unsigned int vaId;
  unsigned int stride;
  vector<VertexBufferLayoutElement> elements;

 public:
  VertexBufferLayout();
  ~VertexBufferLayout();
  template <typename T>
  void Push(unsigned int count, unsigned int normalized = GL_FALSE);
  void Generate();
  void Bind() const;
  void Unbind() const;
};