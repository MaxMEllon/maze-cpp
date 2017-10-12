#include "./block.h"

maze::Block::Block() {
  this->type = maze::BlockType::EMPTY;
}

maze::Block::Block(maze::BlockType type) {
  this->type = type;
}

maze::BlockType  maze::Block::GetType() {
  return this->type;
}

void maze::Block::SetType(maze::BlockType type) {
  this->type = type;
}

bool maze::Block::isWall() {
  return this->type == maze::BlockType::WALL;
}

void maze::Block::Show() {
  switch (this->type) {
    case maze::BlockType::WALL:
      std::cout << "##";
      break;
    case maze::BlockType::EMPTY:
      std::cout << "  ";
      break;
    default:
      break;
  }
}
