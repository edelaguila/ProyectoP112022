#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puesto.h"
#include "Bitacora.h"

Puesto::Puesto()
{
    //ctor
}

Puesto::~Puesto()
{
    //dtor
}

//Mantenimiento de Departamentos y Puestos - Maria Jose Veliz 9959-21-5909
//menu principal de puestos
void Puesto::menu()
{
    Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  SISTEMA GESTION DEPARTAMENTOS   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingreso Puesto"<<endl;
	cout<<"\t\t\t 2. Actualizar Departamento"<<endl;
	cout<<"\t\t\t 3. Consultar Departamento"<<endl;
	cout<<"\t\t\t 4. Imprimir Departamentos"<<endl;
	cout<<"\t\t\t 5. Borrar Departamento"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;

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
    	    control.nuevaActividadTxt(25);
            control.nuevaActividad(25);
    		Ingresar();
    		cout<<"\n\t\t\t Agrega otro Departamento(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		cout <<"Departamentos agregados satisfactoriamente"<<endl;
		break;
	case 2:
	    control.nuevaActividadTxt(26);
        control.nuevaActividad(26);
		Actualizar();
		cout <<"Departamento actualizado satisfactoriamente"<<endl;
		break;
	case 3:
	    control.nuevaActividadTxt(27);
        control.nuevaActividad(27);
		Consultar();
		cout <<"Presiona Enter para salir"<<endl;
		break;
	case 4:
	    control.nuevaActividadTxt(28);
        control.nuevaActividad(28);
		Imprimir();
		cout <<"Impresion realizada satisfactoriamente"<<endl;
		break;
	case 5:
	    control.nuevaActividadTxt(33);
        control.nuevaActividad(33);
		Borrar();
		cout <<"Departamento eliminado satisfactoriamente"<<endl;
		break;
	case 6:
	    cout << "Presiona Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}

//Funcion que ingresa puestos y departamentos
void Puesto::Ingresar()
{
    Bitacora control;
	system("cls");
	fstream file;
	cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de Departamento......................................................"<<endl;
	cout<<"\t\t\tIngresa el nombre del Departamento       : ";
	cin>>Dpuesto;
	cout<<"\t\t\tIngresa el Puesto     : ";
	cin>>Crpuesto;
	cout<<"\t\t\tIngresa Salario  : ";
	cin>>Spuesto;
	cout<<"\t\t\tIngresa hora de entrada  : ";
	cin>>Hentrada;
	cout<<"\t\t\tIngresa hora de salida  : ";
	cin>>Hsalida;
	file.open("PUESTO.dat", ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
	file.close();
    file.open("PUESTO.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
	file.close();
}

//Funcion para imprimir los datos de puestos
void Puesto::Imprimir()
{
    Bitacora control;
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n..............................Tabla de Detalles de Departamento ........................"<<endl;
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
			cout<<"\t\t\t Puesto: "<<Crpuesto<<endl;
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

//funcion para modificar puestos y departamentos
void Puesto::Actualizar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion Detalles Departamento................................."<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento a modificar: ";
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
				cout<<"\t\t\tIngrese el Puesto: ";
				cin>>Crpuesto;
				cout<<"\t\t\tIngresa Salario: ";
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
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}

//funcion para conultar puestos y departamentos
void Puesto::Consultar()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n Ingrese el Departamento que quiere consultar: ";
		cin>>participant_Dp;
		file >> Dpuesto >> Crpuesto >> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp==Dpuesto)
			{
				cout<<"\n\n\t\t\t Departamento: "<<Dpuesto<<endl;
                cout<<"\t\t\t Puesto: "<<Crpuesto<<endl;
                cout<<"\t\t\t Salario: "<<Spuesto<<endl;
                cout<<"\t\t\t Hora de entrada: "<<Hentrada<<endl;
                cout<<"\t\t\t Hora de salida: "<<Hsalida<<endl;

				found++;
			}
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}
}
void Puesto::Borrar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.......................................Detalles Departamento a Borrar.................................."<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento que quiere borrar: ";
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
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file1.close();
		file.close();
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}


    void Puesto::consultarDep()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\t No hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n Ingrese el Departamento que desea ver: ";
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
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}
}


