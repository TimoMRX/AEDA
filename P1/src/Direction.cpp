#include "Direction.hpp"

Direction::Direction() {
  direction_.resize(4);
  
  direction_[0].setPosition(1, 0);
  direction_[1].setPosition(0, 1);
  direction_[2].setPosition(-1, 0);
  direction_[3].setPosition(0, -1);
}


Direction::~Direction() {

}


Position
Direction::getDirection(const int index) {
  return direction_[index];
}