#include "./map.h"

maze::Map::Map() {
  canvas = new nu::Canvas(nu::SizeF(600, 600));
  nu::Painter* painter = canvas->GetPainter();
  painter->SetColor(nu::Color("#000"));
  painter->MoveTo(nu::PointF(0, 0));
  painter->FillRect(nu::RectF(600, 600));
}

maze::Map::~Map() { }

nu::Canvas* maze::Map::GetCanvas() {
  return canvas;
}
