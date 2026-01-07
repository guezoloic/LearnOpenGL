#include "core/core.hpp"
#include "core/ebo.hpp"
#include "core/shader.hpp"
#include "primitives/p_triangle.hpp"

int main()
{
  // Game game{800, 600, "window"};
  // game.run();

  Time time{};
  int width = 800;
  int height = 600;
  const char *WINDOW_NAME = "window";

  glfwSetErrorCallback([](int error, const char *desc)
                       { core::log::error(desc, error); });

  if (glfwInit() == GLFW_FALSE)
  {
    core::log::error("Failed to initialize GLFW.");
    std::exit(EXIT_FAILURE);
  }

  // OpenGL CORE 4.1
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // window properties
  glfwWindowHint(GLFW_DEPTH_BITS, 24);   // request a 24 bits depth buffer
  glfwWindowHint(GLFW_STENCIL_BITS, 8);  // request an 8 bits stencil buffer
  glfwWindowHint(GLFW_SAMPLES, 4);       // activate MSAA (x4)

#ifdef __APPLE__  // disable deprecated functionalities on Apple devices
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  GLFWwindow *window =
      glfwCreateWindow(width, height, WINDOW_NAME, nullptr, nullptr);

  if (window == NULL)
  {
    core::log::error("Failed to create GLFW window.");
    glfwTerminate();
    std::exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    core::log::error("Failed to initialize GLAD.");
    glfwDestroyWindow(window);
    glfwTerminate();
    std::exit(EXIT_FAILURE);
  }

  glfwSwapInterval(1);  // activate vsync

  // glEnable(GL_DEPTH_TEST);
  // glEnable(GL_MULTISAMPLE);

  core::VAO vao{};
  core::VBO vbo{mesh::P_TRIANGLE_VERTICE, sizeof(mesh::P_TRIANGLE_VERTICE)};
  core::EBO ebo{mesh::P_TRIANGLE_INDICE, sizeof(mesh::P_TRIANGLE_INDICE)};
  core::Shader shader{(char *)mesh::P_TRIANGLE_VERT,
                      (char *)mesh::P_TRIANGLE_FRAG};

  vao.bind();
  vbo.bind();
  ebo.bind();

  vao.setAttributePointer(0, 3, GL_FLOAT, 3 * sizeof(GLfloat), (void *)(0));

  time.start();
  while (!glfwWindowShouldClose(window))
  {
    glfwGetFramebufferSize(window, &width, &height);
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.5f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.use();

    vao.drawElement(GL_TRIANGLES, mesh::P_TRIANGLE_INDICE_LEN, GL_UNSIGNED_INT, 0);

    glfwPollEvents();
    glfwSwapBuffers(window);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
      core::log::error("", error);
      std::exit(EXIT_FAILURE);
    }

    time.update();
  }
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}