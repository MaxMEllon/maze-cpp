#include "./main_window.h"

MainWindow::MainWindow() { }

void MainWindow::exec() {
  // Initialize the global instance of nativeui.
  nu::State state;

  // Create GUI message loop.
  nu::Lifetime lifetime;

  // Create window with default options, and then show it.
  scoped_refptr<nu::Window> window(new nu::Window(nu::Window::Options()));
  window->SetContentSize(nu::SizeF(400, 400));
  window->Center();
  window->Activate();

  // Quit when window is closed.
  window->on_close.Connect([](nu::Window*) {
    nu::Lifetime::GetCurrent()->Quit();
  });

  // Enter message loop.
  lifetime.Run();
}
