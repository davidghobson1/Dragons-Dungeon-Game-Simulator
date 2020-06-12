#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"
#include <string>

/*****************************************************
 * Armour Class (abstract)
Derived class of Item representing a generic piece of armour

Armour either increases a players strength or armour stat

Armour has Type = 2, a "boostType" attribute indicating
what Player attribute it affects, and a "boost" attribute
indicating by how much it affects that Player attribute
******************************************************/

class Armour: public Item
{
  public:
    Armour(int=0, int=0);
    virtual ~Armour();

    virtual void collect(int&, int&, int&, char) = 0;
    virtual int getBoost() const = 0;
    virtual string getBoostType() const;

    virtual char getType() const;

  protected:
    int boost;
    string boostType;
};

#endif
