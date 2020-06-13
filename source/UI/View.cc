#include <iostream>
using namespace std;
#include <string>

#include "View.h"

View::View(): board(NULL), xdim(0), ydim(0), caveLocationTop(0), caveLocationBottom(0) {   }

View::~View() {  delete board;  }

int View::getXDimension() {  return xdim;  }

int View::getYDimension() {  return ydim;  }

//gets the playable dimensions of the board
void View::getBoardDimensions(int& x, int& y)
{
  x = xdim;
  y = ydim;
}

//changes the character at the specified position on the display board
void View::setLocation(char c, int x, int y)
{
  board->setElement(c, x, y);
}

//changes the character at the specified position on the display board
void View::setLocation(char c, Position& position)
{
  board->setElement(c, position.getX(), position.getY());
}

//gets the y-coordinate of the top and bottom of the cave entrance, respectively
//the cave is assumed to have an x-coordinate as the last playable x-coordinate + 1
void View::getCaveLocation(int& top, int& bottom)
{
  top = caveLocationTop;
  bottom = caveLocationBottom;
}

//sets the y-coordinate of the top and bottom of the cave entrance, respectively
//the cave is assumed to have an x-coordinate as the last playable x-coordinate + 1
void View::setCaveLocation(int top, int bottom)
{
  caveLocationTop = top;
  caveLocationBottom = bottom;
}

//checks whether the given position is playable or not
//throws an out of bounds exception if position is not playable
void View::checkPositionExists(int x, int y)
{
  if(x < 0 || y < 1 || y > ydim || x > xdim + 1){
    throw("Out of Bounds Error");
  }else if(x == (xdim + 1) && (y < caveLocationTop || y > caveLocationBottom) ){
    throw("Out of Bounds Error");
  }
}

//checks whether the given position is playable or not
//throws an out of bounds exception if position is not playable
void View::checkPositionExists(Position& position)
{
  int x, y;
  try{
    checkPositionExists(position.getX(), position.getY());
  }catch(const char* e){
    throw e;
  }
}

//prints the display board
void View::printBoard()
{
  board->print();
}

//prints the round number with centering
void View::printRoundBanner(int round)
{
  cout << endl;
  printCenter("Round #" + to_string(round), '*');
}

//print the initial display board with a given title, and including the number
//of items on the board
void View::printInitialRound(string boardName, int numOfItems)
{
  cout << endl;
  printCenter(boardName, ' ');
  board->print();
  cout << "Number of Items: " << numOfItems << endl;
}

//prints that a Fighter has spawned
void View::fighterSpawned(Player* player)
{
  if(player->getType() == 2){
    cout << "A " << player->getName() << " has spawned at position " << player->getPosition() << "!!" << endl << endl;
  }
}

//prints when a Hero is moving
void View::playerMoving(Player* player, Position& oldPosition)
{
  if(player->getType() == 1){
    cout << player->getName() << " moved from " << oldPosition << " -> " << player->getPosition() << endl;
  }
}

//prints when two players collide, and displays the change in health of the two players
void View::printCollision(Player* player, Player* otherPlayer, int oldHealthThisPlayer, int oldHealthOtherPlayer)
{
  cout << "   " << player->getName() << " collided with " << otherPlayer->getName() << "!" << endl;
  cout << "      " << player->getName() << ": Health " << oldHealthThisPlayer << " -> " << player->getHealth() << endl;
  cout << "      " << otherPlayer->getName() << ": Health " << oldHealthOtherPlayer << " -> " << otherPlayer->getHealth() << endl;
}

//prints when a player has died as a result of a collision
void View::reportDeath(Player* player)
{
  cout << "         " << player->getName() << " has died!" << endl;
}

//prints when a player has found an item
void View::playerFoundItem(Player* player, Item* item)
{
  cout << "   " << player->getName() << " found a " << item->getName() << endl;
}

