#include <iostream>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022


    gamemap map;
    gamemap map2;
    player hero;
    player hero2;
    map.drawPortada();
    char choice;

    while(map.isGameOver==false)
    {
       map.opcion = 0;
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

     }

            if (map.opcion = 1){
                //system("cls");
            map.drawPortada2();
            getchar();
            while(map2.isGameOver==false)
            {
                cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
                hero2.callInput();


                //Actualizar información del jugador en el mapa
                if(map2.setPlayerCell2(hero2.getValueX(), hero2.getValueY()))
                {
                //   system("cls");
                    map2.draw2();
                } else
                {
                // system("cls");
                    hero2.resetToSafePosition();
                    //Dibujamos el mapa
                    map2.draw2();
                }

                }

        }
    return 0;
}
