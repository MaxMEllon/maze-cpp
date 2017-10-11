#ifndef MAP
#define MAP

#include "./env.h"

namespace maze {
  class Map {
    public:
      Map();
      ~Map();
      nu::Canvas* GetCanvas();
    private:
      nu::Canvas* canvas;
  };
}

#endif
