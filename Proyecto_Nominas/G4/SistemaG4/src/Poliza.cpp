#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Poliza.h"
#include "Bitacora.h"

Poliza::Poliza()
{
    //ctor
}

Poliza::~Poliza()
{
    //dtor
}
void Poliza::menu()
{
    Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  Consulta Poliza   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Seguro de vida "<<endl;
	cout<<"\t\t\t 2. Seguro de Salud "<<endl;
	cout<<"\t\t\t 3. Seguro Familiar "<<endl;
	cout<<"\t\t\t 4. Seguro Dental "<<endl;
	cout<<"\t\t\t 5. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
		cout <<"  - Muerte natural o por enfermedad "<<endl;
		break;
	case 2:
		cout <<" - Atencion medica general "<<endl;
		break;
    case 3:
		cout <<" - Asistencia medica para esposa e hijos"<<endl;
		break;
    case 4:
		cout <<" - Consulta cada 6 meses "<<endl;
	case 5:
		cout <<"Presiona Enter para salir"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
