#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puesto.h"

Puesto::Puesto()
{
    //ctor
}

Puesto::~Puesto()
{
    //dtor
}
void Puesto::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  SISTEMA GESTION PUESTOS   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingreso Puesto"<<endl;
	cout<<"\t\t\t 2. Actualizar Puesto"<<endl;
	cout<<"\t\t\t 3. Consultar Puestos"<<endl;
	cout<<"\t\t\t 4. Imprimir Puesto"<<endl;
	cout<<"\t\t\t 5. Borra Puesto"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		Ingresar();
    		cout<<"\n\t\t\t Agrega otro Puesto(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		Actualizar();
		break;
	case 3:
		Consultar();
		break;
	case 4:
		Imprimir();
		break;
	case 5:
		Borrar();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void Puesto::Ingresar()
{
	system("cls");
	fstream file;
	cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de Puesto......................................................"<<endl;
	cout<<"\t\t\tIngresa Departamento del Puesto       : ";
	cin>>Dpuesto;
	cout<<"\t\t\tIngresa el Cargo del Puesto     : ";
	cin>>Crpuesto;
	cout<<"\t\t\tIngresa Salario del Puesto   : ";
	cin>>Spuesto;
	cout<<"\t\t\tIngresa hora de entrada  : ";
	cin>>Hentrada;
	cout<<"\t\t\tIngresa hora de salida  : ";
	cin>>Hsalida;
	file.open("PUESTO.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
	file.close();
}
void Puesto::Imprimir()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n..............................Tabla de Detalles de Puesto ........................"<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Departamento: "<<Dpuesto<<endl;
			cout<<"\t\t\t Nombre del cargo: "<<Crpuesto<<endl;
			cout<<"\t\t\t Salario: "<<Spuesto<<endl;
			cout<<"\t\t\t Hora de entrada: "<<Hentrada<<endl;
			cout<<"\t\t\t Hora de salida: "<<Hsalida<<endl;
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void Puesto::Actualizar()
{
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion Detalles Puesto................................."<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Departamento de la personas que quiere modificar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp!=Dpuesto)
			{
			 file1<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Departamento del Puesto: ";
				cin>>Dpuesto;
				cout<<"\t\t\tIngrese Cargo del Puesto: ";
				cin>>Crpuesto;
				cout<<"\t\t\tIngresa Salario del Puesto: ";
				cin>>Spuesto;
				cout<<"\t\t\tIngrese hora de entrada: ";
				cin>>Hentrada;
				cout<<"\t\t\tIngresa hora de salida: ";
				cin>>Hsalida;
				file1<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
				found++;
			}
			file >> Dpuesto >> Crpuesto >>Spuesto >> Hentrada >> Hsalida;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
void Puesto::Consultar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Puesto buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del puesto buscado......................................"<<endl;
		cout<<"\nIngrese Departamento de la Persona que quiere buscar: ";
		cin>>participant_Dp;
		file >> Dpuesto >> Crpuesto >> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp==Dpuesto)
			{
				cout<<"\n\n\t\t\t Departamento: "<<Dpuesto<<endl;
                cout<<"\t\t\t Nombre del cargo: "<<Crpuesto<<endl;
                cout<<"\t\t\t Salario: "<<Spuesto<<endl;
                cout<<"\t\t\t Hora de entrada: "<<Hentrada<<endl;
                cout<<"\t\t\t Hora de salida: "<<Hsalida<<endl;

				found++;
			}
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrado...";
		}
		file.close();
	}
}
void Puesto::Borrar()
{
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.......................................Detalles Puesto a Borrar.................................."<<endl;
	file.open("PUESTOS.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento de la Persona que quiere borrar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp!= Dpuesto)
			{
				file1<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento de Puesto no encontrado...";
		}
		file1.close();
		file.close();
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}
