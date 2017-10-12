#include "./map.h"

maze::Map::Map() {
  canvas = new nu::Canvas(nu::SizeF(600, 600));
  this->initializeSelf();
  this->generateRoad();
  this->drawCanvas();
}

maze::Map::~Map() { }

nu::Canvas* maze::Map::GetCanvas() {
  return canvas;
}

void maze::Map::Debug() {
  for (auto line: raw) {
    for (auto block: line) {
      block->Show();
    }
    std::cout << std::endl;
  }
}

void maze::Map::initializeSelf() {
  for (int i = 0; i < 29; i++) {
    this->raw.push_back(std::vector<maze::Block*>());
    for (int j = 0; j < 49; j++) {
      this->raw[i].push_back(new maze::Block());
    }
  }

  for (int i = 0; i < 29; i++) {
    raw[i][0] = new Block(BlockType::WALL);
    raw[i][49 - 1] = new Block(BlockType::WALL);
    for (int j = 0; j < 49; j++) {
      raw[0][j] = new Block(BlockType::WALL);
      raw[29 - 1][j] = new Block(BlockType::WALL);
      if (i % 2 == 0 && j % 2 == 0) {
        raw[i][j]->SetType(maze::BlockType::WALL);
      }
    }
  }
  raw[1][1]->SetType(maze::BlockType::PLAYER);
}

void maze::Map::generateRoad() {
  int add[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  srand((unsigned)time(NULL));
  for (int i = 2; i < 29 - 2; i += 2) {
    for (int j = 2; j < 49 - 2; j += 2) {
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

  for (int i = 0; i < 29; i++) {
    for (int j = 0; j < 49; j++) {
      if (raw[i][j]->isWall()) {
        p->SetColor(nu::Color("#fff"));
        p->FillRect(nu::RectF(j * 11, i * 11, 11, 11));
      }
      if (raw[i][j]->isPlayer()) {
        p->SetColor(nu::Color("#2f2"));
        p->FillRect(nu::RectF(j * 11, i * 11, 11, 11));
      }
    }
  }
}

