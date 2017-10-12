#include "./map.h"

maze::Map::Map() {
  this->canvas = new nu::Canvas(nu::SizeF(600, 600));
  this->mapSize = new maze::Size(29, 49);
  this->emitter = new nu::Signal<void(nu::KeyboardCode)>();
  this->initializeSelf();
  this->generateRoad();
  this->drawCanvas();
  this->emitter->Connect([](nu::KeyboardCode k) -> void {
    std::string key = nu::KeyboardCodeToStr(k);
    std::cout << key << std::endl;
  });
}

maze::Map::~Map() { }

nu::Canvas* maze::Map::GetCanvas() {
  return canvas;
}

nu::Signal<void(nu::KeyboardCode)>* maze::Map::GetEmitter() {
  return this->emitter;
}


void maze::Map::initializeSelf() {
  int width = this->mapSize->GetWidth();
  int height = this->mapSize->GetHeight();

  for (int i = 0; i < height; i++) {
    this->raw.push_back(std::vector<maze::Block*>());
    for (int j = 0; j < width; j++) {
      this->raw[i].push_back(new maze::Block());
    }
  }

  for (int i = 0; i < height; i++) {
    raw[i][0] = new Block(BlockType::WALL);
    raw[i][width - 1] = new Block(BlockType::WALL);
    for (int j = 0; j < width; j++) {
      raw[0][j] = new Block(BlockType::WALL);
      raw[height - 1][j] = new Block(BlockType::WALL);
      if (i % 2 == 0 && j % 2 == 0) {
        raw[i][j]->SetType(maze::BlockType::WALL);
      }
    }
  }
}

void maze::Map::generateRoad() {
  int add[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  srand((unsigned)time(NULL));
  for (int i = 2; i < this->mapSize->GetHeight() - 2; i += 2) {
    for (int j = 2; j < this->mapSize->GetWidth() - 2; j += 2) {
      int dir;
      do {
        dir = rand() % 4;
      } while (raw[i + add[dir][0]][j + add[dir][1]]->isWall());
      raw[i + add[dir][0]][j + add[dir][1]]->SetType(maze::BlockType::WALL);
    }
  }
}

void maze::Map::drawCanvas() {
  nu::Painter* p = this->canvas->GetPainter();
  p->MoveTo(nu::PointF(0, 0));
  p->SetColor(nu::Color("#000"));
  p->FillRect(nu::RectF(600, 600));

  for (int i = 0; i < this->mapSize->GetHeight(); i++) {
    for (int j = 0; j < this->mapSize->GetWidth(); j++) {
      if (raw[i][j]->isWall()) {
        p->SetColor(nu::Color("#fff"));
        p->FillRect(nu::RectF(i * 11, j * 11, 11, 11));
      }
    }
  }
}

void maze::Map::Debug() {
  for (auto line: raw) {
    for (auto block: line) {
      block->Show();
    }
    std::cout << std::endl;
  }
}
