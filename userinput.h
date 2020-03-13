#include "Board.h"
#include <iostream>

class UserInput{

  public:
    UserInput();
    ~UserInput();
    void askConfig();
    void askBoardType(int** someArray);
    void askPauseOption();
    void getFile(int i);

    Board *board;

    int** boardArray;
    int** update;

    int height;
    int width;
    double density;
};
