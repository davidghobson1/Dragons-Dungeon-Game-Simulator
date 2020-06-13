#include <iostream>
using namespace std;
#include <string>

#include "Item.h"

char Item::type = -1;

Item::Item(int x, int y): position(x,y), collected(false) {   }

Item::~Item() {   }

Item& Item::operator=(const Item& item)
{
  name = item.name;
  collected = item.collected;
  position = item.position;
  return *this;
}

bool Item::operator==(const Item& other)
{
  bool b1 = (name == other.name);
  bool b2 = (collected == other.collected);
  bool b3 = (position == other.position);
  return b1 && b2 && b3;
}

bool Item::operator<(const Item& other)
{
  if(collected == true){
    return true;
  }else if(other.collected == true){
    return false;
  }

  return name < other.name;
}

string Item::getName() const  {  return name;  }

int Item::getX() const {  return position.getX();  }

int Item::getY() const {  return position.getY();  }

Position& Item::getPosition() {  return position;  }

char Item::getType() const {  return type;  }

bool Item::hasBeenCollected() const {  return collected;  }

void Item::setCollected(bool b) { collected = b;  }

void Item::setPosition(int newX, int newY)
{
  position.setPosition(newX, newY);
}

ostream& operator<<(ostream& out, Item& item)
{
  out << item.getName() << " ";
  return out;
}
