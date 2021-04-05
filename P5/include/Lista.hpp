#pragma once
#include<vector>

template<class Clave>
class Lista {
  public:
    Lista() {}
    ~Lista() {}

    bool Buscar(const Clave& X) const;
    bool Insertar(const Clave& X);

  private:
    std::vector<Clave> vDatos_;
};


template<class Clave>
bool
Lista<Clave>::Buscar(const Clave& X) const {
  for (unsigned i = 0; i < vDatos_.size(); i++) {
    if (X == vDatos_[i]) {
      return true;
    }
  }
  return false;
}


template<class Clave>
bool
Lista<Clave>::Insertar(const Clave& X) {
  if (Buscar(X)) {
    return false;
  }
  vDatos_.push_back(X);
  return true;
}