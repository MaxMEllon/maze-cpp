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
  container->on_draw.Connect([this](nu::Container*, nu::Painter* p, const nu::RectF)
    {
      p->DrawCanvas(this->map->GetCanvas(), nu::RectF(600, 600));
    }
  );
  return container;
}
