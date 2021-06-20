#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 2

// this function taks numbers to the array
void data_array(int array[][SIZE*SIZE], int size);
// this  function handels the input 
int check_input(int input);

//checks the row
bool check_row(int array[][SIZE*SIZE], int value, int row, int size);
// checks the col
bool check_col(int array[][SIZE*SIZE], int value, int col, int size);

// checks thw square 
bool check_square(int array[][SIZE*SIZE],int value,int row,int col);

// prints the sudoku 
void print_Sudoku(int array[][SIZE*SIZE], int size);

bool solve_Sudoku(int array[][SIZE*SIZE], int row,int col);


int main(){
  int sudoku[SIZE*SIZE][SIZE*SIZE];

  
    data_array (sudoku, SIZE*SIZE);

    if(solve_Sudoku(sudoku, 0, 0))
    {
      print_Sudoku(sudoku, SIZE*SIZE);
    }
    else 
        printf("-1\n");
    
  return 0;
}

// this function solves the sudoku
bool solve_Sudoku(int array[][SIZE*SIZE], int row,int col)
{
    int i;
	// this conditon will stop the program
	if(row == SIZE*SIZE)
		return true;

	// if the value is 0 insert i and check condition
	if(array[row][col] == 0)
	{
		for(i = 1; i <= SIZE*SIZE; i++)
	    {
		    if(col == SIZE*SIZE - 1)
		    {
                array[row][col] = i;
                
    	        if(check_square(array,i,row,col) &&
    	        check_row(array,i,row,SIZE*SIZE)
    	        && check_col(array,i,col,SIZE*SIZE))
    	        {
    	            if(solve_Sudoku(array, row + 1, 0))
                        return true; 
    	        }
        		    
    			array[row][col] = 0;
	        }
	        else
    	    {
    	        array[row][col] = i;
            
    	        if(check_square(array,i,row,col) &&
    	        check_row(array,i,row,SIZE*SIZE) 
    	        && check_col(array,i,col,SIZE*SIZE))
    	        {
    	            if(solve_Sudoku(array, row, col + 1))
                        return true; 
    	        }
    	        
    	        array[row][col] = 0;
    	    }
	    }
	    
	    return false;
	}
    else
    {	// this will check if its the last col and move to diffrent row
        if(col == SIZE*SIZE - 1){
        	if(solve_Sudoku(array, row + 1 , 0))
        		return true;
        	else
        		return false;
        }
        else 
        {
          if(solve_Sudoku(array, row, col + 1))
        		return true;
        	else
        		return false;
        }
    }
    return false;
}


// inserts input to the array
void data_array (int array[][SIZE*SIZE], int size)
{
  int i, j;
  int input = -1;

for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
	{
	  scanf ("%d", &input);
	  array[i][j] = check_input (input);

	    }
    }

}

// this functions checks the input of the user
int check_input (int input)
{
  while (input < 0 || input >= 10)
    {

      printf ("Enter a number between 0 and 4 for 2*2 or 0-9 fir 3*3: ");
      scanf ("%d", &input);
      if (input < 0 || input >= 10)
	printf ("Out of range\n");
    }
  return input;
}

// this function ptints the sudoku
void print_Sudoku(int array[][SIZE*SIZE], int size)
{
  int row, col;
  for (row = 0; row < SIZE*SIZE; row++)
    {
      for(col = 0; col < SIZE*SIZE; col++)
	    printf ("%d ", array[row][col]);
        puts("");
        }
}

// this function checks if the number his accuring more then 1 time in the row
 bool check_row(int array[][SIZE*SIZE], int value, int row, int size)
  {
    int i;
    int counter = 0;
    for (i = 0; i < size; i++)
      {
	if (array[row][i] == value)
	  {
	    counter++;
	    if (counter > 1)
	      return false;
	  }
      }
    return true;
  }
  

// this function checks if the number his accuring more then 1 time in the col
  bool check_col(int array[][SIZE*SIZE], int value, int col, int size)
  {
    int i;
    int counter = 0;

    for (i = 0; i < size; i++)
      {
	if (array[i][col] == value)
	  {
	    counter++;
	    if (counter > 1)
	      return false;
	  }
      }
      return true;
  }

// this function schecks if the row and the col have a perfect square;
bool check_square(int array[][SIZE * SIZE], int value, int row, int col)
{
    int row_start, col_start;
    
    for(row_start = row/SIZE*SIZE; row_start < row/SIZE*SIZE +SIZE; row_start++)
    {
        for(col_start = col/SIZE*SIZE; col_start < col/SIZE*SIZE +SIZE; col_start++)
        {
            if(array[row_start][col_start] == value && row_start != row && col_start != col)
            return false;
        }
    }
    return true;
}