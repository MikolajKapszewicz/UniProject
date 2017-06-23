#include "FloorTile.h"
#include <cstdlib>


FloorTile::FloorTile() : Tile(floor)
    {

    }


string FloorTile::activate()
{
    return "stoicie na korytarzu";
}

string FloorTile::describe()
{

    return "korytarz.";

}
