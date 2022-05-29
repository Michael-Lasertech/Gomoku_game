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
      void Alg1( std::ofstream &dataOut);
      void Alg2();

      bool CheckWin ();

      //void Alg3(int len);

      void setRow(int r);
      void setCol(int c);
      int getRow();
      int getCol();



  private:     //These are private attributes. They can only be accessed using the get and set functions

      double board_2d[15][15];  // Arrays need a maximum to be specified before compiling
      int rowPlay;
      int colPlay;
      int rowCheck;    //storage for a row
      int colCheck;    //storage for a column
      int gamesize;

      bool Row_Win();
      bool Col_Win();
      bool Forward_diagCheck();
      bool Backward_diagCheck();


};
#endif // GAME_H
