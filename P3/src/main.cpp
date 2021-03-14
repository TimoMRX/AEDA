#include <iostream>
#include "../include/Universe.hpp"

int main() {
  Universe universe;
  bool worldsel = 1;
  int sizeX, sizeY, antsize, posX, posY;
  std::vector<Ant> ants;

  std::cout << "Bienvenido a la practica 3 de la hormiga de Langton" << std::endl;
  std::cout << "Desea un mundo Finito (0) o Infitito (1)?";
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
    std::cout << "Hormiga " << i << ":" << std::endl;
    std::cout << "Posicion X: ";
    std::cin >> posX;
    std::cout << "Posicion Y: ";
    std::cin >> posY;
    ants[i].setPosition(posX, posY);
  }
  universe = Universe(ants, sizeX, sizeY, worldsel);
}