#ifndef P_TRIANGLE_HPP
#define P_TRIANGLE_HPP

#include <cstddef>

#include "GLFW/glfw3.h"

namespace mesh
{
// clang-format off
  constexpr GLfloat P_TRIANGLE_VERTICE[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };
// clang-format on

constexpr const std::size_t P_TRIANGLE_VERTICE_LEN =
    sizeof(P_TRIANGLE_VERTICE) / sizeof(GLfloat);

constexpr unsigned int P_TRIANGLE_INDICE[] = {
    0, 1, 2,  // 1
};

constexpr const std::size_t P_TRIANGLE_INDICE_LEN =
    sizeof(P_TRIANGLE_VERTICE) / sizeof(unsigned int);

extern "C"
{
  extern const unsigned char P_TRIANGLE_VERT[];
  extern const unsigned int P_TRIANGLE_VERT_LEN;
  extern const unsigned char P_TRIANGLE_FRAG[];
  extern const unsigned int P_TRIANGLE_FRAG_LEN;
}
}  // namespace mesh

#endif