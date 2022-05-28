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
     {
         srand(time(0));
         lable:

          int i = rand()% len;
          int j = rand()% len;


        if (game::board_2d[i][j] == 0)
        {
            game::board_2d[i][j] = 1;
            setRow(i);
            setCol(j);  //After successfully generating a spot to place our 1, we then store coordinates to perform a check
            cout << "r1 = " << rowCheck << " c1 = " << colCheck << endl;
        }
        else
        {
            goto lable;
        }


     }



     void game::Algae2(int len)
     {
        srand(time(0));
        lable2:

          game :: rowPlay = rand()% len;
          game :: colPlay = rand()% len;


        if (game::board_2d[game :: rowPlay][game :: colPlay] == 0)
        {
            game::board_2d[game :: rowPlay][game :: colPlay] = 2;
            setRow(game :: rowPlay);
            setCol(game :: colPlay);
            cout << "r2 = " << rowCheck << " c2 = " << colCheck << endl;
        }
        else
        {
            goto lable2;
        }
     }

      bool game::CheckWin(int len)
      {
          bool winner = false;
          int score1=0;
          int score2=0;

          //Has someone got 5 in a row
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
            }

            if(score1 == 5 || score2 == 5)
                {
                   bool winner = true;
                   return winner;
                }


             // 5 in a row check for column
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
            }


            if(score1 == 5 || score2 == 5)
                {
                   bool winner = true;
                   return winner;
                }

            //Include Diagonal Check

      }





