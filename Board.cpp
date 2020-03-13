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

int** Board::boardGenerator(){

  //initialize height and width and density
  int totalCells = height* width;
  double populatedCells = totalCells * density;
  int popCount = 0;

  grid = new int*[height];
  for (int i = 0; i < height; i++) {
    // create rows
    grid[i] = new int[width];
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


      if(popCount == populatedCells){
        break;
      }
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
      if(grid[r][c] == 0)
        cout<< "-";
      else if (grid[r][c]==1)
        cout<<"X";
    }
  } cout << endl;
}

int** Board::runClassic(int **grid, int height, int width){
  int h = height;
  int w = width;
  int numNeighbors;

  newGen = new int*[height];
  for (int i = 0; i < height; i++) {
    // create rows
    newGen[i] = new int[width];
  }


  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){

      int r = i;
      int c = j;

        if(i == 0 && j == 0){
          //IN UPPER LEFT
          numNeighbors = grid[r][c+1] + grid[r+1][c] + grid[r+1][r+1];
        }
        else if (i == 0 && j == w-1){
          //IN UPPER RIGHT

          numNeighbors = grid[r+1][c] + grid[r][c-1] + grid[r+1][c-1];
        }
        else if (i == h-1 && j == 0){
          //IN BOTTOM LEFT

          numNeighbors = grid[r][c+1] + grid[r-1][c] + grid[r-1][c+1];

        }
        else if (i == h-1 && j == w-1){
          //IN BOTTOM RIGHT

          numNeighbors = grid[r-1][c] + grid[r][c-1] + grid[r-1][c-1];
        }
        else if (j == 0 && i != 0 && i != h-1){
          //IN LEFT SIDES

          numNeighbors = grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c] + grid[r+1][c+1];

        }
        else if(j == w-1 && i != 0 && i != h-1){
          //IN RIGHT SIDES

          numNeighbors = grid[r+1][c] + grid[r+1][c-1] + grid[r][c-1] + grid[r-1][c-1] + grid[r-1][c];

        }
        else if (j != 0 && i == 0 && j != w-1){
          //IN TOP SIDES

          numNeighbors = grid[r][c-1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1] + grid[r][c+1];
        }
        else if (i == h-1 && j != 0 && j != w-1){
          //IN BOTTOM SIDES
          numNeighbors = grid[r][c-1] + grid[r][c+1] + grid[r-1][c+1] + grid[r-1][c] + grid[r-1][c-1];

        }

        else if(i != 0 && i != h-1 && j != 0 && j != w-1){
          //IN MIDDLE SECTIONS
          numNeighbors = grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1]+ grid[r][c-1];
        }


        if (numNeighbors == 3)
           newGen[i][j] = 1; // continue to lives on


       else if (numNeighbors <=1) //dies of loneliness :(
         newGen[i][j] = 0;

       else if(numNeighbors == 2) //  a location with 2 neighbors remains stable in the next gen.
         newGen[i][j] = grid[i][j];
         //calculate stable count
       else
        newGen[i][j]=0;//overcrowded

    }

  }

printBoard(newGen);

return newGen;

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






void Board:: runDonut(int **grid, int height, int width){
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

void Board:: runMirror(int** grid, int height, int width){

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
