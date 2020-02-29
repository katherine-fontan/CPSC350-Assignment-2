#include "ClassicMode.h"
#include <iostream>
using namespace std;

ClassicMode:: ClassicMode(/* pass in a board*/){

}
//overloaded constructor here
ClassicMode:: ~ClassicMode(/* pass in board from main*/){
  //array = board;
}

int ClassicMode:: numNeighbors(){
  int array[10][12];  //use height (num rows) and  width (num columns)
  int numNeighbors;


  for (int i = 0; i < 10; ++i){
    for (int j = 0; j < 12; ++j){
      int r = i;
      int c = j;


    numNeighbors = array[r-1][c-1] + array[r-1][c] + array[r-1][c+1] + array[r][c+1] +array[r+1][c-1] + array[r+1][c]
      + array[r+1][c-1]+ array[r][c-1];
    }
  }
  return numNeighbors;
}

void ClassicMode:: cellGenerator(int numNeighbors){

  newGenArray[10][12];
  for (int i = 0; i < 10; ++i){
    for (int j = 0; j < 10; ++j){


       if (numNeighbors == 3){
        if(array[i][j] == 1){
          newGenArray[i][j] = 1; // continue to lives on
        }

        else if(array[i][j] == 0){
            newGenArray[i][j] = 1; // a new cell is born if its empty
        }
      }
      else if (numNeighbors >= 4 || numNeighbors <=1){ //overcrowded :(
        newGenArray[i][j] = 0;
      }
      else if(numNeighbors == 2){ //  a location with 2 neighbors remains stable in the next gen.

        if(array[i][j] == 1) {// if full it remains full
          newGenArray[i][j] = 1;
        }
        else if (array[i][j] == 0){// if empty remains empty
          newGenArray[i][j] = 0;
        }
        //calculate stable count
      }
    }
  }
}
