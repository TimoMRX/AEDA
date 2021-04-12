#pragma once

#include "FuncionDispersion.hpp"
#include "FuncionExploracion.hpp"

template<class Clave>
class feRedispersion: public FuncionExploracion<Clave> {
  public:
    feRedispersion();
    unsigned operator()(const Clave& k, unsigned i, FuncionDispersion<Clave> *fd) const {
      return i;
    }
  private:
};
