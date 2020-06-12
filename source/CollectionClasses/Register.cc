#include <iostream>
using namespace std;
#include <string>

#include "Register.h"

Register::Register() {   }

Register::~Register() {   }

List<Player>& Register::getPlayerList()  {  return playerList;  }

List<Item>& Register::getItemList()  {  return itemList;  }

//checks whether the Register is empty
//that is, when the Register contains no players or items
bool Register::isEmpty() const
{
  if((playerList.getSize() == 0) && (itemList.getSize() == 0)){
    return true;
  }else{
    return false;
  }
}

//adds the player to the Register
//collides the player with all other players in the Register, and allows the player
//to collect any items in the Register if they survive
void Register::newPlayer(Player* player, View& view)
{
  //collide the player with all other players in the Register
  playerCollisions(player, view);

  //allow player to collect the items in the Register if they survive
  if(!player->hasDied()){
    playerCollectsItems(player, view);
  }
}

//adds the player to the Register, however avoiding all collisions. Player still
//collects all items at the position
void Register::newPlayerIncognito(Player* player, View& view)
{
  //add player to the Register
  addPlayer(player);

  //if the player is not dead, all them to collect any items
  if(!player->hasDied()){
    playerCollectsItems(player, view);
  }
}

//collides the player with all other players in the Register
void Register::playerCollisions(Player* player, View& view)
{
  Player* otherPlayer;
  for(int i = 0; i < playerList.getSize(); i++){

    otherPlayer = playerList.get(i);

    //if the other player is already dead, skip them
    if(otherPlayer->hasDied()){
      continue;
    }

    int oldHealthThisPlayer = player->getHealth();
    int oldHealthOtherPlayer = otherPlayer->getHealth();

    //collide the players
    player->collision(otherPlayer);

    //print the outcome of the collision
    view.printCollision(player, otherPlayer, oldHealthThisPlayer, oldHealthOtherPlayer);

    //if the player already in the Register dies, they are removed, unless they are a Hero
    if(otherPlayer->hasDied()){
      view.reportDeath(otherPlayer);
      if(otherPlayer->getType() != 1){
        playerList.remove(i--);
      }
    }

    //if the player dies, add them to the Register only if they are a Hero
    if(player->hasDied()){
      view.reportDeath(player);
      if(player->getType() == 1){
        addPlayer(player);
      }
      return;
    }
  }

  //add the player to the Register if they survive all collisions
  addPlayer(player);
}

//allows player to collect any items available in the Register
void Register::playerCollectsItems(Player* player, View& view)
{
  for(int i = 0; i < itemList.getSize(); i++){
    Item* item = itemList.get(i);

    //print that the player has found an item
    view.playerFoundItem(player, item);

    int oldHealth = player->getHealth();
    int oldStrength = player->getStrength();
    int oldArmour = player->getArmour();

    //if the player collects the item, display that information, and remove the item
    //from the Register
    //if the player doesn't collect the item, display a message
    if(player->collectItem(item)){
      view.displayUpdatedPlayerStats(player, oldHealth, oldStrength, oldArmour);
      itemList.remove(i--);
    }else{
      view.playerLeftItem(player);
    }
  }
}

//adds a player to the Register
void Register::addPlayer(Player* player)
{
  playerList += player;
}

//adds an item to the Register
void Register::addItem(Item* item)
{
  itemList += item;
}

//removes the player from the Register
void Register::removePlayer(Player* player)
{
  playerList.remove(player);
}

//prints the players and items that are contained in the Register
void Register::print() const
{
  if(isEmpty()){
    return ;
  }

  playerList.print();

  itemList.print();
}
