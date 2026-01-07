#include "core/shader.hpp"

#include "core/logger.hpp"

// Compile a shader from its ID and source code
static void add(GLuint shader, const char* src)
{
  // Attach the source code to the shader object
  glShaderSource(shader, 1, &src, nullptr);

  // Compile the shader on the GPU
  glCompileShader(shader);

  // Check if the compilation was successful
  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (success) return;  // Compilation succeeded, no error

  // If compilation failed, retrieve the info log from OpenGL
  GLchar infoLog[1024];
  glGetShaderInfoLog(shader, 1024, nullptr, infoLog);

  // Log the compilation error with shader ID and info
  core::log::error(
      std::format("SHADER (ID: {}) compilation failed: {}", shader, infoLog)
          .c_str());
}

void core::Shader::attach(GLuint vert, GLuint frag)
{
  // Attach the vertex shader to the program
  glAttachShader(id, vert);

  // Attach the fragment shader to the program
  glAttachShader(id, frag);

  // Link the program (combine shaders into an executable GPU program)
  glLinkProgram(id);

  // Check if the linking was successful
  GLint success;
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (success) return;  // Linking succeeded, no error

  // If linking failed, retrieve the program info log
  GLchar infoLog[1024];
  glGetProgramInfoLog(id, 1024, nullptr, infoLog);

  // Log the linking error with program ID and info
  core::log::error(
      std::format("SHADER (ID: {}) linking failed: {}", id, infoLog).c_str());
}

void core::Shader::detach(GLuint vert, GLuint frag)
{
  // Detach the vertex shader from the program
  glDetachShader(id, vert);

  // Detach the fragment shader from the program
  glDetachShader(id, frag);

  // Delete the shader objects from GPU memory
  // After linking, shaders are no longer needed
  glDeleteShader(vert);
  glDeleteShader(frag);
}

core::Shader::Shader(const char* vert, const char* frag)
{
  // Create a vertex shader object on the GPU
  GLuint vertex = glCreateShader(GL_VERTEX_SHADER);

  // Create a fragment shader object on the GPU
  GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

  // Create a program object to combine shaders
  id = glCreateProgram();

  // Compile each shader from source
  add(vertex, vert);
  add(fragment, frag);

  // Attach compiled shaders and link the program
  attach(vertex, fragment);

  // Detach and delete shaders after linking (they are no longer needed)
  detach(vertex, fragment);
}

core::Shader::~Shader() { glDeleteProgram(id); }

void core::Shader::use() const { glUseProgram(id); }