#include "mapcellDiegoCulajay.h"
//Implementacion de toda la funcionabilidad de las celdas del mapa de juego
#include <iostream>

using namespace std;

mapcellDiegoCulajay::mapcellDiegoCulajay()
{
    //ctor
    id = 0; //ascii de espacios en el mapa
    //id = 178;
}
bool mapcellDiegoCulajay::isBlockedCell()
{
    //cout << "caracter visitado=" << id << endl;
    if( id == '1')
    //if( id == 178)
    {
        return true;
    } else
    {
        return false;
    }
}
mapcellDiegoCulajay::~mapcellDiegoCulajay()
{
    //dtor
}
