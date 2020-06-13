#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

#include <Array2D.h>
#include <Position.h>
#include <Player.h>
#include <Item.h>

//the maximum and minimum playable dimensions for the x- and y-coordinates respectively
#define XMIN 25
#define YMIN 5
#define XMAX 60
#define YMAX 30

/*****************************************************
 * View Class
Class to provide the user-interface. This class stores and manages the display board,
provides bounds-checks for Control (since it controls the display), and prints all
messages seen during the game.
The display board is stored using the Array2D class which represents a custom 2D-array
data structure. View also stores the playable dimensions of the board, (not the same as
the dimensions of the 2D-array), and the y-coordinates of the top and bottom of the cave
entrance (the x-coordinate is assumed to be the last playable x-coordinate + 1)
******************************************************/

class View
{
  public:
    View();
    ~View();

    int getXDimension();
    int getYDimension();
    void getBoardDimensions(int&, int&);
    void getCaveLocation(int&, int&);
    void setLocation(char, int, int);
    void setLocation(char, Position&);

    void checkPositionExists(int, int);
    void checkPositionExists(Position&);

    void printBoard();
    void printRoundBanner(int);
    void printInitialRound(string, int);

    void fighterSpawned(Player*);
    void playerMoving(Player*, Position&);
    void printCollision(Player*, Player*, int, int);
    void reportDeath(Player*);
    void playerFoundItem(Player*, Item*);
    void displayUpdatedPlayerStats(Player*, int, int, int);
    void playerLeftItem(Player*);
    void printDeceased(Player*);

    void printTooManySpacesError(Player*);
    void printInvalidPositionError(Player*);

    void playerWonTheGame(Player* player);
    void gameIsLost();

    void printString(string);

    void createBoard();

    void getNumberOfHeros(int&, int);
    void getNameOfHero(string&, int);
    void displayPlayerStats(Player*);

  private:
    Array2D<char>* board;
    int xdim;
    int ydim;
    int caveLocationTop;
    int caveLocationBottom;

    void setCaveLocation(int, int);

    void askUserBoardDimensions(int&, int&);
    void initializeBoard(int, int);

    void askUserNumOfHeros(int&, int);

    void printCenter(string, char);
};

#endif
