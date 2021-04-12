#pragma once

template<class Clave>
class feLineal: public FuncionExploracion<Clave> {
  public:
    feLineal() {}
    unsigned operator()(const Clave& k, unsigned i) const {
      return i;
    }
  private:
};
