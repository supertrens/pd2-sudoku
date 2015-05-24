#include <iostream>
#include <cstdlib>

#include "Sudoku.h"

using namespace std;

int main()
{
    Sudoku a;
     //a.GiveQuestion();

    a.ReadIn();
    a.Solve();
    return 0;
}



