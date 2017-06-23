#include <iostream>
#include "Tile.h"


using namespace std;




class DoorTile : public Tile
{
    bool are_open;

public:
    DoorTile();

    string describe();
    string activate();


};

