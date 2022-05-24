#include "mapcell.h"
//Implementacion de toda la funcionabilidad de las celdas del mapa de juego
#include <iostream>

using namespace std;

mapcell::mapcell()
{
    //ctor
    id = 0; //ascii de espacios en el mapa
}
bool mapcell::isBlockedCell()
{
    //Caracter bloqueado, Carlos hernandez 9959-21-363.
    if( id == '#')
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
