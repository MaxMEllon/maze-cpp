#include "./main_window.h"

MainWindow::MainWindow() {
  map = new maze::Map();
  createWindow();
}

void MainWindow::createWindow() {
  nu::State state;
  nu::Lifetime lifetime;

  scoped_refptr<nu::Window> window(new nu::Window(nu::Window::Options()));
  window->SetContentSize(nu::SizeF(600, 600));
  window->SetContentView(Exec());
  window->Center();
  window->Activate();
  window->on_close.Connect([this](nu::Window*) {
    delete this->map;
    nu::Lifetime::GetCurrent()->Quit();
  });

  lifetime.Run();
}

nu::View* MainWindow::Exec() {
  nu::Container* container = new nu::Container();
  container->SetFocusable(true);
  container->Focus();
  container->on_draw.Connect([this](nu::Container*, nu::Painter* p, nu::RectF) -> void {
    p->DrawCanvas(this->map->GetCanvas(), nu::RectF(600, 600));
  });
  container->on_key_down.Connect([this](nu::View*, nu::KeyEvent k) -> bool {
    nu::Signal<void(nu::KeyboardCode)>* emitter = this->map->GetEmitter();
    emitter->Emit(k.key);
    return false;
  });
  return container;
}
