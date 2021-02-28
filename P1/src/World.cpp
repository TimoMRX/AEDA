#include "World.hpp"

World::World(const int sizeX, const int sizeY) {
  sizeX_ = sizeX;
  sizeY_ = sizeY_;
  Resize(sizeX, sizeY);
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
World::Resize(int sizeX, int sizeY) {
  world_.resize(sizeX);
  for (int i = 0; i < sizeX; i++) {
    world_[i].resize(sizeY, 0);
  }
}