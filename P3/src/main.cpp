#include <iostream>
#include "../include/Universe.hpp"

int main() {
  Universe universe;
  bool worldsel = 1;
  int sizeX, sizeY, antsize, posX, posY;
  std::vector<Ant> ants;
  system("clear");
  std::cout << "Bienvenido a la practica 3 de la hormiga de Langton" << std::endl;
  std::cout << "Desea un mundo Finito (0) o Infitito (1)? ";
  std::cin >> worldsel;

  std::cout << "Cual es el tamaño del mundo?" << std::endl;
  std::cout << "Numero de filas: ";
  std::cin >> sizeX;

  std::cout << "Numero de columnas: ";
  std::cin >> sizeY;

  std::cout << "Cuantas hormigas deseas y cuales son sus posiciones? ";
  std::cin >> antsize;

  ants.resize(antsize);
  for (int i = 0; i < antsize; i++) {
    std::cout << "Hormiga " << i + 1 << ":" << std::endl;
    std::cout << "Posicion X: ";
    std::cin >> posX;
    assert((posX >= 0) && (posX <= sizeX -1));
    std::cout << "Posicion Y: ";
    std::cin >> posY;
    assert((posY >= 0) && (posY <= sizeY -1));
    ants[i].setPosition(posX, posY);
  }
  universe = Universe(ants, sizeX, sizeY, worldsel);

  while (true) {
    universe.Loop();
  }
}