#define PUZZLE_H
#ifndef PUZZLE_H

template <typename T>
class Puzzle{
  public:
    Puzzle();

  private:
    vector<vector<T>> puzzleBoard; //the board containing the numbers for the puzzle
}

Puzzle::Puzzle()
{
  for(int i = 0; i < 9; i++){
    for(int j = 0; i < 9; i++){
      puzzleBoard.insert(puzzleBoard[i][j], 0);
    }
  }
}
}

#endif
