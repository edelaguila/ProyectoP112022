#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "generacionnomina.h"
#include "empleados.h"
#include "menus.h"

using namespace std;
//Codigo de la generación de nomina, Victor Guzman 9959-21-5648
generacionnomina::generacionnomina(){
 double horast, sueldo, iva, sueldofinal, sueldoiva, isr, sueldoisr, igss, sueldoigss, bonificacion, sueldobonificacion, sueldores;
}

generacionnomina::~generacionnomina(){

}

void generacionnomina::menuprincipalgeneracionnomina()
{
    int opcion;
	int x;

	do{

	system("cls");

	cout<<"------------------------------------------------------"<<endl;
	cout<<"\t\t ||||          GENERACION DE NOMINAS           ||||"<<endl;
	cout<<"------------------------------------------------------"<<endl;

	cout<<"\t 1. Ingresar datos de nueva nomina"<<endl;
	cout<<"\t 2. Ver nominas actuales"<<endl;
	cout<<"\t 3. Salir"<<endl;

    cout<<"-"<<endl;

    cout<<"\n\t RESPUESTA: ";
    cin>>opcion;
    menus genera;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		generar();
    		cout<<"\n\t �Deseas generar una nueva nomina?"<<endl;
    		cout<<"\n\t 1. Si"<<endl;
    		cout<<"\n\t 2. No"<<endl;
    		cout<<"-"<<endl;
    		cout<<"\n\t RESPUESTA:";
    		cin>>x;
		}while(x==1);
		break;
	case 2:
		vernominas();
		break;
    case 3:
        genera.menuGeneral();
	default:
		cout<<"\n\t Por favor, elegir un numero del 1 al 5 segun dice la pantalla";
	}
	getch();
    }while(opcion!= 2);
}

void generacionnomina::generar()
{
    double calculo;
    double calculo2;
    double sueldofinal;

	system("cls");
	fstream archivo, archivo2;
	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n----------------------------------- INGRESO DE DATOS ----------------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	cout<<"\tIngresa el sueldo: ";
	cin>>sueldo;

	cout<<"\tIngresa las horas trabajadas durante el mes: ";
	cin>>horast;

	iva = 0.12;
	isr = 0.05;
	bonificacion = 250;
	igss = 0.0483;

	sueldoiva = sueldo * iva;
	sueldoisr = sueldo * isr;
	sueldoigss = sueldo * igss;

	calculo = sueldoiva + sueldoisr + sueldoigss;

    sueldobonificacion = bonificacion + sueldo;

	sueldores = sueldo - calculo  ;

	if(horast > 160){
        calculo2 = (horast - 160) * 50;
        sueldofinal = (sueldores + calculo2 + bonificacion);
	}

	else{
        sueldofinal = (sueldores + bonificacion);
	}

    archivo.open("nominasgeneradas.dat", ios::binary | ios::app | ios::out);
    archivo2.open("nominasgeneradas2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15)<< horast <<std::left<<std::setw(15)<< iva <<std::left<<std::setw(15)<< sueldoiva <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< sueldoigss <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< sueldoisr <<std::left<<std::setw(15)<< bonificacion <<std::left<<std::setw(15)<< sueldobonificacion <<std::left<<std::setw(15)<< sueldores << std::left<<std::setw(15)<< sueldofinal<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldo),
         sizeof( sueldo ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&horast),
         sizeof( horast ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&iva),
         sizeof( iva ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldoiva),
         sizeof( sueldoiva ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&isr),
         sizeof( isr ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldoisr),
         sizeof( sueldoisr ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&igss),
         sizeof( igss ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldoigss),
         sizeof( sueldoigss ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&bonificacion),
         sizeof( bonificacion ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldobonificacion),
         sizeof( sueldobonificacion ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldores),
         sizeof( sueldores ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&sueldofinal),
        sizeof( sueldofinal ) );
    }
}

void generacionnomina::vernominas()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- VISUALIZACION DE NOMINAS GENERADAS --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	archivo.open("nominasgeneradas.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has generado ninguna nomina al sistema";
		archivo.close();
	}

	else
	{
		archivo >> sueldo >> horast >> iva >> sueldoiva >> igss >> sueldoigss >> isr >> sueldoisr >> bonificacion >> sueldobonificacion >> sueldores >> sueldofinal;

		while(!archivo.eof())
		{
			total++;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"|                     CUADRO DE NOMINAS                      |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"\n| Sueldo :                      |"<< sueldo <<"                       |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Horas trabajadas:             |"<< horast <<"                        |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| IVA:                          |"<< iva <<"                       |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| IVA a descontar:              |"<< sueldoiva <<"                        |" <<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| IGSS:                         |"<< igss <<"                     |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| IGGS a descontar:             |"<< sueldoigss <<"                      |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| ISR:                          |"<< isr <<"                       |"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| ISR a descontar:              |"<< sueldoisr <<"                        |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Bonificación:                |"<< bonificacion <<"                        |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Sueldo + Bonificación:       |"<< sueldobonificacion <<"                       |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Sueldo SIN bonificacion:      |"<< sueldores <<"                     |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
			cout<<"| Sueldo final CON bonificacion:|"<< sueldofinal <<"                     |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            archivo >> sueldo >> horast >> iva >> sueldoiva >> igss >> sueldoigss >> isr >> sueldoisr >> bonificacion >> sueldobonificacion >> sueldores >> sueldofinal;

		}
		if(total==0)
		{
			cout<<"\n\t No ha insertado informacion, por favor verifica o empieza a ingresar datos";
		}
	}

	cout<<"\t ."<<endl;
	cout<<"\t NOTA: Toma en cuenta que m�s de 160 horas laboradas durante el mes"<<endl;
	cout<<"\t implicaran 50 quetzales a�adidos en el sueldo por cada hora extra"<<endl;
	cout<<"-"<<endl;
	cout<<"\t Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion;

    if(opcion = 1){
        menuprincipalgeneracionnomina();
    }
}
