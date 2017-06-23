#include "Tile.h"
#include <iostream>

using namespace std;

class FloorTile : public Tile{


public:

    FloorTile();

    virtual string describe();
    virtual string activate();

};
