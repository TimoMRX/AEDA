#pragma once
#include "Direction.hpp"
#include "World.hpp"
#include <random>

class Ant {

public:
  Ant(World *world, int option = 0);
  Ant(World *world, int x, int y);
  ~Ant();

  void setPosition(const int x, const int y);
  void setPosition(const Position position);
  void setNextPosition(const int index);
  void setIndex(const int index);

  Position getPosition();
  Position getNextPosition();
  int getIndex();

private:
  Position position_;
  Position next_position_;
  Direction direction_;
  int index_;
};