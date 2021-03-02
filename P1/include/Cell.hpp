#pragma once
#include "Position.hpp"

class Cell {

public:
  Cell();
  Cell(const int color, const Position position);
  ~Cell();

  void setColor(const int color);
  void setPosition(const int x, const int y);
  int getColor() const;

private:
  int color_;
  Position position_;
};