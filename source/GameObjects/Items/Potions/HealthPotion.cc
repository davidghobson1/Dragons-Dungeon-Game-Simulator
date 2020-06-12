#include <iostream>
using namespace std;

#include "HealthPotion.h"
#include <string>
#include "random.h"

HealthPotion::HealthPotion(int x, int y): Potion(x, y)
{
  name = "Health Potion";
  boostType = "health";
  boost = random(100)%4 + 1;
}

HealthPotion::~HealthPotion() {   }

//Health potions collect function
//A health potion increases the health for a Hero, but is not used by a Fighter
void HealthPotion::collect(int& health, int& strength, int& armour, char type)
{
  if(hasBeenCollected()){
    return;
  }

  if(type == 1){
    health += getBoost();
    setCollected(true);
  }
}
