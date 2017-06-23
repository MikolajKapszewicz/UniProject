#include "../tiles/FloorTile.h"
#include "../tiles/DoorTile.h"
#include "../tiles/EnemiesTile.h"
#include "../tiles/HostagesTile.h"
#include "../tiles/WallTile.h"
#include "../tiles/EntranceTile.h"

class Map
{

public:
    Tile *** tileMap;
    int startX, startY;
    Map();
    void print();
    void describe(int x, int y);
    string tryDescribing(int y, int x);


};
