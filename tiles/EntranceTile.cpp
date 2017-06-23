#include "EntranceTile.h"
#include <cstdlib>

EntranceTile::EntranceTile() : Tile(entrance)
{
    //cout << "FUCKING ENTRANCE ASDAASDDASADA" << endl;
}

string EntranceTile::activate()
{
    return "stoicie w drzwiach wejsciowych do budynku";
}

string EntranceTile::describe()
{
    return "wyjscie z budynku.";
}
