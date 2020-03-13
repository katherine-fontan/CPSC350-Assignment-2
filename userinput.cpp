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
  //function to ask what type of configuration they want file or random generator
    int input;
    cout << "Would you like to: \n 1 - Specify a flat-file configuration or \n 2 - Generate a random configuration ";
    cin >> input;

    if (input == 1)
    {
      getFile(input);
      askBoardType(boardArray); //ask what type of board
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
      boardArray = board->boardGenerator(); // generates a random board
      askBoardType(boardArray); //pass in ask board type
    }
    else
    {
      cout << "Invaid input. Try again. " << endl;
      cout << "\n1 - Specify a flat-file configuration or \n 2 - Generate a random configuration ";
      cin >> input;
    }
}


void UserInput::askBoardType(int** someArray)
{
  char response;
  //gameMode mode;
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' " << endl;
  cin >> response;

//switch statement to figure out which board type the user answered and based on that a new board object is created and and the other functions from board.cpp are called
  switch(response)
  {
    case 'C': case 'c':
      board = new Board(height, width);
      cout<< "Generation 0 "<<endl;
      board->printBoard(someArray);


      for (int i = 1; i < 4; ++i)
      {
        cout << "Generation " << i << endl;
        update = board->runClassic(someArray, height, width);
        someArray = board->updateBoard(update);
      }
      break;
    case 'D': case 'd':
      //runDonut(board);
      /*board = new Board(height, width);
      cout<< "Generation 0 "<<endl;
      board->printBoard(someArray);


      for (int i = 1; i < 4; ++i)
      {
        cout << "Generation " << i << endl;
        update = board->runDonut(someArray, height, weight);
        someArray = board->updateBoard(update);
      }*/

      break;
    case 'M' : case 'm':
      //runMirror(board);
      /*board = new Board(height, width);
      cout<< "Generation 0 "<<endl;
      board->printBoard(someArray);


      for (int i = 1; i < 4; ++i)
      {
        cout << "Generation " << i << endl;
        update = board->runMirror(someArray, height, weight);
        someArray = board->updateBoard(update);
      }*/

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
      cout <<"Enter a filename. " << endl;
      cin >> fileName;
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

        }

      }
      f.close();
      }
      i = 0;
    }
  }
