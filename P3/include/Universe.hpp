#pragma once
#include "Ant.hpp"
#include <list>

class Universe {

public:
  Universe() {}
  Universe(std::vector<Ant> ants, const int sizeX, const int sizeY, bool sel = 1);
  ~Universe() {}

  World* getWorld();

  void Loop();
  int Write(int antsel);
private:
  World *world_;
  std::vector<Ant> ants_;
  bool worldsel_;
};