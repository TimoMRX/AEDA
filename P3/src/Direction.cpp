#include "Direction.hpp"

Direction::Direction() {
  direction_.resize(8);
  
  direction_[0].setPosition(-1, 0);
  direction_[1].setPosition(-1, 1);
  direction_[2].setPosition(0, 1);
  direction_[3].setPosition(1, 1);
  direction_[4].setPosition(1, 0);
  direction_[5].setPosition(1, -1);
  direction_[6].setPosition(0, -1);
  direction_[7].setPosition(-1, -1);
}


Direction::~Direction() {
}


Position
Direction::getDirection(const unsigned int index) {
  return direction_[index];
}