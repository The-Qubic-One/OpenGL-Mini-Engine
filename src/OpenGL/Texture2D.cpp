#include "OpenGL/Texture2D.h"

Texture2D::Texture2D() {
  glint temp = getId();
  glGenTextures(1, &temp);
  setId(temp);
}

Texture2D::~Texture2D() {
  glint temp = getId();
  glDeleteTextures(GL_TEXTURE_2D, &temp);
  setId(temp);
}

// Binding

void Texture2D::bind() { glBindTexture(GL_TEXTURE_2D, getId()); }

void Texture2D::activateUnit(unsigned int index) {
  glActiveTexture(GL_TEXTURE0 + index);
}

void Texture2D::unbind() { glBindTexture(GL_TEXTURE_2D, 0); }

// Parameters

void Texture2D::setParameter(glint key, glint val) {
  glTexParameteri(GL_TEXTURE_2D, key, val);
}

// Setup

void Texture2D::data(unsigned char* data, glint width, glint height,
                     glint channels) {
  this->width = width;
  this->height = height;

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, channels,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
}