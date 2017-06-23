#include "map/Map.h"
#include "soldiers/soldier.h"
#include <deque>




class GameController
{
    Map gameMap;
    deque <Soldier*> soldiers;
    int currentX, currentY;
    bool hostagesSaved;

public:
    GameController();
    void makeMove();
    void describe();
    void tryMovingTo(int y, int x);
    void enemiesMove();
    void win();

};
