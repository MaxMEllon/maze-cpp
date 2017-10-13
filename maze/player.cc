#include "./player.h"

maze::Player::Player(maze::Pos pos) {
  this->pos = pos;
}

void maze::Player::MoveTo(maze::Pos const& pos) {
  this->pos = pos;
}

const maze::Pos maze::Player::GetPos() const {
  return this->pos;
}
