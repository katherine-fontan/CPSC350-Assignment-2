#include <iostream>

class ClassicMode{
  public:
    ClassicMode();
    //ClassicMode(); //string boardMode
    ~ClassicMode();

    int numNeighbors();
    void cellGenerator(int numNeighbors);


    //int numNeighbors;
    //int stableCounts;
    //int length;
    //int width;
    int** array;
    int** newGenArray;



};
