#ifndef GOBLIN_H
#define GOBLIN_H

#include <string>
#include "Fighter.h"

/*****************************************************
 * Goblin Class
Derived class of Fighter representing a Goblin
Goblins have strength generated randomly between 8 and 11
******************************************************/

class Goblin: public Fighter
{
  public:
    Goblin(int, int);
    virtual ~Goblin();
};

#endif
