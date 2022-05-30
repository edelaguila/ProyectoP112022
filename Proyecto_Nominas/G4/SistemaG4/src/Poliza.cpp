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

//Clase para Poliza de Seguros - Meyglin Rosales 9959-21-4490, Maria Jose Veliz 9959-21-5909
/*void Poliza::menu()
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
        //Se muestran las distintas opciones de seguros con los que cuenta la empresa
        control.nuevaActividadTxt(35);
        control.nuevaActividad(35);
		cout <<"  - Muerte natural o por enfermedad "<<endl;
		cout <<"  - Muerte Accidental "<<endl;
		cout <<"  - Gastos funerarios "<<endl;
		cout <<"  - Enfermedad terminal "<<endl;
		cout <<"  - Invalidez total "<<endl;
		cout <<"  - Indemnizacion escolar "<<endl;
		break;
	case 2:
	    control.nuevaActividadTxt(36);
        control.nuevaActividad(36);
		cout <<" - Atencion medica general "<<endl;
		cout <<" - Examenes de laboratorio "<<endl;
		cout <<" - Hospitalizacion "<<endl;
		cout <<" - Gastos ambulatorios "<<endl;
		cout <<" - Medicamentos por receta medica "<<endl;
		cout <<" - Telemedicina "<<endl;
		cout <<" - Maternidad  "<<endl;
		cout <<" - Servicios de emergencias  "<<endl;
		cout <<" - Servicios de salud mental "<<endl;
		break;
    case 3:
        control.nuevaActividadTxt(37);
        control.nuevaActividad(37);
		cout <<" - Asistencia medica para esposa e hijos"<<endl;
		cout <<" - Asistencia quirurgica para esposa e hijos "<<endl;
		cout <<" - Asistencia farmaceutica para esposa e hijos "<<endl;
		cout <<" - Asistencia hospitalaria para esposa e hijos "<<endl;
		cout <<" - Servicios de laboratorio "<<endl;
		cout <<" - Atencion durante el embarazo y parto  "<<endl;
		cout <<" - Control general en periodo de maternidad   "<<endl;
		cout <<" - Servicios pediatricos   "<<endl;
		break;
    case 4:
        control.nuevaActividadTxt(38);
        control.nuevaActividad(38);
		cout <<" - Consulta cada 6 meses "<<endl;
		cout <<" - Cuidado basico de restauracion dental "<<endl;
		cout <<" - Limpiezas regulares de dientes  "<<endl;
		cout <<" - Tratamientos  "<<endl;
		cout <<" - Radiografias de rutina "<<endl;
		cout <<" - Extracciones   "<<endl;
		cout <<" - Tratamiento de Ortodoncias "<<endl;
	case 5:
		cout <<"Presiona Enter para salir"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}*/
