#include <fstream>
#include <iostream>
#include "userinput.h"
using namespace std;

UserInput:: UserInput(){
  boardArray = 0;
  update = 0;
  height = 0;
  width = 0;
  density = 0.0;

}

UserInput:: ~UserInput(){

  for (int i = 0; i < height; i++)
    delete[] boardArray[i]; // delete the i-th row
  delete[] boardArray;

  for (int i = 0; i < height; i++)
    delete[] update[i]; // delete the i-th row
  delete[] update;

  delete board;

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
      cout << "Invaid input. " << endl;
    }
}


void UserInput::askBoardType(int** someArray)
{
  int generation = 1;
  bool stable = false;
  char response;
  //gameMode mode;
  cout << "Which game mode would you like to play in? \n Classic 'C', Donut 'D' or Mirror 'M' " << endl;
  cin >> response;

//switch statement to figure out which board type the user answered and based on that a new board object is created and and the other functions from board.cpp are called
  switch(response)
  {
    //classic mode case
    case 'C': case 'c':
      board = new Board(height, width);
      cout<< "Generation 0 "<<endl;
      board->printBoard(someArray);

      while(stable == false){

          cout << "Generation " << generation << endl;
          update = board->runClassic(someArray, height, width);
          stable = board-> stabilityOfBoard(someArray, update, height, width);
          someArray = board->updateBoard(update);

          if(stable == true){

            cout << "Your board is stable... bye" << endl;
            break;
          }
          else{
            stable = false;
          }
          generation++;
      }

      break;
    //donut mode case
    case 'D': case 'd':
      //runDonut(board);
      board = new Board(height, width);
      cout<< "Generation 0 "<<endl;
      board->printBoard(someArray);

      while(stable == false){

          cout << "Generation " << generation << endl;
          update = board->runDonut(someArray, height, width);

          stable = board-> stabilityOfBoard(someArray, update, height, width);
          someArray = board->updateBoard(update);

          if(stable == true){
            cout << "Your board is stable... bye" << endl;
            break;
          }
          else{
            stable = false;
          }
          generation++;
          stable = false;
      }

      break;
    //mirror mode case
    case 'M' : case 'm':
      //runMirror(board);
      board = new Board(height, width);
      cout<< "Generation 0 "<<endl;
      board->printBoard(someArray);

      while(stable == false){

          cout << "Generation " << generation << endl;
          update = board->runMirror(someArray, height, width);

          stable = board-> stabilityOfBoard(someArray, update, height, width);
          someArray = board->updateBoard(update);

          if(stable == true){
            cout << "Your board is stable... bye" << endl;
            break;
          }
          else{
            stable = false;
          }
          generation++;
          stable = false;
      }
      break;
  }
}

//function that reads in a file and turns contents into an array
void UserInput::getFile(int i)
{
  while(i == 1)
  {
    string fileName;
    ifstream fileStream;
    string line;
    cout <<"Enter a filename. " << endl;
    cin >> fileName;

    fileStream.open(fileName);

    if(!fileStream)
    {

      cout << "Filename was not found. Try again. " << endl;

      continue;
    }
    else
    {
      //reads first line and makes into row dimension
      getline(fileStream, line);
      height = stoi(line);
      //reads second line an makes into column dimension
      getline(fileStream, line);
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
          fileStream >> myArray[i][j];
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
      fileStream.close();
      }
      i = 0;
    }
  }
