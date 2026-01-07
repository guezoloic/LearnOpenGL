#include "core/ebo.hpp"

core::EBO::EBO(const GLuint* indices, std::size_t size)
{
  // Generate a unique OpenGL buffer handle (ID)
  glGenBuffers(1, &id);

  // Binding the EBO is mandatory before allocating GPU memory
  // This makes OpenGL know which buffer we are uploading data to
  bind();

  // Allocate GPU memory and upload index data to the buffer
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

core::EBO::~EBO()
{
  // Delete the OpenGL buffer handle and free GPU memory
  glDeleteBuffers(1, &id);
}

void core::EBO::bind()
{
  // Bind this buffer to the GL_ELEMENT_ARRAY_BUFFER target
  // OpenGL will use this buffer for indexed drawing (glDrawElements)
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void core::EBO::unbind()
{
  // Unbind any buffer from GL_ELEMENT_ARRAY_BUFFER
  // This prevents accidental modification of the previously bound EBO
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}