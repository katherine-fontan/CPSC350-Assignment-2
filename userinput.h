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

    int** boardArray = 0;
    int** update = 0;

    int height;
    int width;
    double density;
};
