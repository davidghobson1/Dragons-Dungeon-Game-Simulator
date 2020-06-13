#ifndef BORC_H
#define BORC_H

#include <string>
#include "Fighter.h"

/*****************************************************
 * Borc Class
Derived class of Fighter representing a Borc
Borcs have strength generated randomly between 8 and 11
******************************************************/

class Borc: public Fighter
{
  public:
    Borc(int, int);
    virtual ~Borc();
};

#endif
