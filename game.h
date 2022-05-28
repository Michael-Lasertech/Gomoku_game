// <2382971>

#ifndef GAME_H
#define GAME_H


class game
{
  public:

      game();


      void CreateBoard(double arr[][15],int len);     //Used to create a board for the game

      void ShowBoard(double arr[][15],int len);

      void Algae1(int len);

      void Algae2(int len);

      bool CheckWin (int len);

      //int Rows();
      //int Cols();
      void setRow(int r);
      void setCol(int c);


  private:     //These are private attributes. They can only be accessed using the get and set functions

      double board_2d[15][15];  // Arrays need a maximum to be specified before compiling
      int rowPlay;
      int colPlay;
      int rowCheck;    //storage for a row
      int colCheck;    //storage for a column




};
#endif // GAME_H
