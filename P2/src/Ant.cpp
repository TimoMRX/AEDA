#include "Ant.hpp"
#include <unistd.h>

Ant::Ant(World *world, int option) {
  assert((option == 0) || (option == 1));
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
      setNextPosition(index_);
      break;
    default:
      break;
  }
  
}


Ant::Ant(World *world, int x, int y) {
  assert((x >= 0) && (y >= 0));
  assert( (x <= world->getSizeX() -1) && (y <= world->getSizeY() -1));
  index_ = 0;
  setPosition(x, y);
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


void
Ant::Write(World *world) {
  system("clear");
  for (int i = 0; i < world->getSizeX() - 1; i++) {
      for (int j = 0; j < world->getSizeY() - 1; j++) {
        if ((getPosition().getX() == i) && (getPosition().getY() == j)) {
          switch (unsigned(getIndex()) % 8) {
            case 0:
              std::cout << "^";
              break;
            case 1:
              std::cout << "↗";
              break;
            case 2:
              std::cout << ">";
              break;
            case 3:
              std::cout << "↘";
              break;
            case 4:
              std::cout << "v";
              break;
            case 5:
              std::cout << "↙";
              break;
            case 6:
              std::cout << "<";
              break;
            case 7:
              std::cout << "↖";
              break;
            default:
              std::cout << "Test";
              break;
          }
        }
        else if (world->getCellColor(i, j) == 0) {
          std::cout << " ";
        }
        else if (world->getCellColor(i, j) == 1) {
          std::cout << "X";
        }
      }
      std::cout << std::endl;
    }
    
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