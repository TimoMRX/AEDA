#pragma once
#include "World.hpp"


class FWorld : public World {

public:
  FWorld(const int sizeX = 5, const int sizeY = 5, const int color = 0): World(sizeX, sizeY, color) {}
  ~FWorld() {}

  void ResizeUD(const bool sel);
  void ResizeLR(const bool sel);
private:
};