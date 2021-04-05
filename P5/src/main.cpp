#include <iostream>

#include "FuncionDispersion.hpp"
#include "fdModulo.hpp"
#include "fdPseudoaleatoria.hpp"
#include "TablaHash.hpp"
#include "Lista.hpp"


int main() {
  using Clave = int;

  unsigned tamaño;
  bool eleccion = 0;
  FuncionDispersion<Clave>* fd;
  TablaHash<Clave>* tabla;
  char opcion;
  Clave numero;

  std::cout << "¿Cual es el tamaño de la tabla?" << std::endl;
  std::cin >> tamaño;
  
  std::cout << "¿Que funcion de dispersion desea utilizar?:" << std::endl;
  std::cout << "0. Funcion Modulo" << std::endl;
  std::cout << "1. Funcion Pseudoaleatoria" << std::endl;
  std::cin >> eleccion;

  if (eleccion == false) {
    fd = new fdModulo<Clave>(tamaño);
  }
  else {
    fd = new fdPseudoaleatoria<Clave>(tamaño);
  }

  tabla = new TablaHash<Clave>(tamaño, fd);


  do {
    std::cout << "Elija una opción:" << std::endl;
    std::cout << "a. Insertar nuevo elemento" << std::endl;
    std::cout << "b. Buscar un elemento" << std::endl;
    std::cout << "q. Salir" << std::endl;
    std::cin >> opcion;

    switch (opcion) {
    case 'a':
      std::cout << "Introduzca el número a insertar: ";
      std::cin >> numero;
      if (tabla->Insertar(numero) == true)
        std::cout << "Se ha introducido correctamente" << std::endl;
      else
        std::cout << "No se ha podido introducir" << std::endl;
      break;

    case 'b':
      std::cout << "Introduzca el número a buscar: ";
      std::cin >> numero;
      if (tabla->Buscar(numero) == true)
        std::cout << "Valor encontrado" << std::endl;
      else
        std::cout << "No se ha encontrado al valor" << std::endl;
      break;

    default:
      break;
    }
  } while (opcion != 'q');
  
  
}