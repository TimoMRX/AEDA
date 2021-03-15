#include "Universe.hpp"


Universe::Universe(std::vector<Ant> ants, const int sizeX, const int sizeY, bool sel) {
  worldsel_ = sel;
  if (worldsel_ == false) {
    world_ = new FWorld(sizeX, sizeY);
  }
  else {
    world_ = new IWorld(sizeX, sizeY);
  }

  ants_.resize(ants.size());

  for (int i = 0; i < int(ants.size()); i++) {
    ants_[i] = ants[i];
  }
}




World*
Universe::getWorld() {
  return world_;
}


void
Universe::Loop() {
  int i = 0;
  do {
    if (ants_[i].getPosition().getX() == 0) {
      world_->ResizeUD(0);
      if (worldsel_ == true) {
        for (int j = 0; j < int(ants_.size()); j++) {
          ants_[j].setPosition(ants_[j].getPosition().getX() + 5, ants_[j].getPosition().getY());
        }
      }
    }

    else if (ants_[i].getPosition().getY() == 0) {
      world_->ResizeLR(0);
      if (worldsel_ == true) {
        for (int j = 0; j < int(ants_.size()); j++) {
          ants_[j].setPosition(ants_[j].getPosition().getX(), ants_[j].getPosition().getY() + 5);
        }
      }
    }

    else if (ants_[i].getPosition().getX() == world_->getSizeX() -1) {
      world_->ResizeUD(1);
    }

    else if (ants_[i].getPosition().getY() == world_->getSizeY() -1) {
      world_->ResizeLR(1);
    }

    Write(i);
  } while (i < int(ants_.size()));
}


int
Universe::Write(int antsel) {
  system("clear");
  for (int i = 0; i < world_->getSizeX() -1; i++) {
    for (int j = 0; j < world_->getSizeY() -1; j++) {
      ants_[antsel].Write(world_, i, j);
    }
    std::cout << std::endl;
  }
  ants_[antsel].Move(world_);
  return antsel++;
}