#include <iostream>
using namespace std;

#include <list>
#include <iterator>

#include "Control.h"
#include "Hero.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dorc.h"
#include "HealthPotion.h"
#include "WickedPotion.h"
#include "Shield.h"
#include "Sword.h"
#include "random.h"

Control::Control(): round(0) {  }

Control::~Control()
{
  //deallocate all the players
  int size = playerList.size();
  for(int i = 0; i < size; i++){
    Player* p = NULL;
    p = playerList.front();
    playerList.pop_front();
    delete p;
  }

  //deallocate all the items
  size = itemList.size();
  for(int j = 0; j < size; j++){
    Item* i = NULL;
    i = itemList.front();
    itemList.pop_front();
    delete i;
  }
}

void Control::launch()
{
  initializeGame();
  printInitializedGame();

  while(!gameOver()){
    playRound();
    view.printBoard();
  }
}

//completes a single round moving all players in the list, and executing all collistions
//or collections of items
void Control::playRound()
{
  view.printRoundBanner(++round);

  //generate a new fighter with 60% probability and add it to the players list
  generateFighter();

  //move each player
  movePlayers();

  //clean up the round:remove fighters that have died, and items that have been used
  cleanUpTheRound();

  //update the display board
  updateDisplay();
}

//generates a random fighter with 60% probability
void Control::generateFighter()
{
  int xdim, ydim;
  view.getBoardDimensions(xdim, ydim);

  int diceRoll = random(100);

  if(diceRoll <= 60){
    //generate a random type of Fighter
    int newType = random(999)%3 + 1;
    Player* fighter;
    if(newType == 1){
      fighter = new Goblin(xdim, random(100)%ydim + 1);
    }else if (newType == 2){
      fighter = new Dorc(xdim, random(100)%ydim + 1);
    }else{
      fighter = new Orc(xdim, random(100)%ydim + 1);
    }

    //print that a Fighter has been generated
    view.fighterSpawned(fighter);

    //add the Fighter to the playerList and add them to the board
    playerList.push_back(fighter);
    board.addPlayer(fighter, view);
  }
}

//moves all the players in the player list
void Control::movePlayers()
{
  //get board dimensions and location of the cave
  int xdim, ydim, caveTop, caveBottom;
  view.getBoardDimensions(xdim, ydim);
  view.getCaveLocation(caveTop, caveBottom);

  //iterate through the players and move each one
  list<Player*>::iterator itr;
  for(itr = playerList.begin(); itr != playerList.end(); ++itr){
    movePlayer(*itr, xdim, ydim, caveTop, caveBottom);
  }
}

//moves a player
void Control::movePlayer(Player* player, int xdim, int ydim, int caveTop, int caveBottom)
{
  //if Player is dead, let them rest in peace
  if(player->hasDied()){
    view.printDeceased(player);
    return;
  }

  //move the player and make sure they are in bounds
  Position oldPosition = player->getPosition();
  player->move(xdim, ydim, caveTop, caveBottom);
  if(!checkPlayerPosition(player, oldPosition)){
    return ;
  }

  //print their move
  view.playerMoving(player, oldPosition);

  //clear the player's old position
  clearLocation(player, oldPosition);

  //update the board, and perform all necessary collisions or collections of items
  board.collideAndCollect(player, view);
}

//basic error-check to make sure moving player objects behave as required
//That is, stay in bounds, and don't move more than one square at a time
//If players violate one of these conditions, they are moved back to their
//original position
bool Control::checkPlayerPosition(Player* player, Position& oldPosition)
{
  //compare player's new position with their old position
  Position newPosition = player->getPosition();
  double distance = oldPosition.distanceFrom(newPosition);

  //make sure player moves only one square at a time
  if(distance > 1.42){
    view.printTooManySpacesError(player);
    player->setPosition(oldPosition);
  }else{        //check that player is moving to a valid position
    try{
      view.checkPositionExists(newPosition);
      return true;
    }catch(const char* errorMessage){
      view.printString(errorMessage);
      view.printInvalidPositionError(player);
      player->setPosition(oldPosition);
    }
  }
  return false;
}

//clears a player's previous location when they move
//updates the display, and removes their entry from the board
void Control::clearLocation(Player* player, Position& oldPosition)
{
  view.setLocation(' ', oldPosition);
  board.clearLocation(player, oldPosition);
}

//provides necessary cleanup after each round
//this includes removing dead Fighters from the player list,
//and removing items that have been collected from the item list
void Control::cleanUpTheRound()
{
  //deletes fighters that have died
  removeDeadFighters();

  //deletes items that have been
  removeUsedItems();
}

//removes all dead Fighters from the player list
void Control::removeDeadFighters()
{
  //sort the player list
  playerList.sort(comparePlayers);

  //iterate through and remove all dead Fighters
  list<Player*>::iterator itr;
  for(itr = playerList.begin(); itr != playerList.end(); ++itr){
    if((*itr)->getType() == 2){
      Player* deadFighter = *itr;
      playerList.erase(itr--);
      delete deadFighter;
    }else{
      break;
    }
  }
}

