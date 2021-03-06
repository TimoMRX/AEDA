#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>

class Position {

public:
  Position(int x, int y);
  Position() {};
  ~Position() {};

  void setX(const int x);
  void setY(const int y);
  void setPosition(const int x, const int y);
  void setPosition(Position position);

  int getX() const;
  int getY() const;
  Position getPosition() const;

  Position Sum(Position A, Position B);

  Position& operator +(Position B);

private:
  int x_, y_;
};