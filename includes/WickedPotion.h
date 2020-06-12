#ifndef WICKED_POTION_H
#define WICKED_POTION_H

#include "Potion.h"
#include <string>

/*****************************************************
 * WickedPotion Class
Derived class of Potion representing a Wicked Potion.

WickedPotions have boostType = "health", and have a boost
value between -1 and -2
******************************************************/

class WickedPotion: public Potion
{
  public:
    WickedPotion(int=0, int=0);
    virtual ~WickedPotion();

    virtual void collect(int&, int&, int&, char);
};

#endif
