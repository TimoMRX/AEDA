#pragma once

#include "FuncionExploracion.hpp"

template<class Clave>
class feLineal: public FuncionExploracion<Clave> {
  public:
    unsigned operator()(const Clave& k, unsigned i) const {
      return i;
    }
  private:
};
