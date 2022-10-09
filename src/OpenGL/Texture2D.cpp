#include "Texture2D.h"
#include <glad/glad.h>

Texture2D::Texture2D() {
    glGenTextures(1, &id);
}

Texture2D::~Texture2D() {
    glDeleteTextures(GL_TEXTURE_2D, &id);
}

// Binding

void Texture2D::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture2D::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

// Parameters

void Texture2D::setParameter(glint key, glint val) {
    glTexParameteri(GL_TEXTURE_2D, key, val);
}

void Texture2D::setParameter(glint key, float val) {
    glTexParameteri(GL_TEXTURE_2D, key, val);
}

// Setup

void Texture2D::data(unsigned char* data, glint width, glint height, glint channels) {
    this->width = width;
    this->height = height;
    this->channels = channels;
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}