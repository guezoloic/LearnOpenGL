#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "camera.hpp"
#include "ebo.hpp"
#include "glm/ext/vector_float3.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vao.hpp"
#include "vbo.hpp"

class Shape
{
 private:
  glm::vec3 pos;

 protected:
  Camera &camera;

  VBO vbo;
  EBO ebo;
  VAO vao;

  Shader shader;
  Texture texture;

 public:
  Shape(Camera &camera, glm::vec3 pos, Shader shader, Texture texture);

  virtual void render(int width, int height) = 0;

  glm::vec3 getPosition() const { return pos; }
  void setPosition(glm::vec3 &new_pos) { pos = new_pos; }
};

#endif