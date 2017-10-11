#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include "base/command_line.h"
#include "nativeui/nativeui.h"

class MainWindow
{
public:
  MainWindow();
  ~MainWindow() = default;
  MainWindow& operator=(const MainWindow& other) = default;
  void exec();
};

#endif
