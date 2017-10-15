#include "./map.h"

maze::Map::Map() {
  this->canvas = new nu::Canvas(nu::SizeF(600, 600));
  this->player = new maze::Player(maze::Pos(1, 1));
  this->mapSize = new maze::Size(49, 49);
  this->emitter = new nu::Signal<void(nu::KeyboardCode)>();

  this->initializeSelf();
  this->generateRoad();
  this->drawCanvas();

  this->emitter->Connect([this](nu::KeyboardCode k) -> void {
    this->handleKeyEvent(k);
  });
}

maze::Map::~Map() { }

void maze::Map::handleKeyEvent(const nu::KeyboardCode k) {
  const Pos pos = this->player->GetPos();
  switch (k) {
    case nu::KeyboardCode::VKEY_UP: {
      Pos nextPos = maze::Pos(pos.GetX(), pos.GetY() - 1);
      if (this->movable(nextPos)) {
        this->player->MoveTo(nextPos);
      }
      break;
    }
    case nu::KeyboardCode::VKEY_DOWN: {
      Pos nextPos = maze::Pos(pos.GetX(), pos.GetY() + 1);
      if (this->movable(nextPos)) {
        this->player->MoveTo(nextPos);
      }
      break;
    }
    case nu::KeyboardCode::VKEY_LEFT: {
      Pos nextPos = maze::Pos(pos.GetX() - 1, pos.GetY());
      if (this->movable(nextPos)) {
        this->player->MoveTo(nextPos);
      }
      break;
    }
    case nu::KeyboardCode::VKEY_RIGHT: {
      Pos nextPos = maze::Pos(pos.GetX() + 1, pos.GetY());
      if (this->movable(nextPos)) {
        this->player->MoveTo(nextPos);
      }
      break;
    }
  default:
    break;
  }
}

bool maze::Map::movable(const maze::Pos p) {
  int x = p.GetX();
  int y = p.GetY();
  if (1 < x && x < this->mapSize->GetWidth() - 1
      && 1 < y && y < this->mapSize->GetHeight() - 1) {
    return !raw[x][y]->isWall();
  }
  return false;
}

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

  // Pos pos = this->player->GetPos();
  // p->SetColor(nu::Color("#3f0"));
  // p->FillRect(nu::RectF(pos.GetX() * 11, pos.GetY() * 11, 11, 11));
}

void maze::Map::Debug() {
  for (auto line: raw) {
    for (auto block: line) {
      block->Show();
    }
    std::cout << std::endl;
  }
}
