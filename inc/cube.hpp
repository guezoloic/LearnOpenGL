#ifndef CUBE_HPP
#define CUBE_HPP

#include "camera.hpp"
#include "glm/ext/vector_float3.hpp"
#include "shape.hpp"

class Cube : public Shape
{
 public:
  Cube(Camera &camera, glm::vec3 pos, std::string texture);
  void render(int width, int height) override;
};

#endif