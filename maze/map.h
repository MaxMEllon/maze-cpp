#ifndef MAP
#define MAP

#include "./env.h"
#include "./block.h"

namespace maze {
  class Map {
    public:
      Map();
      ~Map();
      nu::Canvas* GetCanvas();
      void Debug();
    private:
      std::vector<std::vector<maze::Block*>> raw;
      nu::Canvas* canvas;
      void initializeSelf();
      void generateRoad();
      void drawCanvas();
  };
}

#endif
