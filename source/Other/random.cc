#include <iostream>

#include "random.h"

//generates a random integer between 0 and max-1 (inclusive) 
int random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) );
	return (int)(r * max);
}
