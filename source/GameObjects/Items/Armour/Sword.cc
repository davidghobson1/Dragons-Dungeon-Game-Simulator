#include <iostream>
using namespace std;

#include "Sword.h"
#include <string>
#include "random.h"

Sword::Sword(int x, int y): Armour(x, y)
{
  name = "Sword";
  boostType = "strength";
  boost = random(100)%4 + 1;
}

Sword::~Sword() {   }

int Sword::getBoost() const {  return boost;  }

//Sword's collect function
//a sword boosts a Hero's strength but decreases a Fighter's strength (by half)
//(logic behind that being that the fighter attacks the sword and breaks
//their own in the process)
void Sword::collect(int& health, int& strength, int& armour, char type)
{
  if(hasBeenCollected()){
    return;
  }

  if(type == 1){
    strength += getBoost();
    setCollected(true);
  }else if(type == 2){
    strength -= strength/2;
    setCollected(true);
  }
}
