#include "./size.h"

maze::Size::Size() {
  this->width = 49;
  this->height = 29;
}

maze::Size::Size(int w, int h) {
  this->width = w;
  this->height = h;
}

int maze::Size::GetWidth() {
  return this->width;
}

int maze::Size::GetHeight() {
  return this->height;
}

void maze::Size::Resize(int w, int h) {
  this->width = w;
  this->height = h;
}
