#include "World.hpp"

World::World(const int color, const int sizeX, const int sizeY) {
  Resize(color, sizeX, sizeY);
}


World::World(const World &obj) {
  sizeX_ = obj.sizeX_;
  sizeY_ = obj.sizeY_;
  world_ = obj.world_;
}


World::~World() {
}


int
World::getSizeX() {
  return sizeX_;
}


int
World::getSizeY() {
  return sizeY_;
}


int
World::getCellColor(const int x, const int y) {
  return world_[x][y].getColor();
}


void
World::setCellColor(const int color, const int x, const int y) {
  world_[x][y].setColor(color);
}


void
World::setCellColor(const int color, Position position) {
  world_[position.getX()][position.getY()].setColor(color);
}


Cell
World::getCell(const int x, const int y) {
  return world_[x][y];
}


Cell
World::getCell(Position position) {
  return world_[position.getX()][position.getY()];
}


void
World::setCell(const int x, const int y, Cell cell) {
  world_[x][y] = cell;
}


void
World::Resize(const int color, const int sizeX, const int sizeY) {
  sizeX_ = sizeX;
  sizeY_ = sizeY;
  world_.resize(sizeX);
  for (int i = 0; i < sizeX_; i++) {
    world_[i].resize(sizeY);
		for (int j = 0; j < sizeY_; j++) {
			world_[i][j].setColor(color);
			world_[i][j].setPosition(i, j);
		}
  }
}


void
World::ResizeUD(const int sel) {
  std::vector<Cell> dummy;
  dummy.resize(sizeY_);
  for (int i = 0; i < sizeY_ - 1; i++) {
    dummy[i].setColor(0);
  }

  for (int i = 0; i < 5; i++) {
    if (sel == 0)
      world_.insert(world_.begin(), dummy);
    else
      world_.push_back(dummy);
    sizeX_ ++;
  }
}


void
World::ResizeLR(const int sel) {
  Cell dummy;
  dummy.setColor(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < sizeX_; j++) {
      if (sel == 0)
        world_[j].insert(world_[j].begin(), dummy);
      else
        world_[j].push_back(dummy);
    }
      sizeY_++;
  }
}