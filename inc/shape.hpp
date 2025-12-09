#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <stddef.h>

#include <mutex>

#include "camera.hpp"
#include "glm/fwd.hpp"

class Shape
{
 protected:
  glm::vec3 position;
  Camera& cameraRef;

  virtual void init() = 0;

 public:
  Shape(Camera& cameraRef, glm::vec3 position)
      : position(position), cameraRef(cameraRef)
  {
  }

  glm::vec3 getPosition() const { return position; }
  Camera& getCamera() const { return cameraRef; }

  virtual void render() = 0;
};

#endif