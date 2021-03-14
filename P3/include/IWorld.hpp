#pragma once
#include "World.hpp"

class IWorld : public World {

public:
  IWorld(const int sizeX = 5, const int sizeY = 5, const int color = 0): World(sizeX, sizeY, color) {}
  ~IWorld() {}

  void ResizeUD(const bool sel);
  void ResizeLR(const bool sel);

private:
};