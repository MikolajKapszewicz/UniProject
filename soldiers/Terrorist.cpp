#include "Terrorist.h"
#include <cstdlib>



Terrorist::Terrorist() : Soldier( terrorist, 50, 25, getRandomName())
{

}

int    Terrorist::deliverDamage(int distance)
    {
        int attack_chance = 10;
        attack_chance = attack_chance - distance;


           if(rand()%10 > attack_chance)
            return 0;

    return getDamage();
    }

