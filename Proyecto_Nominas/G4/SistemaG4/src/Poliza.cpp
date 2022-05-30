#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Poliza.h"
#include "Bitacora.h"
#include "Persona.h"
Poliza::Poliza()
{
    //ctor
}

Poliza::~Poliza()
{
    //dtor
}

//Clase para Poliza de Seguros - Meyglin Rosales 9959-21-4490, Maria Jose Veliz 9959-21-5909


void Poliza::menu()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  Consulta Poliza   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Generacion de poliza "<<endl;
	cout<<"\t\t\t 2. Salir  "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
        //Se muestran las distintas opciones de seguros con los que cuenta la empresa
    case 1:
        control.nuevaActividadTxt(37);
        control.nuevaActividad(37);
        control.fechaHora();
		empleado.busquedaRegistro2(empleadosEntradaSalida);
        cout<<"\t\t\t"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;

		break;
	case 2:
	     cout <<"Presiona Enter para salir"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 2);
}
