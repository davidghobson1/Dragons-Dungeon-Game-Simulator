#include <iostream>
using namespace std;

#include "Armour.h"
#include <string>
#include "random.h"

Armour::Armour(int x, int y): Item(x, y)
{
  type = 2;
}

Armour::~Armour() {   }

char Armour::getType() const {  return type;  }

string Armour::getBoostType() const {  return boostType;  }
