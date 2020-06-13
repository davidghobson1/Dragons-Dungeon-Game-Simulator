#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include "Player.h"
#include "Potion.h"
#include "Armour.h"

/*****************************************************
 * Fighter Class
Derived class of Player representing a fighter (Goblin, Orc or Dorc).
Fighters spawn from the cave and move to attack Heros, but only ever attack Heros

Fighters have: type = 2, a maximum health of 3, max strength of 15,
and a max armour of 6
******************************************************/

class Fighter: public Player
{
  public:
    Fighter();
    virtual ~Fighter();

    virtual void move(int, int, int, int);

  protected:
    static char type;

    static int maxHealth;
    static int maxStrength;
    static int maxArmour;

    virtual char getType() const;
    virtual void setHealth(int);
    virtual void setStrength(int);
    virtual void setArmour(int);

    virtual void attack(Player*, int&);
    virtual void checkBounds(int&, int&, int, int, int, int);
};

#endif
