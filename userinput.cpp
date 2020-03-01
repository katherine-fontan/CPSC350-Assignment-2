#include <fstream>
#include <iostream>
#include "userinput.h"
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
      cout << "Choose the height: "<<endl;
      cin>>height;

      cout<< "Choose the width: "<< endl;
      cin>>width;

      cout << "Choose the population density of the world greater than 0 and less than or equal to 1): " <<endl;
      cin>>density;
      //config.getConfig(input);
      board = new Board(height, width, density);
      board -> boardGenerator();


    }
    else
    {
      cout << "Invaid input. Try again. " << endl;
    }
}

void UserInput::askBoardType()
{
  char response;
  //gameMode mode;
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' ";
  cin >> response;

  switch(response)
  {
    case 'C': case 'c':
      //runClassic(board);
      break;
    case 'D': case 'd':
      //runDonut(board);
      break;
    case 'M' : case 'm':
      //runMirror(board);
      break;
  }

}
  //run classic here, inherit board
  //switch(response)




//void UserInput::askPauseOption(){

//}


void UserInput::getConfig(int i)
{
  while(i == 1)
  {
    string fileName;
    ifstream f;
    string line;
    Board boardFile;
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

      //int fileArray[line1][line2];
      fileArray = new int*[line1];
      for (int i = 0; i < line2; i++){
        fileArray[i] = new int[line1];
      }

      //initialize array
      char myArray[line1][line2];

      //read through array and print out array contents
      for(int i = 0; i < line1; i++) {
        for(int j = 0; j < line2; j++) {
          f >> myArray[i][j];
          if (myArray[i][j] == 'X')
          {
            fileArray[i][j] = 1;
          }
          else if (myArray[i][j] == '-')
          {
            fileArray[i][j] = 0;
          }

          cout << fileArray[i][j];

        }
        cout << endl;
    }
    i = 0;
    f.close();
    //boardFile.runClassic(fileArray);
    }
  }

  //random board will be created
  if(i == 2)
  {
    //code for random board here

  }
}
