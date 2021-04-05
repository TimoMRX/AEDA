#pragma once
#include <vector>
#include "FuncionDispersion.hpp"
#include "Lista.hpp"

template<class Clave>
class TablaHash {
  public:
    TablaHash(unsigned datos, FuncionDispersion<Clave> *obj);
    ~TablaHash() {}

    bool Buscar(const Clave& X) const;
    bool Insertar(const Clave& X);

  private:
    unsigned nDatos_;
    std::vector<Lista<Clave>> vDatos_;
    FuncionDispersion<Clave>* fd_;
};


template<class Clave>
TablaHash<Clave>::TablaHash(unsigned datos, FuncionDispersion<Clave> *obj) {
  nDatos_ = datos;
  fd_ = obj;
  vDatos_.resize(nDatos_);
}



template<class Clave>
bool
TablaHash<Clave>::Buscar(const Clave& X) const {
    return vDatos_.at(fd_->operator()(X)).Buscar(X);
}


template<class Clave>
bool
TablaHash<Clave>::Insertar(const Clave& X) {
  if (!Buscar(X)) {
    return vDatos_.at(fd_->operator()(X)).Insertar(X);
  }
}