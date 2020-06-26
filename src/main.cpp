#define GLFW_INCLUDE_NONE
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "headers/IndexBuffer.h"
#include "headers/Renderer.h"
#include "headers/Shader.h"
#include "headers/VertexBuffer.h"
#include "headers/VertexBufferLayout.h"
using namespace std;

static void error(GLenum source, GLenum type, GLuint id, GLenum severity,
                  GLsizei length, const GLchar* message, const void* userParam) {
  cout << (char*)message << endl;
}

int main(void) {
  GLFWwindow* window;
  if (!glfwInit())
    return -1;

  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwSwapInterval(1);
  glfwMakeContextCurrent(window);

  glewInit();
  glDebugMessageCallback(error, nullptr);
  glEnable(GL_DEBUG_OUTPUT);
  Shader shader("./src/shaders/fragment.shader",
                "./src/shaders/vertex.shader");

  float positions[8] = {
      0.0f, 0.5f,
      0.5f, 0.5f,
      0.5f, -0.5f,
      -0.5f, -0.5f};
  unsigned int indices1[6] = {0, 1, 2, 0, 2, 3};

  IndexBuffer ib(indices1, 6);

  VertexBuffer vb(positions, sizeof(float) * 8);

  VertexBufferLayout* vertexLayout = new VertexBufferLayout();
  vertexLayout->Push<float>(2);
  vertexLayout->Generate();
  Renderer renderer;
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    shader.Bind();
    shader.SetUniform4f("u_color", (float)(rand() % 100) / 100, (float)(rand() % 100) / 100, (float)(rand() % 100) / 100, (float)(rand() % 100) / 100);
    renderer.Draw(vb, ib, shader, *vertexLayout);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  vertexLayout->~VertexBufferLayout();
  glfwTerminate();
  return 0;
}