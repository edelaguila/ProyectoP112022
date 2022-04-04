#include "menus.h"
#include <iostream>
#include<conio.h>
using namespace std;

menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}
void menus::menuPrincipal()
{
    int choice;
	char x;
	do
    {
	system("cls");

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

    switch(choice)
    {
    case 1:
        menus::consultas();
		break;
	case 2:
        menus::contabilidad();
		break;
	case 3:
        menus::gestionEmpleados();
		break;
	case 4:
        menus::seguridad();
		break;
	case 5:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
void menus::consultas()
{
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
        cout<<"Estamos trabajando en la Consulta de Empleados"<<endl;
		break;
	case 2:
        cout<<"Estamos trabajando en la Consulta de Departamentos"<<endl;
		break;
	case 3:
        cout<<"Estamos trabajando en la Consulta de Sueldos"<<endl;
		break;
	case 4:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 4);
}

void menus::contabilidad()
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
	getch();
    }while(choice!= 7);
}

void menus::gestionEmpleados()
{
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
	cout<<"\t\t\t 6. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"Estamos trabajando en la Consulta de Empleados"<<endl;
		break;
	case 2:
        cout<<"Estamos trabajando en la Busqueda de Empleados"<<endl;
		break;
	case 3:
        cout<<"Estamos trabajando en Agregar Empleados"<<endl;
		break;
	case 4:
        cout<<"Estamos trabajando en Modificar Empleados"<<endl;
		break;
	case 5:
        cout<<"Estamos trabajando en Eliminar Empleados"<<endl;
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}

void menus::seguridad()
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
	getch();
    }while(choice!= 4);
}
