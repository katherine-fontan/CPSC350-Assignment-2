#include "Board.h"
#include <iostream>

using namespace std;

Board:: Board(){

}
Board:: ~Board(){

}

int Board::boardGenerator(){ /*pass in height, width and density*/
  int height = 3;
  int width = 4;
  double density = 0.5;
  //initialize height and width and density TEMPORARILY
  int totalCells = height* width;
  double populatedCells = totalCells * density;
  int popCount = 0;
  //int grid[height][width];
  grid = new int*[height];
  for (int i = 0; i < width; i++) {
    // create rows
    grid[i] = new int[height];

  }

  for(int r = 0; r < height; ++r){
    for (int c = 0; c < width; ++c){
      double randNum = ((double) rand() /(RAND_MAX + 1.0));
      if(0 < randNum && randNum <= density){
        grid[r][c] = 1;
        ++popCount;
      }
      else {
        grid[r][c] = 0;
      }

      //when grid is filled break
      if(popCount == populatedCells){
        break;
      }
      cout << grid[r][c];
    }
    cout << endl;
  }
  runClassic(grid);

   return 0;
}

void Board:: run(){

  //switch statements for each game mode


}

void Board:: runClassic(int **grid){
  int h = 3;
  int w = 4;
  double density = 0.5;

  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      int r = i;
      int c = j;


    numNeighbors = grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c-1] + grid[r+1][c]
      + grid[r+1][c-1]+ grid[r][c-1];
    }
  }
  int **newGen= new int*[h]
  for (int i = 0; i < w; i++) {
    // create rows
    newGen[i] = new int[h];

  }

  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){


       if (numNeighbors == 3){
        if(grid[i][j] == 1){
          newGen[i][j] = 1; // continue to lives on
        }

        else if(grid[i][j] == 0){
            newGen[i][j] = 1; // a new cell is born if its empty
        }
      }
      else if (numNeighbors >= 4 || numNeighbors <=1){ //overcrowded :(
        newGen[i][j] = 0;
      }
      else if(numNeighbors == 2){ //  a location with 2 neighbors remains stable in the next gen.

        if(grid[i][j] == 1) {// if full it remains full
          newGen[i][j] = 1;
        }
        else if (grid[i][j] == 0){// if empty remains empty
          newGen[i][j] = 0;
        }
        //calculate stable count
      }
    }
  }
}
