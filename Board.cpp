#include "Board.h"
#include <iostream>

using namespace std;

Board:: Board(){

}
Board:: ~Board(){

}

int Board::boardGenerator(){ /*pass in height, width and density*/

  //initialize height and width and density TEMPORARILY
  const int HEIGHT = 10;
  const int WIDTH = 12;
  const double DENSITY = 0.6;
  //random board

  /* If they want a random assignment, prompt for the dimensions of the world.
   Then prompt for a decimal value (greater than 0 and less than or equal to 1)
   representing the initial population density of the world.
   Randomly generate the initial cell configuration usingthe dimension and density inputs. */


   int totalCells = HEIGHT* WIDTH;
   double populatedCells = totalCells * DENSITY;
   int popCount = 0;
   int board[HEIGHT][WIDTH];

   for(int r = 0; r < HEIGHT; ++r){
     for (int c = 0; c < WIDTH; ++c){
       double randNum = ((double) rand() /(RAND_MAX +1.0));
       if(0 < randNum && randNum <= 1){//i dont know exactly if this is correct
         board[r][c] = 1; //also shouldnt it be 0 or 1 idk
         ++popCount;
       }

       if(popCount == populatedCells){
         break;
       }
     }
   }
   return 0;
}
