#include "SoldierSniper.h"
#include <cstdlib>


SoldierSniper::SoldierSniper() : Soldier(sniper, 80, 50, getRandomName())
    {

        cout << getName() << ", snajper wyrusza na misje" << endl;
    }


int    SoldierSniper::deliverDamage(int distance)
    {
        int attack_chance = 10;
        attack_chance = attack_chance - (distance)/2;
        if(distance == 1 || distance == 0)
        {
            attack_chance == 2;
        }

        int damage;
        damage = getDamage();

        if(rand()%10 > attack_chance)
        {
            damage = 0;
        }

    return damage;
    }
