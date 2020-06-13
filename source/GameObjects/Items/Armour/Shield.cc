#include <iostream>
using namespace std;

#include "Shield.h"
#include <string>
#include "random.h"

Shield::Shield(int x, int y): Armour(x, y)
{
  name = "Shield";
  boostType = "armour";
  boost = random(99)%3 + 1;
}

Shield::~Shield() {   }

int Shield::getBoost() const {  return boost;  }

//A shield's collect function
//A shield boosts the armour for both Heros and Fighters
void Shield::collect(int& health, int& strength, int& armour, char type)
{
  if(hasBeenCollected()){
    return;
  }

  if(type == 1 || type == 2){
    armour += getBoost();
    setCollected(true);
  }
}
