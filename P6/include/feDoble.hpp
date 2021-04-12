#pragma once

#include "FuncionDispersion.hpp"
#include "FuncionExploracion.hpp"

template<class Clave>
class feDoble: public FuncionExploracion<Clave> {
  public:
    feDoble(FuncionDispersion<Clave> *fd) {
      fd_ = fd;
    }
    unsigned operator()(const Clave& k, unsigned i) const {
      return fd_->operator()(k) * i;
    }
  private:
    FuncionDispersion<Clave> *fd_;
};
