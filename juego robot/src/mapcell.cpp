#include "mapcell.h"
//Implementacion de toda la funcionabilidad de las celdas del mapa de juego
#include <iostream>

using namespace std;

mapcell::mapcell()
{
    //ctor
    id = 0; //ascii de espacios en el mapa
    //id = 176;
}
bool mapcell::isBlockedCell()
{
    if( id == '1')
    //if( id == 176)
    {
        return true;
    } else
    {
        return false;
    }
}
mapcell::~mapcell()
{
    //dtor
}
