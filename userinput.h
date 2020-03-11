#include "Board.h"
#include <iostream>

class UserInput{

  public:
    UserInput();
    ~UserInput();
    void askConfig();
    void askBoardType();
    void askPauseOption();
    void getConfig(int i);

    Board *board;
};
