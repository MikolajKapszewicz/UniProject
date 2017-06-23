#pragma once
#include <iostream>


using namespace std;

enum soldierType{

assault,
sniper,
support,
terrorist

};



class Soldier
{

soldierType type;
int hp;
string name;
int base_damage;

public:
    Soldier(soldierType, int hp, int base_damage, string name);
    int getDamage();
    virtual int deliverDamage(int distance)=0;
    void getWounded(int damage);
    int CountLines();
    static string getRandomName();
    string getName();
    int getHp();
};

