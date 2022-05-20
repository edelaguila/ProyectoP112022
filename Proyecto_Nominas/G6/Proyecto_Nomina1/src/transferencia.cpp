#include "transferencia.h"
#include "menus.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>


transferencia::transferencia()
{
    //ctor
}

transferencia::~transferencia()
{
    //dtor
}

void transferencia::menu1()
{


     int choice;
     char x;
     do
     {
         system("cls");

    cout<<"\t--------------------------------------"<<endl;
    cout<<"\t|Bienvenido Al Menu DE Transferencias|"<<endl;
    cout<<"\t--------------------------------------"<<endl;
    cout<<"\t| 1. Ingresar Dinero A La Cuenta     |"<<endl;
    cout<<"\t| 2. Hacer Una Transferencia         |"<<endl;
    cout<<"\t| 3. Historial De Transferencia      |"<<endl;
    cout<<"\t| 4. Salida                          |"<<endl;
    cout<<"\t--------------------------------------"<<endl;
	cout<<"\t|     Opcion A Escoger:(1/2/3/4)     |"<<endl;
	cout<<"\t--------------------------------------"<<endl;
	cout<<"Ingresa Tu Opcion: ";
    cin>>choice;
    menus tilde;
switch(choice)
    {
    case 1:
    	do
    	{
    		insertdi();
    		cout<<"\t Desea ingresar mas dinero?(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
	    do
    	{
    		inserttrans();
    		cout<<"\t Su transferencia fue excitosa(C): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 3: searchtrans();
		break;
	case 4:
		tilde.menuGeneral();

	default:
		cout<<"\n\t\t La transferencia fue cancelada";
			}
	getch();
    }while(choice!= 4);

}
void transferencia::insertdi()
{
	 string ncuenta, dinero;
	system("cls");
	fstream file;
	cout<<"\t-----------------------------------------"<<endl;
	cout<<"\t|      DEPOSITE DINERO A SU CUENTA      |"<<endl;
	cout<<"\t-----------------------------------------"<<endl;
	cout<<"\tIngrese su numero de cuenta: ";
	cin>>ncuenta;
	cout<<"\tIngrese la cantidad a depositar: ";
	cin>>dinero;
	file.open("depositos.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<<ncuenta <<std::left<<std::setw(15)<<dinero << "\n";
	file.close();
}
void transferencia::inserttrans()
{
    string ncuentat, cantidad;
    system("cls");
	fstream file;
	cout<<"\t------------------------------------"<<endl;
	cout<<"\t|      TRANSFERENCIA BANCARIA      |"<<endl;
	cout<<"\t------------------------------------"<<endl;
	cout<<"\tIngrese numero de cuenta: ";
	cin>>ncuentat;
	cout<<"\tIngrese la cantidad a transferir: ";
	cin>>cantidad;
	file.open("transferencias.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<<ncuentat <<std::left<<std::setw(15)<<cantidad << "\n";
	file.close();
}

void transferencia::searchtrans()
{
    string ncuentat, cantidad;
    system("cls");
	fstream file;
	int found=0;
	file.open("transferencias.txt",ios::in);
	if(!file)
	{
		cout<<"---------------------------------------"<<endl;
		cout<<"|     Historial De Transferencias     |"<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string historial;
		cout<<"\t----------------------------------------"<<endl;
		cout<<"\t|       Datos De La Transferencia       |"<<endl;
		cout<<"\t----------------------------------------"<<endl;
		cout<<"\n\tIngrese el numero de cuenta: ";
		cin>>historial;
		file >> ncuentat >> cantidad;
		while(!file.eof())
		{
			if(historial==ncuentat)
			{
				cout<<"\n\n\t Numero De Cuenta: "<<ncuentat<<endl;
				cout<<"\tMonto Transferido: "<<cantidad<<endl;
				found++;
			}
			file >> ncuentat >> cantidad;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Numero de cuenta no encontrado...";
		}
		file.close();
	}
}
