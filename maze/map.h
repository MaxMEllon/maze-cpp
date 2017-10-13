#ifndef MAP
#define MAP

#include "./env.h"
#include "./block.h"
#include "./size.h"
#include "./player.h"

namespace maze {
  class Map {
    public:
      Map();
      ~Map();
      nu::Canvas* GetCanvas();
      nu::Signal<void(nu::KeyboardCode)>* GetEmitter();
      void Debug();
    private:
      std::vector<std::vector<maze::Block*>> raw;
      nu::Signal<void(nu::KeyboardCode)>* emitter;
      nu::Canvas* canvas;
      maze::Player* player;
      maze::Size* mapSize;
      void initializeSelf();
      void generateRoad();
      void drawCanvas();
  };
}

#endif
