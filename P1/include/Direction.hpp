#pragma once
#include "Position.hpp"


class Direction {

public:
  Direction();
  ~Direction();
  Position getDirection(const int index);
private:
  std::vector<Position> direction_;
};