// <2382971>

#ifndef GAME_H
#define GAME_H


class game
{
  public:

      game();

      void CreateBoard(int len);     //Used to create a board for the game
      void ShowBoard(int len);
      void Algae1(int len);
      void Algae2(int len);
      void TestAlg(int len);
      bool CheckWin (int len);

      void setRow(int r);
      void setCol(int c);
      int getRow();
      int getCol();

      bool Row_Win(int len);
      bool Col_Win(int len);
      bool Forward_diagCheck(int len);
      bool Backward_diagCheck(int len);


  private:     //These are private attributes. They can only be accessed using the get and set functions

      double board_2d[15][15];  // Arrays need a maximum to be specified before compiling
      int rowPlay;
      int colPlay;
      int rowCheck;    //storage for a row
      int colCheck;    //storage for a column
      bool state;      //whether or not we have a winner


};
#endif // GAME_H
