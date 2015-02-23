/* Kristopher Thieneman
 * Lab 5, Part 2
 *
 * Templated header file for reading a file containing a sudoku board with any
 * type of data type in it, as long as the file is all one type. 
 */

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <fstream>//needed to read in file
#include <vector>

using namespace std;

template <typename T>//template class as type T
class Puzzle{
  public:
    Puzzle(char [20]);//non-default constructor takes in name of file to be opened
    void print(); //prints board

  private:
    vector<vector<T> > puzzleBoard; //the board containing the numbers for the puzzle
};

template <typename T>//needed before each function becuase Puzzle is of type T
Puzzle<T>::Puzzle(char inFile[20])
{
  ifstream myFile;//creates a member that a file is read in to
  myFile.open(inFile);//opens the file given as an input to the constructor
  vector<T> tempVec; //creates a temporary vector of type T
  T temp; //value of type T

  for(int i = 0; i < 9; i++){//loops through a 9x9 board
    for(int j = 0; j < 9; j++){
      myFile >> temp;//takes in a value from file, white space is used as a delimitor
      tempVec.push_back(temp);//puts the read in value into the temporary vector
    }
    puzzleBoard.push_back(tempVec);//once a vector of length 9 is created, push it in the 2D vector puzzleBoard
    tempVec.clear();//empty the temp vector
  }
}

template <typename T>
void Puzzle<T>::print()
{//prints board on screen
  for(int i = 0; i< 9; i++){//loops through 9x9 board
    for(int j = 0; j < 9; j++){
      cout << puzzleBoard[i][j];//prints the i,j th element of the board
      if(((j+1)%3==0) && (j!=8)) cout << " |";//prints a bar after three columns have been printed
      cout << " ";
    }
    cout << endl;
    if(((i+1)%3==0) && (i!=8)){
      cout << "---------------------" << endl;//prints a horizontal line after three rows have been printed
    }
  }
}

#endif
