// <2382971>

#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <iostream>

using namespace std;

class game
{
  public:

      game();

      void CreateBoard(int len);     //Used to create a board for the game
      void ShowBoard();
      bool Alg1( std::ofstream &dataOut);
      bool Alg2(std::ofstream &dataOut);


  private:     //These are private attributes. They can only be accessed using the get and set functions

      double board_2d[15][15];  // Arrays need a maximum to be specified before compiling
      bool CheckWin (int row, int col);
      int rowPlay;
      int colPlay;
      int rowCheck;    //storage for a row
      int colCheck;    //storage for a column
      int gamesize;

      bool Row_Win(int row);
      bool Col_Win(int col);
      bool Forward_diagCheck(int row, int col);
      bool Backward_diagCheck(int row,int col);

      void setRow(int r);
      void setCol(int c);
//      int getRow();
//      int getCol();


};
#endif // GAME_H
