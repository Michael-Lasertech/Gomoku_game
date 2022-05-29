// <2382971>

#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;


     game :: game()
     {
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

    int game::getRow()
    {
       int r = rowCheck;
       return r;
    }

    int game::getCol()
    {
       int c = colCheck;
       return c;
    }

     void game::CreateBoard(int len)
     {
         game::gamesize = len;
         for(int i = 0; i < len; i++)
         {
            for(int j =0; j < len; j++)
            {
              game :: board_2d[i][j] = 0;
            }
         }

     }


     void game::ShowBoard()
     {
         for(int i = 0; i < gamesize; i++)
         {
            for(int j =0; j < gamesize; j++)
            {
             cout << game :: board_2d[i][j] << " ";

            }

            cout << " " << endl;
         }
     }


        void game::Alg1( std :: ofstream &dataOut)
        {   srand(time(0));
            bool cellSet = false;
            while (!cellSet)
         {
            int i = rand() % gamesize;
            int j = rand() % gamesize;

            if (game::board_2d[i][j] == 0)
            {
                game::board_2d[i][j] = 1;
                setRow(i);
                setCol(j); //After successfully generating a spot to place our 1, we then store coordinates to perform a check
                dataOut << "did data out r" << getRow() << "c" << getCol() << " Alg1" << endl;

                cellSet = true;
            }
          }
        }



      void game::Alg2()
      {   srand(time(0));
          int approach = 1;
          int choice = 0;
          int moves = 0;
          int i;
          int j;

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

             i = rand() % gamesize;
             j = rand() % gamesize;

            if (game::board_2d[i][j] == 0)
            {
                game::board_2d[i][j] = 2;
                setRow(i);
                setCol(j); //After successfully generating a spot to place our 1, we then store coordinates to perform a check

                cellSet = true;
            }

             moves++;
             break;
             }

             case 2:
             {
             j = rand() % gamesize;

           if (game::board_2d[choice][j] == 0)
            {
                game::board_2d[choice][j] = 2;
                setRow(choice);
                setCol(j); //After successfully generating a spot to place our 1, we then store coordinates to perform a check

                cellSet = true;
            }

             moves++;
             break;
             }

             case 3:
               {
                i = rand() % gamesize;

               if (game::board_2d[i][choice] == 0)
              {
                game::board_2d[i][choice] = 2;
                setRow(i);
                setCol(choice); //After successfully generating a spot to place our 1, we then store coordinates to perform a check

                cellSet = true;
               }
             moves++;
             break;
               }
             }
           }

            choice++;

          }
      }

//     void game::Alg3(int gamesize)
//     {
//        {
//         srand(time(0));
//         int i = 0;
//         int j = rand() % gamesize;
//         bool cellSet = false;
//         while (!cellSet)
//         {
//           while(i >= gamesize)
//           {
//             j = rand() % gamesize;
//             i = 0;
//           }
//
//           if (game::board_2d[i][j] == 0)
//            {
//                game::board_2d[i][j] = 2;
//                setRow(i);
//                setCol(j); //After successfully generating a spot to place our 1, we then store coordinates to perform a check
//
//                cellSet = true;
//            }
//            i++;
//
//          }
//        }
//     }





      bool game::Row_Win(){
          //5 in a row check
        int score1 =0;
        int score2 =0;
        int p1 = score1;
        int p2 = score2;

          for(int i = 0; i < gamesize ; i++)
            {

                if (game::board_2d[rowCheck][i] == 1)
                {
                    p1++;
                    p2 =0;

                }
               else
                     if (game::board_2d[rowCheck][i] == 2)
                {
                    p2++;
                    p1 = 0;
                }
                else
                     if (game::board_2d[rowCheck][i] == 0)
                {
                    p2 = 0;
                    p1 = 0;
                }

                if(p1 >= 5 || p2 >= 5)
                    {
                       score1 = p1;
                       score2 = p2;
                       break;
                    }
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


        bool game::Col_Win()
        {
           int score1 =0;
           int score2 =0;

            // 5 in a column
            for(int i = 0; i < gamesize ; i++)
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
                    score2 =0;
                    score1 = 0;
                }
                if(score1 >= 5 || score2 >= 5)
                    {
                      return true;
                    }

            }     return false;

        }


        bool game::Forward_diagCheck()
        {
             int score1 =0;
             int score2 =0;
             int p1 = score1;
             int p2 = score2;
            //Diagonal Checks
             int sRowF, sColF;  //The starting row and column of the forward diagonal check
             int eRowF, eColF;  //The ending row and column of the forward diagonal check

             sRowF = rowCheck;
             sColF = colCheck;

             eRowF = rowCheck;
             eColF = colCheck;

             //initialised to a starting position. Now we need to find the actual diagonal start position on the board
             while(sRowF > 0 && sColF > 0)
                {
                    sRowF--;
                    sColF--;
                }

             //finding end position.
             while(eRowF < gamesize && eColF < gamesize)
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
                    p1++;
                    p2 = 0;
                }

               else
                     if (game::board_2d[i][tempCol] == 2)
                {
                    p2++;
                    p1 = 0;
                }
                 else
                     if (game::board_2d[i][tempCol] == 0)
                {
                    p2 = 0;
                    p1 = 0;
                }
                tempCol++;
                    if(p1 >= 5 || p2 >= 5)
                    {
                       score1 = p1;
                       score2 = p2;
                       break;
                    }

                }
                return(score1 >= 5 || score2 >= 5);
            }


            bool game::Backward_diagCheck()
            {
             int score1 =0;
             int score2 =0;
             int p1 = score1;
             int p2 = score2;

             int sRowB, sColB;  //The starting row and column of the backward diagonal check
             int eRowB, eColB;  //The ending row and column of the backward diagonal check

             sRowB = rowCheck;
             sColB = colCheck;

             eRowB = rowCheck;
             eColB = colCheck;

             //checking back diagonal
             while(sRowB > 0 && sColB < gamesize)
                {
                    sRowB--;  //to reach start row, decrement
                    sColB++;  //increment coloumns

                }

             //finding end position.
             while(eRowB < gamesize && eColB > 0)
             {
                   eRowB++;
                   eColB--;
             }

            //using i so as to not overwrite ending row
            int tempCol = sColB;
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

                  if(p1 >= 5 || p2 >= 5)
                    {
                       score1 = p1;
                       score2 = p2;
                       break;
                    }

                }
                return(score1 >= 5 || score2 >= 5);
            }

        bool game::CheckWin()
        {
          if(Row_Win())
            {
                return true;
            }
          else if(Col_Win())
            {
                return true;
            }
          else if(Forward_diagCheck())
            {
                return true;
            }
          else if(Backward_diagCheck())
            {
                return true;
            }
          else
            {
                return false;
            }
        }




