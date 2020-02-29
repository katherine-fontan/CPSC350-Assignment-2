#include "userinput.h"
#include "configuration.h"
using namespace std;

void userinput::askConfig()
{
    int input;
    configuration config;
    cout << "Would you like to: \n 1 - Specify a flat-file configuration or \n 2 - Generate a random configuration ";
    cin >> input;

    if (input == 1)
    {
      config.getConfig(input);
    }
    else if (input == 2)
    {
      config.getConfig(input);
    }
    else
    {
      cout << "Invaid input. Try again. " << endl;
    }
}

void userinput::askBoardType()
{
  string response;
  //gameMode mode;
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' ";
  cin >> response;

  //switch(response)
}

//void userinput::askPauseOption(){

//}
