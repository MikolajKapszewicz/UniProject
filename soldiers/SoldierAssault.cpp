#include "SoldierAssault.h"
#include <cstdlib>


SoldierAssault::SoldierAssault() : Soldier( assault, 100, 50, getRandomName())
    {
        cout << getName() << ", szturmowiec wyrusza na misje" << endl;
    }


int    SoldierAssault::deliverDamage(int distance)
    {
        int attack_chance = 10;
        attack_chance = attack_chance - distance;

        int damage;
        damage = getDamage();

        if(rand()%10 > attack_chance)
        {
            damage = 0;
        }

    return damage;
    }