//displays how a player's stats have changed as a result of collecting an item
void View::displayUpdatedPlayerStats(Player* player, int oldHealth, int oldStrength, int oldArmour)
{
  int newHealth = player->getHealth();
  int newStrength = player->getStrength();
  int newArmour = player->getArmour();
  int change;
  char sign;

  //if the item affected a player's health
  if(newHealth != oldHealth){
    change = newHealth - oldHealth;
    sign = (change > 0 ? '+' : '-');
    change = (change > 0 ? change : -change);
    cout << "      Health (" << sign << change << ") " << oldHealth << " -> " << newHealth << endl;
  }
  //if the item affected a player's strength
  if(newStrength != oldStrength){
    change = newStrength - oldStrength;
    sign = (change > 0 ? '+' : '-');
    change = (change > 0 ? change : -change);
    cout << "      Strength (" << sign << change << ") " << oldStrength << " -> " << newStrength << endl;
  }
  //if the item affected a player's armour
  if(newArmour != oldArmour){
    change = newArmour - oldArmour;
    sign = (change > 0 ? '+' : '-');
    change = (change > 0 ? change : -change);
    cout << "     Armour (" << sign << change << ") " << oldArmour << " -> " << newArmour << endl;
  }
}

//prints that a player decided not to collect an item
void View::playerLeftItem(Player* player)
{
  cout << "      " << player->getName() << " left the item " << endl;
}

//prints when a hero has died, and at what position
void View::printDeceased(Player* player)
{
  if(player->getType() == 1){
    cout << player->getName() << " is deceased at position " << player->getPosition() << endl;
  }
}

//error message
//notifies user that a player has moved too many spaces in one round
void View::printTooManySpacesError(Player* player)
{
  cout << player->getName() << " moved too many spaces... Only moving 1 space at a time is allowed.\nMoving them back..." << endl;
}

//error message
//notifies user that a player has moved to an invalid position
void View::printInvalidPositionError(Player* player)
{
  cout<< player->getName() << " has tried moving to an invalid position... Moving them back." << endl;
}

//prints an end-of-game message
//when a Hero has collected the Emerald
void View::playerWonTheGame(Player* player)
{
  cout << player->getName() + " CLAIMS THE EMERALD!!!" << endl;
}

//prints an end-of-game message
//when no Hero has collected the Emerald
void View::gameIsLost()
{
  cout << "Our heros have perished..." << endl;
}

//prints a generic message
void View::printString(string str)
{
  cout << str << endl;
}

//creates the display board
//asks the user for the board dimensions (must be at least XMIN x YMIN and at most XMAX x YMAX)
//if the user enters invalid dimensions, an error message is displayed and the user is asked
//re-enter the dimensions
//if (-1, -1) is entered, the program terminates
//initializes the display board
void View::createBoard()
{
  bool createdBoard = false;
  int x, y;

  while(!createdBoard){
    //ask the user for the board dimensions
    askUserBoardDimensions(x, y);

    //check that the board is a valid size
    if(x >= XMIN && x <= XMAX && y >= YMIN && y <= YMAX){
      //if the board size is valid, allocate the display board
      board = new Array2D<char>(x+4, y+2);
      xdim = x;
      ydim = y;

      cout << "The game board is " << xdim << " x " << ydim << "!" << endl << endl;
      createdBoard = true;
    }else if(x == -1 && y == -1){             //if user enters (-1, -1), the program terminates
      printString("Please play again soon!");
      exit(0);
    }else{                  //the user has entered an invalid board dimension, so ask again for a valid one
      string minDimensions = to_string(XMIN) + " x " + to_string(YMIN);
      string maxDimensions = to_string(XMAX) + " x " + to_string(YMAX);
      printString("Error! Dimensions must be at least " + minDimensions + " and at most " + maxDimensions);
    }
  }

  //initialize the board
  initializeBoard(xdim, ydim);
}

