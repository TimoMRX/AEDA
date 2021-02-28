#include "Cell.hpp"

Cell::Cell() {
  setColor(0);
}


Cell::Cell(int color) {
  setColor(color);
}


Cell::~Cell() {

}


void 
Cell::setColor(const int color) {
  color_ = color;
}


int 
Cell::getColor() const{
  return color_;
}
