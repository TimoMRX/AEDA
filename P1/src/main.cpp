#include <iostream>
#include "../include/Ant.hpp"

int main() {
  World *world;
  Ant ant(world);
  int index = 0;

  while (1) {
    for (int i = 0; i < world->getSizeX() - 1; i++) {
      for (int j = 0; i < world->getSizeY() - 1; j++) {
        if (world->getCell(i, j).getColor() == 0)
          std::cout << " ";
        else if (world->getCell(i, j).getColor() == 1)
          std::cout << "X";
        else if (ant.getPosition().getX() == i && ant.getPosition().getY() == j) {
          switch (index) {
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
      
    }
    
    if (world->getCell(ant.getPosition()).getColor() == 0) {
      world->getCell(ant.getPosition()).setColor(1);
      index--;
      ant.setIndex(index);
      ant.setPosition(ant.getNextPosition());
      ant.setNextPosition(index);
    }
    else if (world->getCell(ant.getPosition()).getColor() == 1) {
      world->getCell(ant.getPosition()).setColor(0);
      index++;
      ant.setIndex(index);
      ant.setPosition(ant.getNextPosition());
      ant.setNextPosition(index);
    }
  }
  
  
}