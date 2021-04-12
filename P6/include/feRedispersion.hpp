#pragma once

#include <stdlib.h>
#include "FuncionDispersion.hpp"
#include "FuncionExploracion.hpp"

template<class Clave>
class feRedispersion: public FuncionExploracion<Clave> {
  public:
    unsigned operator()(const Clave& k, unsigned i, FuncionDispersion<Clave> *fd) const {
      unsigned resultado;
      srand(k);
      for (unsigned j = 0; j < i; j++) {
        resultado = rand();
      }
      return resultado;
    }
  private:
};
