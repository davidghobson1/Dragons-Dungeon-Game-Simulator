#ifndef DRAGON_H
#define DRAGON_H

#include <string>
#include "Player.h"

/*****************************************************
 * Dragon Class
Derived class of Player representing the Dragon guarding the front of the cave.

Dragons have Type = 3, avatar 'D', and a maximum health, strength, and armour
of 10000

Dragons pace back and forth in front of the cave entrance, and have a direction
attribute representing the current direction they are pacing in front of the cave.
******************************************************/

class Dragon: public Player
{
  public:
    Dragon(int, int);
    Dragon(const Dragon&);
    virtual ~Dragon();
    virtual Dragon& operator=(const Dragon&);
    virtual bool operator==(const Dragon&);

    virtual void move(int, int, int, int);

  private:
    int direction;
    int caveLocation;

    int getDirection() const;
    void changeDirection();

    virtual void attack(Player*, int&);
};

#endif
