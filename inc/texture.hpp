#ifndef TEXTUTE_HPP
#define TEXTUTE_HPP

#include <GL/glew.h>
#include <string>
#include <filesystem>
#include <stb_image.h>

class Texture
{
private:
    unsigned int id;

public:
    Texture(const std::string& path);

    ~Texture();

    void bind(GLenum textureUnit) const;

    unsigned int getID() const;
};

#endif