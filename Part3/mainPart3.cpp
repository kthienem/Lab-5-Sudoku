/* Kristopher Thieneman
 * Lab 5, Part 3
 * 
 * Driver file to play a game of sudoku with integers as elements of the board.
 */

#include <iostream>
#include "Puzzle.h"

using namespace std;

int main()
{
  char puzzle[20] = "sudokuPuzzle.txt";//name of file containing puzzle to be read in
  Puzzle<int> myPuzzle(puzzle);//create object of type Puzzle<int> 

  myPuzzle.play();//play the game with the given board
}
