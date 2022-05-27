#include "gamemapCarlosGonzalez.h"
#include <iostream>
#include <fstream>
//Implementacion de toda la funcionabilidad del mapa del juego

using namespace std;
gamemapCarlosGonzalez::gamemapCarlosGonzalez()
{
    //ctor
    playerCell = NULL;
    loadMapFromFile();
    isGameOver = false;
}
void gamemapCarlosGonzalez::draw(){
    //system("cls");
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            // Utilizar las celulas cuando se dibuja el mapa
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
bool gamemapCarlosGonzalez::setPlayerCell(int playerX, int playerY)
{
    if (cell[playerX][playerY].isBlockedCell() == false)
    {
        if (cell[playerX][playerY].id == '$')
        {
            drawVictoria();
            isGameOver = true;
            return true;
        }if (cell[playerX][playerY].id=='2')
        {
            drawFinalA();
            isGameOver==true;
            return true;
        }
        if (cell[playerX][playerY].id=='_')
        {
            drawMuerte();
            isGameOver==true;
            return true;
        }
        else
        { // evalúa espacio
            //Se verifica que maque con cero la posicion que abandona el jugador
            if (playerCell != NULL)
            {
                // Cambio permitira quitar los ceros en el camino del jugador, al traslador un cero a un char se convierte en espacio
                playerCell->id='0';
                //playerCell->id=0;
            }
            //cout << "Las coordenadas del jugador estan en: " << playerX << "," << playerY << endl;
            //Cambio de coordenadas para corregiro problema de los movimientos del jugador en el eje X
            //playerCell = &cell[playerY][playerX];
            playerCell = &cell[playerX][playerY];
            //Simbolo del jugador en el mapa
            playerCell->id=169; //ascii 169
        }

        return true;
    }
    else
    {
        return false;
    }

}

void gamemapCarlosGonzalez::loadMapFromFile2()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("mapCarlosMontes.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == 0)
                {
                    cell[row][p].id = '0';//posible solucion
                } else
                {
                    cell[row][p].id = line[p];
                }
                // Cambio para quitar ceros y colocar espacios en blanco en el mapa
                // cell[row][p].id = line[p];
                /*if (line[p] =='1')
                {
                    cell[row][p].id=176;
                }else
                {
                    cell[row][p].id=line[p];
                }*/
            }
            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createMapToFile();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }


}
void gamemapCarlosGonzalez::loadMapFromFile()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("mapCarlosGonzalez.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == 0)
                {
                    cell[row][p].id = '0';//posible solucion
                } else
                {
                    cell[row][p].id = line[p];
                }
                // Cambio para quitar ceros y colocar espacios en blanco en el mapa
                // cell[row][p].id = line[p];
                /*if (line[p] =='1')
                {
                    cell[row][p].id=176;
                }else
                {
                    cell[row][p].id=line[p];
                }*/
            }
            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cout << "Desea crearlo? " << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createMapToFile();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}
void gamemapCarlosGonzalez::createMapToFile()
{
    ofstream myFile("mapCarlosGonzalez.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (i == 0 || i == 11)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 19)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}
void gamemapCarlosGonzalez::drawPortada()
{
    system("cls");
    string line;
    ifstream myFile("portada.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        cout<<"\n\n";
        while( getline(myFile, line))
        {
            cout << "\t" <<line << endl;
        }
        myFile.close();
        cout<<"\n\t\t\t";system("pause");//cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
}

void gamemapCarlosGonzalez::drawFinalA(){
    system("cls");
    string line;
    ifstream myFile("tunelInfinito.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        cout<<"\n\n";
        while( getline(myFile, line))
        {
            cout << "\t" <<line << endl;
        }
        myFile.close();
        cout<<"\n\t\t\t";system("pause");//cin >> userInput;
        loadMapFromFile2();
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
}

void gamemapCarlosGonzalez::drawMuerte()
{
    system("cls");
    string line;
    char userInput = ' ';
    ifstream myFile("muerte.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << "\t" << line << endl;
        }
        myFile.close();
        cout<<"\n\t\t\t";system("pause");//cin >> userInput;
        exit(0);
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

void gamemapCarlosGonzalez::drawVictoria()
{
    string line;
    char userInput = ' ';
    ifstream myFile("victoria.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << "\t\t\t" << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}

gamemapCarlosGonzalez::~gamemapCarlosGonzalez()
{
    //dtor
}
