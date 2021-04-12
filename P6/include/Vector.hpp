#pragma once
#include<vector>

template<class Clave>
class Vector {
  public:
    Vector(unsigned x = 0) {
      nSinonimos_ = x; 
      vDatos_.resize(nSinonimos_);
    }
    ~Vector() {}

    bool Buscar(const Clave& X) const;
    bool Insertar(const Clave& X);
    bool estaLleno() const;

  private:
    std::vector<Clave> vDatos_;
    unsigned nSinonimos_;
    unsigned num_ = 0;
};


template<class Clave>
bool
Vector<Clave>::Buscar(const Clave& X) const {
  for (unsigned i = 0; i < vDatos_.size(); i++) {
    if (X == vDatos_[i])
      return true;
  }
  return false;
}


template<class Clave>
bool
Vector<Clave>::Insertar(const Clave& X) {
  if ((Buscar(X)) || estaLleno()) {
    return false;
  }
  vDatos_.push_back(X);
  num_++;
  return true;
}


template<class Clave>
bool
Vector<Clave>::estaLleno() const {
  if (num_ == nSinonimos_) {
    return true;
  }
  return false;
}