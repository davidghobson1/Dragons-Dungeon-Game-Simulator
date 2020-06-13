#include <iostream>
using namespace std;
#include <string.h>
#include "random.h"

#include "Orc.h"

Orc::Orc(int px, int py)
{
  setName("Orc");
  setAvatar('o');
  setStrength(random(1000)%2 + 4);
  setPosition(px, py);
}

Orc::~Orc() {   }
