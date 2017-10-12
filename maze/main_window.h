#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include "./env.h"
#include "./map.h"

class MainWindow
{
public:
  MainWindow();
  ~MainWindow() = default;
  MainWindow& operator=(const MainWindow& other) = default;
  nu::View* Exec();
  nu::Signal<void(nu::Canvas*)> GetEmitter();
private:
  nu::Signal<void(nu::Canvas*)> emitter = nu::Signal<void(nu::Canvas*)>();
  nu::Painter* painter;
  maze::Map* map;
  void createWindow();
};

#endif
