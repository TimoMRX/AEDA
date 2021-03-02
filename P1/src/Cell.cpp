#include "Cell.hpp"

Cell::Cell() {
  setColor(0);
}


Cell::Cell(const int color, const Position position) {
  setColor(color);
  position_.setPosition(position);
}


Cell::~Cell() {

}


void 
Cell::setColor(const int color) {
  color_ = color;
}


void
Cell::setPosition(const int x, const int y) {
  position_.setPosition(x, y);
}


int 
Cell::getColor() const{
  return color_;
}
