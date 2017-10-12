#ifndef __MAZE__SIZE__
#define __MAZE__SIZE__

#include "./env.h"

namespace maze {
  class Size {
    public:
      Size();
      Size(int, int);
      ~Size();
      int GetHeight();
      int GetWidth();
      void Resize(int, int);
    private:
      int width;
      int height;
  };
}

#endif
