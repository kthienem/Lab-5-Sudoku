#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
class Puzzle{
  public:
    Puzzle(char []);
    void print();

  private:
    vector<vector<T> > puzzleBoard; //the board containing the numbers for the puzzle
};

template <typename T>
Puzzle<T>::Puzzle(char inFile[20])
{
  ifstream myFile;
  myFile.open(inFile);
  vector<T> tempVec;
  T temp;

  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      myFile >> temp;
      tempVec.push_back(temp);
    }
    puzzleBoard.push_back(tempVec);
    tempVec.clear();
  }
}

template <typename T>
void Puzzle<T>::print()
{
  for(int i = 0; i< 9; i++){
    for(int j = 0; j < 9; j++){
      cout << puzzleBoard[i][j];
      if((j+1)%3==0) cout << "|";
    }
    cout << endl;
    if(((i+1)%3==0) && (i!=8)){
      cout << "------------" << endl;
    }
  }
}

#endif
