#include "Empresas.h"
#include "menus.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
//Codigo CRUD de Empresas, Salvador Martinez 9959-21-4167

Empresas::Empresas()
{
    //ctor
}

Empresas::~Empresas()
{
    //dtor
}

void Empresas::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t |||||||||||||||||||||||||||"<<endl;
	cout<<"\t\t\t |  MANTENIMIENTO EMPRESA  |"<<endl;
	cout<<"\t\t\t |||||||||||||||||||||||||||"<<endl;

    cout<<"" << endl;

	cout<<"\t\t\t 1. -Ingrese la empresa-"<<endl;
	cout<<"\t\t\t 2. -Despliegue la empresa-" << endl;
	cout<<"\t\t\t 3. -Modificar empresa-"<<endl;
	cout<<"\t\t\t 4. -Buscar empresa-"<<endl;
	cout<<"\t\t\t 5. -Borrar empresa-"<<endl;
	cout<<"\t\t\t 6. -Salir-"<<endl;

	cout<<"\t\t\t __________________________"<<endl;
	cout<<"\t\t\t | Opciones: [1/2/3/4/5/6]|"<<endl;
	cout<<"\t\t\t "<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    menus av;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t �Desea agregar otra empresa?  (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		av.mantenimientos();
	default:
		cout<<"\n\t\t\t -�Opcion invalida!-";
	}
	getch();
    }while(choice!= 6);
}

void Empresas::insert()
{


     string id,nombre,telefono;
	system("cls");
	fstream file;
	cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  AGREGA INFORMACION DE EMPRESA _______________________________________________"<<endl;
    cout <<""<<endl;
	cout<<"\t\t\t  Ingresa ID de la empresa         : ";
	cin>>id;
	cout<<"\t\t\t  Ingresa Nombre de la empresa     : ";
	cin>>nombre;
	cout<<"\t\t\t  Ingresa Telefono de la empresa   : ";
	cin>>telefono;

    file.open("registroDeEmpresas.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono<< "\n";
	file.close();
}

void Empresas::display()
{
     string id,nombre,telefono;

	system("cls");
	fstream file;
	int total=0;
cout<<"\n________________________________________________________________________________________________________________________"<<endl;
cout<<"\n_________________________________________  INFORMACION GUARDADA DE EMPRESAS ____________________________________________"<<endl;

    cout <<""<<endl;
    file.open("registroDeEmpresas.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informaci�n...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID empresa: "<<id<<endl;
			cout<<"\t\t\t Nombre empresa: "<<nombre<<endl;
			cout<<"\t\t\t Telefono empresa: "<<telefono<<endl;
			file >> id >> nombre >> telefono;
		}
		if(total==0)
		{
			cout<<"\n\t\t\t-No hay informacion-";
		}
	}
	file.close();
}

void Empresas::modify()
{
     string id,nombre,telefono;
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  MODIFICACION DE EMPRESAS ____________________________________________________"<<endl;

    cout <<""<<endl;

    file.open("registroDeEmpresas.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la empresa que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id de la empresa ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del empresa: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Telefono del empresa: ";
				cin>>telefono;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono<< "\n";
				found++;
			}
			file >> id >> nombre >> telefono;

		}
		file1.close();
		file.close();
		remove("registroDeEmpresas.dat");
		rename("registro.dat","registroDeEmpresas.dat");
	}
}

void Empresas::search()
{
     string id,nombre,telefono;
	system("cls");
	fstream file;
	int found=0;
	file.open("registroDeEmpresas.dat",ios::binary|ios::in);
	if(!file)
	{
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  AGREGA INFORMACION DE EMPRESA _______________________________________________"<<endl;

    cout <<""<<endl;		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  BUSCAR INFORMACION DE EMPRESA _______________________________________________"<<endl;

    cout <<""<<endl;

        cout<<"\nIngrese Id de la empresa que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id de la empresa: "<<id<<endl;
				cout<<"\t\t\t Nombre de la empresa: "<<nombre<<endl;
				cout<<"\t\t\t Telefono de la empresa: "<<telefono<<endl;
				found++;
			}
			file >> id >> nombre >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empresa no encontrado...";
		}
		file.close();
	}
}


void Empresas::delet()
{
     string id,nombre,telefono;
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  BORRAR INFORMACION EMPRESA __________________________________________________"<<endl;

    cout <<""<<endl;	file.open("registroDeEmpresas.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de empresa que quiere borrar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id de empresa no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeEmpresas.dat");
		rename("registro.dat","registroDeEmpresas.dat");
	}
}
