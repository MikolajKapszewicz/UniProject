#include <iostream>
#include "Tile.h"
#include <fstream>
#include <cstdlib>

using namespace std;


Tile::Tile(tileType newType)

    {
        discovered = false;
        type = newType;
        //cout << "making a tile ";
    }



tileType Tile::getType()
{
    return this->type;
}

char Tile::toChar()
{
    switch(type)
    {
    case floor:
        return ' ';
        break;
    case door:
        return 'D';
        break;
    case enemies:
        return 'E';
            break;
    case wall:
        return 'O';
        break;
    case entrance:
        //cout << "ASDAHDSJKDASDKAHDJADHKDJAKD";
        return 'S';
        break;
    case hostages:
        return 'H';
    default:
        return 'W';
        break;
    }
}
