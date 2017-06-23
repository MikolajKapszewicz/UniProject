#include "SoldierSupport.h"
#include <cstdlib>

SoldierSupport::SoldierSupport() : Soldier(support, 120, 50, getRandomName())
    {

        cout << getName() << ", zolnierz wsparcia wyrusza na misje" << endl;
    }


int    SoldierSupport::deliverDamage(int distance)
    {
        int attack_chance = 10;
        attack_chance = attack_chance - (distance)*2;

        int damage;
        damage = 2*(getDamage());

        if(rand()%10 > attack_chance)
        {
            damage = 0;
        }

    return damage;
    }
