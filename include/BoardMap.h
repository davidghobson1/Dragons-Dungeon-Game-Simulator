#ifndef BOARD_MAP_H
#define BOARD_MAP_H

#include <unordered_map>
#include "Player.h"
#include "Item.h"
#include "Position.h"
#include "Register.h"
#include "View.h"

/*****************************************************
 * BoardMap Class
Collection Class used to associate a position on the game board to the all other
Players and Item objects at that location.
A BoardMap object stores a hash map (specifically an unordered_map from the C++
STL) mapping Position objects to Register objects. The Register object for a
given Position stores lists of players and items stored at that position, and is
responsible for handling collisions between Players, and collections of Items by
Players.
Note: only Positions with non-empty Registers are stored in the hash map
******************************************************/

//hash function used by the unordered_map to map 2D Position objects to Register Objects
//This hash function is adapted from the hash function of Matthew Szudzik (Wolfram Research)
//hashing pairs of ints to ints
class MyHashFunction
{
  public:
    size_t operator()(const Position& p) const noexcept
    {
      int x = p.getX();
      int y = p.getY();
      int r = (x >= y ? x*x + x + y : y*y + x);
      return hash<int>{}(r);
    }
};

class BoardMap
{
  public:
    BoardMap();
    ~BoardMap();

    void collideAndCollect(Player*, View&);
    void addItem(Item*);
    void addPlayer(Player*, View&);
    void clearLocation(Player*, Position&);

  private:
    unordered_map<Position, Register, MyHashFunction> boardMap;
};

#endif
