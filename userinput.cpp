#include "main.h"
using namespace std;

int main ()
{

  //while (true)
  //{
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
  //}


}
