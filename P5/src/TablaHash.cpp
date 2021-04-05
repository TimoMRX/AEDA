#include "TablaHash.hpp"

// template<class Clave>
// TablaHash<Clave>::TablaHash(unsigned datos, FuncionDispersion<Clave> *obj) {
//   nDatos_ = datos;
//   fd_ = obj;
//   vDatos_.resize(nDatos_);
// }



// template<class Clave>
// bool
// TablaHash<Clave>::Buscar(Clave& X) const {
//   for (unsigned i = 0; i < vDatos_.size(); i++) {
//     if (X == vDatos_[i]) {
//       return true;
//     }
//   }
//   return false;
// }


// template<class Clave>
// bool
// TablaHash<Clave>::Insertar(const Clave& X) {
//   for (unsigned i = 0; i < vDatos_.size(); i++) {
//     if (X == vDatos_[i]) {
//       return false;
//     }
//   }
//   return true;
// }