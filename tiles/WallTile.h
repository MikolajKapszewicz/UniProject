#include <iostream>
#include "Tile.h"


using namespace std;




class WallTile : public Tile
{


public:
    WallTile();

    string describe();
    string activate();


};

