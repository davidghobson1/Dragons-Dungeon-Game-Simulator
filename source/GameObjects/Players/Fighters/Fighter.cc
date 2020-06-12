#include <iostream>
using namespace std;
#include <string.h>
#include "random.h"

#include "Fighter.h"

Fighter::Fighter()
{
  type = 2;
  maxHealth = 10;
  maxStrength = 15;
  maxArmour = 6;

  setHealth(5);
  setArmour(0);
}

Fighter::~Fighter() {   }

//moves the Fighter
//Fighters always move one unit left, and either up, down, or at the same level
void Fighter::move(int xdim, int ydim, int caveTop, int caveBottom)
{
  if(hasDied() == true){
    return;
  }

  int newX = getX() - 1;
  int newY = getY() + random(99)%3 - 1;

  checkBounds(newX, newY, xdim, ydim, caveTop, caveBottom);

  setPosition(newX, newY);
}

//Fighters own bounds checks
//At the entrance of the board, the Fighter dies and sets its health to zero
void Fighter::checkBounds(int& newX, int& newY, int xdim, int ydim, int caveTop, int caveBottom)
{
	//bounds check on the side of the board
  if(newY < 1){
    newY = 1;
  }else if(newY > ydim){
    newY = ydim;
  }

  //bounds check on the entrance, and the cave-side of the board
  //if the Fighter reaches the entrance, they die
  if(newX < 1){
    setHealth(0);
    newX = 0;
  }else if(newX > xdim){
		newX = xdim;
	}
}

//Fighter's collide function.
//Note: only collisions with Heros are possible
void Fighter::attack(Player* otherPlayer, int& damageGiven)
{
  //get the type of the opponent
	char c = otherPlayer->getType();
	if(c == 2 || c == 3){				//colliding with the Dragon or another Fighter
		damageGiven = 0;
	}else if(c == 1){			//colliding with a Hero
	  damageGiven = getStrength() - otherPlayer->getArmour();
		if(damageGiven < 0){
			damageGiven = 0;
		}
	}
}
