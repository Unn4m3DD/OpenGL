#include "./headers/Shader.h"

#include <fstream>
#include <iostream>

static unsigned int CompileShader(const string& path, unsigned int type) {
  unsigned int id = glCreateShader(type);
  string line;
  ifstream file(path);

  string sourceString = "";
  while (getline(file, line)) {
    sourceString = sourceString + line + "\n";
  }
  const char* source = sourceString.c_str();
  glShaderSource(id, 1, &source, NULL);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  return id;
}
Shader::Shader(const string& fragPath, const string& vertexPath) {
  unsigned int fsId = CompileShader(fragPath, GL_FRAGMENT_SHADER);
  unsigned int vsId = CompileShader(vertexPath, GL_VERTEX_SHADER);

  shaderId = glCreateProgram();
  glAttachShader(shaderId, fsId);
  glAttachShader(shaderId, vsId);
  glLinkProgram(shaderId);
  glValidateProgram(shaderId);

  glDeleteShader(vsId);
  glDeleteShader(fsId);
  Bind();
}

void Shader::SetUniform4f(const string& name, float v0, float v1, float v2, float v3) {
  int location = UniformGetLocation(name);
  glUniform4f(location, v0, v1, v2, v3);
}

int Shader::UniformGetLocation(const string& name) {
  Bind();
  if (uniformCache.find(name) != uniformCache.end()) {
    return uniformCache[name];
  }

  int result = glGetUniformLocation(shaderId, name.c_str());
  if (result == -1) {
    cout << "ERROR\n"
         << name << " return -1 as location" << endl;
  }
  uniformCache[name] = result;
  return result;
}
void Shader::Bind() const {
  glUseProgram(shaderId);
}
void Shader::Unbind() const {
  glUseProgram(0);
}
Shader::~Shader() {
  glDeleteProgram(shaderId);
}
