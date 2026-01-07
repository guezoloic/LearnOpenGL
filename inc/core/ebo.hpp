#ifndef EBO_HPP
#define EBO_HPP

#include <cstddef>

#include "glad/glad.h"

namespace core
{
// An EBO (Element Buffer Object) is a contiguous block of GPU memory that
// stores indices for indexed drawing (used with glDrawElements). Unlike VBOs,
// the EBO binding is stored in the VAO when bound while a VAO is active.
class EBO
{
 private:
  GLuint id;  // OpenGL handle for this buffer

 public:
  // EBO constructor
  // Uploads index data into GPU memory (VRAM) using GL_ELEMENT_ARRAY_BUFFER.
  // The indices are used for indexed rendering with glDrawElements.
  EBO(const GLuint *indices, std::size_t size);

  // EBO destructor
  // Deletes the GPU buffer when the EBO object goes out of scope, freeing VRAM.
  ~EBO();

  // Binds this EBO to the GL_ELEMENT_ARRAY_BUFFER target.
  // If a VAO is bound, this binding is stored in the VAO.
  void bind();

  // Unbinds the current GL_ELEMENT_ARRAY_BUFFER by binding 0.
  // This can be useful to avoid accidental modifications to the EBO.
  static void unbind();
};
}  // namespace core

#endif  // EBO_HPP