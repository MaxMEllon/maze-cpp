#ifndef MAP
#define MAP

#include "./env.h"

namespace maze {
  class Map {
    public:
      Map(nu::Signal<void(nu::Canvas*)> emitter);
      ~Map();
      nu::Canvas* GetCanvas();
    private:
      nu::Signal<void(nu::Canvas*)> emitter;
      nu::Canvas* canvas;
  };
}

#endif
