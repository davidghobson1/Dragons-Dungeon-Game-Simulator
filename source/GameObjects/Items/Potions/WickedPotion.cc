#include <iostream>
using namespace std;

#include "WickedPotion.h"
#include <string>
#include "random.h"

WickedPotion::WickedPotion(int x, int y): Potion(x, y)
{
  name = "Wicked Potion";
  boostType = "health";
  boost = random(100)%2 + 1;
}

WickedPotion::~WickedPotion() {   }

//Wicked Potion's collect function
//Wicked potions have a negative effect on Hero health, but a positive effect on
//Fighter health
void WickedPotion::collect(int& health, int& strength, int& armour, char type)
{
  if(hasBeenCollected() || health == 0){
    return;
  }

  if(type == 1){
    health -= getBoost();
    setCollected(true);
  }else if(type == 2){
    health += getBoost();
    setCollected(true);
  }
}
