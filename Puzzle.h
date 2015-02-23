#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
class Puzzle{
  public:
    Puzzle();
    void print();
    void play();
    int isValid(int, int, int);
    int isSolved();

  private:
    vector<vector<T> > puzzleBoard; //the board containing the numbers for the puzzle
};

template <typename T>
Puzzle<T>::Puzzle()
{
  ifstream myFile;
  myFile.open("sudokuPuzzle.txt");
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

template <typename T>
void Puzzle<T>::play()
{
  int row, column, choice;

  while (isSolved() != 1){
    print();
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> column;
    cout << "Number to be placed: ";
    cin >> choice;

    if(isValid(row, column, choice) == 0){
      cout << "That is not a valid placement." << endl;
    }
    else{
      puzzleBoard[row-1][column-1] = choice;
    }
  }
  cout << "You have solved the puzzle." << endl;
}

template <typename T>
int Puzzle<T>::isValid(int row, int column, int choice)
{
  for(int i = 0; i < 9; i++){
    if(puzzleBoard[row-1][i] == choice) return 0;
  }

  for(int j = 0; j < 9; j++){
    if(puzzleBoard[j][column-1] == choice) return 0;
  }

  

  return 1;
}

template <typename T>
int Puzzle<T>::isSolved()
{
  
}
#endif
