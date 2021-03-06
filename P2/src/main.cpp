#include <iostream>
#include "../include/Ant.hpp"

int main() {
  // std::cout << "Test" << std::endl;
  World *world = new World;
  // std::cout << "Test" << std::endl;
  Ant ant(world, 1);
  // std::cout << "Test" << std::endl;
  while (true) {
    ant.Write(world);
  }
}