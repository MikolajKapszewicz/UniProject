#include <iostream>
#pragma once

using namespace std;

enum tileType{

floor,
door,
enemies,
hostages,
wall,
entrance

};



class Tile
{

tileType type;
bool discovered;


public:
    Tile(tileType newType);
    char toChar();

    virtual string describe()=0;
    virtual string activate()=0;
    tileType getType();


};

