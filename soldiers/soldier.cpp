#include <iostream>
#include "soldier.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;


Soldier::Soldier(soldierType, int hp, int base_damage, string name)

    {
        this->base_damage = base_damage;
        this->hp = hp;
        this->name = name;

    }

int Soldier::getDamage()
{
    return base_damage;
}

void Soldier::getWounded(int damage)
{
    hp = hp - damage;
}

int Soldier::CountLines()
{
        int numLines = 0;
ifstream in("names.txt");
string unused;
while ( getline(in, unused) )
   {
   ++numLines;
   }
   return numLines;
}

string Soldier::getRandomName()
{

     string STRING;                 // TODO: Finish method to get random name for soldiers
	fstream nameDatabase;
	nameDatabase.open ("names.txt", ios::in);
	int linesCount = 0;
	while(getline(nameDatabase, STRING))
    {
        linesCount++;
    }
    nameDatabase.close();
    nameDatabase.open ("names.txt", ios::in);

    int lineNum = rand()%(linesCount+1);

    while(lineNum--)
    {
        getline(nameDatabase, STRING);
    }
    return STRING;

}

string Soldier::getName()
{
    return name;
}


int Soldier::getHp()
{
    return hp;
}

