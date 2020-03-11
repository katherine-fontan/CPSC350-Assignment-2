#include "configuration.h"
#include "Board.h"
#include <fstream>
using namespace std;


void configuration::getConfig(int i)
{
  while(i == 1)
  {
    string fileName;
    ifstream f;
    string line;
    cout <<"Enter a filename. ";
    cin >> fileName;

    f.open(fileName);

    if(!f)
    {
      cout << "Filename was not found. Try again. ";
    }
    else
    {
      //reads first line and makes into row dimension
      getline(f, line);
      int line1 = stoi(line);
      //reads second line an makes into column dimension
      getline(f, line);
      int line2 = stoi(line);

      //initialize array
      char myArray[line1][line2];
      
      //read through array and print out array contents
      for(int i = 0; i < line1; i++) {
        for(int j = 0; j < line2; j++) {
          if(myArray)


          f >> myArray[i][j];
          cout << myArray[i][j];

        }
        cout << endl;
    }
    i = 0;
    f.close();
    }
  }

  //random board will be created
  if(i == 2)
  {
    //code for random board here
    //Board* b = new Board();
     //b->boardGenerator();
    // cout << b -> grid << endl;
  }
}
