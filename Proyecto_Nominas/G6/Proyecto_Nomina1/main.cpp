#include <iostream>
#include <conio.h>
#include <fstream>
#include "ingreso.h"
#include "menus.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) //main, Victor Jerez 9959-21-2081
{
    menus menuG;

    bool accesoUsuarios;
    ingreso usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
        if (accesoUsuarios){menuG.menuGeneral();}
    system("cls");
    cout<<"\n\t\t\t          ** Hasta la proxima **"<<endl;

   return 0;
}
