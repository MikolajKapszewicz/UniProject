#include "HostagesTile.h"
#include <cstdlib>


HostagesTile::HostagesTile() : Tile(hostages)
    {

    }


string HostagesTile::activate()
    {
        return "zabieracie ze soba zakladnikow!";
    }

string    HostagesTile::describe()
    {
        return "zakladnicy!";
    }
