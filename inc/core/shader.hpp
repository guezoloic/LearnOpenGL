#ifndef SHADER_HPP
#define SHADER_HPP

#include "glad/glad.h"

namespace core
{
class Shader
{
 private:
  GLuint id;  // Shader program ID

  // Attach compiled shaders (vertex & fragment) to the program and link it
  // Combines the shaders into an executable GPU program
  void attach(GLuint vert, GLuint frag);

  // Detach and delete compiled shaders from the program
  // After linking, shaders are no longer needed on the GPU
  void detach(GLuint vert, GLuint frag);

 public:
  // Constructor: takes vertex & fragment shader source code
  // Compiles shaders, links them into a program, and stores the program ID
  Shader(const char *vert, const char *frag);

  // Destructor: deletes the program from GPU memory
  ~Shader();

  // Activates the shader program for rendering
  // All subsequent draw calls will use this program
  void use() const;
};
}  // namespace core

#endif