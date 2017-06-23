#include "EnemiesTile.h"
#include <cstdlib>
#include <sstream>


EnemiesTile::EnemiesTile() : Tile(enemies)
{
    int enemiesCount = rand()%2+2;
    for(int i = 0; i < enemiesCount; i++)
    {
        terrorists.push_back(new Terrorist);
    }
}


string EnemiesTile::activate()
{
    return "wpadacie w bezpośrednią walkę";
}

int EnemiesTile::getEnemyCount()
{
    return terrorists.size();
}
string EnemiesTile::describe()
{
    std::ostringstream oss;

    oss  << "terrorysci! Jest ich " << terrorists.size() << ".";
    return oss.str();
}

int EnemiesTile::getDamageOf(int n, int distance)
{
    return terrorists.at(n)->deliverDamage(distance);
}

void EnemiesTile::takeDamage(int damage)
{

   terrorists.at(0)->getWounded(damage);
   if(terrorists.at(0)->getHp()<=0)
   {
       cout << "jeden z terrorystow ginie!" << endl;
       terrorists.pop_front();
   }

}
