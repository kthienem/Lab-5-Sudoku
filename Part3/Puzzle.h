/* Kristopher Thieneman
 * Lab5, Part 3
 * 
 * Header file to read in a file containing a sudoku board and play that puzzle.
 * Checks if users placement is valid and does not let the user overwrite 
 * numbers that were already placed in the original puzzle.
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
    void print();//prints board
    void play();//function to let the user play the board
    int isValid(int, int, int);//checks if the location and input of the user is valid
    int isSolved();//checks if the board has been solved

  private:
    vector<vector<T> > puzzleBoard; //the board containing the numbers for the puzzle
    vector<vector<T> > originalBoard; //contains the original board from before user input
};

template <typename T>//needed before each function because Puzzle is of type T
Puzzle<T>::Puzzle(char inFile[20])
{
  ifstream myFile;//creates a memeber that a file is read in to
  myFile.open(inFile);//opens the file given as an input to the constructor
  vector<T> tempVec;//creates a temporary vector of type T
  T temp;//value of type T

  for(int i = 0; i < 9; i++){//loops through a 9x9 board
    for(int j = 0; j < 9; j++){
      myFile >> temp;//takes in a value from file, white space is used as a delimitor
      tempVec.push_back(temp);//puts the read in value into the temp vector
    }
    puzzleBoard.push_back(tempVec);//once a vector of length 9 is created, push it in the 2D vector puzzleBoard
    tempVec.clear();//empty the temp vector
  }

  originalBoard = puzzleBoard;//sets the originalBoard equal to the read in board before any changes are made
}

template <typename T>
void Puzzle<T>::print()
{//prints board on screen
  for(int i = 0; i< 9; i++){//loops through 9x9 board
    for(int j = 0; j < 9; j++){
      cout << puzzleBoard[i][j];//print the i,j th element of the board
      if(((j+1)%3==0) && (j!=8)) cout << " |";//prints a bar after 3 columns have been printed
      cout << " ";
    }
    cout << endl;
    if(((i+1)%3==0) && (i!=8)){
      cout << "---------------------" << endl;//prints a horizontal line after 3 rows have been printed
    }
  }
}

template <typename T>
void Puzzle<T>::play()
{//prmpts user to put numbers into the board to play the game
  int row, column, choice;//inputs from the user

  while (isSolved() != 1){//each time through the loop it checks if it has been solved
    print();//prints the board
    cout << "Enter row: ";//asks user to input which row the cell is in
    cin >> row;
    cout << "Enter column: ";//asks user to input which column the cell is in
    cin >> column;
    cout << "Number to be placed: ";//ask the user to input what number they want to place in the board
    cin >> choice;

    if((row > 9) || (row < 1)){//checks if the row number is between 1 and 9
      cout << "That is not a valid position." << endl;
    }
    else if((column > 9) || (column < 1)){//checks if the column number is between 1 and 9
      cout << "That is not a valid position." << endl;
    }
    else if((choice > 9) || (choice < 1)){//checks if the input is between 1 and 9
      cout << "That is not a valid input." << endl;
    }
    else if((originalBoard[row-1][column-1]!=0) || (isValid(row-1, column-1, choice) == 0)){//checks that the position is not a number set from the original board and that the number is a valid placement
      cout << "That is not a valid placement." << endl;
    }
    else{//if all previous if statements are not an issue set that position to the user inputted value
      puzzleBoard[row-1][column-1] = choice;
    }
  }
  print(); //print the solved puzzle
  cout << "You have solved the puzzle." << endl;//tells teh user they have solved the puzzle at the end
}

template <typename T>
int Puzzle<T>::isValid(int row, int column, int choice)
{//function to check if a number placement is valid
  
  for(int i = 0; i < 9; i++){//checks if the user inputed number does not occur anywhere else in the row
    if(puzzleBoard[row][i] == choice) return 0;
  }

  for(int j = 0; j < 9; j++){//checks if the user inputed number does not occur anywhere else in the row 
    if(puzzleBoard[j][column] == choice) return 0;
  }

  //integer division returns a number that corresponds to which minigrid the cell is in
  //multiplying by 3 then gets the first row or column number of that minigrid
  int colRange = (column/3)*3;
  int rowRange = (row/3)*3;

  for(int k = colRange; k < colRange+3; k++){//goes from previous computed value to 2 greater than it, e.g. 6 to 8
    for(int l = rowRange; l < rowRange+3; l++){
      if(puzzleBoard[l][k] == choice) return 0;
    }
  }
//if there is no conflict with the number and position return a 1
  return 1;
}

template <typename T>
int Puzzle<T>::isSolved()
{//determines if the puzzle has been solved
  for(int i = 0; i < 9; i++){//loops through 9x9 grid
    for(int j = 0; j < 9; j++){
      if(puzzleBoard[i][j] == 0) return 0; //if there is a zero in the cell return a 0 for not solved
    }
  }

  return 1;//return a 1 if the puzzle is solved
}
#endif