//removes all collected items in the item list
void Control::removeUsedItems()
{
  //sorts the item list
  itemList.sort(compareItems);

  //iterate and remove all collected items
  list<Item*>::iterator itr;
  for(itr = itemList.begin(); itr != itemList.end(); ++itr){
    if((*itr)->hasBeenCollected()){
      Item* usedItem = *itr;
      view.setLocation(' ', usedItem->getPosition());
      itemList.erase(itr--);
      delete usedItem;
    }else{
      break;
    }
  }
}

//checks whether the game is over
//that is, whether the emerald has been found, or whether all heros have died
//Note: this function assumes the list of players is in sorted order
//(however normal gameplay always ensures the list is sorted)
bool Control::gameOver()
{
  int xdim = view.getXDimension();

  bool heroAlive = false;

  //iterate through the (sorted) player list to see whether a Hero has entered the cave
  list<Player*>::iterator itr;
  itr = playerList.begin();
  while((*itr)->getType() == 1 && itr != playerList.end()){
    if((*itr)->getX() == (xdim + 1) ){          //if a Hero enters the cave, they claim the Emerald!
      view.playerWonTheGame(*itr);
      return true;
    }

    //see whether a Hero is still alive
    if(!(*itr)->hasDied()){
      heroAlive = true;
    }

    ++itr;
  }

  //if a Hero is still alive, the game continues
  //otherwise the game is over
  if(heroAlive){
    return false;
  }else{
    view.gameIsLost();
    return true;
  }
}

//updates the display board with the current positions of the players and items
void Control::updateDisplay()
{
  //update the item positions
  list<Item*>::iterator itr;
  for(itr = itemList.begin(); itr != itemList.end(); ++itr){
    view.setLocation('?', (*itr)->getPosition());
  }

  //update the player positions
  list<Player*>::iterator itr2;
  for(itr2 = playerList.begin(); itr2 != playerList.end(); ++itr2){
    view.setLocation((*itr2)->getAvatar(), (*itr2)->getPosition());
  }
}

//initializes the game, including creating the view display board, and initializing
//the player and item objects
void Control::initializeGame()
{
  //create the display board
  view.createBoard();

  int xdim, ydim;
  view.getBoardDimensions(xdim, ydim);

  //initialize the players and items
  initializePlayers(xdim, ydim);
  initializeItems(xdim, ydim);

  //update the display board
  updateDisplay();
}

//initializes the Dragon, and the heros based on user input
//users input the number of heros and the names of the heros
//the hero stats are generated randomly
void Control::initializePlayers(int xdim, int ydim)
{
  //ask user for number of heros
  int numOfHeros;
  view.getNumberOfHeros(numOfHeros, MAX_NUM_OF_HEROS);

  //get the hero names, display their stats, and add them to the list of players
  string heroName;
  for(int i = 1; i <= numOfHeros; i++){
    //get the hero's name from the user
    view.getNameOfHero(heroName, i);
    //capitalize the first letter just in case
    heroName[0] = toupper(heroName[0]);

    //create the player
    Player* newPlayer = new Hero(heroName, 15, random(5) + 1, random(6), toupper(heroName[0]), 1, random(100)%ydim + 1);

    //display the player's stats
    view.displayPlayerStats(newPlayer);

    //add the player to the list of players and to the board
    playerList.push_back(newPlayer);
    board.addPlayer(newPlayer, view);
  }

  Player* dragon = new Dragon(xdim, (ydim+1)/2);
  playerList.push_back(dragon);
  board.addPlayer(dragon, view);
}

//initializes the Items in the game (between 11 and 30 items are randomly generated)
//and places them on the board
void Control::initializeItems(int xdim, int ydim)
{
  //randomly choose a number between 11 and 30 for the number of items
  int numberOfItems = random(100)%20 + 11;
  int itemXCoordinates[numberOfItems], itemYCoordinates[numberOfItems];
  //randomly choose positions for the items
  for(int i = 0; i < numberOfItems; i++){
    itemXCoordinates[i] = random(100)%xdim + 1;
    itemYCoordinates[i] = random(100)%ydim + 1;
  }

  //place items in the chosen positions
  for(int j = 0; j < numberOfItems; j++){

    //randomly generate an Item for each position
    Item* i;
    int diceRoll = random(100);
    if(diceRoll%4 == 0){
      i = new HealthPotion(itemXCoordinates[j], itemYCoordinates[j]);
    }else if(diceRoll%4 == 1){
      i = new WickedPotion(itemXCoordinates[j], itemYCoordinates[j]);
    }else if(diceRoll%4 == 2){
      i = new Shield(itemXCoordinates[j], itemYCoordinates[j]);
    }else{
      i = new Sword(itemXCoordinates[j], itemYCoordinates[j]);
    }
    board.addItem(i);
    itemList.push_back(i);
  }
}

//prints the initial board along with the title and number of items
void Control::printInitializedGame()
{
  view.printInitialRound("Dragon's Dungeon", itemList.size());
}

//compare function to sort the list of players
bool comparePlayers(Player* player1, const Player* player2)
{
  return (*player1) < (*player2);
}

//compare function to sort the list of items
bool compareItems(Item* item1, const Item* item2)
{
  return (*item1) < (*item2);
}
