#define PUZZLE_H
#ifndef PUZZLE_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Puzzle{
  public:
    Puzzle();
    void print();

  private:
    vector<vector<T>> puzzleBoard; //the board containing the numbers for the puzzle
};

template <typename T>
Puzzle<T>::Puzzle()
{
  ifstream myFile;
  myFile.open(Sudoku-Puzzle.txt);
  vec<T> tempVec;
 
  for(int i = 0; i < 9; i++){
    for(int j = 0; i < 9; j++){
      tempVec.push_back(myFile);
    }
    puzzleBoard.push_back(tempVec);
    tempVec.clear();
  }
}

void Puzzle::print()
{
  for(int i = 0; i< 9; i++){
    for(int j = 0; j < 9; j++){
      cout << puzzleBoard[i][j];
    }
    cout << endl;
  }
}

#endif
