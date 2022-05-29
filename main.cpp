// <2382971>

#include <iostream>
#include <fstream>
#include "game.h"

using namespace std;

void process(int gamesize, int loops)
{
 int loop = 0;
 int alg1wins= 0;
 int alg2wins =0;
 ofstream dataOut("output.txt");

 while (loop <= loops){
 game gameboard;

    dataOut << "size=" << gamesize << endl;

    int max_moves =  gamesize * gamesize;

    gameboard.CreateBoard(gamesize);

    int moves = 0;
    while(moves < max_moves)
    {
        gameboard.Alg1(gamesize);

        dataOut << "r" << gameboard.getRow() << "c" << gameboard.getCol() << " Alg1" << endl;

        if(gameboard.CheckWin(gamesize))
        {

          alg1wins++;
          dataOut << "win=alg1" << endl;
          break;
        }
        moves++;

        gameboard.Alg2(gamesize);

        dataOut << "r" << gameboard.getRow() << "c" << gameboard.getCol() << " Alg2" << endl;

        if(gameboard.CheckWin(gamesize))
        {
          alg2wins++;
          dataOut << "win=alg2" << endl;

          break;
        }
        moves++;
    }

    if(!gameboard.CheckWin(gamesize))
        {
          dataOut << "Game Drawn" << endl;
        }

    cout << "\n";
    dataOut << "\n";
    gameboard.ShowBoard(gamesize);

    loop++;
 }

    dataOut <<"\n";
    dataOut << "wins alg1=" << alg1wins;
    dataOut << "wins alg2=" << alg2wins;

    dataOut.close();

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
