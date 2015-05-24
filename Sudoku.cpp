#include "Sudoku.h"


using namespace std;


Sudoku::Sudoku()
    {
        no_number = 0;
        dont_care = 0;
        tmp = 0;
        check = true;

        for (int i = 0 ; i < sudoku_size ; ++i)
         for (int j = 0; j<  sudoku_size ; ++j)
          {
              grille[i][j]= 0;
              dont_care++;
          }
    }

Sudoku::Sudoku (int init_grille[sudoku_size][sudoku_size])
{
        no_number = 0;
        dont_care = 0;

        for (int i = 0 ; i <sudoku_size ; ++i)
          for(int j = 0; j < sudoku_size ; ++j)
           grille[i][j]= init_grille[i][j];

}


void Sudoku::ReadIn()
    {
       // cout << "Please Input the Sudoku_board?"<< endl;
            for(int i=0 ; i < sudoku_size ; ++i) //loop to read the map
				for(int j = 0 ; j < sudoku_size ; ++j)
				{
					do
                                     {
 					    //  cout << i+1 << ". row " << j+1 << ". column: ";
                                           cin >> grille[i][j];
				     }
					while( grille[i][j] <= 0 && grille[i][j] > 10);

					if( grille[i][j]==0)
						no_number++;
                    if (grille[i][j] == -1)
                        dont_care++;
				}
     //   PrintBoard (grille);
    }


void Sudoku::Solve()
{
    check = EstValide(grille,0);
    // cout <<" Solution: " <<endl;

    //puts("-------------------------------------------");
    if (check)
        {
            cout << "1"<<endl;
           // AddExtra();
            PrintBoard (grille);
        }
    else
        cout<<"0" <<endl;

}

void Sudoku::GiveQuestion()
{

    int row = 0 , column=0,  position=0; // to  randomly save the map position

    srand (time(NULL));
    position = rand() %10;

    Sudoku::EstValide(grille, position);




      for (int i = 0 ; i < 45; ++i)

          {
             row = rand() % 10;
             column  = rand() % 10;
             if ( grille[row][column] != -1)
             grille[row][column]= 0;
          }
          PrintBoard(grille);

}


void Sudoku::PrintBoard (int grille[sudoku_size][sudoku_size])
  {
     // cout<<"1" <<endl;
      for (int i = 0 ; i < sudoku_size ; ++i)
      {
        for (int j = 0; j < sudoku_size ; ++j)
        {
             
             printf( ((j+1)%3) ? "%2d " : "%2d  ", grille[i][j]);
        }
        putchar('\n');
       // if (!((i+1)%3) );
       //  puts("-------------------------------------------");
      }
      puts("\n\n");
  }


  void Sudoku::AddExtra( )
  {
      // add Extra -1 at the last square
    for (int i=0 ; i < 3 ; ++i)
         for (int j =9; j < sudoku_size ; ++j)
          grille[i][j] =-1 ;

     // add extra -1 at the first square
       for (int i = 3 ; i < 6 ; ++i)
         for (int j = 0; j < 3 ; ++j)
          grille[i][j] =-1;

     for (int i=6 ; i < 9 ; ++i)
         for (int j =6; j < 9 ; ++j)
          grille[i][j] =-1;

      for (int i=9 ; i < sudoku_size ; ++i)
         for (int j = 3; j < 6 ; ++j)
          grille[i][j] =-1;

  }


bool Sudoku::EstValide (int grille[sudoku_size][sudoku_size], int position)
{
    // if we are out of the range , we quit the map
    if (position == sudoku_size*sudoku_size)
        return true;
    // we take the position i,j of the square
    int i = position/sudoku_size, j = position%sudoku_size;

    // If the case is not empty, we go to the next (recursif)
    if (grille[i][j] != 0)
        return EstValide(grille, position+1);
    if( grille[i][j] == -1)
        return EstValide(grille,position);
   // Backtrack to enumerate the possible value
    for (int k=1; k <= 9; ++k)
    {
        //If the digit is absent , we can accept it
        if (AbsentSurLigne(k,grille,i) && AbsentSurColonne(k,grille,j) && AbsentSurBloc(k,grille,i,j))
        {
            //we save it at position  i j
            grille[i][j] = k;

            // and call recursively the function EstValide to see if the choice is good
            if ( EstValide (grille, position+1) )
                return true; // Since , the choice is good, we stop
        }
    }
    grille[i][j] = 0; // No digit is ok after test, so reinitialize the case

    return false;
}


// Method to check the row
bool Sudoku::AbsentSurLigne (int k, int grille[sudoku_size][sudoku_size], int i)
{
    for (int j=0; j < sudoku_size; j++)
        if (grille[i][j] == k)
            return false;
    return true;
}

//Method to check the column

bool Sudoku::AbsentSurColonne (int k, int grille[sudoku_size][sudoku_size], int j)
{
    for (int i=0; i < sudoku_size; i++)
        if (grille[i][j] == k)
            return false;
    return true;
}

// Method to check the block
bool Sudoku::AbsentSurBloc (int k, int grille[sudoku_size][sudoku_size], int i, int j)
{
    int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
    for (i=_i; i < _i+3; i++)
        for (j=_j; j < _j+3; j++)
            if (grille[i][j] == k)
                return false;
    return true;
}






