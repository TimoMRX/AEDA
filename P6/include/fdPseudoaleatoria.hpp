#pragma once
#include <stdlib.h>
#include "FuncionDispersion.hpp"

template<class Clave>
class fdPseudoaleatoria: public FuncionDispersion<Clave> {
  public:
    fdPseudoaleatoria(const unsigned n): nDatos(n){}
    unsigned operator()(const Clave& k) const {
      srand(k);
      return rand() % nDatos;
    }
  private:
    unsigned nDatos;
};