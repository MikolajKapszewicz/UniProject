#include "DoorTile.h"
#include <cstdlib>


DoorTile::DoorTile() : Tile(door)
    {
        are_open = false;
    }


string    DoorTile::activate()
    {
        if(!are_open){
            are_open = true;
        return "otwieracie drzwi.";
        }
        else
        {
          return "stoicie w otwartych drzwiach";
        }
    }

string  DoorTile::describe()
    {

        if(are_open)
        {
            return  "otwarte drzwi.";
        }
        else{
            return  "zamkniete drzwi.";
        }

    }
