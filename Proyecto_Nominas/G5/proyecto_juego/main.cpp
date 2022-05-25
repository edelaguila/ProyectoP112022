#include <iostream>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
    int opcion;
    gamemap map;//Monica Perez 9959-21-1840
    player hero;
    map.drawPortada();//Alan Galicia 9959-21-3632
    //Daniel Hall 9959-21-1395

cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |            MENU              |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. ENTRAR AL JUEGO" << endl
        << "\t\t\t  2. INSTRUCCIONES" << endl
        << "\t\t\t  3. CREDITOS" << endl
        << "\t\t\t  4. SALIR" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
    {
    int contador=0;
    while(map.isGameOver==false){//Monica Perez 9959-21-1840

      cout << "\n----------------------------------------------------------------------------------------" << endl;
      cout << "\t\t\t   ****COMANDOS DE MOVIMIENTO****";
      cout << "\n----------------------------------------------------------------------------------------" << endl;
      cout << "\n\t\tArriba|w|, Abajo |s|, Izquierda |a|, Derecha |d|" << endl;
      cout << "\n\t\t\t     Salir del Juego |x|" << endl;
      cout << "\n----------------------------------------------------------------------------------------" << endl;
      cout << "\nIntroduza Comando de Movimiento: ";

      hero.callInput();
      contador+=1;
      cout<<"\nNumero de Movimientos: "<<contador<<endl<<endl;

      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
        {
        map.draw();
      }else
      {
        hero.resetToSafePosition();
        map.draw();
      }
    }
    } //Daniel Hall 9959-21-1395
    break;
            case 2:
                {

                    map.drawIns();
                    return main();

                }
            break;
            case 3:
                {
                    map.drawcredi();
                    return main();
                    break;
                }
            case 4:
                {
                }
                break;

    }

    return 0;
}
