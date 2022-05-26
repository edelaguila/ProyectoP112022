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
    gamemap map3;
    gamemap map4;
    player hero;
    player hero2;
    player hero3;
    player hero4;
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 39ba803861718d26772eae793d797e30eaa7c02f
        }
            if (map.opcion = 1){
                //system("cls");
            map.drawPortada3();
            getchar();
            while(map3.isGameOver==false)
            {
                cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
                hero3.callInput();


                //Actualizar información del jugador en el mapa
                if(map3.setPlayerCell3(hero3.getValueX(), hero3.getValueY()))
                {
                //   system("cls");
                    map3.draw3();
                } else
                {
                // system("cls");
                    hero3.resetToSafePosition();
                    //Dibujamos el mapa
                    map3.draw3();
                }

                }


<<<<<<< HEAD
=======
>>>>>>> 74909decd316040db6568f5684d1d556bad9c255
        }
            if (map.opcion = 1){
                //system("cls");
            map.drawPortada3();
            getchar();
            while(map3.isGameOver==false)
            {
                cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
                hero3.callInput();


                //Actualizar información del jugador en el mapa
                if(map3.setPlayerCell3(hero3.getValueX(), hero3.getValueY()))
                {
                //   system("cls");
                    map3.draw3();
                } else
                {
                // system("cls");
                    hero3.resetToSafePosition();
                    //Dibujamos el mapa
                    map3.draw3();
                }

                }


=======
>>>>>>> 39ba803861718d26772eae793d797e30eaa7c02f
        }
            if (map.opcion = 1){
                //system("cls");
            map.drawPortada4();
            getchar();
            while(map4.isGameOver==false)
            {
                cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
                hero4.callInput();


                //Actualizar información del jugador en el mapa
                if(map4.setPlayerCell4(hero4.getValueX(), hero4.getValueY()))
                {
                //   system("cls");
                    map4.draw4();
                } else
                {
                // system("cls");
                    hero4.resetToSafePosition();
                    //Dibujamos el mapa
                    map4.draw4();
                }

                }
        }
    return 0;
}
