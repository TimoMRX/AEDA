#pragma once
#include <vector>
#include "FuncionDispersion.hpp"
#include "FuncionExploracion.hpp"
#include "Vector.hpp"

template<class Clave>
class TablaHash {
  public:
    TablaHash(unsigned datos, unsigned sinonimos, FuncionDispersion<Clave> *obj, FuncionExploracion<Clave> *objex);
    ~TablaHash() {}

    bool Buscar(const Clave& X, unsigned i) const;
    bool Insertar(const Clave& X, unsigned i);

  private:
    unsigned nDatos_;
    unsigned nSinonimos_;
    std::vector<Vector<Clave>> vDatos_;
    FuncionDispersion<Clave>* fd_;
    FuncionExploracion<Clave>* fe_;
};


template<class Clave>
TablaHash<Clave>::TablaHash(unsigned datos, unsigned sinonimos, FuncionDispersion<Clave> *obj, FuncionExploracion<Clave> *objex) {
  Vector<Clave> dummy(sinonimos);
  nDatos_ = datos;
  nSinonimos_ = sinonimos;
  fd_ = obj;
  fe_ = objex;
  vDatos_.resize(nDatos_);
  for (unsigned i = 0; i < vDatos_.size; i++)
    vDatos_[i] = dummy;
}



template<class Clave>
bool
TablaHash<Clave>::Buscar(const Clave& X, unsigned i) const {
  int j = 0;
  bool valor = true;
  if (!vDatos_.at(fd_->operator()(X)).Buscar(X)) {
    do {
      valor = vDatos_.at(fd_->operator()(X) + fe->operator(X, j) % nDatos_).Buscar(X);
      j++;
    } while ((j < i) && (valor == false));
  }
  return valor;
}


template<class Clave>
bool
TablaHash<Clave>::Insertar(const Clave& X, unsigned i) {
  int j = 0;
  bool valor = true;
  if (!Buscar(X, i).Insertar(X)) {
    do {
      valor = vDatos_.at(fd_->operator()(X) + fe->operator()(X, j) % nDatos_).Insertar(X);
      j++;
    } while ((j < i) && (valor == false));
  }
  return valor;
}