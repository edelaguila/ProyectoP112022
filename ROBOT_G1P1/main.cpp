#include <iostream>
#include <windows.h>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
    //char cancion[]="C:\music.wav";
    //cout<<PlaySound((LCPCSTR)cancion, NULL , SND_FILENAME);
    //-static-libgcc -lwimm
    int op;
    gamemap map;
    player hero;
    map.drawPortada();
    //map.draw();
    cout<<"-------------------------------"<<endl;
    cout<<"|             MENU            |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1.INICIAR JUEGO"<<endl;
    cout<<"2.INSTRUCCIONES"<<endl;
    cout<<"3.CREDITOS"<<endl;
    cout<<"4.SALIR"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"OPCION A ESCOGER:[1/2/3]"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"INGRESA TU OPCION:"<<endl;
    cin>>op;
    switch(op){
        case 1:
            {
        while(map.isGameOver==false)
    {
    cout<<"-------------------------------"<<endl;
    cout<<"|           CONTROLES         |"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"w=ARRIBA, s=ABAJO, a=IZQUIERDA, d=DERECHA"<<endl;
    cout<<"PRESIONE CUALQUIER TECLA PARA COMENZAR"<<endl;
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
        break;

        case 2:
            {
                system("cls");
               map.drawInstrucciones();
            }
            break;

            case 3:
            {
                  system("cls");
               map.drawCreditos();
               break;
            }
             case 4:
                 {
                 }
                 break;
    }
    return 0;
}
