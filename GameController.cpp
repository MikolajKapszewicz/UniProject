#include <cstdlib>
#include "GameController.h"
#include "soldiers/SoldierAssault.h"
#include "soldiers/SoldierSniper.h"
#include "soldiers/SoldierSupport.h"
#include <conio.h>

GameController::GameController() : gameMap()
{
    hostagesSaved = false;
    currentX = gameMap.startX;
    currentY = gameMap.startY+1;

    soldiers.push_back(new SoldierAssault);
    soldiers.push_back(new SoldierSniper);
    soldiers.push_back(new SoldierSupport);
}
int moveChoice()
{
    int choice = 0;

    do
    {

        cout << endl << endl << "== CO ZAMIERZASZ ZROBIC? ==" << endl;
        cout << "1. Ruch przed siebie" << endl;
        cout << "2. Ruch za siebie" << endl;
        cout << "3. Ruch w prawo" << endl;
        cout << "4. Ruch w lewo" << endl;
        cout << "==="<<endl;
        cout << "5. Strzelac przed siebie" << endl;
        cout << "6. Strzelac za siebie" << endl;
        cout << "7. Strzelac w prawo" << endl;
        cout << "8. Strzelac w lewo" << endl;

        cout << "Wybor: ";
        cin >> choice;
        if(choice >=1 && choice <= 8)
        {
            return choice;
        }
        else
        {
            cout << "Bledna akcja!"<<endl<<endl;
        }
    }
    while(true);
}


void GameController::makeMove()
{
    int distance, bulletsX, bulletsY;
    bool trafilo;

    int choice = moveChoice();
    switch(choice)
    {
    case 1:
        tryMovingTo(currentY+1, currentX);
        break;
    case 2:
        tryMovingTo(currentY-1, currentX);
        break;
    case 3:
        tryMovingTo(currentY, currentX-1);
        break;
    case 4:
        tryMovingTo(currentY, currentX+1);
        break;


    case 5:
        cout << "Nie trafiacie w nic zywego";
        getch();
        break;

    case 6:
        cout << "Nie trafiacie w nic zywego";
        getch();
        break;

    case 7:
        distance = 1;
        bulletsX = currentX-1;
        bulletsY = currentY;
        trafilo = false;
        while(gameMap.tileMap[bulletsY][bulletsX]->getType() != wall)
        {
            if(gameMap.tileMap[bulletsY][bulletsX]->getType() == enemies)
            {
                trafilo = true;
                EnemiesTile *p = dynamic_cast<EnemiesTile *>(gameMap.tileMap[bulletsY][bulletsX]);
                for(int i = 0; i < soldiers.size(); i++)
                {
                    int damage = soldiers.at(i)->deliverDamage(distance);
                    cout << soldiers.at(i)->getName() << " strzela i ";
                    if(damage)
                    {
                        cout << "zadaje " << damage << " obrazen!" << endl;


                        p->takeDamage(damage);
                        if(p->getEnemyCount() == 0)
                        {
                            delete gameMap.tileMap[bulletsY][bulletsX];
                            gameMap.tileMap[bulletsY][bulletsX] = new FloorTile;
                            cout << "Cala grupa terrorystow wyeliminowana!" << endl;
                            return;
                        }

                    }
                    else
                    {
                        cout << "nie trafia!" << endl;
                    }
                    cout << endl;
                    getch();
                }

            }
            distance++;
            bulletsX--;
        }
        if(!trafilo)
        {
            cout << "Nie trafiacie w nic zywego" << endl;
            getch();
        }

        break;


    case 8:
        distance = 1;
        bulletsX = currentX+1;
        bulletsY = currentY;
        trafilo = false;
        while(gameMap.tileMap[bulletsY][bulletsX]->getType() != wall)
        {
            if(gameMap.tileMap[bulletsY][bulletsX]->getType() == enemies)
            {
                trafilo = true;
                EnemiesTile *p = dynamic_cast<EnemiesTile *>(gameMap.tileMap[bulletsY][bulletsX]);
                for(int i = 0; i < soldiers.size(); i++)
                {
                    int damage = soldiers.at(i)->deliverDamage(distance);
                    cout << soldiers.at(i)->getName() << " strzela i ";
                    if(damage)
                    {
                        cout << "zadaje " << damage << " obrazen!" << endl;


                        p->takeDamage(damage);
                        if(p->getEnemyCount() == 0)
                        {
                            delete gameMap.tileMap[bulletsY][bulletsX];
                            gameMap.tileMap[bulletsY][bulletsX] = new FloorTile;
                            cout << "Cala grupa terrorystow wyeliminowana!" << endl;
                            return;
                        }

                    }
                    else
                    {
                        cout << "nie trafia!" << endl;
                    }
                    cout << endl;
                    getch();
                }

            }
            distance++;
            bulletsX++;
        }
        if(!trafilo)
        {
            cout << "Nie trafiacie w nic zywego" << endl;
            getch();
        }

    }
}



