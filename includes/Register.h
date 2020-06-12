#ifndef REGISTER_H
#define REGISTER_H

#include "List.h"
#include "Player.h"
#include "Item.h"
#include "View.h"

/*****************************************************
 * Register Class
Collection Class used to store lists of all Players and Items located at the
same location
Registers handle all collisions between Players, and collections of Items by
Players when they move to a new location
******************************************************/

class Register
{
  public:
    Register();
    ~Register();

    List<Player>& getPlayerList();
    List<Item>& getItemList();
    bool isEmpty() const;

    void newPlayer(Player*, View&);
    void newPlayerIncognito(Player*, View&);
    void addItem(Item*);
    void removePlayer(Player*);

    void print() const;

  private:
    List<Player> playerList;
    List<Item> itemList;

    void playerCollisions(Player*, View&);
    void playerCollectsItems(Player*, View&);
    void addPlayer(Player*);
};

#endif
