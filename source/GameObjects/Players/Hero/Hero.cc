#include <iostream>
using namespace std;
#include <string>
#include "random.h"

#include "Hero.h"

Hero::Hero(string name, int h, int s, int a, char av, int px, int py)
{
  type = 1;

	maxHealth = 15;
	maxStrength = 10;
	maxArmour = 6;

  setName(name);
  setHealth(h);
  setStrength(s);
  setArmour(a);
  setAvatar(av);
  setPosition(px, py);
}

Hero::~Hero() {   }

void Hero::setHealth(int h)
{
	Player::setHealth(h);
	if(hasDied()){
		setAvatar('+');
	}
}

//Heros move function
//Heros move one space right, and either up, down, or straight
void Hero::move(int xdim, int ydim, int caveTop, int caveBottom)
{
  if(hasDied() == true){
    return;
  }

  //move one unit right and either up, down, or straight
  int newX = getX() + 1;
  int newY = getY() + random(99)%3 - 1;

	checkBounds(newX, newY, xdim, ydim, caveTop, caveBottom);

  setPosition(newX, newY);
}

//Heros bounds check function
void Hero::checkBounds(int& newX, int& newY, int xdim, int ydim, int caveTop, int caveBottom)
{
	//bounds check on the sides of the board
  if(newY < 1){
    newY = 1;
  }else if(newY > ydim){
    newY = ydim;
  }

  //bounds check on the entrance, and cave-side
  if(newX < 1){
    newX = 1;
  }else if(newX > xdim + 1){
		newX = xdim + 1;
	}

  //check whether the hero has entered the cave
  if(newX == xdim + 1){
    if(( newY < caveTop || newY > caveBottom )){
      newX = xdim;
    }
  }
}

//Hero's collide function. Note: only collisions with Fighters and Dragons are possible
void Hero::attack(Player* otherPlayer, int& damageGiven)
{
	//get the type of the opponent
	char c = otherPlayer->getType();
	if(c == 1 || c == 3){				//colliding with the Dragon or another Hero
		damageGiven = 0;
	}else if(c == 2){			//colliding with a Fighter
	  damageGiven = getStrength() - otherPlayer->getArmour();
		if(damageGiven < 0){
			damageGiven = 0;
		}
	}
}
