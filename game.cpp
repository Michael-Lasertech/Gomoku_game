// <2382971>

#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


     game :: game()
     {
         //game::board_2d[15][15];
         game::rowPlay = 1;
         game::colPlay = 1;
     }



    void game::setRow(int r)
    {
       rowCheck = r;
    }


    void game::setCol(int c)
    {
       colCheck = c;
    }

    void game::setState(bool w)
    {
        state = w;
    }

    bool game::getState()
    {
        return state;
    }

     void game::CreateBoard(double arr[][15],int len)
     {
         for(int i = 0; i < len; i++)
         {
            for(int j =0; j < len; j++)
            {
              arr[i][j] = 0; // initialise array passes
              game :: board_2d[i][j] = arr[i][j] ; //using array to set game board
            }
         }

     }


     void game::ShowBoard(double arr[][15],int len)
     {
         for(int i = 0; i < len; i++)
         {
            for(int j =0; j < len; j++)
            {
             cout << game :: board_2d[i][j] << " ";

            }

            cout << " " << endl;
         }
     }


        void game::Algae1(int len)
        {   srand(time(0));
            bool cellSet = false;
            while (!cellSet)
         {
            int i = rand() % len;
            int j = rand() % len;

            if (game::board_2d[i][j] == 0)
            {
                game::board_2d[i][j] = 1;
                setRow(i);
                setCol(j); //After successfully generating a spot to place our 1, we then store coordinates to perform a check
                cout << "r1 = " << rowCheck << " c1 = " << colCheck << endl;
                cellSet = true;
            }
          }
        }

     void game::Algae2(int len)
     {
        {
         srand(time(0));
         bool cellSet = false;
         while (!cellSet)
         {
           int i = rand() % len;
           int j = rand() % len;

           if (game::board_2d[i][j] == 0)
            {
                game::board_2d[i][j] = 2;
                setRow(i);
                setCol(j); //After successfully generating a spot to place our 1, we then store coordinates to perform a check
                cout << "r2 = " << rowCheck << " c2 = " << colCheck << endl;
                cellSet = true;
            }
          }
        }
     }

      bool game::RwinCheck(int score1,int score2,int len){
          //5 in a row check
          for(int i = 0; i < len ; i++)
            {

                if (game::board_2d[rowCheck][i] == 1)
                {
                    score1++;
                    score2 = 0;
                }
               else
                     if (game::board_2d[rowCheck][i] == 2)
                {
                    score2++;
                    score1 = 0;
                }
                else
                     if (game::board_2d[rowCheck][i] == 0)
                {
                    score2 = 0;
                    score1 = 0;
                    //the count still counts zeros???zeros dont break the count, so make them
                }
                if(score1 >= 5 || score2 >= 5)
                {
                return true;
                }
                else
                {
                return  false;
                }
            }
      }



        bool CwinCheck(int score1,int score2, int len)
        {
             // 5 in a column
            for(int i = 0; i < len ; i++)
            {

                if (game::board_2d[i][colCheck] == 1)
                {
                    score1++;
                    score2 = 0;
                }

               else
                     if (game::board_2d[i][colCheck] == 2)
                {
                    score2++;
                    score1 = 0;
                }
                else
                     if (game::board_2d[i][colCheck] == 0)
                {
                    score2 = 0;
                    score1 = 0;

                }
                  if(score1 >= 5 || score2 >= 5)
                  {
                   return true;
                  }
                  else
                  {
                   return  false;
                  }
            }


        }

      bool game::CheckWin(int len)
      {
          int score1=0;
          int score2=0;

          if(RwinCheck(score1,score2,len))
            {
                return true;
            }

           if(CwinCheck(score1,score2,len))
            {
                return true;
            }

            if(diagCheck(score1,score2,len))
            {
                return true;
            }
    }


        bool diagCheck(int score1,int score2, int len)
        {
            //Diagonal Checks
             int sRowF, sColF;  //The starting row and column of the forward diagonal check
             int eRowF, eColF;  //The ending row and column of the forward diagonal check
             int sRowB, sColB;  //The starting row and column of the forward diagonal check
             int eRowB, eColB;  //The ending row and column of the forward diagonal check
             int shiftCol;
             int shiftRow;

             sRowF = rowCheck;
             sColF = colCheck;
             sRowB = rowCheck;
             sRowB = colCheck;
             eRowF = rowCheck;
             eColF = colCheck;
             eRowB = rowCheck;
             eRowB = colCheck;


             //initialised to a starting position. Now we need to find the actual diagonal start position on the board
             while(sRowF > 0 && sColF > 0)
                {
                    sRowF--;
                    sColF--;

                }


             //finding end position.
             while(eRowF < len && eColF < len)
             {
                   eRowF++;
                   eColF++;
             }

            //using i so as to not overwrite ending row
            int tempCol = sColF;
            for(int i = sRowF; i < eRowF; i++)
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
                 else
                 {
                   return  false;
                 }
                }

             //checking back diagonal
             while(sRowB > 0 && sColB < len)
                {
                    sRowB--;  //to reach start row, decrement
                    sColB++;  //increment coloumns

                }

             //finding end position.
             while(eRowB < len && eColB > 0)
             {
                   eRowB++;
                   eColB--;
             }

            //using i so as to not overwrite ending row
            tempCol = sColB;
            for(int i = sRowB; i < eRowB; i++)
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
                     else
                     {
                       return  false;
                     }
                }

            }


            }





