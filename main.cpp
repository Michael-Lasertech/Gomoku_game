// <2382971>

#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    game instantiate;
    double array_2[15][15];

    int length = 6;

    int MAX =  length * length;

    instantiate.CreateBoard(array_2, length);

    int moves = 0;
    while(moves < MAX)
    {
        instantiate.Algae1(length);
        instantiate.CheckWin(length);
        moves++;
        instantiate.Algae2(length);
        instantiate.CheckWin(length);
        moves++;
    }

    cout << "\n";
    instantiate.ShowBoard(array_2,length);


    return 0;
}
