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