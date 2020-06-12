#ifndef ORC_H
#define ORC_H

#include <string>
#include "Fighter.h"

/*****************************************************
 * Orc Class
Derived class of Fighter representing a Orc
Orcs have strength generated randomly between 4 and 5
******************************************************/

class Orc: public Fighter
{
  public:
    Orc(int, int);
    virtual ~Orc();
};

#endif
