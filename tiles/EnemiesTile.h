#include <iostream>
#include "Tile.h"
#include <deque>
#include "../soldiers/Terrorist.h"

using namespace std;




class EnemiesTile : public Tile
{

    deque <Terrorist *> terrorists;


public:
    EnemiesTile();

    string describe();
    string activate();
    void test();
    void takeDamage(int damage);
    int getEnemyCount();
    int getDamageOf(int n, int distace);

};

