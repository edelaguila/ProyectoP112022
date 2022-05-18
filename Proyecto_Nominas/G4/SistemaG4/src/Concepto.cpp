#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Concepto.h"
#include "Bitacora.h"

Concepto::Concepto()
{
    //ctor
}

Concepto::~Concepto()
{
    //dtor
}
//menu principal de puestos
void Concepto::menu()
{ Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  SISTEMA DE NOMINA  ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingresar Nonima"<<endl;
	cout<<"\t\t\t 2. Actualizar Nomina"<<endl;
	cout<<"\t\t\t 3. Consultar Nomina"<<endl;
	cout<<"\t\t\t 4. Eliminar Nomina"<<endl;
	cout<<"\t\t\t 5. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        do
        {
            control.nuevaActividadTxt(34);
            control.nuevaActividad(34);
            IngresarNomina();
            cout<<"\n\t\t\t Agrega otra Nomina(Y,N): ";
            cin>>x;
		}while(x=='y'||x=='Y');
		cout <<"Nominas agregados satisfactoriamente"<<endl;
		break;
    case 2:
        control.nuevaActividadTxt(37);
        control.nuevaActividad(37);
        ActualizarNomina();
        cout<<"Nomina actualizado corectamente "<<endl;
        break;
    case 3:
        control.nuevaActividadTxt(36);
        control.nuevaActividad(36);
        ConsultarNomina();
        cout<<"Presiona Enter para salir"<<endl;
        break;
    case 4:
        control.nuevaActividadTxt(39);
        control.nuevaActividad(39);
        EliminarNomina();
        cout<<"Presionar Enter para confirmar"<<endl;
        break;
    case 5:
        break;
        default:
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        }
        getch();
        }while(choice!= 5);

}
//Función para ingresar nomina
void Concepto::IngresarNomina()
{   Bitacora control;
    system("cls");
    fstream file;
    cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de Nomina......................................................"<<endl;
    cout<<"\t\t\tIngresa la clave del empleado :";
    cin>>IdNomina;
    cout<<"\t\t\tIngresa el cargo del empleado :";
    cin>>CrNomina;
    cout<<"\t\t\tIngresa el sueldo del empleado :";
    cin>>SNomina;
    cout<<"\t\t\tIngresa las horas extra del empleado : ";
    cin>>Hextra;
    cout<<"\t\t\tIngresa los dias laborados del empleado :";
    cin>>Dlaborados;
    cout<<"\t\t\tIngresa el numero de cuenta del empleado :";
    cin>>Ncuenta;
file.open("Nomina.dat", ios::out | ios::binary );
file<<std::left<<std::setw(15)<<IdNomina<<std::left<<std::setw(15)<<CrNomina<<std::left<<std::setw(15)<<SNomina<<std::left<<std::setw(15)<<Hextra<<std::left<<std::setw(15)<<Dlaborados<<std::left<<std::setw(15)<<Ncuenta<<"\n";
file.close();
file.open("Nomina.txt", ios::app | ios::out);
file<<std::left<<std::setw(15)<<IdNomina<<std::left<<std::setw(15)<<CrNomina<<std::left<<std::setw(15)<<SNomina<<std::left<<std::setw(15)<<Hextra<<std::left<<std::setw(15)<<Dlaborados<<std::left<<std::setw(15)<<Ncuenta<<"\n";
file.close();
}
void Concepto:: ActualizarNomina()
{   Bitacora control;
system ("cls");
fstream file, file1;
string participant_NoCuenta;
int found= 0;
cout<<"\n.....................................Modificar Nomina......................................................"<<endl;
file.open("Nomina.text", ios::in);
if(!file)
{
    cout<<"\n\t\t\tNo se encontro informacion"<<endl;
    file.close();
}
else
{
    cout<<"\t\t\tIngrese el id de la persona a modificar : ";
    cin>>participant_NoCuenta;
    file1.open("Record.txt", ios:: app | ios::out);
    file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
    while(!file.eof())
    {
        if(participant_NoCuenta!=Ncuenta)
        {
            file1<<std::left<<std::setw(15)<<IdNomina<<std::left<<std::setw(15)<<CrNomina<<std::left<<std::setw(15)<<SNomina<<std::left<<std::setw(15)<<Hextra<<std::left<<std::setw(15)<<Dlaborados<<std::left<<std::setw(15)<<Ncuenta<<"\n";
        }
        else
        {
    cout<<"\t\t\tIngresa la clave del empleado :";
    cin>>IdNomina;
    cout<<"\t\t\tIngresa el cargo del empleado :";
    cin>>CrNomina;
    cout<<"\t\t\tIngresa el sueldo del empleado :";
    cin>>SNomina;
    cout<<"\t\t\tIngresa las horas extra del empleado : ";
    cin>>Hextra;
    cout<<"\t\t\tIngresa los dias laborados del empleado :";
    cin>>Dlaborados;
    cout<<"\t\t\tIngresa el numero de cuenta bancaria del empleado :";
    cin>>Ncuenta;
    file1<<std::left<<std::setw(15)<<IdNomina<<std::left<<std::setw(15)<<CrNomina<<std::left<<std::setw(15)<<SNomina<<std::left<<std::setw(15)<<Hextra<<std::left<<std::setw(15)<<Dlaborados<<std::left<<std::setw(15)<<Ncuenta<<"\n";
    found++;
        }
        file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
    }
    file1.close();
    file.close();
    remove("ParticipantRecord.txt");
    rename("Record.txt","ParticipantRecord.txt");

    }
}
void Concepto::ConsultarNomina()
{   Bitacora control;
    system ("cls");
    fstream file;
    int found=0;
    file.open("Nomina.txt", ios::in);
    if(!file)
    {
        cout<<"\n...............................Datos de la nomina encontrada....................:"<<endl;
        cout<<"\n\t\t\t No hay informacion :";
    }
    else
    {
        string participant_NoCuenta;
        cout<<"\n.......................... ....Datos de la nomina encontrada....................:"<<endl;
        cout<<"\nIngrese Numero de cuenta bancaria de la persona que quiere buscar :" <<endl;
        cin>>participant_NoCuenta;
        file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
        while(!file.eof())
        {
            if(participant_NoCuenta==Ncuenta)
            {
                cout<<"\t\t\t\t\t Identificacion del empleado: "<<IdNomina<<endl;
                cout<<"\t\t\t\t\t Cargo del Empleado: " <<CrNomina<<endl;
                cout<<"\t\t\t\t\t Sueldo de Nomina: " <<SNomina<<endl;
                cout<<"\t\t\t\t\t Horas extras del empleado: " <<Hextra<<endl;
                cout<<"\t\t\t\t\t Dias laborados del empleado: "<<Dlaborados<<endl;
                cout<<"\t\t\t\t\t Numero de cuenta bancaria del empleado: "<<Ncuenta<<endl;

                found++;
            }
            file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t Nomina no encontrada ";
        }
        file.close();
    }
}
void Concepto::EliminarNomina()
{   Bitacora control;
    system ("cls");
    fstream file, file1;
    string participant_NoCuenta;
    int found=0;
    cout<<"\n..................Borrar Nomina................"<<endl;
    file.open("Nomina.txt", ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tNo se encontro informacion";
        file.close();
    }
    else
    {
        cout<<"\nIngrese el numero de cuenta bancaria de la persona que deseas borrar: ";
        cin>>participant_NoCuenta;
        file1.open("Record.txt", ios::app | ios::out);
        file >> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
        while(!file.eof())
        {
            if(participant_NoCuenta!= Ncuenta)
            {
                file1<<std::left<<std::setw(15)<<IdNomina<<std::left<<std::setw(15)<<CrNomina<<std::left<<std::setw(15)<<SNomina<<std::left<<std::setw(15)<<Hextra<<std::left<<std::setw(15)<<Dlaborados<<std::left<<std::setw(15)<<Ncuenta<<"\n";
            }
            else
            {
                found++;
                cout<<"\n\t\t\t Nomina del empleado borrado exitosamente: ";
            }
            file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t Nomina no encontrada";
        }
        file1.close();
        file.close();
        remove("Nomina.txt");
        rename("Record.txt","Nomina.txt");
    }
}
/* void Concepto::ConsultarPlanilla()
{
    Bitacora control;
    system ("cls");
    fstream file;
    int found=0;
    file.open("Nomina.txt", ios::in);
    if(!file)
    {
        cout<<"\n...............................Datos de la nomina encontrada....................:"<<endl;
        cout<<"\n\t\t\t No hay informacion :";
    }
    else
    {
        string participant_NoCuenta;
        cout<<"\n.......................... ....Datos de la nomina encontrada....................:"<<endl;
        cout<<"\nIngrese Numero de cuenta de la persona que quiere buscar :" <<endl;
        cin>>participant_NoCuenta;
        file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
        while(!file.eof())
        {
            if(participant_NoCuenta==Ncuenta)
            {
                cout<<"\t\t\t\t\t Identificacion del empleado: "<<IdNomina<<endl;
                cout<<"\t\t\t\t\t Cargo del Empleado: " <<CrNomina<<endl;
                cout<<"\t\t\t\t\t Sueldo de Nomina: " <<SNomina<<endl;
                cout<<"\t\t\t\t\t Horas extras del empleado: " <<Hextra<<endl;
                cout<<"\t\t\t\t\t Dias laborados del empleado: "<<Dlaborados<<endl;
                cout<<"\t\t\t\t\t Numero de cuenta bancaria del empleado: "<<Ncuenta<<endl;

                found++;
            }
            file>> IdNomina >> CrNomina >> SNomina >> Hextra >> Dlaborados >> Ncuenta;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t Nomina no encontrada ";
        }
        file.close();
    }
}*/
