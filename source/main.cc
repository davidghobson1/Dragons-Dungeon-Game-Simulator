#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>

#include "random.h"
#include "Control.h"

int main(){
  srand( (unsigned)time( NULL ) );
  Control control;
  control.launch();
}
