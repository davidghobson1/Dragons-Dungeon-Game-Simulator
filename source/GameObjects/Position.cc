#include <iostream>
using namespace std;
#include <string>
#include <math.h>

#include "Position.h"

Position::Position(int xCoordinate, int yCoordinate): x(xCoordinate), y(yCoordinate)  {   }

Position::Position(const Position& position)
{
  x = position.x;
  y = position.y;
}

Position::~Position() {   }

Position& Position::operator=(const Position& position)
{
  x = position.x;
  y = position.y;
  return *this;
}

bool Position::operator==(const Position& other) const
{
  return (x == other.x) && (y == other.y);
}

int Position::getX() const {  return x;  }

int Position::getY() const {  return y;  }

void Position::setX(int newX)  {  x = newX;  }

void Position::setY(int newY)  {  y = newY;  }

void Position::setPosition(int newX, int newY)
{
  setX(newX);
  setY(newY);
}

//computes the Euclidean distance from one position to another
double Position::distanceFrom(Position& otherPosition)
{
  return sqrt(pow(getX()-otherPosition.getX(), 2) + pow(getY()-otherPosition.getY(), 2));
}

ostream& operator<<(ostream& out, const Position& position)
{
  out << "(" << position.getX() << ", " << position.getY() << ")";
  return out;
}
