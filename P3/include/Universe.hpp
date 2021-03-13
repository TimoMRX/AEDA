#pragma once
#include "Ant.hpp"

class Universe {

public:
  Universe();
  ~Universe();

  World* getWorld();

  void Loop();
private:
  World *world_ = new World;
  Ant ant_;
};