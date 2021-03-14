#pragma once
#include "Direction.hpp"
#include "FWorld.hpp"
#include "IWorld.hpp"
#include <random>

class Ant {

public:
  Ant(World *world);
  Ant(World *world, int x, int y);
  Ant(World *world, Position position);
  Ant() {};
  ~Ant();

  void setPosition(const int x, const int y);
  void setPosition(const Position position);
  void setNextPosition(const int index);
  void setIndex(const int index);

  Position getPosition();
  Position getNextPosition();
  int getIndex();

  bool Write(World *world, const int i, const int j);

private:
  Position position_;
  Position next_position_;
  Direction direction_;
  int index_;

  void Refresh(World *world);
};