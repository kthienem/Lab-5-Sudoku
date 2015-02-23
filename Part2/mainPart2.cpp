#include <iostream>
#include "Puzzle.h"

using namespace std;

int main()
{
  char number[20] = "sudokuPuzzle.txt";
  Puzzle<int> intPuzzle(number);
  intPuzzle.print();
  cout << endl;
  char word[20] = "wordoku.txt";
  Puzzle<char> charPuzzle(word);
  charPuzzle.print();
}
