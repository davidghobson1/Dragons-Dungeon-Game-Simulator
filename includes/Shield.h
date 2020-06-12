#ifndef SHIELD_H
#define SHIELD_H

#include "Armour.h"
#include <string>

/*****************************************************
 * Shield Class
Derived class of Armour representing a stray shield

Shields have boostType = "armour", and have a boost
value determined randomly between 1 and 3
******************************************************/

class Shield: public Armour
{
  public:
    Shield(int=0, int=0);
    virtual ~Shield();

    virtual void collect(int&, int&, int&, char);
    int getBoost() const;
};

#endif
