#include <iostream>
using namespace std;

#include "Potion.h"
#include <string>
#include "random.h"

char Potion::type = 1;

Potion::Potion(int x, int y): Item(x, y)  {   }

Potion::~Potion() {   }

char Potion::getType() const {  return type;  }

int Potion::getBoost() const {  return boost;  }

string Potion::getBoostType() const {  return boostType;  }
