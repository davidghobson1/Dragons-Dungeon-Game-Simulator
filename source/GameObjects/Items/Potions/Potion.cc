#include <iostream>
using namespace std;

#include "Potion.h"
#include <string>
#include "random.h"

Potion::Potion(int x, int y): Item(x, y)
{
  type = 1;
}

Potion::~Potion() {   }

char Potion::getType() const {  return type;  }

int Potion::getBoost() const {  return boost;  }

string Potion::getBoostType() const {  return boostType;  }
