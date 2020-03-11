#include <iostream>
#include "userinput.h"

using namespace std;

int main (int argc, char** argv)
{
  //userinput ask;
  //ask.askConfig();



//assign the dimensions of the world based on input from input file;
//pass in parameter in boardGenerator() from board cpp

  //bool userInput = true;
  //call class of user inputs
  UserInput *user = new UserInput();

  user -> askConfig();
  user -> askBoardType();

  cout << "Done" <<endl;





 //else if statement for donut
 //else if for mirror mode
 return 0;
}
