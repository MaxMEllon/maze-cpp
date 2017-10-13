#ifndef __MAZE__BLOCK__
#define __MAZE__BLOCK__

#include "./env.h"

namespace maze {
  enum class BlockType {
    EMPTY = 0, WALL
  };

  class Block {
  public:
    Block();
    Block(maze::BlockType type);
    ~Block();
    maze::BlockType GetType();
    void SetType(maze::BlockType type);
    bool isWall();
    void Show();
  private:
    BlockType type;
  };
}

#endif
