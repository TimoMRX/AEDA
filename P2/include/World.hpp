#pragma once
#include "Cell.hpp"


class World {

public:
  World(const int color = 0, const int sizeX = 75, const int sizeY = 75);
  ~World();

  int getSizeX();
  int getSizeY();
  int getCellColor(const int x, const int y);
  void setCellColor(const int color, const int x, const int y);
  void setCellColor(const int color, Position position);
  Cell getCell(Position position);

  void Resize(const int color, const int sizeX,const int sizeY);

private:
  int sizeX_, sizeY_;
  std::vector<std::vector<Cell>> world_;
};