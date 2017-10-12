#ifndef BLOCK
#define BLOCK

#include "./env.h"

namespace maze {
  enum class BlockType {
    EMPTY = 0, WALL, PLAYER
  };

  class Block {
  public:
    Block();
    Block(maze::BlockType type);
    ~Block();
    maze::BlockType GetType();
    void SetType(maze::BlockType type);
    bool isWall();
    bool isPlayer();
    void Show();
  private:
    BlockType type;
  };
}

#endif
