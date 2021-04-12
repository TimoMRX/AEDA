#include <iostream>

#include "fdModulo.hpp"
#include "fdPseudoaleatoria.hpp"
#include "feLineal.hpp"
#include "feCuadratica.hpp"
#include "feDoble.hpp"
#include "feRedispersion.hpp"
#include "TablaHash.hpp"
#include "Vector.hpp"

using Clave = int;

int main() {

  unsigned tamaño, sinonimo, imax;
  bool elecciond = 0;
  int eleccione = 0;
  FuncionDispersion<Clave>* fd;
  FuncionExploracion<Clave>* fe;
  TablaHash<Clave>* tabla;
  char opcion;
  Clave numero;

  std::cout << "¿Cual es el tamaño de la tabla?" << std::endl;
  std::cin >> tamaño;
  std::cout << "¿Cuantos sinonimos se permiten en la tabla?" << std::endl;
  std::cin >> sinonimo;
  std::cout << "Introduzca el numero maximo de iteraciones:" << std::endl;
  do {
    std::cin >> imax;
    if (imax >= tamaño)
      std::cout << "Introduzca un valor valido [0, tamaño - 1]" << std::endl;
  } while (imax >= tamaño);
  
  
  std::cout << "¿Que funcion de dispersion desea utilizar?:" << std::endl;
  std::cout << "0. Funcion Modulo" << std::endl;
  std::cout << "1. Funcion Pseudoaleatoria" << std::endl;
  std::cin >> elecciond;

  if (elecciond == false) {
    fd = new fdModulo<Clave>(tamaño);
  }
  else {
    fd = new fdPseudoaleatoria<Clave>(tamaño);
  }

  std::cout << "¿Que funcion de exploracion desea utilizar?:" << std::endl;
  std::cout << "0. Funcion Lineal" << std::endl;
  std::cout << "1. Funcion Cuadratica" << std::endl;
  std::cout << "2. Funcion Doble Dispersion" << std::endl;
  std::cout << "3. Funcion Redispersion" << std::endl;
  do {
    std::cin >> eleccione;
    switch (eleccione) {
      case 0:
        fe = new feLineal<Clave>;
        break;
      case 1:
        fe = new feCuadratica<Clave>;
        break;
      case 2:
        fe = new feDoble<Clave>(fd);
        break;
      case 3:
        // fe = new feRedispersion<Clave>();
        break;
      default:
        std::cout << "Introduzca un valor valido" << std::endl;
        break;
    }
  } while ((eleccione < 0) || (eleccione > 3));
  

  tabla = new TablaHash<Clave>(tamaño, sinonimo, fd, fe);

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
      if (tabla->Insertar(numero, imax) == true)
        std::cout << "Se ha introducido correctamente" << std::endl;
      else
        std::cout << "No se ha podido introducir" << std::endl;
      break;

    case 'b':
      std::cout << "Introduzca el número a buscar: ";
      std::cin >> numero;
      if (tabla->Buscar(numero, imax) == true)
        std::cout << "Valor encontrado" << std::endl;
      else
        std::cout << "No se ha encontrado al valor" << std::endl;
      break;

    default:
      break;
    }
  } while (opcion != 'q');
  
  
}