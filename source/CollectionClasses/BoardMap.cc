#include <iostream>
using namespace std;
#include <string>

#include "BoardMap.h"

BoardMap::BoardMap() {   }

BoardMap::~BoardMap() {   }

//adds an Item to the Register at the Item's position
void BoardMap::addItem(Item* item)
{
  boardMap[item->getPosition()].addItem(item);
}

//adds a Player to the Register at the Player's position, but so that no collisions
//occur (collection of items still occurs however)
void BoardMap::addPlayer(Player* player, View& view)
{
  boardMap[player->getPosition()].newPlayerIncognito(player, view);
}

//handles collisions and collections of Items that occur when a player moves
//to a new location
void BoardMap::collideAndCollect(Player* player, View& view)
{
  if(!player->hasDied()){
    boardMap[player->getPosition()].newPlayer(player, view);
  }
}

//deletes the player from its Register when the player moves to a different location
//Registers that are empty after the removal are deleted
void BoardMap::clearLocation(Player* player, Position& oldPosition)
{
  //get the Register at the old location
  Register& r = boardMap[oldPosition];

  //remove Player from the Register
  r.removePlayer(player);

  //if the Register is now empty, delete it
  if(r.isEmpty()){
    boardMap.erase(oldPosition);
  }
}
