#ifndef PORC_H
#define PORC_H

#include <string>
#include "Fighter.h"

/*****************************************************
 * Porc Class
Derived class of Fighter representing a Porc
Porcs have strength generated randomly between 4 and 5
******************************************************/

class Porc: public Fighter
{
  public:
    Porc(int, int);
    virtual ~Porc();
};

#endif
