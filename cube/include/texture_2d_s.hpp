#pragma once

#include <glad/glad.h>
#include <string.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class Texture
{
public:
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Texture(const char *texturePath, GLenum textureUnit = GL_TEXTURE0) : textureUnit_(textureUnit)
    {

        // load and create a texture
        glActiveTexture(textureUnit);
        // -------------------------
        glGenTextures(1, &texture_);
        glBindTexture(GL_TEXTURE_2D, texture_); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        // load image, create texture and generate mipmaps
        stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
        int width, height, nrChannels;
        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

        if (data)
        {
            unsigned int format = GetFileFormat(texturePath);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }
    ~Texture(){};
    unsigned int GetTextureUnit()
    {
        return textureUnit_ - GL_TEXTURE0;
    }
    void bindUnit()
    {
        glActiveTexture(textureUnit_);
        glBindTexture(GL_TEXTURE_2D, texture_);
    }

private:
    unsigned int GetFileFormat(const char *filePath)
    {
        char *suffix = strchr(filePath, '.');
        if (suffix == nullptr)
        {
            return ~0;
        }
        if (memcmp(suffix, ".jpg", strlen(".jpg")) == 0)
        {
            return GL_RGB;
        }
        else
        {
            return GL_RGBA;
        }
    }
    unsigned int textureUnit_;
    unsigned int texture_;
};
