#pragma once

#include "FuncionExploracion.hpp"

template<class Clave>
class feCuadratica: public FuncionExploracion<Clave> {
  public:
    // feCuadratica() {}
    unsigned operator()(const Clave& k, unsigned i) const {
      return i*i;
    }
  private:
};
