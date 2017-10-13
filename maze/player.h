#ifndef __MAZE__PLAYER__
#define __MAZE__PLAYER__

#include "./env.h"
#include "./pos.h"

namespace maze {
  class Player {
  public:
    Player(maze::Pos pos);
    Player& operator=(maze::Player const& Player) = default;
    ~Player();
    void MoveTo(maze::Pos const& pos);
    const maze::Pos GetPos() const;
  private:
    maze::Pos pos;
  };
}

#endif
