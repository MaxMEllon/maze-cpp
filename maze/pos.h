#ifndef __MAZE__POS__
#define __MAZE__POS__

#include "./env.h"

namespace maze {
  class Pos {
  public:
    Pos();
    Pos(int x, int y);
    ~Pos() = default;
    Pos& operator=(maze::Pos const& Pos) = default;
    int GetX() const;
    int GetY() const;

  private:
    int x;
    int y;
  };
}

#endif
