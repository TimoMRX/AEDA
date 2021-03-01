#include "Ant.hpp"

Ant::Ant(World &world, int option) {
  assert((option == 0) | (option == 1));
  switch (option) {
    case 0: {
      std::random_device randomx;
      std::mt19937 genx(randomx());
      std::uniform_int_distribution<> distrx(0, world->getSizeX() -1);

      std::random_device randomy;
      std::mt19937 geny(randomy());
      std::uniform_int_distribution<> distry(0, world->getSizeY() -1);

      setPosition(distrx(genx), distry(geny));
      index_ = 0;
    };
      break;

    case 1:
      index_ = 0;
      setPosition(world->getSizeX()/2, world->getSizeY()/2);
      break;

    default:
      break;
  }
  
}


Ant::Ant(World &world, int x, int y) {
  setPosition(x, y);
  index_ = 0;
}


Ant::~Ant() {

}


void
Ant::setPosition(const int x, const int y) {
  position_.setPosition(x, y);
}


void 
Ant::setPosition(const Position position) {
  position_.setPosition(position);
}


void
Ant::setNextPosition(const int index) {
  next_position_.setPosition(position_ + direction_.getDirection(index % 4));
}


Position
Ant::getPosition() {
  return position_;
}


Position
Ant::getNextPosition() {
  return next_position_;
}


void
Ant::setIndex(const int index) {
  index_ = index;
}
