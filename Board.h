#include <iostream>

class Board{

  public:
    Board();
    Board(int height, int width);
    Board(int height, int width, double density);
    ~Board();
    int** boardGenerator();
    void runClassic(int** grid,int height, int width);
    void runClassicFile(int** array);
    void runDonut(int** grid);
    void runMirror(int** grid);

    int** array;

    int** grid;
    int** newGenArray;


    int height;
    int width;
    double density;

};
