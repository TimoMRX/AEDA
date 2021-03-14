#pragma once
#include "Position.hpp"
#define UP 0
#define UPRIGHT 1
#define RIGHT 2
#define DOWNRIGHT 3
#define DOWN 4
#define DOWNLEFT 5
#define LEFT 6
#define UPLEFT 7

class Direction {

public:
  Direction();
  ~Direction();
  Position getDirection(const unsigned int index);
private:
  std::vector<Position> direction_;
};