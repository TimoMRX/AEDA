#pragma once

template<class Clave>
class FuncionExploracion {
  public:
    virtual unsigned operator()(const Clave& k, unsigned i) const = 0;
  private:
};
