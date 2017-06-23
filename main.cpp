#include <iostream>
#include <time.h>
#include <cstdlib>

#include "GameController.h"
using namespace std;

int main()
{
        srand (time(NULL));

    /*
    1. Sprawdzanie czy zakladnicy zostali odnalezieni
    2. Mechanika strzelania (polecenia od 5 do 8)
    3. funkcja enemiesMove()
        - Dla każdego odddziału terrorystów
        - Patrz w obu kierunkach
        - Jeśli znajdziesz gracza
            - Strzelaj

        */

        GameController game;

        while(true)
        {
            game.describe();
            game.makeMove();
            game.enemiesMove();


        }

   return 0;
}
