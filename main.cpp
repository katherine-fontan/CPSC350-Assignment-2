#include "ClassicMode.h"
#include "Board.h"
#include <iostream>

using namespace std;

int main (int argc, char** argv){


//assign the dimensions of the world based on input from input file;
//pass in parameter in boardGenerator() from board cpp

  //bool userInput = true;
  //call class of user inputs
  Board* b = new Board();
   b -> boardGenerator();
   cout << b -> grid << endl;


 //else if statement for donut
 //else if for mirror mode
 return 0;
}
