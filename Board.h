#include <iostream>

class Board{

  public:
    Board();
    Board(int height, int width, double density);
    ~Board();
    int boardGenerator();
    void run();
    void runClassic(int** grid);

    int** grid;
    int** newGenArray;

    int height;
    int width;
    double density;

};
