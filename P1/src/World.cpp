#include "World.hpp"

World::World(const int color, const int sizeX, const int sizeY) {
  Resize(color, sizeX, sizeY);
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
World::getCellColor(int x, int y) {
  return world_[x][y].getColor();
}


Cell
World::getCell(Position position) {
  return world_[position.getX()][position.getY()];
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