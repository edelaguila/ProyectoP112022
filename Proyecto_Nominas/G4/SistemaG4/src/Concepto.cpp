#include "Concepto.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Bitacora.h"
Concepto::Concepto()
{
    //ctor
}

Concepto::~Concepto()
{
    //dtor
}
void Concepto::menu()
{
    Bitacora control;
    int choice;
    char x;
    do
    {
    system("cls");
    cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\tCambios de % de deducciones y percepciones."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Actualizar Porcentaje"<<endl;
	cout<<"\t\t\t 2. Consultar Porcentaje"<<endl;
    cout<<"\t\t\t 3. Regresar"<<endl;
    cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        control.nuevaActividad(35);
        Actualizar();
        cout<<"Porcentajes actualizados satisfactoriamente" << endl;
        break;
    case 2:
        Consultar();
        control.nuevaActividad(34);
        cout<<"Consulta existosa"<<endl;
        break;
    case 3:
        cout<<"Presionar enter para confirmar"<< endl;
        break;
    default:
        cout<< "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    }
    getch();

    }while(choice!=3);
}

//función para modificar porcentajes de nomina de deducciones y percepciones
void Concepto::Actualizar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion de Porcentaje................................."<<endl;
	file.open("Porcentajes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el anio anterior a modificar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file>>anio>>PIGSS>>PISR>>PAnticipos>>Ppension>>resultIGSS>>resultISR>>resultAnticipo>>resultpension;
		while(!file.eof())
		{
			if(participant_Dp!=anio)
			{
			 file1<<std::left<<std::setw(15)<<anio<<std::left<<std::setw(15)<< PIGSS <<std::left<<std::setw(15)<< PISR <<std::left<<std::setw(15)<< PAnticipos <<std::left<<std::setw(15)<< Ppension <<std::left<<std::setw(15)<< resultIGSS<<std::left<<std::setw(15)<<resultISR<<std::left<<std::setw(15)<<resultAnticipo<<std::left<<std::setw(15)<<resultpension << "\n";
			}
			else
			{
			    cout<<"Ingrese el anio de la nomina: ";
			    cin>>anio;
				cout<<"\t\t\tIngrese porcentaje nuevo de IGSS: ";
				cin>>PIGSS;
				cout<<"\t\t\tIngrese porcentaje nuevo de ISR: ";
				cin>>PISR;
				cout<<"\t\t\tIngresa porcentaje nuevo de Anticipos: ";
				cin>>PAnticipos;
				cout<<"\t\t\tIngrese porcentaje nuevo de Pension alimenticia: ";
				cin>>Ppension;
				double cIGSS = PIGSS/100;
				double cISR = PISR/100;
				double cAnticipos = PAnticipos/100;
				double cPension = Ppension/100;
				file1<<std::left<<std::setw(15)<<anio<<std::left<<std::setw(15)<< PIGSS <<std::left<<std::setw(15)<< PISR <<std::left<<std::setw(15)<< PAnticipos <<std::left<<std::setw(15)<< Ppension <<std::left<<std::setw(15)<< cIGSS<<std::left<<std::setw(15)<<cISR<<std::left<<std::setw(15)<<cAnticipos<<std::left<<std::setw(15)<<cPension << "\n";
                found++;
			}
			file>>anio>>PIGSS>>PISR>>PAnticipos>>Ppension>>resultIGSS>>resultISR>>resultAnticipo>>resultpension;

		}
		file1.close();
		file.close();
		remove("Porcentajes.txt");
		rename("Record.txt","Porcentajes.txt");
	}
}
void Concepto::Consultar()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("Porcentajes.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos de porcentaje buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n...................................Datos de porcentaje buscado......................................"<<endl;
		cout<<"\nIngrese el anio que quiera consultar la vigencia de deducciones y percepciones: ";
		cin>>participant_Dp;
		file>>anio>>PIGSS>>PISR>>PAnticipos>>Ppension>>resultIGSS>>resultISR>>resultAnticipo>>resultpension;
		while(!file.eof())
		{
			if(participant_Dp==anio)
			{
			    cout<<"\n\n\t\t\t anio: "<<anio<<endl;
				cout<<"\n\n\t\t\t IGSS en %: "<<PIGSS<<endl;
                cout<<"\t\t\t ISR en %: "<<PISR<<endl;
                cout<<"\t\t\t Anticipo en %: "<<PAnticipos<<endl;
                cout<<"\t\t\t Pensionn en %: "<<Ppension<<endl;
                cout<<"\t\t\t IGSS en decimales: "<<resultIGSS<<endl;
                cout<<"\t\t\t ISR en decimales: "<<resultISR<<endl;
                cout<<"\t\t\t Anticipos en Decimales: "<<resultAnticipo<<endl;
                cout<<"\t\t\t Pension ALimenticia en decimales: "<<resultpension<<endl;
                found++;

			}
			file>>anio>>PIGSS>>PISR>>PAnticipos>>Ppension>>resultIGSS>>resultISR>>resultAnticipo>>resultpension;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t anio no encontrado...";
		}
		file.close();
	}
}

void Concepto::Consultar2()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("Porcentajes.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos de porcentaje buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		file>>anio>>PIGSS>>PISR>>PAnticipos>>Ppension>>resultIGSS>>resultISR>>resultAnticipo>>resultpension;
		while(!file.eof())
		{
			file>>anio>>PIGSS>>PISR>>PAnticipos>>Ppension>>resultIGSS>>resultISR>>resultAnticipo>>resultpension;
			eIGSS = PIGSS/100;
			eISR = PISR/100;
			eAnticipos = PAnticipos/100;
			ePension = Ppension/100;
		}
		file.close();
	}
}
