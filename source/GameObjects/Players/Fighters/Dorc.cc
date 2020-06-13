#include <iostream>
using namespace std;
#include <string.h>
#include "random.h"

#include "Dorc.h"

Dorc::Dorc(int px, int py)
{
  setName("Dorc");
  setAvatar('d');
  setStrength(random(999)%3 + 6);
  setPosition(px, py);
}

Dorc::~Dorc() {   }
