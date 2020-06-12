#ifndef CONTROL_H
#define CONTROL_H

#include <list>
#include "Player.h"
#include "Item.h"
#include "View.h"
#include "BoardMap.h"

/*****************************************************
 * Control Class
Simulates the rounds and manages the interactions of the Players and Items, as the heros seek
to claim the Emerald from the mighty Dragon.
Maintains a list of the current Players, a list of current Items, a BoardMap object to
faciliate game object interactions, a View object for UI, and a "round" attribute to
track the current round
******************************************************/
bool comparePlayers(Player*, const Player*);
bool compareItems(Item*, const Item*);

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    list<Player*> playerList;
    list<Item*> itemList;
    View view;
    BoardMap board;
    int round;

    void playRound();

    void generateFighter();
    void movePlayers();
    void movePlayer(Player*, int, int, int, int);
    bool checkPlayerPosition(Player*, Position&);
    void clearLocation(Player*, Position&);
    void cleanUpTheRound();
    void removeDeadFighters();
    void removeUsedItems();

    bool gameOver();
    void updateDisplay();

    void initializeGame();
    void initializePlayers(int, int);
    void initializeBoardItems(int, int);
    void printInitializedGame();
};

#endif
