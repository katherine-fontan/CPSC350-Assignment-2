#include "Board.h"
#include <iostream>

using namespace std;

Board:: Board(){

}
Board:: Board(int height, int width){
  this->height = height;
  this->width = width;
}
Board:: Board(int height, int width, double density){
  this->height = height;
  this->width = width;
  this->density = density;
}
Board:: ~Board(){

}

int** Board::boardGenerator(){ /*pass in height, width and density*/

  //initialize height and width and density TEMPORARILY
  int totalCells = height* width;
  double populatedCells = totalCells * density;
  int popCount = 0;
  //int grid[height][width];
  grid = new int*[height];
  for (int i = 0; i < height; i++) {
    // create rows
    grid[i] = new int[width];
  }

  for(int r = 0; r < height; ++r){
    //cout << "first loop" << endl;
    for (int c = 0; c < width; ++c){
      //cout << "second loop" << endl;
      double randNum = ((double) rand() /(RAND_MAX + 1.0));
      //cout << "afrer randnum assign" << endl;
      if(0 < randNum && randNum <= density){
        //cout << "after first if" << endl;
        grid[r][c] = 1;
        ++popCount;
      }
      else {
        //cout << "in else" << endl;
        grid[r][c] = 0;
        //cout << "second in else" << endl;
      }

      //cout << "after else" << endl;

      //when grid is filled break
      if(popCount == populatedCells){
        //cout << "in if pop" << endl;
        break;
      }
      //cout << "after if pop" << endl;
      cout << grid[r][c];
    }
    cout << endl;
  }
  return grid;

}

void Board::printBoard(int** grid)
{
  for(int r=0; r < height; r++)
  {
    cout << endl;
    for(int c=0; c <width; c++)
    {
      cout << grid[r][c];
    }
  } cout << endl;
}

int** Board::runClassic(int **grid, int height, int width){
  int h = height;
  int w = width;
  double d = density;
  int numNeighbors;

  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      int r = i;
      int c = j;

        if(i == 0 && j == 0){
          //top left
          //check if its upper
          //cout << "IN UPPER LEFT" << endl;
          numNeighbors = grid[r][c+1] + grid[r+1][c] + grid[r+1][r+1];
        }
        else if (i == 0 && j == w-1){
          //top right
          //cout << "IN UPPER RIGHT" << endl;

          numNeighbors = grid[r+1][c] + grid[r][c-1] + grid[r+1][c-1];
        }
        else if (i == h-1 && j == 0){
          //bottom left
          // this makes it lower
          //cout << "IN BOTTOM LEFT" << endl;

          numNeighbors = grid[r][c+1] + grid[r-1][c] + grid[r-1][c+1];

        }
        else if (i == h-1 && j == w-1){
          //bottom right
          //cout << "IN BOTTOM RIGHT" << endl;

          numNeighbors = grid[r-1][c] + grid[r][c-1] + grid[r-1][c-1];
        }
        else if (j == 0 && i != 0 && i != h-1){
          //left side
          //this accounts for sides
          //cout << "IN LEFT SIDES" << endl;

          numNeighbors = grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c] + grid[r+1][c+1];

        }
        else if(j == w-1 && i != 0 && i != h-1){
          //right side
          //cout << "IN RIGHT SIDES" << endl;

          numNeighbors = grid[r+1][c] + grid[r+1][c-1] + grid[r][c-1] + grid[r-1][c-1] + grid[r-1][c];

        }
        else if (j != 0 && i == 0 && j != w-1){
          //top side
          //cout << "IN TOP SIDES" << endl;

          numNeighbors = grid[r][c-1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1] + grid[r][c+1];
        }
        else if (i == h-1 && j != 0 && j != w-1){
          //cout << "IN BOTTOM SIDES" << endl;
          numNeighbors = grid[r][c-1] + grid[r][c+1] + grid[r-1][c+1] + grid[r-1][c] + grid[r-1][c-1];

        }

        else if(i != 0 && i != h-1 && j != 0 && j != w-1){
          //middle section
          //cout << "IN MIDDLE SECTIONS" << endl;
          numNeighbors = grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1]+ grid[r][c-1];
        }
        //cout << "neighbors count is " << numNeighbors << endl;
    }

  }

  newGen = new int*[height];
  for (int i = 0; i < height; i++) {
    // create rows
    newGen[i] = new int[width];
  }

//rules of game of life
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

  //grid = newGen;
  //cout << "before temp delete" <<endl;
//delete temp;
  //cout << "temp is deleted"<<endl;
}

int** Board::updateBoard(int** grid)
{
  for(int r=0; r < height; r++){
    for(int c=0; c < width; c++)
    {
      grid[r][c] == newGen[r][c];
    }
  } return grid;
}

//make a current and next class printing out and copy from one another




void Board:: runDonut(int **grid){
  int numNeighbors;
  int h = height;
  int w = width;

//iterate throught array to figure out number of neighbors
  for (int i = 0; i < h; ++i){

    for (int j = 0; j < w; ++j){


      int r = i;
      int c = j;


      //if statements to figure out number of neighbors // similar to classic structure

    }
  }




//new generator

//rules of game of life // from classic may have to change this
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){

       if (numNeighbors == 3){
        if(grid[i][j] == 1){
          //newGen[i][j] = 1; // continue to lives on
        }

        else if(grid[i][j] == 0){
            //newGen[i][j] = 1; // a new cell is born if its empty
        }
      }
      else if (numNeighbors >= 4 || numNeighbors <=1){ //overcrowded :(
        //newGen[i][j] = 0;
      }
      else if(numNeighbors == 2){ //  a location with 2 neighbors remains stable in the next gen.

        if(grid[i][j] == 1) {// if full it remains full
          //newGen[i][j] = 1;
        }
        else if (grid[i][j] == 0){// if empty remains empty
          //newGen[i][j] = 0;
        }
        //calculate stable count
      }
    }
  }





}

void Board:: runMirror(int** grid){

  int numNeighbors;
  int h = height;
  int w = width;

//iterate throught array to figure out number of neighbors
  for (int i = 0; i < h; ++i){

    for (int j = 0; j < w; ++j){


      int r = i;
      int c = j;


      //if statements to figure out number of neighbors // simiral to classic structure

    }
  }




//new generator

//rules of game of life // from classic may have to change this
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){

       if (numNeighbors == 3){
        if(grid[i][j] == 1){
          //newGen[i][j] = 1; // continue to lives on
        }

        else if(grid[i][j] == 0){
            //newGen[i][j] = 1; // a new cell is born if its empty
        }
      }
      else if (numNeighbors >= 4 || numNeighbors <=1){ //overcrowded :(
        //newGen[i][j] = 0;
      }
      else if(numNeighbors == 2){ //  a location with 2 neighbors remains stable in the next gen.

        if(grid[i][j] == 1) {// if full it remains full
          //newGen[i][j] = 1;
        }
        else if (grid[i][j] == 0){// if empty remains empty
          //newGen[i][j] = 0;
        }
        //calculate stable count
      }
    }
  }
}
