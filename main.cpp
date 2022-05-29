// <2382971>

#include <iostream>
#include <fstream>
#include "game.h"

using namespace std;


int main()
{
     ifstream dataIn("input.txt");
     ofstream dataOut("output.txt");

     int gamesize;
     int alg1wins= 0;
     int alg2wins =0;

    while(dataIn >> gamesize)
    {

    game gameboard;

    dataOut << "size=" << gamesize << endl;

    int max_moves =  gamesize * gamesize;

    gameboard.CreateBoard(gamesize);

    int moves = 0;
    while(moves < max_moves)
    {

        if(gameboard.Alg1( dataOut))
        {
          alg1wins++;
          dataOut << "win=alg1" << endl;
          dataOut << "\n";
          break;
        }
        moves++;

        if(gameboard.Alg2(dataOut))
        {
          alg2wins++;
          dataOut << "win=alg2" << endl;
          dataOut << "\n";

          break;
        }
        moves++;
    }

    if(moves >= max_moves)
        {
          dataOut << "Game Drawn" << endl;
          dataOut << "\n";
        }

    cout << "\n";
    gameboard.ShowBoard();
    cout << "\n";

    }

    dataOut <<"\n";
    dataOut << "wins alg1=" << alg1wins << "\n";
    dataOut << "wins alg2=" << alg2wins;

    dataOut.close();
    dataIn.close();


    return 0;
}
