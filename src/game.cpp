#include "GL/glew.h"
#include "game.hpp"
#include "GLFW/glfw3.h"
#include <iostream>


Game::Game(int width, int height, string name) : 
  width(width), 
  height(height), 
  name(name.c_str())
{
  if(glfwInit() == GLFW_FALSE)
    std::cerr << "error glfw" << std::endl;
  
  this->window = glfwCreateWindow(
    this->width,
    this->height,
    this->name, 
    nullptr, 
    nullptr
  );

  // OpenGL 3.3
  glfwWindowHint(GLFW_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_VERSION_MINOR, 3);
  
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  glfwWindowHint(GLFW_DEPTH_BITS, 24);
  glfwWindowHint(GLFW_STENCIL_BITS, 8);

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwMakeContextCurrent(this->window);

  glewInit();

  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_MULTISAMPLE);
}

void Game::run()
{

}

Game::~Game()
{
  glfwTerminate();
}