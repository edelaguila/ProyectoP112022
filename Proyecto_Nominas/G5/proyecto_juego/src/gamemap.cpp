#include "gamemap.h"
#include <iostream>
#include <fstream>

using namespace std;
gamemap::gamemap()
{
    playerCell = NULL;
    loadMapFromFile();
    isGameOver = false;
}
void gamemap::draw(){//MONICA PEREZ 9959-21-1840
    for (int i = 0; i < 16  ; i++)
    {
        for (int j = 0; j < 35; j++)
        {
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
bool gamemap::setPlayerCell(int playerX, int playerY)//MONICA PEREZ 9959-21-1840
{
    if (cell[playerX][playerY].isBlockedCell() == false){
        if (cell[playerX][playerY].id == '$'){
            drawVictoria();
            isGameOver = true;
            return true;
        }else{
            if (cell[playerX][playerY].id == '&'){
                drawTrampa();
                isGameOver = true;
                return true;
            }
            if (playerCell != NULL){
                playerCell->id=0;
            }
            playerCell = &cell[playerX][playerY];
            //Simbolo del jugador en el mapa
            playerCell->id=254;
        }

        return true;
    }
    else
    {
        return false;
    }

}
void gamemap::loadMapFromFile()//MONICA PEREZ 9959-21-1840
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("MapG5.txt");
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
void gamemap::createMapToFile(){//MONICA PEREZ 9959-21-1840
    ofstream myFile("MapG5.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 35; j++)
            {
                if (i == 0 || i == 15)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 34)
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
void gamemap::drawPortada()//Alan Galicia 9959-21-3632
{
    string line;
    char userInput = ' ';
    ifstream myFile("portadaG5.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
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
void gamemap::drawVictoria()//Alan Galicia 9959-21-3632
{
    system("cls");
    string line;
    system("color a");
    char userInput = ' ';
    ifstream myFile("casa.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        exit(0);
    }
    else
    {
        cout << "Error FATAL: el archivo Ganador no pudo ser cargado" << endl;
    }
}
void gamemap::drawTrampa()//MONICA PEREZ 9959-21-1840
{
    system("cls");
    string line;
    system("color c");
    char userInput = ' ';
    ifstream myFile("Trampa.txt");
    if(myFile.is_open())
    {
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cout << "\n\tNOOO!!, ESE ERA EL LOBOOO :(" << endl;
        cout << "\tVuelve a intentarlo..." << endl<< endl;
        exit(0);
        //cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo Trampa no pudo ser cargado" << endl;
    }
}
void gamemap::drawIns() //Daniel Hall 9959-21-1395
{
    string line;
    char userInput = ' ';
    ifstream myFile("Instrucciones.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
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
void gamemap::drawcredi()// ABIGAIL VASQUEZ 9959-21-13777
{
    string line;
    char userInput = ' ';
    ifstream myFile("Creditos.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        exit(0);
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}


gamemap::~gamemap()
{
    //dtor
}
