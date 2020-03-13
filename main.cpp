#include "userinput.h"
#include <iostream>

using namespace std;

int main (int argc, char** argv)
{


  UserInput *user = new UserInput();

  user->askConfig();


  cout << "The End...Bye" <<endl;




  delete user;
  return 0;
}
