#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "Potion.h"
#include <string>

/*****************************************************
 * HealthPotion Class
Derived class of Potion representing a Health Potion

HealthPotions have boostType = "health", and have a boost
value between 1 and 4
******************************************************/

class HealthPotion: public Potion
{
  public:
    HealthPotion(int=0, int=0);
    virtual ~HealthPotion();

    virtual void collect(int&, int&, int&, char);
};

#endif
