#include "Direction.hpp"

Direction::Direction() {
  direction_.resize(8);
  
  direction_[UP].setPosition(-1, 0);
  direction_[UPRIGHT].setPosition(-1, 1);
  direction_[RIGHT].setPosition(0, 1);
  direction_[DOWNRIGHT].setPosition(1, 1);
  direction_[DOWN].setPosition(1, 0);
  direction_[DOWNLEFT].setPosition(1, -1);
  direction_[LEFT].setPosition(0, -1);
  direction_[UPLEFT].setPosition(-1, -1);
}


Direction::~Direction() {
}


Position
Direction::getDirection(const unsigned int index) {
  return direction_[index];
}