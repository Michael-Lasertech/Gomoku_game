// <2382971>

#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;


     game :: game()
     {

     }


     void game::CreateBoard(int len)
     {
         game::gamesize = len;
         for(int r = 0; r < len; r++)
         {
            for(int c =0; c < len; c++)
            {
              game :: board_2d[r][c] = 0;
            }
         }

     }


     void game::ShowBoard(std :: ofstream &dataOut)
     {
         for(int r = 0; r < gamesize; r++)
         {
            for(int c =0; c < gamesize; c++)
            {
             cout << game :: board_2d[r][c] << " ";
             //dataOut << game :: board_2d[r][c] << " ";

            }
            //dataOut << "\n";

            cout << " " << endl;
         }
     }


        bool game::Alg1( std :: ofstream &dataOut)
        {
            srand(time(0));
            int r = 0;
            int c = 0;
            bool cellSet = false;
            while (!cellSet)
         {
            int r = rand() % gamesize;
            int c = rand() % gamesize;

            if (game::board_2d[r][c] == 0)
            {
                game::board_2d[r][c] = 1;
                dataOut << "r" << r << "c" << c << " Alg1" << endl;

                cellSet = true;
            }
          }
          return CheckWin(r,c);
        }



      bool game::Alg2(std :: ofstream &dataOut)
      {   srand(time(0));
          int approach = 1;
          int choice = 0;
          int moves = 0;
          int r ;
          int c;

          bool cellSet = false;
          while (!cellSet)

          {

          while(choice >= gamesize)
           {
            choice = 0;

            if(moves > 3){
                approach++;
                if(approach > 3)
                    {
                        approach = 1;
                    }
            }

             switch (approach)
             {
             case 1:
             {

             r = rand() % gamesize;
             c = rand() % gamesize;

            if (game::board_2d[r][c] == 0)
            {
                game::board_2d[r][c] = 2;

                dataOut << "r" << r << "c" << c << " Alg2" << endl;

                cellSet = true;
            }
             moves++;

             break;
             }

             case 2:
             {
             c = rand() % gamesize;

            if (game::board_2d[choice][c] == 0)
             {
                game::board_2d[choice][c] = 2;
                //setRow(choice);
                r =choice;
                //setCol(c); //After successfully generating a spot to place our 1, we then store coordinates to perform a check
                dataOut << "r" << r << "c" << c << " Alg2" << endl;

                cellSet = true;
             }

             moves++;
             break;
             }

             case 3:
               {
                r = rand() % gamesize;

               if (game::board_2d[r][choice] == 0)
              {
                game::board_2d[r][choice] = 2;

                c = choice;
                dataOut << "r" << r << "c" << c << " Alg2" << endl;

                cellSet = true;
               }

             moves++;
             break;
               }
             }
           }

            choice++;

          }
          return CheckWin(r,c);
      }



      bool game::Row_Win(int row){
          //5 in a row check
        int score1 =0;
        int score2 =0;

          for(int i = 0; i < gamesize ; i++)
            {

                if (game::board_2d[row][i] == 1)
                {
                    score1++;
                    score2 =0;

                }
               else
                     if (game::board_2d[row][i] == 2)
                {
                    score2++;
                    score1 = 0;
                }
                else
                     if (game::board_2d[row][i] == 0)
                {
                    score2 = 0;
                    score1 = 0;
                }
                    if(score1 >= 5 || score2 >= 5)
                    {
                      return true;
                    }

            }     return false;
        }


        bool game::Col_Win(int col)
        {
           int score1 =0;
           int score2 =0;

            // 5 in a column
            for(int i = 0; i < gamesize ; i++)
            {
               if (game::board_2d[i][col] == 1)
                {
                    score1++;
                    score2 = 0;
                }

               else
                     if (game::board_2d[i][col] == 2)
                {
                    score2++;
                     score1 = 0;
                }
                else
                     if (game::board_2d[i][col] == 0)
                {
                    score2 =0;
                    score1 = 0;
                }
                if(score1 >= 5 || score2 >= 5)
                    {
                      return true;
                    }

            }     return false;

        }


        bool game::Forward_diagCheck(int row,int col)
        {
             int score1 =0;
             int score2 =0;

            //Diagonal Checks

             int startRow = row;
             int startCol = col;

             int endRow = row;
             int endCol= col;

             //initialised to a starting position. Now we need to find the actual diagonal start position on the board
             while(startRow > 0 && startCol > 0)
                {
                    startRow--;
                    startCol--;
                }

             //finding end position.
             while(endRow < gamesize && endCol < gamesize)
               {
                   endRow++;
                   endCol++;
               }

            //using i so as to not overwrite ending row
            int tempCol = startCol;
            for(int i = startRow; i <= endRow; i++)
                {
                     if (game::board_2d[i][tempCol] == 1)
                {
                    score1++;
                    score2 = 0;
                }

               else
                     if (game::board_2d[i][tempCol] == 2)
                {
                    score2++;
                    score1 = 0;
                }
                 else
                     if (game::board_2d[i][tempCol] == 0)
                {
                    score2 = 0;
                    score1 = 0;
                }
                tempCol++;
                    if(score1 >= 5 || score2 >= 5)
                    {
                      return true;
                    }

            }     return false;
            }


            bool game::Backward_diagCheck(int row, int col)
            {
             int score1 =0;
             int score2 =0;

             int startRow = row;
             int startCol = col;

             int endRow = row;
             int endCol= col;

             //checking back diagonal
             while(startRow > 0 && startCol < gamesize)
                {
                    startRow--;  //to reach start row, decrement
                    startCol++;  //increment coloumns

                }

             //finding end position.
             while(endRow< gamesize && endCol> 0)
             {
                   endRow++;
                   endCol--;
             }

            //using i so as to not overwrite ending row
            int tempCol = startCol;
            for(int i = startRow; i <= endRow; i++)
                {
                     if (game::board_2d[i][tempCol] == 1)
                {
                    score1++;
                    score2 = 0;
                }

               else
                     if (game::board_2d[i][tempCol] == 2)
                {
                    score2++;
                    score1 = 0;
                }

                else
                     if (game::board_2d[i][tempCol] == 0)
                {
                    score2 = 0;
                    score1 = 0;

                }
                tempCol --;

                  if(score1 >= 5 || score2 >= 5)
                    {
                      return true;
                    }

            }     return false;
            }

        bool game::CheckWin(int row, int col)
        {
          if(Row_Win(row))
            {
                return true;
            }
          else if(Col_Win(col))
            {
                return true;
            }
          else if(Forward_diagCheck(row,col))
            {
                return true;
            }
          else if(Backward_diagCheck(row,col))
            {
                return true;
            }

                return false;
         }

