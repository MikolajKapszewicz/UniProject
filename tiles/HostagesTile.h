#include <iostream>
#include "Tile.h"


using namespace std;




class HostagesTile : public Tile
{


public:
    HostagesTile();

    string describe();
    string activate();


};

