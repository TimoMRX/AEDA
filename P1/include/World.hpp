#pragma once
#include "Cell.hpp"


class World {

public:
  World(const int sizeX = 100, const int sizeY = 100);
  ~World();

  int getSizeX();
  int getSizeY();
  Cell getCell(int x, int y);
  Cell getCell(Position position);

  void Resize(int sizeX, int sizeY);

private:
  int sizeX_, sizeY_;
  std::vector<std::vector<Cell>> world_;
};