#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Player.h"

int Player::nextId = 1;

Player::Player(int h, int s, int a, char av, int px, int py): id(nextId++), health(h), strength(s), armour(a), avatar(av), position(px, py) {   }

Player::Player(const Player& player)
{
  id = player.id;
  name = player.name;
  health = player.health;
  strength = player.strength;
  armour = player.armour;
  avatar = player.avatar;
  position = player.position;
  type = player.type;
}

Player::~Player() {   }

Player& Player::operator=(const Player& player)
{
  health = player.health;
  strength = player.strength;
  armour = player.armour;
  avatar = player.avatar;
  position = player.position;
  type = player.type;

  return *this;
}

bool Player::operator==(const Player& other)
{
  return (id == other.id ? true : false);
}

bool Player::operator<(const Player& other)
{
  if(getHealth() == 0 && getType() == 2){
    return true;
  }else if(other.getHealth() == 0 && other.getType() == 2){
    return false;
  }else{
    if(getType() == 1){
      return true;
    }else{
      return false;
    }
  }
}

int Player::getNextId() {  return nextId;  }

int Player::getId() const {  return id;  }

string Player::getName() const { return name;  }

char Player::getAvatar() const { return avatar; }

int Player::getHealth() const { return health; }

int Player::getStrength() const { return strength; }

int Player::getArmour() const { return armour; }

Position& Player::getPosition() { return position; }

int Player::getX() const { return position.getX(); }
int Player::getY() const { return position.getY(); }

char Player::getType() const {  return type;  }

bool Player::hasDied() const {  return getHealth() == 0 ? true : false;  }

void Player::setName(string n) {  name = n;  }

void Player::setAvatar(char c) { avatar = c; }

void Player::setHealth(int h)
{
  if(h < 0){
    health = 0;
  }else if(h > maxHealth){
    health = maxHealth;
  }else{
    health = h;
  }
}

void Player::setStrength(int s)
{
  if(s < 0){
    strength = 0;
  }else if(s > maxStrength){
    strength = maxStrength;
  }else{
    strength = s;
  }
}

void Player::setArmour(int a)
{
  if(a < 0){
    armour = 0;
  }else if(a > maxArmour){
    armour = maxArmour;
  }else{
    armour = a;
  }
}

void Player::setPosition(int x, int y)
{
  position.setPosition(x, y);
}

void Player::setPosition(Position& newPosition)
{
  position = newPosition;
}

//player collecting an item
bool Player::collectItem(Item* item){

  if(hasDied()){
    return false;
  }

  int newHealth = getHealth();
  int newStrength = getStrength();
  int newArmour = getArmour();

  //give the item the player's stats. This will then change one or more of them
  //based on Player type
  item->collect(newHealth, newStrength, newArmour, getType());

  //if none of the player stats have been changed, leave the item
	if(newHealth == getHealth() && newStrength == getStrength() && newArmour == getArmour()){
    return false;
  }

  //update player stats
  setHealth(newHealth);
  setStrength(newStrength);
  setArmour(newArmour);

  return true;
}

//player colliding with another player
void Player::collision(Player* otherPlayer)
{
	if(getHealth() > 0 && otherPlayer->getHealth() > 0){
		int damageTaken = 0;
		int damageGiven = 0;

    //each player attacks the other and the damage is collected
		attack(otherPlayer, damageGiven);
		otherPlayer->attack(this, damageTaken);

    //each player's stats are updated
		setHealth(getHealth() - damageTaken);
		otherPlayer->setHealth(otherPlayer->getHealth() - damageGiven);
	}
}

ostream& operator<<(ostream& out, Player& player)
{
  out << player.getName();
  return out;
}
