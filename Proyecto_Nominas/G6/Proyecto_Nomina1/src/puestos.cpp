#include "puestos.h"
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
//Codigo CRUD de puestos, Victor Jerez 9959-21-2081
Puestos::Puestos()
{

}

Puestos::~Puestos(){

}

void Puestos::menu()
{
    int choice;
    char x;
    do

    {
    system("cls");
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t             | MENU DE PUESTOS |            "<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t 1. Ingresar nuevo Puesto"<<endl;
    cout << "\t\t\t 2. Buscar Puestos"<<endl;
    cout << "\t\t\t 3. Desplegar Puestos"<<endl;
    cout << "\t\t\t 4. Modificar Puestos"<<endl;
    cout << "\t\t\t 5. Borrar Puestos"<<endl;
    cout << "\t\t\t 6. Salir"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Ingresa tu opcion [1/2/3/4/5/6]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion: ";
    cin>>choice;
    menus punto;
    switch(choice)
        {
            case 1:
                insertar();
                break;
            case 2:
                buscar();
                break;
            case 3:
                desplegar();
                break;
            case 4:
                modificar();
                break;
            case 5:
                borrar();
                break;
            case 6:
                punto.mantenimientos();
                break;
            default:
                cout<<"\n\t\t\t Hubo un error, intentalo nuevamente"<<endl;

        }
        getch();
    }while(choice!= 5);
}
void Puestos::insertar()
{
    string id, nombre, departamento, vacantes;
    system("cls");
    fstream archivo, archivo2;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t              | NUEVO PUESTO |              "<<endl;
    cout << "\t\t\t *********************************************"<<endl;

    cout << "\t\t\t Ingrese ID del Puesto: ";
    cin >> id;
    cout << "\t\t\t Ingrese Nombre del Puesto: ";
    cin >> nombre;
    cout << "\t\t\t Ingrese el Departamento: ";
    cin >> departamento;
    cout << "\t\t\t Ingrese los puestos vacantes: ";
    cin >> vacantes;

    archivo.open("puestos.dat", ios::binary | ios::app | ios::out);
    archivo2.open("puestos2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< departamento <<std::left<<std::setw(15)<< vacantes <<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&id),
         sizeof( id ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&departamento),
         sizeof( departamento ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&vacantes),
         sizeof( vacantes ) );
    }
}
void Puestos::buscar()
{
    string id, nombre, departamento, vacantes;
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t              | PUESTOS|                   "<<endl;
	cout << "\t\t\t *********************************************"<<endl;

	archivo.open("puestos.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\t No hay ninguna informacion en el sistema";
		archivo.close();
	}

	else
	{
		string participant_id;
		cout<<"\n\t\t\t Ingrese Id del puesto que quiere buscar: ";
		cin>>participant_id;
        system("cls");

        archivo >> id >> nombre >> departamento >> vacantes;
		while(!archivo.eof())
	{
            if(participant_id==id)
		{

            cout << "\t\t\t *********************************************"<<endl;
            cout << "\t\t\t              | CONCEPTOS |                   "<<endl;
            cout << "\t\t\t *********************************************"<<endl;
            cout << "\n\t\t\t Id del Puesto : "<< id << endl;
            cout << "\t\t\t Nombre del Puesto: "<< nombre <<endl;
            cout << "\t\t\t Departamento: "<< departamento <<endl;
            cout << "\t\t\t Vacantes del Puesto: "<< vacantes <<endl;

			total++;

		}
		        archivo >> id >> nombre >> departamento >> vacantes;
	}

		if(total==0)
		{
			cout<<"\n\t\t\t No hay informacion almacenada";
		}
		archivo.close();
	}

}
void Puestos::desplegar()
{
    system("cls");
    string id, nombre, departamento, vacantes;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t              | PUESTOS |                   "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("puestos.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> departamento >> vacantes;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID del Puesto: "<<id<<endl;
			cout<<"\t\t\t Nombre del Puesto: "<<nombre<<endl;
			cout<<"\t\t\t Departamento: "<<departamento<<endl;
			cout<<"\t\t\t Vacantes del Puesto: "<<vacantes<<endl;

			archivo >> id >> nombre >> departamento >> vacantes;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}archivo.close();

	char ctrl;
	cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        menu();
    }
}

void Puestos::modificar()
{
	system("cls");
	string id, nombre, departamento, vacantes;
	fstream file,file1;
	string participant_id;
	int found=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t           | MODIFICACION DE PUESTOS |        "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	file.open("puestos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Puesto que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> departamento >> vacantes;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< departamento <<std::left<<std::setw(10)<< vacantes<<"\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id del Puesto: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del Puesto: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Departamento: ";
				cin>>departamento;
				cout<<"\t\t\tIngrese vacantes del puesto: ";
				cin>>vacantes;
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< departamento <<std::left<<std::setw(10)<< vacantes<<"\n";
				found++;
			}
			file >> id >> nombre >> departamento >> vacantes;

		}
		file1.close();
		file.close();
		remove("puestos.dat");
		rename("registro.dat","puestos.dat");
	}
}

void Puestos::borrar()
{
    string id, nombre, departamento, vacantes;
    system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t           | Borrar Informacion |"<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("puestos.dat",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del puesto que quiere borrar: ";
		cin>>id_persona;
		file1.open("registro.dat",ios::binary | ios::app | ios::out);
		file >> id >> nombre >> departamento >> vacantes;
		while(!file.eof())
		{
			if(id_persona!= id)
			{
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< departamento <<std::left<<std::setw(10)<< vacantes<<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> departamento >> vacantes;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("puestos.dat");
		rename("registro.dat","puestos.dat");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}
