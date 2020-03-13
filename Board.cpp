#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(){
  grid = 0;
  newGen = 0;
  height = 0;
  width = 0;
  density = 0.0;
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

    }
  }
  return grid;

}

void Board::printBoard(int** grid)
{
  for(int r=0; r < height; r++)
  {
    cout << endl;
    for(int c = 0; c < width; c++)
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
  int stableCount = 0;


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


bool Board:: stabilityOfBoard(int** gridOld, int** gridNew, int height, int width){
  int stableCount=0;
  int zeroCount = height*width;
  for(int i = 0; i < height; ++i){
    for(int j = 0; j < width; ++j){

      if(gridOld[i][j] != gridNew[i][j]){
        stableCount++;

      }
    }
 }

  if(stableCount == 0){
    return true;
  }

  else if(stableCount > 0){
    return false;
  }
  else{
    return false;
  }

}


int** Board:: runDonut(int **grid, int height, int width){
  int h = height;
  int w = width;
  int numNeighbors;
  int stableCount = 0;


  newGen = new int*[height];
  for (int i = 0; i < height; i++) {
    // create rows
    newGen[i] = new int[width];
  }


  for (int i = 0; i < height; ++i){
    for (int j = 0; j < width; ++j){

      int r = i;
      int c = j;

        if(i == 0 && j == 0){
          //IN UPPER LEFT
          numNeighbors = grid[r][c+1] + grid[r+1][c] + grid[r+1][r+1] + grid[r+(height-1)][c] + grid[r+(height-1)][c+1] + grid[r+(height-1)][c+(width-1)] + grid[r][c+(width-1)] +grid[r+1][c+(width-1)];
        }
        else if (i == 0 && j == w-1){
          //IN UPPER RIGHT
          numNeighbors = grid[r+1][c] + grid[r][c-1] + grid[r+1][c-1] + grid[r+(height-1)][c] + grid[r+(height-1)][c-1] + grid[r+(height-1)][c-(width-1)] + grid[r][c-(width-1)] +grid[r+1][c-(width-1)];
        }
        else if (i == h-1 && j == 0){
          //IN BOTTOM LEFT
          numNeighbors = grid[r][c+1] + grid[r-1][c] + grid[r-1][c+1] + grid[r-(height-1)][c] + grid[r-(height-1)][c+1] + grid[r-(height-1)][c+(width-1)] + grid[r][c+(width-1)] +grid[r-1][c+(width-1)];

        }
        else if (i == h-1 && j == w-1){
          //IN BOTTOM RIGHT
          numNeighbors = grid[r-1][c] + grid[r][c-1] + grid[r-1][c-1] + grid[r-(height-1)][c] + grid[r-(height-1)][c-1] + grid[r-(height-1)][c-(width-1)] + grid[r][c-(width-1)] +grid[r-1][c-(width-1)];
        }
        else if (j == 0 && i != 0 && i != h-1){
          //IN LEFT SIDES
          numNeighbors = grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c] + grid[r+1][c+1] + grid[r-1][c+(width-1)] + grid[r+1][c+(width-1)] + grid[r][c+(width-1)];

        }
        else if(j == w-1 && i != 0 && i != h-1){
          //IN RIGHT SIDES
          numNeighbors = grid[r+1][c] + grid[r+1][c-1] + grid[r][c-1] + grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c-(width-1)] + grid[r+1][c-(width-1)] + grid[r][c-(width-1)];;

        }
        else if (j != 0 && i == 0 && j != w-1){
          //IN TOP SIDES
          numNeighbors = grid[r][c-1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1] + grid[r][c+1] + grid[r+(height-1)][c-1] + grid[r+(height-1)][c+1] + grid[r+(height-1)][c];
        }
        else if (i == h-1 && j != 0 && j != w-1){
          //IN BOTTOM SIDES
          numNeighbors = grid[r][c-1] + grid[r][c+1] + grid[r-1][c+1] + grid[r-1][c] + grid[r-1][c-1] + grid[r-(height-1)][c-1] + grid[r-(height-1)][c+1] + grid[r-(height-1)][c];

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



int** Board:: runMirror(int** grid, int height, int width){

  int h = height;
  int w = width;
  int numNeighbors;
  int stableCount = 0;
  bool stability = false;

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
        numNeighbors = grid[r+1][c+1] + grid[r][c+1] + grid[r+1][c] + grid[r+(h-1)][c] + grid[r+(h-1)][c+1] + grid[r+1][c+1] + grid[r+1][c+(w-1)] + grid[r][c+(2-1)];
      }
      else if (i == 0 && j == w-1){
        //IN UPPER RIGHT
        numNeighbors = grid[r+1][c] + grid[r][c-1] + grid[r+1][c-1] + grid[r+(h-1)][c] + grid[r+(h-1)][c-1] + grid[r+1][c-1] + grid[r+1][c-(w-1)] + grid[r][c-(w-1)];
      }
      else if (i == h-1 && j == 0){
        //IN BOTTOM LEFT
        numNeighbors = grid[r][c+1] + grid[r-1][c] + grid[r-1][c+1] + grid[r-(h-1)][c] + grid[r-(h-1)][c+1] + grid[r-1][c] + grid[r-1][c+(w-1)] + grid[r][c+(w-1)];

      }
      else if (i == h-1 && j == w-1){
        //IN BOTTOM RIGHT
        numNeighbors = grid[r-1][c] + grid[r][c-1] + grid[r-1][c-1] + grid[r-(h-1)][c] + grid[r-(h-1)][c-1] + grid[r-1][c-1] + grid[r-1][c-(w-1)] + grid[r][c-(w-1)];
      }
      else if (j == 0 && i != 0 && i != h-1){
        //IN LEFT SIDES
        numNeighbors = grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c] + grid[r+1][c+1] + grid[r-1][c+(w-1)] + grid[r+1][c+(w-1)] + grid[r][c+(w-1)];

      }
      else if(j == w-1 && i != 0 && i != h-1){
        //IN RIGHT SIDES
        numNeighbors = grid[r+1][c] + grid[r+1][c-1] + grid[r][c-1] + grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c-(w-1)] + grid[r+1][c-(w-1)] + grid[r][c-(w-1)];

      }
      else if (j != 0 && i == 0 && j != w-1){
        //IN TOP SIDES
        numNeighbors = grid[r][c-1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1] + grid[r][c+1] + grid[r+(h-1)][c-1] + grid[r+(h-1)][c+1] + grid[r+(h-1)][c];
      }
      else if (i == h-1 && j != 0 && j != w-1){
        //IN BOTTOM SIDES
        numNeighbors = grid[r][c-1] + grid[r][c+1] + grid[r-1][c+1] + grid[r-1][c] + grid[r-1][c-1] + grid[r-(h-1)][c-1] + grid[r-(h-1)][c+1] + grid[r-(h-1)][c];

      }
      else if(i != 0 && i != h-1 && j != 0 && j != w-1){
        //IN MIDDLE SECTIONS SAME AS CLASSIC!!!!
        numNeighbors = grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] + grid[r][c+1] + grid[r+1][c-1] + grid[r+1][c] + grid[r+1][c+1]+ grid[r][c-1];
      }


        //populating next generation out next generation
        if (numNeighbors == 3){
           newGen[i][j] = 1; // continue to lives on

       }
       else if (numNeighbors <=1){ //dies of loneliness :(
         newGen[i][j] = 0;

       }
       else if(numNeighbors == 2){ //  a location with 2 neighbors remains stable in the next gen.
         newGen[i][j] = grid[i][j];
         //calculate stable count
      }
       else{
        newGen[i][j] = 0;//overcrowded

      }
      if(grid[i][j] != newGen[i][j]){
        stableCount++;


      }
    }

  }

  printBoard(newGen);


  return newGen;

}
