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
      askBoardType(boardArray);
    }
    else if (input == 2)
    {
      getFile(input);
      cout << "Choose the height: "<< endl;
      cin >> height;

      cout<< "Choose the width: "<< endl;
      cin >> width;

      cout << "Choose the population density of the world greater than 0 and less than or equal to 1): " <<endl;
      cin >> density;

      board = new Board(height, width, density);
      boardArray = board->boardGenerator();
      askBoardType(boardArray);
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
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' " << endl;
  cin >> response;

  switch(response)
  {
    case 'C': case 'c':
      board = new Board(height, width);
      for (int i = 0; i < 5; ++i)
      {
        cout << endl;
        cout << "Generation " << i << endl;
        board->printBoard(someArray);
        board->runClassic(someArray,height,width);
        board->updateBoard(someArray);
      }
      break;
    case 'D': case 'd':
      //runDonut(board);
      break;
    case 'M' : case 'm':
      //runMirror(board);
      break;
  }
}

void UserInput::getFile(int i)
{
  while(i == 1)
  {
    string fileName;
    ifstream f;
    string line;
    cout <<"Enter a filename. " << endl;
    cin >> fileName;

    f.open(fileName);

    if(!f)
    {
      cout << "Filename was not found. Try again. " << endl;
    }
    else
    {
      //reads first line and makes into row dimension
      getline(f, line);
      height = stoi(line);
      //reads second line an makes into column dimension
      getline(f, line);
      width = stoi(line);

      //int boardArray[line1][line2];
      boardArray = new int*[height];
      for (int i = 0; i < width; i++){
        boardArray[i] = new int[height];
      }

      //initialize array
      char myArray[height][width];

      //read through array and print out array contents
      for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
          f >> myArray[i][j];
          if (myArray[i][j] == 'X')
          {
            boardArray[i][j] = 1;
          }
          else if (myArray[i][j] == '-')
          {
            boardArray[i][j] = 0;
          }
          //cout << boardArray[i][j];
        }
        //cout << endl;
      }
      f.close();
      }
      i = 0;
    }
  }

//two copies-- previous and current of next gen and current gen
// object with pointers curr and next to keep track of successive generations
// then compare two generations with one another- draw/map out
