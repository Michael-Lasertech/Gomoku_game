// <2382971>

#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    game instantiate;
    double array_2[15][15];

    int length = 14;

    int MAX =  length * length;

    instantiate.CreateBoard(array_2, length);

    int moves = 0;
    while(moves < MAX)
    {
        instantiate.Algae1(length);
        if(instantiate.CheckWin(length))
        {
          cout << "Player1 won" << endl;
          break;
        }
        moves++;
        instantiate.Algae2(length);

        if(instantiate.CheckWin(length))
        {
          cout << "Player2 won" << endl;
          break;

        }
        moves++;
    }

    if(!instantiate.CheckWin(length))
        {
          cout << "Game Drawn" << endl;

        }


    cout << "\n";
    instantiate.ShowBoard(array_2,length);


    return 0;
}
