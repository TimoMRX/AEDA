#include "Position.hpp"

Position::Position(int x, int y) {
  setPosition(x,y);
}


void 
Position::setX(const int x) {
  x_ = x;
}


void 
Position::setY(const int y) {
  y_ = y;
}


void 
Position::setPosition(const int x, const int y) {
  x_ = x;
  y_ = y;
}


void
Position::setPosition(Position position) {
  x_ = position.getX();
  y_ = position.getY();
}


int 
Position::getX() const {
  return x_;
}


int 
Position::getY() const {
  return y_;
}


Position 
Position::getPosition() const {
  Position position(x_, y_);
  return position;
}

Position
Position::Sum(Position A, Position B) {
  int x = A.getX() + B.getX();
  int y = A.getY() + B.getY();
  return Position(x, y);
}


Position&
Position::operator +(Position B) {
  this->Sum(getPosition(), B);
  return *this;
}