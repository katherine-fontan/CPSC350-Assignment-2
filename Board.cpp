#include "Board.h"
#include <iostream>

using namespace std;

Board:: Board(){

}
Board:: ~Board(){

}

int Board::boardGenerator(){ /*pass in height, width and density*/

  //initialize height and width and density TEMPORARILY
  int totalCells = height* width;
  double populatedCells = totalCells * density;
  int popCount = 0;
  int board[height][width];

  for(int r = 0; r < height; ++r){
    for (int c = 0; c < width; ++c){
      double randNum = ((double) rand() /(RAND_MAX +1.0));
      if(0 < randNum && randNum <= density){//i dont know exactly if this is correct
        board[r][c] = 1; //also shouldnt it be 0 or 1 idk
        ++popCount;
      }
      else {
        board[r][c] = 0;
      }

      //when array is filled break
      if(popCount == populatedCells){
        break;
      }
      cout << board[r][c];
    }
    cout << endl;
  }

   return 0;
}
