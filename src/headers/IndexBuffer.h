#pragma once
class IndexBuffer {
 private:
  unsigned int ibId;
  unsigned int count;

 public:
  IndexBuffer(const unsigned int* indices, unsigned int count);
  ~IndexBuffer();
  void Bind() const;
  void Unbind() const;
  inline unsigned int GetCount() { return count; }
};