//asks the user for the board dimensions (must be at least XMIN x YMIN and at most XMAX x YMAX)
//provides basic error checking to ensure the user enters integer dimensions
void View::askUserBoardDimensions(int& x, int& y)
{
  cout << "Enter dimensions for the game board (Must be at least " << XMIN << " x " << YMIN << " and at most " << XMAX << " x " << YMAX << ")" << endl;
  cout << "Enter (-1, -1) to quit" << endl;
  cout << "x = ";
  while(!(cin >> x)){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Only numbers are accepted!" << endl;
  }
  cout << "y = ";
  while(!(cin >> y)){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Only numbers are accepted!" << endl;
  }
}

//retrieves the number of heros to play in the game
//the number of players must be less than the playable y-dimension and also less
//than the maximum allowable number of heros set in Control
void View::getNumberOfHeros(int& n, int maxNumOfHeros)
{
  bool numberKnown = false;
  //detemine the maximum number of heros that can be chosen
  int max = (maxNumOfHeros > ydim ? ydim : maxNumOfHeros);

  while(!numberKnown){
    //ask the user for the number of heros
    askUserNumOfHeros(n, max);

    //check that the number of heros is valid
    if(n > 0 && n <= max){
      cout << "Creating " << n << " heros!" << endl;
      numberKnown = true;
    }else if(n == -1){             //if user enters -1, the program terminates
      printString("Please play again soon!");
      exit(0);
    }else{                  //the user has entered an invalid number of heros, so ask again for a valid one
      cout << endl << "Sorry! Number of heros must be between 1 and " << max << "!" << endl;
    }
  }
}

//asks the user for the number of heros
//helper function for getNumberOfHeros
void View::askUserNumOfHeros(int& n, int max)
{
  cout << endl << "Please choose a number of heros to play." << endl;
  cout << "(Must be at least 1, and at most " << max << ". Enter -1 to quit)" << endl;
  while(!(cin >> n)){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Only numbers are accepted!" << endl;
  }
}

//asks the user to name a hero
//entering "quit" quits the program
void View::getNameOfHero(string& s, int i)
{
  cout << endl << "Please give a name for Hero " << i << ":" << endl;
  cout << "(No spaces allowed. Enter 'quit' to quit)" << endl;
  while(!(cin >> s)){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter a valid name!" << endl;
  }

  if(s == "quit"){
    printString("Please play again soon!");
    exit(0);
  }
}

//displays the stats of the new heros being created
void View::displayPlayerStats(Player* newPlayer)
{
  cout << "New Player!   Health:" << newPlayer->getHealth() << endl;
  cout << "\t      Strength:" << newPlayer->getStrength() << endl;
  cout << "\t      Armour:" << newPlayer->getArmour() << endl;
  cout << "\t      Avatar:" << newPlayer->getAvatar() << endl;
  cout << "\t      Position:" << newPlayer->getPosition() << endl;
}

//initializes the display board
void View::initializeBoard(int xdim, int ydim)
{
  for(int j = 0; j < ydim + 2; j++){
    board->setElement('|', 0, j);
  }

  for(int i = 1; i < xdim + 1; i++){
    board->setElement('-', i, 0);
    board->setElement('-', i, ydim + 1);
    for(int j = 1; j < ydim + 1; j++){
      board->setElement(' ', i, j);
    }
  }

  int middle = (ydim + 1)/2;
  for(int j = 0; j < ydim + 2; j++){
    if(j == middle || j == (middle - 1) || j == (middle + 1) ){
      board->setElement('=', xdim + 1, j);
    }else{
      board->setElement('|', xdim + 1, j);
    }
  }

  if(ydim%2 ==0){
    board->setElement('=', xdim + 1, middle + 2);
    setCaveLocation(middle -1, middle + 2);
  }else{
    setCaveLocation(middle -1, middle + 1);
  }

  for(int i = xdim + 2; i < xdim + 4; i++){
    for(int j = 0; j < ydim + 2 ; j++){
      board->setElement(' ', i, j);
    }
  }

  board->setElement('*', xdim + 3, middle);
}

//function to center messages
void View::printCenter(string s, char c)
{
  int length = (xdim - s.length())/2;
  string s2 = "";
  for(int i = 0; i < length; i++){
    s2 += c;
  }
  cout << s2 << " " << s << " " << s2 << endl;
}
