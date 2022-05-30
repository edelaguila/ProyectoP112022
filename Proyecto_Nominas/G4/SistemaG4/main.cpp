#include <iostream>
#include<conio.h>
#include "Persona.h"
#include "Bitacora.h"
#include "Puesto.h"
#include "Usuarios.h"
#include "menus.h"
#include "Concepto.h"
#include "Poliza.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

void portadaproyec();
//Inicio de main
int main(int argc, char *argv[])
{
    menus menuG;

    //Llamado a clase Usuarios para el Login
    bool accesoUsuarios;
    portadaproyec();
    Usuarios usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
    if (accesoUsuarios){menuG.menuGeneral();}
    system("cls");
    cout<<"** REGRESE PRONTO **";
    return 0;

}
void portadaproyec(){
string line;
    //char userInput = ' ';
    ifstream myFile("Portada.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cout<<"Presione cualquier tecla para continuar";
        cin.get();
    }
    else
    {
        cout << "Error FATAL: el archivo de modulo no pudo ser cargado" << endl;
        cin.get();
    }
}
