#pragma once
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class Renderer {
 private:
 public:
  Renderer();
  ~Renderer();
  void BindLayout(VertexBuffer& vb, VertexBufferLayout& vbl);
  void Draw(VertexBuffer& vb, IndexBuffer& ib, Shader& shader);
  void Draw(VertexBuffer& vb, IndexBuffer& ib, Shader& shader, VertexBufferLayout& vbl);
};
