#include "IWorld.hpp"


void
IWorld::ResizeUD(const bool sel) {
  std::vector<Cell> dummy;
  dummy.resize(getSizeY());
  for (int i = 0; i < getSizeY() - 1; i++) {
    dummy[i].setColor(0);
  }

  for (int i = 0; i < 5; i++) {
    if (sel == false)
      getWorld().insert(getWorld().begin(), dummy);
    else
      getWorld().push_back(dummy);
  }
}


void
IWorld::ResizeLR(const bool sel) {
  Cell dummy;
  dummy.setColor(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < getSizeX(); j++) {
      if (sel == false)
        getWorld()[j].insert(getWorld()[j].begin(), dummy);
      else
        getWorld()[j].push_back(dummy);
    }
  }
}