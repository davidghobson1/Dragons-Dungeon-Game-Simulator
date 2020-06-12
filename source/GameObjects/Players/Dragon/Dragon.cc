#include <iostream>
using namespace std;
#include <string>

#include "Dragon.h"

Dragon::Dragon(int px, int py)
{
  type = 3;
  direction = 1;
  caveLocation = py;

  maxHealth = 10000;
  maxStrength = 10000;
  maxArmour = 10000;

  setName("Dragon");
  setHealth(10000);
  setStrength(10000);
  setArmour(10000);
  setAvatar('D');
  setPosition(px, py);
}

Dragon::Dragon(const Dragon& dragon) : Player(dragon)
{
  direction = dragon.direction;
  caveLocation = dragon.caveLocation;
}

Dragon::~Dragon() {   }

Dragon& Dragon::operator=(const Dragon& dragon)
{
  Player::operator=(dragon);
  direction = dragon.direction;
  caveLocation = dragon.caveLocation;

  return *this;
}

bool Dragon::operator==(const Dragon& other)
{
  bool b1 = Player::operator==(other);
  bool b2 = (direction == other.direction);

  return (b1 && b2);
}

int Dragon::getDirection() const {  return direction;  }

//changes the direction the Dragon is pacing in front of the cave
void Dragon::changeDirection() { direction = (direction == 1 ? -1 : 1 );}

//Dragons pace back and forth in front of the cave
void Dragon::move(int xdim, int ydim, int caveTop, int caveBottom)
{
  if(direction == 1){
    setPosition(xdim, getY() + 1);
  }else{
    setPosition(xdim, getY() - 1);
  }

  //if the Dragon has reached the boundary of the cave, they change directions
  if(getY() == caveTop || getY() == caveBottom){
    changeDirection();
  }
}

//Dragon's collide function. Only collisions with Heros are possible, whom they
//kill instantly
void Dragon::attack(Player* otherPlayer, int& damageGiven)
{
	//get the type of the opponent
	char c = otherPlayer->getType();
	if(c == 2 || c == 3){				//colliding with another Dragon or a Fighter
		damageGiven = 0;
	}else if(c == 1){			//colliding with a Hero
	  damageGiven = otherPlayer->getHealth();
		if(damageGiven < 0){
			damageGiven = 0;
		}
	}
}
