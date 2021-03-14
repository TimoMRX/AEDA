#pragma once
#include "Ant.hpp"
#include <list>

class Universe {

public:
  Universe(World *world, std::vector<Ant> ants, std::vector<Position> positions, const int sizeX, const int sizeY, bool sel = 1);
  ~Universe();

  World* getWorld();

  void Loop();
private:
  World *world_;
  std::vector<Ant> ants_;
  bool worldsel_;
};