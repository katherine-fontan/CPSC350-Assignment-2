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
      getFile(input);
      askBoardType(fileArray);

      }
    else if (input == 2)
    {
      cout << "Choose the height: "<<endl;
      cin >> height;

      cout<< "Choose the width: "<< endl;
      cin >> width;

      cout << "Choose the population density of the world greater than 0 and less than or equal to 1): " <<endl;
      cin >> density;
      board = new Board(height, width, density);
      //board->boardGenerator();

      //int** b = board-> boardGenerator();
      //askBoard(b);
      fileArray = board->boardGenerator();
      askBoardType(fileArray);
    }
    else
    {
      cout << "Invaid input. Try again. " << endl;
    }
  }


void UserInput::askBoardType(int** someArray)
{
  char response;
  //gameMode mode;
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' ";
  cin >> response;

  switch(response)
  {
    case 'C': case 'c':
      board = new Board(height, width);
      board->runClassic(someArray,height,width);
      break;
    case 'D': case 'd':
      //runDonut(board);
      break;
    case 'M' : case 'm':
      //runMirror(board);
      break;
  }

}

//void UserInput::askPauseOption(){

//}


void UserInput::getFile(int i)
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
      height = stoi(line);
      //reads second line an makes into column dimension
      getline(f, line);
      width = stoi(line);

      //int fileArray[line1][line2];
      fileArray = new int*[height];
      for (int i = 0; i < width; i++){
        fileArray[i] = new int[height];
      }

      //initialize array
      char myArray[height][width];

      //read through array and print out array contents
      for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
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

    //board = new Board(int height,int width);


    }

  }

}

  //classic mode working, 

//two copies-- previous and current of next gen and current gen
// object with pointers curr and next to keep track of successive generations
// then compare two generations with one another- draw/map out
