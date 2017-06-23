#include "WallTile.h"
#include <cstdlib>


WallTile::WallTile() : Tile(wall)
    {
        //cout << "wall" << endl;
    }


string     WallTile::activate()
    {
        return "to nie powinnno się stać.";
    }

string    WallTile::describe()
    {
        return "betonowa sciana.";
    }
