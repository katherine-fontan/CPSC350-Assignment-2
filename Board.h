#include <iostream>

class Board{

  public:
    Board();
    ~Board();
    int boardGenerator();
    void run();
    void runClassic(int** grid);

    int** grid;
    int** newGenArray;

};
