#pragma once
#include "Position.hpp"

class Cell {

public:
  Cell();
  Cell(int color);
  ~Cell();

  void setColor(const int color);
  // void setPosition(Position position)
  int getColor() const;

private:
  int color_;
  Position position_;
};