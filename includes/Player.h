#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Position.h"
#include "Item.h"

class Control;

/*****************************************************
 * Player Class (abstract)
Base class representing a generic player.

Players have a health attribute for their current health, a strength attribute
for the damage they inflict in battle, an armour attribute for their
defence in battle, an avatar which represents them on player board, a
position representing their current position on the board, a type attribute to
easily determine what kind of player they are (Type 1 -> Hero, Type 2-> Fighter,
Type 3 -> Dragon), and an id value to uniquely identify each player

Players support sorting including the '<' and '==' operators.
******************************************************/

class Player
{
  friend class Control;
  friend ostream& operator<<(ostream&, Player&);
  public:
    Player(int=0, int=0, int=0, char='0', int=0, int=0);
    Player(const Player&);
    ~Player();
    virtual Player& operator=(const Player&);
    virtual bool operator==(const Player&);
    virtual bool operator<(const Player&);

    static int getNextId();

    int getId() const;
    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getArmour() const;
    char getAvatar() const;
    Position& getPosition();
    char getType() const;
    int getX() const;
    int getY() const;
    bool hasDied() const;

    virtual void move(int, int, int, int) = 0;
    void collision(Player*);
    bool collectItem(Item*);

  protected:
    static int nextId;

    int id;
    string name;
    int health;
    int strength;
    int armour;
    char avatar;
    Position position;
    char type;

    int maxHealth;
    int maxStrength;
    int maxArmour;

    void setName(string);
    virtual void setHealth(int);
    virtual void setStrength(int);
    virtual void setArmour(int);
    void setAvatar(char);
    void setPosition(int, int);
    void setPosition(Position&);

    virtual void attack(Player*, int&) = 0;
};

#endif
