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


Cell
World::getCell(int x, int y) {
  return world_[x][y];
}


Cell
World::getCell(Position position) {
  return world_[position.getX()][position.getY()];
}


void
World::Resize(const int color, const int sizeX, const int sizeY) {
  sizeX_ = sizeX;
  sizeY_ = sizeY_;
  world_.resize(sizeX);
  for (int i = 0; i < sizeX; i++) {
    world_[i].resize(sizeY);
		for (int j = 0; j < sizeY; ++j) {
			world_[i][j].setColor(color);
			world_[i][j].setPosition(i, j);
		}
    
  }
}