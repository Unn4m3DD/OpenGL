#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#pragma once

#include <unordered_map>
using namespace std;

class Shader {
 private:
  unsigned int shaderId;
  unordered_map<string, int> uniformCache;

 public:
  Shader(const string& fragmentPath, const string& vertexPath);
  ~Shader();
  void SetUniform4f(const string& name, float v0, float v1, float v2, float v3);
  int UniformGetLocation(const string& name);
  void Bind() const;
  void Unbind() const;
};