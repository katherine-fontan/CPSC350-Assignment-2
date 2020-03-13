#include "userinput.h"
#include <iostream>

using namespace std;

int main (int argc, char** argv)
{

  //call class of user inputs
  UserInput *user = new UserInput();

  user->askConfig();

  //user->askBoardType(boardArray);
  cout << "Done" <<endl;




  delete user;


 //else if statement for donut
 //else if for mirror mode
 //return 0;
}
