#include <iostream>
#include "Tile.h"


using namespace std;




class EntranceTile : public Tile
{


public:
    EntranceTile();

    string describe();
    string activate();


};

