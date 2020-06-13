#include <iostream>
using namespace std;

#include "Armour.h"
#include <string>
#include "random.h"

char Armour::type = 2;

Armour::Armour(int x, int y): Item(x, y) {   }

Armour::~Armour() {   }

char Armour::getType() const {  return type;  }

string Armour::getBoostType() const {  return boostType;  }
