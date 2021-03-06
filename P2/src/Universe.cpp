#include "Universe.hpp"

Universe::Universe() {
  ant_ = Ant(world_, 1);
}


Universe::~Universe() {}


World*
Universe::getWorld() {
  return world_;
}


void
Universe::Loop() {
  if (ant_.getPosition().getX() == 0) {
    world_->ResizeUD(0);
    ant_.setPosition(ant_.getPosition().getX() + 5, ant_.getPosition().getY());
  }
  else if (ant_.getPosition().getY() == 0) {
    world_->ResizeLR(0);
    ant_.setPosition(ant_.getPosition().getX(), ant_.getPosition().getY() + 5);
  }
  else if (ant_.getPosition().getX() == world_->getSizeX() -1) {
    world_->ResizeUD(1);
  }
  else if (ant_.getPosition().getY() == world_->getSizeY() -1) {
    world_->ResizeLR(1);
  }
  ant_.Write(world_);
}