#ifndef HERO_H
#define HERO_H

#include "Player.h"
#include "Potion.h"
#include "Armour.h"
#include <string>

/*****************************************************
 * Hero Class
Derived class of Player representing a hero attempting to retrieve the Emerald.

Heros have Type = 1, a maximum health of 15, a max strength of 10, and a max 
armour of 6
******************************************************/

class Hero: public Player
{
  public:
    Hero(string="Hero", int=15, int=3, int=1, char='H', int=1, int=1);
    virtual ~Hero();

    virtual void move(int, int, int, int);

  private:
    virtual void setHealth(int);
    virtual void attack(Player*, int&);
    virtual void checkBounds(int&, int&, int, int, int, int);
};

#endif
