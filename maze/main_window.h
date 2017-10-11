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
private:
  maze::Map* map;
  void createWindow();
};

#endif
