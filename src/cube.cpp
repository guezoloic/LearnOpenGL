#include "cube.hpp"

#include "ebo.hpp"
#include "render/primitives/cube.hpp"
#include "vao.hpp"
#include "vbo.hpp"

Cube::Cube(Camera &camera, glm::vec3 pos, std::string texture)
    : Shape(camera, pos, Shader{}, Texture{texture})
{
  this->vao.bind();
  this->vbo.bind();
  this->ebo.bind();

  this->vbo.setData(VERTICE, sizeof(VERTICE));
  this->ebo.setData(INDICE, sizeof(INDICE));

  this->shader.compile((const char *)__res_render_primitives_cube_vert,
                       (const char *)__res_render_primitives_cube_frag);
}

void Cube::render(int width, int height) {}
// Cube::Cube(Camera& camera)
//     : vbo(cubeVertices, sizeof(cubeVertices)),
//       ebo(cubeIndices, sizeof(cubeIndices)),
//       texture("stone.png"),
//       camera(camera),
//       shader(cubeVertexShader, cubeFragShader)
// {
//   vao.bind();
//   vbo.bind();

//   GLsizei stride = 8 * sizeof(float);

//   vao.setAttributePointer(0, 3, GL_FLOAT, stride, (void*)0);
//   vao.setAttributePointer(1, 3, GL_FLOAT, stride, (void*)(3 *
//   sizeof(float))); vao.setAttributePointer(2, 2, GL_FLOAT, stride, (void*)(6
//   * sizeof(float)));

//   ebo.bind();
// }

// void Cube::loop(int width, int height)
// {
//   shader.use();
//   glActiveTexture(GL_TEXTURE0);

//   glm::vec3 coordinate = glm::vec3(0.0f, 0.0f, -1.0f);
//   glm::mat4 projection = glm::perspective(
//       glm::radians(camera.fov),
//       static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);

//   GLint texLoc = glGetUniformLocation(shader.getProgram(),
//   "material.diffuse"); glUniform1i(texLoc, 0);

//   GLint projectionLoc = glGetUniformLocation(shader.getProgram(),
//   "projection"); glUniformMatrix4fv(projectionLoc, 1, GL_FALSE,
//   glm::value_ptr(projection));

//   GLint viewLoc = glGetUniformLocation(shader.getProgram(), "view");
//   glUniformMatrix4fv(viewLoc, 1, GL_FALSE,
//                      glm::value_ptr(camera.getViewMatrix()));

//   glm::mat4 model = glm::translate(glm::mat4(1.0f), coordinate);
//   GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
//   glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

//   vao.drawElement(GL_TRIANGLES, sizeof(cubeIndices) / sizeof(unsigned int),
//                   GL_UNSIGNED_INT, 0);
// }