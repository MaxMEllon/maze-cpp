#include "./pos.h"

maze::Pos::Pos() {
  this->x = 1;
  this->y = 1;
}

maze::Pos::Pos(int x, int y) {
  this->x = x;
  this->y = y;
}

int maze::Pos::Pos::GetX() const {
  return this->x;
}

int maze::Pos::Pos::GetY() const {
  return this->y;
}
