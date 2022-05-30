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


//Inicio de main
int main(int argc, char *argv[])
{
    menus menuG;

    //Llamado a clase Usuarios para el Login
    bool accesoUsuarios;
    Usuarios usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
    if (accesoUsuarios){menuG.menuGeneral();}
    system("cls");
    cout<<"** REGRESE PRONTO **";
    return 0;

}
