#include <iostream>

class Board{

  public:
    Board();
    Board(int height, int width);
    Board(int height, int width, double density);
    ~Board();
    int** boardGenerator();
    int** runClassic(int** grid, int height, int width);
    void printBoard(int** grid);
    int** updateBoard(int** grid);

    int** runDonut(int** grid, int height, int width);
    int** runMirror(int** grid, int height, int width);

    bool stabilityOfBoard(int** gridOld, int** gridNew, int height, int width);


    int** grid = 0;
    int** newGen = 0;


    int height;
    int width;
    double density;


};
