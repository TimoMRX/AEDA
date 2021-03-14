#include "Ant.hpp"
#include <unistd.h>

Ant::Ant(World *world) {
  index_ = UP;
  setPosition(world->getSizeX()/2, world->getSizeY()/2);
  setNextPosition(index_);
}


Ant::Ant(World *world, int x, int y) {
  assert((x >= 0) && (y >= 0));
  assert( (x <= world->getSizeX() -1) && (y <= world->getSizeY() -1));
  index_ = UP;
  setPosition(x, y);
  setNextPosition(index_);
}


Ant::Ant(World *world, Position position) {
  assert((position.getX() >= 0) && (position.getY() >= 0));
  assert( (position.getX() <= world->getSizeX() -1) && (position.getY() <= world->getSizeY() -1));
  index_ = UP;
  setPosition(position);
  setNextPosition(index_);
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
  Position dummy;
  next_position_.setPosition(dummy.Sum(position_, direction_.getDirection(unsigned(index) % 8)));
}


Position
Ant::getPosition() {
  return position_;
}


Position
Ant::getNextPosition() {
  return next_position_;
}


int
Ant::getIndex() {
  return index_;
}


void
Ant::setIndex(const int index) {
  index_ = index;
}


bool
Ant::Write(World *world, const int i, const int j) {
  if ((getPosition().getX() == i) && (getPosition().getY() == j)) {
    switch (unsigned(getIndex()) % 8) {
      case UP:
        std::cout << "^";
        break;
      case UPRIGHT:
        std::cout << "↗";
        break;
      case RIGHT:
        std::cout << ">";
        break;
      case DOWNRIGHT:
        std::cout << "↘";
        break;
      case DOWN:
        std::cout << "v";
        break;
      case DOWNLEFT:
        std::cout << "↙";
        break;
      case LEFT:
        std::cout << "<";
        break;
      case UPLEFT:
        std::cout << "↖";
        break;
      default:
        std::cout << "Test";
        break;
    }
    return true;
  }
  else if (world->getCellColor(i, j) == 0) {
    std::cout << " ";
    return false;
  }
  else if (world->getCellColor(i, j) == 1) {
    std::cout << "X";
    return false;
  }
}


void
Ant::Refresh(World *world) {
    if (world->getCell(getPosition()).getColor() == 0) {
      setIndex(getIndex() - 1);
      world->setCellColor(1, getPosition());
    }
    else if (world->getCell(getPosition()).getColor() == 1) {
      setIndex(getIndex() + 1);
      world->setCellColor(0, getPosition());
    }
    std::cout << world->getSizeX();
    std::cout << world->getSizeY() << std::endl;
    setNextPosition(getIndex());
    setPosition(getNextPosition());
    sleep(0.9);
}