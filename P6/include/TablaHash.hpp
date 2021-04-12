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

    // operator=(Vector<Clave> dummy);

  private:
    unsigned nDatos_;
    unsigned nSinonimos_;
    std::vector<Vector<Clave>> vDatos_;
    FuncionDispersion<Clave>* fd_;
    FuncionExploracion<Clave>* fe_;
};


template<class Clave>
TablaHash<Clave>::TablaHash(unsigned datos, unsigned sinonimos, FuncionDispersion<Clave> *obj, FuncionExploracion<Clave> *objex) {
  nDatos_ = datos;
  nSinonimos_ = sinonimos;
  fd_ = obj;
  fe_ = objex;
  Vector<Clave> dummy(nSinonimos_);
  // vDatos_.resize(nDatos_);
  // for (unsigned i = 0; i < vDatos_.size(); i++)
  vDatos_.assign(nDatos_, dummy);
}



template<class Clave>
bool
TablaHash<Clave>::Buscar(const Clave& X, unsigned i) const {
  unsigned j = 0;
  bool valor = true;
  if (!vDatos_.at(fd_->operator()(X)).Buscar(X)) {
    do {
      valor = vDatos_.at(fd_->operator()(X) + fe_->operator()(X, j) % nDatos_).Buscar(X);
      j++;
    } while ((j < i) && (valor == false));
  }
  return valor;
}


template<class Clave>
bool
TablaHash<Clave>::Insertar(const Clave& X, unsigned i) {
  unsigned j = 0;
  bool valor = true;
  if (!Buscar(X, i)) {
    if (!vDatos_.at(fd_->operator()(X)).Insertar(X)) {
      do {
        valor = vDatos_.at(fd_->operator()(X) + fe_->operator()(X, j) % nDatos_).Insertar(X);
        j++;
      } while ((j < i) && (valor == false));
    }
  }
  return valor;
}