void GameController::tryMovingTo(int y, int x)
{
    if(x>=0 && y>=0 && x<12 && y < 12 && gameMap.tileMap[y][x]->describe() != "betonowa sciana." )
    {
        if(gameMap.tileMap[y][x]->getType() == hostages)
        {
            hostagesSaved = true;
            delete gameMap.tileMap[y][x];
            gameMap.tileMap[y][x] = new FloorTile;
        }


        if(gameMap.tileMap[y][x]->describe() == "wyjscie z budynku.")
        {
            if(hostagesSaved == true)
            {

                cout << "Sukces!\nZakladnicy uratowani!"<<endl;
                exit(0);




            }
            else
            {
                cout << "Nie uratowales jeszcze zakladnikow!"<<endl;
                cout << "Tracisz ture"<<endl;
                return;
            }
        }
        currentX = x;
        currentY = y;
    }
    else
    {
        cout << "Nie mozesz ruszyc sie w tym kierunku!" <<endl;
        cout << "Tracisz ture"<<endl;
    }
}

void GameController::enemiesMove()
{
    //EnemiesTile *p = dynamic_cast<EnemiesTile *>(gameMap.tileMap[bulletsY][bulletsX]);
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(gameMap.tileMap[i][j]->getType() == enemies)
            {
                int distance = 1;
                int startX, startY;
                startX = j;
                startY = i;
                // going left
                startX++;
                while(gameMap.tileMap[startY][startX]->getType() !=wall && gameMap.tileMap[startY][startX]->getType() !=door)
                {
                    if(startX == currentX && startY == currentY )
                    {

                        EnemiesTile *p = dynamic_cast<EnemiesTile *>(gameMap.tileMap[i][j]);
                        for(int k=0; k<p->getEnemyCount(); k++)
                        {
                            int damage = p->getDamageOf(k, distance);
                            cout<< "Jeden z terrorystow oddaje strzal w waszym kierunku i ";
                            if(damage)
                                cout << "dostaje "<<soldiers.at(0)->getName()<<endl;
                            else
                                cout<<"nie trafia! "<<endl;
                            soldiers.at(0)->getWounded(damage);
                            if(soldiers.at(0)->getHp()<=0)
                            {
                                cout<<"Ginie " << soldiers.at(0)->getName()<<endl;
                                soldiers.pop_front();
                                if(soldiers.size() == 0)
                                {
                                    cout<<"Wszyscy Twoi ludzie zgineli\n Totalna porazka! ";
                                    exit(0);
                                }

                            }
                        }


                    }

                    startX++;
                    distance++;

                }

                //going right
                startX = j;
                startY = i;
                distance = 0;
                startX--;
                while(gameMap.tileMap[startY][startX]->getType() !=wall && gameMap.tileMap[startY][startX]->getType() !=door)
                {
                    if(startX == currentX && startY == currentY )
                    {

                        EnemiesTile *p = dynamic_cast<EnemiesTile *>(gameMap.tileMap[i][j]);
                        for(int k=0; k<p->getEnemyCount(); k++)
                        {
                            int damage = p->getDamageOf(k, distance);
                            cout<< "Jeden z terrorystow oddaje strzal w waszym kierunku i ";
                            if(damage)
                                cout << "dostaje "<<soldiers.at(0)->getName()<<endl;
                            else
                                cout<<"nie trafia! "<<endl;
                            soldiers.at(0)->getWounded(damage);
                            if(soldiers.at(0)->getHp()<=0)
                            {
                                cout<<"Ginie " << soldiers.at(0)->getName()<<endl;
                                soldiers.pop_front();
                                if(soldiers.size() == 0)
                                {
                                    cout<<"Wszyscy Twoi ludzie zgineli\nTotalna porazka! ";
                                    exit(0);
                                }

                            }
                        }


                    }

                    startX--;
                    distance++;

                }
                // kek

            }
        }
    }
}

void GameController::describe()
{
    gameMap.describe(currentY, currentX);
}
