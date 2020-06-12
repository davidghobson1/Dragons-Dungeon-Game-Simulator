#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include <string>

/*****************************************************
 * Potion Class (abstract)
Derived class of Item representing a generic potion

Potions have Type = 1, a "boostType" attribute indicating
what Player attribute it affects, and a "boost" attribute
indicating by how much it affects that Player's attribute
******************************************************/

class Potion: public Item
{
  public:
    Potion(int=0, int=0);
    virtual ~Potion();

    virtual void collect(int&, int&, int&, char) = 0;
    virtual int getBoost() const;
    virtual string getBoostType() const;

    virtual char getType() const;

  protected:
    int boost;
    string boostType;
};

#endif
