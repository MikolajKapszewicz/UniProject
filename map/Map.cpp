#include "map.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Map::Map()
{
    //inicjalizacja tablicy
    char ** charMap;
    //tworzę mapę najpierw jako tablicę charów, dla uproszczenia

    charMap = new char*[10];

    for (int i = 0; i < 10; i++)
    {
        charMap[i] = new char;
    }

    //czyszczenie tablicy
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            charMap[i][j] = '0';
        }
    }


    //generowanie dwóch losowych linii
    int mainCorridor = rand()%6 +2;



    for(int i = 0; i < 10; i ++)
    {
        charMap[i][mainCorridor] = ' ';
    }

    int corridor1Left = rand()%5+2;
    int corridor2Left = rand()%5+2;

    while(corridor1Left == corridor2Left || corridor1Left+1 == corridor2Left || corridor1Left-1 == corridor2Left)
    {
        corridor2Left = rand()%5+2;
    }

    int corridor1Right = rand()%5+2;
    int corridor2Right = rand()%5+2;

    while(corridor1Right == corridor2Right || corridor1Right+1 == corridor2Right || corridor1Right-1 == corridor2Right)
    {
        corridor2Right = rand()%5+2;
    }

    for(int i = 0; i < mainCorridor; i++)
    {
        charMap[corridor1Left][i] = ' ';
        charMap[corridor2Left][i] = ' ';
    }

    for(int i = 9; i > mainCorridor; i--)
    {
        charMap[corridor1Right][i] = ' ';
        charMap[corridor2Right][i] = ' ';
    }


    //doors
    charMap[corridor1Left][mainCorridor-1] = 'D';
    charMap[corridor2Left][mainCorridor-1] = 'D';
    charMap[corridor1Right][mainCorridor+1] = 'D';
    charMap[corridor2Right][mainCorridor+1] = 'D';

    //terrorists
    charMap[corridor1Left][0] = 'E';
    charMap[corridor2Left][0] = 'E';
    charMap[corridor1Right][9] = 'E';
    charMap[corridor2Right][9] = 'E';


    //hostages
    switch(rand()%4)
    {
    case 0:
        charMap[corridor1Left][0] = 'H';
        break;
    case 1:
        charMap[corridor2Left][0] = 'H';
        break;
    case 2:
        charMap[corridor1Right][9] = 'H';
        break;
    case 3:
        charMap[corridor2Right][9] = 'H';
        break;

    }

    charMap[0][mainCorridor] = 'S';



    tileMap = new Tile**[12];
    for(int i = 0; i < 12; i ++)
    {
        tileMap[i] = new Tile*[12];
    }

    // covering the whole map with walls...
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            tileMap[i][j] = new WallTile;
        }
    }
    // ..to now fill them with the right stuff
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            switch(charMap[i][j])
            {
            case '0':
                break;
            case 'E':
                delete tileMap[i+1][j+1];
                tileMap[i+1][j+1] = new EnemiesTile;
                break;
            case 'D':
                delete tileMap[i+1][j+1];
                tileMap[i+1][j+1] = new DoorTile;
                break;
            case ' ':
                delete tileMap[i+1][j+1];
                tileMap[i+1][j+1] = new FloorTile;
                break;
            case 'H':
                delete tileMap[i+1][j+1];
                tileMap[i+1][j+1] = new HostagesTile;
                break;
            case 'S':
                delete tileMap[i+1][j+1];
                tileMap[i+1][j+1] = new FloorTile;

                delete tileMap[i][j+1];
                tileMap[i][j+1] = new EntranceTile;
                startX = j+1;
                startY = i;
                break;


            }

        }
    }


}



void Map::print()
{

    for(int i = 11; i >= 0; i--)
    {

        for(int j = 11; j >= 0; j--)
        {
            cout << tileMap[i][j]->toChar() << " ";
        }
        cout << endl;
    }

}


void Map::describe(int y1, int x1)
{
    cout << endl << endl << endl;
    cout << "opis dla x: " << x1 << ". y: " << y1 << endl;

    cout << tileMap[y1][x1]->activate() << endl;

    int x,y;
    y=y1; x=x1;
    int lenght = 0;

    cout << "przed wami ";
    if(tryDescribing(y+1,x) == "korytarz.")
    {
        while(tryDescribing(++y,x) == "korytarz.")
        {
            lenght++;
        }
        cout << "korytarz dlugosci okolo " << lenght*2 << " metrow, dalej " << tryDescribing(y,x) << endl;
    }else
    cout << tryDescribing(y+1,x) << endl;

    lenght = 0;
    y=y1; x=x1;


    cout << "za wami ";

    if(tryDescribing(y-1,x) == "korytarz.")
    {
        while(tryDescribing(--y,x) == "korytarz.")
        {
            lenght++;
        }
        cout << "korytarz dlugosci okolo " << lenght*2 << " metrow, dalej " << tryDescribing(y,x) << endl;
    }else
    cout << tryDescribing(y-1,x) << endl;


    lenght = 0;
    y=y1; x=x1;

    cout << "na prawo od was ";

    if(tryDescribing(y,x-1) == "korytarz.")
    {
        while(tryDescribing(y,--x) == "korytarz.")
        {
            lenght++;
        }
        cout << "korytarz dlugosci okolo " << lenght*2 << " metrow, dalej " << tryDescribing(y,x) << endl;
    }else
    cout << tryDescribing(y,x-1) << endl;


    lenght = 0;
    y=y1; x=x1;

    cout << "na lewo od was ";


    if(tryDescribing(y,x+1) == "korytarz.")
    {
        while(tryDescribing(y,++x) == "korytarz.")
        {
            lenght++;
        }
        cout << "korytarz dlugosci okolo " << lenght*2 << " metrow, dalej " << tryDescribing(y,x) << endl;
    }else
    cout << tryDescribing(y,x+1) << endl;

}

string Map::tryDescribing(int y, int x)
{
    if(x<0 || x>11 || y < 0 || y > 11)
    {
        return "betonowa sciana.";
    }
    else {
            return tileMap[y][x]->describe();
    }
}
