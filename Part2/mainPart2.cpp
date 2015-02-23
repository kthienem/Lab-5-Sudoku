/* Kristopher Thieneman
 * Lab 5, Part 2
 * 
 * This is a driver file to demonstrate reading in two different files, one with
 * integers and one with characters, and displaying the sudoku board that they
 * correspnd to.
 */

#include <iostream>
#include "Puzzle.h" //header to read in files and make into a board

using namespace std;

int main()
{
  char number[20] = "sudokuPuzzle.txt";//name of file containing integer puzzle
  Puzzle<int> intPuzzle(number);
  intPuzzle.print();//prints board
  cout << endl;
  char word[20] = "wordoku.txt";//name of file containing character puzzle
  Puzzle<char> charPuzzle(word);
  charPuzzle.print();//prints board
}
