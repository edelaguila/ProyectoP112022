#include <iostream>
#include<conio.h>
#include "Persona.h"
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

//Declaracion de las funciones para abrir los menus
void consultas();
void gestionEmpleados();
void contabilidad();
void seguridad();

int main(int argc, char *argv[])
{

/*
    struct tm {
      int tm_sec;   // seconds of minutes from 0 to 61
      int tm_min;   // minutes of hour from 0 to 59
      int tm_hour;  // hours of day from 0 to 24
      int tm_mday;  // day of month from 1 to 31
      int tm_mon;   // month of year from 0 to 11
      int tm_year;  // year since 1900
      int tm_wday;  // days since sunday
      int tm_yday;  // days since January 1st
      int tm_isdst; // hours of daylight savings time
    }
*/

time_t now = time(0);
tm * time = localtime(&now);

vector<string> dia_semana;
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");

vector<string> mes;
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");

int year = 1900 + time->tm_year;

//inicio menu principal
int choice;
	char x;
	do
    {
	system("cls");
    cout<<"\t\t\t-----------------------------------------------------------------"<<endl;
    cout << "\t\t\tHoy " << dia_semana[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
    cout <<"\t\t\tHora: "<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
    cout<<"\t\t\t-----------------------------------------------------------------"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    SISTEMA RECURSOS HUMANOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultas"<<endl;
	cout<<"\t\t\t 2. Contabilidad"<<endl;
	cout<<"\t\t\t 3. Gestion Empleados"<<endl;
	cout<<"\t\t\t 4. Seguridad"<<endl;
	cout<<"\t\t\t 5. Exit"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        consultas();
		break;
	case 2:
        contabilidad();
		break;
	case 3:
        gestionEmpleados();
		break;
	case 4:
        seguridad();
		break;
	case 5:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 5);
    return 0;
}
//Declaracion menu consultas
void consultas()
{
    //Creacion de un objeto de la clase Persona
    Persona empleado;
    fstream empleadosEntradaSalida = empleado.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    CONSULTAS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Empleados"<<endl;
	cout<<"\t\t\t 2. Consulta Departamentos"<<endl;
	cout<<"\t\t\t 3. Consulta Sueldos"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        empleado.consultarRegistro(empleadosEntradaSalida);
		break;
	case 2:
        cout<<"Estamos trabajando en la Consulta de Departamentos"<<endl;
		break;
	case 3:
        cout<<"Estamos trabajando en la Consulta de Sueldos"<<endl;
		break;
	case 4:
	        cout<<"Presione Enter otra vez para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 4);
}

void contabilidad()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    CONTABILIDAD    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Nomina"<<endl;
	cout<<"\t\t\t 2. Consulta Poliza"<<endl;
	cout<<"\t\t\t 3. Consulta Planillas"<<endl;
	cout<<"\t\t\t 4. Consulta Retenciones"<<endl;
	cout<<"\t\t\t 5. Gestion Salarios"<<endl;
	cout<<"\t\t\t 6. Transferencias"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"Estamos trabajando en la Consulta de Nomina"<<endl;
		break;
	case 2:
        cout<<"Estamos trabajando en la Consulta de Poliza"<<endl;
		break;
	case 3:
        cout<<"Estamos trabajando en la Consulta de Planillas"<<endl;
		break;
	case 4:
        cout<<"Estamos trabajando en la Consulta de Retenciones"<<endl;
		break;
	case 5:
        cout<<"Estamos trabajando en la Gestion de Salarios"<<endl;
		break;
	case 6:
        cout<<"Estamos trabajando en las Transferencias"<<endl;
		break;
	case 7:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    }
    }while(choice!= 7);
}

void gestionEmpleados()
{
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    GESTION EMPLEADOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Empleados"<<endl;
	cout<<"\t\t\t 2. Busqueda de Empleados"<<endl;
	cout<<"\t\t\t 3. Agregar Empleados"<<endl;
	cout<<"\t\t\t 4. Modificar Empleados"<<endl;
	cout<<"\t\t\t 5. Eliminar Empleados"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Empleados"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter otra vez para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}

void seguridad()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    SEGURIDAD    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Cambio de Usuario"<<endl;
	cout<<"\t\t\t 2. Cambio de Contraseña"<<endl;
	cout<<"\t\t\t 3. Backup"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"Estamos trabajando en el Cambio de Usuario"<<endl;
		break;
	case 2:
        cout<<"Estamos trabajando en la Cambio de Contraseña"<<endl;
		break;
	case 3:
        cout<<"Estamos trabajando en el Backup"<<endl;
		break;
	case 4:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 4);
}
