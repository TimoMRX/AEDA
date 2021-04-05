#pragma once
#include <stdlib.h>

template<class Clave>
class fdPseudoaleatoria: public FuncionDispersion<Clave> {
  public:
    fdPseudoaleatoria(const unsigned n): nDatos(n){}
    unsigned operator()(const Clave& k) const {
      srand(k.entero);
      return rand() % nDatos;
    }
  private:
    unsigned nDatos;
};