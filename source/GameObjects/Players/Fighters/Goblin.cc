#include <iostream>
using namespace std;
#include <string.h>
#include "random.h"

#include "Goblin.h"

Goblin::Goblin(int px, int py)
{
  setName("Goblin");
  setAvatar('g');
  setStrength(random(1000)%4 + 8);
  setPosition(px, py);
}

Goblin::~Goblin() {   }
