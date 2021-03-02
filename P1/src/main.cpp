#include <iostream>
#include "../include/Ant.hpp"

int main() {
  std::cout << "Test";
  World *world = new World;
  Ant ant(world);

  std::cout << "Test";
  while (true) {
    for (int i = 0; i < world->getSizeX() - 1; i++) {
      for (int j = 0; i < world->getSizeY() - 1; j++) {
        if (world->getCell(i, j).getColor() == 0)
          std::cout << " ";

        else if (world->getCell(i, j).getColor() == 1)
          std::cout << "X";
        else if ((ant.getPosition().getX() == i) && (ant.getPosition().getY() == j)) {
          std::cout << "Test";
          switch (ant.getIndex()) {
            case 0:
              std::cout << "^";
              break;
            case 1:
              std::cout << ">";
              break;
            case 2:
              std::cout << "v";
              break;
            case 3:
              std::cout << "<";
              break;
            default:
              break;
          }
        }
      }
      std::cout << "\n";
    }
    
    if (world->getCell(ant.getPosition()).getColor() == 0) {
      world->getCell(ant.getPosition()).setColor(1);
      ant.setIndex(ant.getIndex() - 1);
    } else if (world->getCell(ant.getPosition()).getColor() == 1) {
        world->getCell(ant.getPosition()).setColor(0);
        ant.setIndex(ant.getIndex() + 1);
      }
    ant.setPosition(ant.getNextPosition());
    ant.setNextPosition(ant.getIndex());
  }
  
  
}