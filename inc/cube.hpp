#ifndef CUBE_HPP
#define CUBE_HPP

#include "vbo.hpp"
#include "ebo.hpp"
#include "vao.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "camera.hpp"

class Cube
{
private:
  VBO vbo;
  EBO ebo;
  VAO vao;

  Camera &camera;
  Shader shader;
  Texture texture;

public:
  Cube(Camera &camera);
  void loop(int width, int height);
};

#endif