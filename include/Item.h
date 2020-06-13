#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Position.h"

/*****************************************************
 * Item Class (abstract)
Base class representing an item for a player to collect.

Items have a name, a position, a collected attribute indicating whether the item
has been collected or not, and a type attribute to easily disguise
different types of items (Type 1 -> Potion, Type 2 -> Armour)

Items support sorting including the '<' and '==' operators.
******************************************************/

class Item
{
  friend ostream& operator<<(ostream&, Item&);
  public:
    Item(int=0, int=0);
    virtual ~Item();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&);
    virtual bool operator<(const Item&);

    string getName() const;
    bool hasBeenCollected() const;
    virtual void collect(int&, int&, int&, char) = 0;
    virtual char getType() const;
    int getX() const;
    int getY() const;
    Position& getPosition();

  protected:
    string name;
    bool collected;
    Position position;

    static char type;

    void setPosition(int, int);
    void setCollected(bool);
};

#endif
