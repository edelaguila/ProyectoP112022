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
#include "playerDiegoCulajay.h"
#include "mapcellDiegoCulajay.h"
#include "gamemapDiegoCulajay.h"
int decision;
using namespace std;

int main()
{
    ifstream file("portada1.txt");
    string line;
    if(file.is_open())
    {
        cout<<"\n\n";
        while( getline(file, line))
        {
            cout << "\t\t\t" <<line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
    int desicion;
    cout<<"\n\n\t\t\tBIENVENIDO, ELIGE UNA OPCION: "<<"\n\n\t\t[1] ENTRAR A JUGAR"<<"\n\t\t[2] Segundo Mapa"<<"\n\t\t[3] ¿SALIR?"<<"\n\n\t\t";cin>>desicion;
    if (decision==1){
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
    }
    else if(desicion==2){
        gamemapDiegoCulajay map;
    playerDiegoCulajay hero;
    map.drawPortada();
    //map.draw();
    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();
      }
      //map.draw();
    }
}
else {

            cout<<"\n\t\t\tGRACIAS POR JUGAR... :)";
            cout<<"\n\t\t\t";system("pause");
            return(0);

}


    }





