#include "main.h"
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
      //reading through file given and print out contents of file
      while(f >> line)
      {
        //code for making file into an array
      }
    i = 0;
    f.close();
    }
  }
  //random board will be created
  if(i = 2)
  {
    c//code for random board here
  }
}
