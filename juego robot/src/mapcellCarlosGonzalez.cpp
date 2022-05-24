#include "mapcellCarlosGonzalez.h"
//Implementacion de toda la funcionabilidad de las celdas del mapa de juego
#include <iostream>

using namespace std;

mapcellCarlosGonzalez::mapcellCarlosGonzalez()
{
    //ctor
    id = 0; //ascii de espacios en el mapa
    //id = 176;
}
bool mapcellCarlosGonzalez::isBlockedCell()
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
mapcellCarlosGonzalez::~mapcellCarlosGonzalez()
{
    //dtor
}
