#include "./headers/Renderer.h"

#include <iostream>
Renderer::Renderer() {
}

void Renderer::Draw(VertexBuffer& vb, IndexBuffer& ib, Shader& shader) {
  vb.Bind();
  ib.Bind();
  shader.Bind();
  glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
void Renderer::Draw(VertexBuffer& vb, IndexBuffer& ib, Shader& shader, VertexBufferLayout& vbl) {
  vb.Bind();
  vbl.Bind();
  ib.Bind();
  shader.Bind();
  glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
void Renderer::BindLayout(VertexBuffer& vb, VertexBufferLayout& vbl) {
  vb.Bind();
  vbl.Bind();
}

Renderer::~Renderer() {
}