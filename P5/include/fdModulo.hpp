#pragma once

template<class Clave>
class fdModulo: public FuncionDispersion<Clave> {
  public:
    fdModulo(const unsigned n): nDatos(n){}
    unsigned operator()(const Clave& k) const {
      return k.entero % nDatos;
    }
  private:
    unsigned nDatos;
};
