#include <iostream>

class Board{

  public:
    Board();
    Board(int height, int width);
    Board(int height, int width, double density);
    ~Board();
    int** boardGenerator();
    void runClassic(int** grid,int height, int width);
    void printBoard(int** grid);
    int** updateBoard(int** grid);

    void runDonut(int** grid);
    void runMirror(int** grid);

    int** grid;
    int** newGen;


    int height;
    int width;
    double density;

};
