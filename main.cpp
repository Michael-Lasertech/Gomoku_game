// <2382971>

#include <iostream>
#include <fstream>
#include "game.h"

using namespace std;

void process(int gamesize, int loops)
{
 int init = 0;
 int alg1wins= 0;
 int alg2wins =0;

 while (init <= loops){
 game gameboard;
 ofstream dataOut("output.txt");

    cout << "size=" << gamesize << endl;
    int max_moves =  gamesize * gamesize;

    gameboard.CreateBoard(gamesize);

    int moves = 0;
    while(moves < max_moves)
    {
        gameboard.Algae1(gamesize);
        cout << "r" << gameboard.getRow() << "c" << gameboard.getCol() << " Alg1" << endl;

        if(gameboard.CheckWin(gamesize))
        {

          cout << "win=alg1" << endl;
          alg1wins++;
          //dataOut << "Player1 won" << endl;
          break;
        }
        moves++;
        //gameboard.Algae2(gamesize);
        gameboard.TestAlg(gamesize);
        cout << "r" << gameboard.getRow() << "c" << gameboard.getCol() << " Alg2" << endl;

        if(gameboard.CheckWin(gamesize))
        {
          cout << "win=alg2" << endl;
          alg2wins++;
          //dataOut << "Player2 won" << endl;

          break;
        }
        moves++;
    }

    if(!gameboard.CheckWin(gamesize))
        {
          cout << "Game Drawn" << endl;
        }

    cout << "\n";
    gameboard.ShowBoard(gamesize);

    init++;
 }

    cout <<"\n";
    cout << "wins alg1=" << alg1wins;
    cout << "wins alg2=" << alg2wins;

}


int main()
{
    ifstream dataIn("input.txt");


    int sizeIn;
    int loops =0;

    while(dataIn >> sizeIn)
    {
         while(dataIn >> sizeIn)
         {
            loops++;
         }

         process(sizeIn,loops);
         cout << "\n";

    }
    dataIn.close();

    return 0;
}
