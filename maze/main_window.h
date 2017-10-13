#ifndef __MAZE__MAIN_WINDOW__
#define __MAZE__MAIN_WINDOW__

#include "./env.h"
#include "./map.h"
#include "./block.h"

class MainWindow
{
public:
  MainWindow();
  ~MainWindow() = default;
  MainWindow& operator=(const MainWindow& other) = default;
  nu::View* Exec();
  nu::Signal<void(nu::Canvas*)> GetEmitter();
private:
  maze::Map* map;
  void createWindow();
};

#endif
