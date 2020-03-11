#include <fstream>
#include <iostream>
#include "UserInput.h"
using namespace std;

UserInput:: UserInput(){

}
UserInput:: ~UserInput(){

}


void UserInput::askConfig()
{
    int input;

    cout << "Would you like to: \n 1 - Specify a flat-file configuration or \n 2 - Generate a random configuration ";
    cin >> input;

    if (input == 1)
    {
      getConfig(input);
    }
    else if (input == 2)
    {
      //config.getConfig(input);
      //board = new Board();
      //board -> boardGenerator();
    }
    else
    {
      cout << "Invaid input. Try again. " << endl;
    }
}

void UserInput::askBoardType()
{
  string response;
  //gameMode mode;
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' ";
  cin >> response;

  if(response == "C"){
    board = new Board();
    board -> boardGenerator();

  }
  //run classic here, inherit board
  //switch(response)


}

//void UserInput::askPauseOption(){

//}


void UserInput::getConfig(int i)
{
  while(i == 1)
  {
    string fileName;
    ifstream f;
    string line;
    cout <<"Enter a filename. ";
    cin >> fileName;

    f.open(fileName);

    if(!f)
    {
      cout << "Filename was not found. Try again. ";
    }
    else
    {
      //reads first line and makes into row dimension
      getline(f, line);
      int line1 = stoi(line);
      //reads second line an makes into column dimension
      getline(f, line);
      int line2 = stoi(line);

      //initialize array
      char myArray[line1][line2];

      //read through array and print out array contents
      for(int i = 0; i < line1; i++) {
        for(int j = 0; j < line2; j++) {
          if(myArray)


          f >> myArray[i][j];
          cout << myArray[i][j];

        }
        cout << endl;
    }
    i = 0;
    f.close();
    }
  }

  //random board will be created
  if(i == 2)
  {
    //code for random board here
    //Board* b = new Board();
     //b->boardGenerator();
    // cout << b -> grid << endl;
  }
}
