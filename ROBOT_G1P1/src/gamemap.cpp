#include "gamemap.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
//Implementacion de toda la funcionabilidad del mapa del juego

using namespace std;
gamemap::gamemap()
{
    //ctor
    playerCell = NULL;
    loadMapFromFile();
    isGameOver = false;
}
void gamemap::draw(){
    //system("cls");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Utilizar las celulas cuando se dibuja el mapa
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
bool gamemap::setPlayerCell(int playerX, int playerY)
{
    if (cell[playerX][playerY].isBlockedCell() == false)
    {
        if (cell[playerX][playerY].id == '$')
        {
            drawVictoria();
            isGameOver = true;
            return true;
        } else
        { // evalúa espacio
            if (cell[playerX][playerY].id == '#')
            {
            drawTrampa();
            isGameOver = true;
            return true;
            }
            if (cell[playerX][playerY].id == '&')
            {
            drawBromita();
            isGameOver = true;
            return true;
            }
            //Se verifica que maque con cero la posicion que abandona el jugador
            if (playerCell != NULL)
            {
                // Cambio permitira quitar los ceros en el camino del jugador, al traslador un cero a un char se convierte en espacio
                //playerCell->id='0';
                playerCell->id=0;
            }
            //cout << "Las coordenadas del jugador estan en: " << playerX << "," << playerY << endl;
            //Cambio de coordenadas para corregiro problema de los movimientos del jugador en el eje X
            //playerCell = &cell[playerY][playerX];
            playerCell = &cell[playerX][playerY];
            //Simbolo del jugador en el mapa
            playerCell->id=223; //ascii 223
        }


        return true;
    }
    else
    {
        return false;
    }

}
void gamemap::loadMapFromFile()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("map.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                }
                // Cambio para quitar ceros y colocar espacios en blanco en el mapa
                // cell[row][p].id = line[p];
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
        if (userInput=' ')
        {
            createMapToFile();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}
void gamemap::createMapToFile()
{
    ofstream myFile("map.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 || i == 14)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 9)
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
void gamemap::drawPortada()
{
    string line;
    char userInput = ' ';
    ifstream myFile("portada.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
    }
}
void gamemap::drawVictoria()
{
    string line;
    char userInput = ' ';
    ifstream myFile("premio.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}
void gamemap::drawBromita()
{
    string line;
    char userInput = ' ';
    ifstream myFile("bromita.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de bromita no pudo ser cargado" << endl;
    }
}

void gamemap::drawTrampa()
{
    string line;
    char userInput = ' ';
    ifstream myFile("trampa.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de trampa no pudo ser cargado" << endl;
    }
}
void gamemap::drawCreditos()
{
    string line;
    char userInput = ' ';
    ifstream myFile("creditos.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de creditos no pudo ser cargado" << endl;
    }
}
void gamemap::drawInstrucciones()
{
    string line;
    char userInput = ' ';
    ifstream myFile("instrucciones.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de instrucciones no pudo ser cargado" << endl;
    }
}

gamemap::~gamemap()
{
    //dtor
}
