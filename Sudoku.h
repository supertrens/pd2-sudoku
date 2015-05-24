#ifndef DEF_SUDOKU
#define DEF_SUDOKU

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

class Sudoku
{
public:

    static const int sudoku_size = 12;

    Sudoku();
    Sudoku(int init_grille[sudoku_size][sudoku_size]);



    void ReadIn ( );
    void GiveQuestion();
    void Solve ();
    void PrintBoard( int grille[sudoku_size][sudoku_size]);
    void AddExtra();



private:

//Private attributes
int grille[sudoku_size][sudoku_size];
int no_number ;
int dont_care ;
int tmp;
bool check;

// Private Methods

bool AbsentSurLigne (int k, int grille[sudoku_size][sudoku_size], int i); // to check the row
bool AbsentSurColonne (int k, int grille[sudoku_size][sudoku_size], int j); // to check the column
bool AbsentSurBloc (int k, int grille[sudoku_size][sudoku_size], int i, int j); // to check the block
bool EstValide (int grille[sudoku_size][sudoku_size], int position); // to check if it's valid

};

#endif // DEF_SUDOKU



