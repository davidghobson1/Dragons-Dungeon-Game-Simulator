#ifndef DORC_H
#define DORC_H

#include <string>
#include "Fighter.h"

/*****************************************************
 * Dorc Class
Derived class of Fighter representing a Dorc
Dorcs have strength generated randomly between 6 and 8
******************************************************/

class Dorc: public Fighter
{
  public:
    Dorc(int, int);
    virtual ~Dorc();
};

#endif
