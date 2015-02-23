#include <iostream>
#include "Puzzle.h"

using namespace std;

int main()
{
  Puzzle<int> intPuzzle;
  intPuzzle.print();

  Puzzle<char> charPuzzle;
  charPuzzle.print();
}
