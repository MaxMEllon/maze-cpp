#ifndef __MAZE__MAP__
#define __MAZE__MAP__

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
      bool movable(const maze::Pos);
      void initializeSelf();
      void generateRoad();
      void drawCanvas();
      void handleKeyEvent(const nu::KeyboardCode);
  };
}

#endif
