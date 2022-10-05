#include "Texture2D.h"
#include <glad/glad.h>

Texture2D::Texture2D() {
    glGenTextures(1, &id);
    wrap_s = GL_REPEAT;
    wrap_t = GL_REPEAT;
    min_filter = GL_NEAREST;
    mag_filter = GL_LINEAR;
}

Texture2D::~Texture2D() {
    glDeleteTextures(GL_TEXTURE_2D, &id);
}

void Texture2D::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture2D::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::setParameters() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);
}