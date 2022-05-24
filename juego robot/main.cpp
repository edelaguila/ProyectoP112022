#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "playerCarlosGonzalez.h"
#include "mapcellCarlosGonzalez.h"
#include "gamemapCarlosGonzalez.h"

using namespace std;

int main()
{
    int desicion;
    cout<<"\n\n\t\t\tBIENVENIDO, CUAL MAPA QUISIERA JUGAR: "<<"\n\n\t\t\t[1] Mapa creado por Carlos Gonzalez"<<"\n\t\t\t[2] Mapa creado por Diego Culajay"<<"\n\t\t\t[3] Mapa creado por William Mayen"<<"\n\t\t\t[4] Mapa creado por Carlos Montes"<<"\n\n\t\t\t[5]¿Salir?";
    cout<<"\n\n\t\t\t";cin>>desicion;
    switch(desicion){
    case 1:
        gamemapCarlosGonzalez map;
        playerCarlosGonzalez hero;
        string line;
        ifstream myFile("controles.txt");
        system("cls");
        if(myFile.is_open())
        {
            cout<<"\n\n";
            while( getline(myFile, line))
            {
                cout << "\t\t\t" <<line << endl;
            }
            myFile.close();
            cout<<"\n\t\t\t";system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
        }
        map.drawPortada();
        while(map.isGameOver==false)
        {
            cout << "\n\t\tIntroduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
            hero.callInput();

            //Actualizar información del jugador en el mapa
            if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
            {
            system("cls");
            map.draw();
            } else
            {
            system("cls");
            hero.resetToSafePosition();
            map.draw();
            }
        }
        break;
    /*case 2:
        cout<<"\n\t\t\tAUN EN DESARROLLO :(";
        break;
    case 3:
        cout<<"\n\t\t\tAUN EN DESARROLLO :(";
        break;
    case 4:
        cout<<"\n\t\t\tAUN EN DESARROLLO :(";
        break;
    case 5:
        cout<<"\n\t\t\tGRACIAS POR JUGAR... G2 :)";
        cout<<"\n\t\t\t";system("pause");
        exit(0);
        break;*/
    }
}
