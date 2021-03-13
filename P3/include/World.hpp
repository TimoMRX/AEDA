#pragma once
#include "Cell.hpp"


class World {

public:
  World(const int color = 0, const int sizeX = 5, const int sizeY = 5);
  World(const World &obj);
  ~World();

  int getSizeX();
  int getSizeY();
  int getCellColor(const int x, const int y);
  Cell getCell(const int x, const int y);
  Cell getCell(Position position);
  void setCell(const int x, const int y, Cell cell);
  void setCellColor(const int color, const int x, const int y);
  void setCellColor(const int color, Position position);

  void Resize(const int color, const int sizeX,const int sizeY);
  void ResizeUD(const int sel);
  void ResizeLR(const int sel);

private:
  int sizeX_, sizeY_;
  std::vector<std::vector<Cell>> world_;
};