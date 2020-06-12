#ifndef SWORD_H
#define SWORD_H

#include "Armour.h"
#include <string>

/*****************************************************
 * Sword Class
Derived class of Armour representing a stray sword

Swords have boostType = "strength", and have a boost
value determined randomly between 1 and 4
******************************************************/

class Sword: public Armour
{
  public:
    Sword(int=0, int=0);
    virtual ~Sword();

    virtual void collect(int&, int&, int&, char);
    int getBoost() const;
};

#endif
