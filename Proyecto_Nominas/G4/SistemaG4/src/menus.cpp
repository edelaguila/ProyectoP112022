#include "menus.h"
#include <iostream>
#include<conio.h>
#include "Persona.h"
#include "Bitacora.h"
#include "Puesto.h"
#include "Usuarios.h"
#include "Concepto.h"
#include "Poliza.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}

menus::menuGeneral()
{
    Puesto gesPuesto;
    Bitacora control;
    menus menuG;
int choice;
	char x;
	do
    {
	system("cls");
	//Funcion que imprime Fecha  y Hora
	control.fechaHora();
	cout<<"\t\t\t    SISTEMA RECURSOS HUMANOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consultas"<<endl;
	cout<<"\t\t\t 2. Contabilidad"<<endl;
	cout<<"\t\t\t 3. Gestion Empleados"<<endl;
	cout<<"\t\t\t 4. Gestion Departamentos"<<endl;
	cout<<"\t\t\t 5. Seguridad"<<endl;
	cout<<"\t\t\t 6. Salir"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        //Se envia a la Bitacora la accion realizada por el usuario
        control.nuevaActividadTxt(1);
        control.nuevaActividad(1);
        menuConsultas();
		break;
	case 2:
        control.nuevaActividadTxt(2);
        control.nuevaActividad(2);
        menuContabilidad();
		break;
	case 3:
	    control.nuevaActividadTxt(3);
        control.nuevaActividad(3);
        menuEmpleados();
		break;
    case 4:
        control.nuevaActividadTxt(4);
        control.nuevaActividad(4);
        gesPuesto.menu();
		break;
    case 5:
        control.nuevaActividadTxt(5);
        control.nuevaActividad(5);
        menuSeguridad();
	case 6:
	    control.nuevaActividadTxt(6);
        control.nuevaActividad(6);
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 6);
    return 0;
}

menus::menuConsultas()
{
    //Creacion de un objeto de la clase Persona
    Persona empleado;
    Bitacora control;
    Puesto dep;
    fstream empleadosEntradaSalida = empleado.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    CONSULTAS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Empleados"<<endl;
	cout<<"\t\t\t 2. Consulta Departamentos"<<endl;
	cout<<"\t\t\t 3. Consulta Nomina"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(7);
        control.nuevaActividad(7);
        empleado.consultarRegistro(empleadosEntradaSalida);
		break;
	case 2:
	    control.nuevaActividadTxt(8);
        control.nuevaActividad(8);
        dep.Imprimir();
		break;
	case 3:
	    control.nuevaActividadTxt(9);
        control.nuevaActividad(9);
        empleado.consultarRegistro2(empleadosEntradaSalida);
		break;
	case 4:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 4);
}

menus::menuContabilidad()
{   Concepto gesConcepto;
    Persona empleado;
    Poliza gesPoliza;
    Bitacora control;
    menus opMenu;
    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    fstream empleadosEntradaSalida2 = empleado.inicioArchivo();
    int choice;
    int opcion;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    CONTABILIDAD    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Nomina"<<endl;
	cout<<"\t\t\t 2. Autorizacion Nomina"<<endl;
	cout<<"\t\t\t 3. Consulta Poliza"<<endl;
	cout<<"\t\t\t 4. Transferencias"<<endl;
	cout<<"\t\t\t 5. Mantenimiento de Deducciones y Percepciones"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(10);
        control.nuevaActividad(10);
        empleado.consultarRegistro2(empleadosEntradaSalida);
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 2:
	    empleado.consultarRegistro2(empleadosEntradaSalida);
	    control.nuevaActividadTxt(12);
        control.nuevaActividad(12);
        //Funcion para imprimir la nomina si esta se autoriza - Maria Jose Veliz 9959-21-5909
        cout << "¿Autoriza la Nomina? SI=1, NO=2" << endl;
        cin >> opcion;
        if (opcion == 1){
            empleado.imprimirRegistro2(empleadosEntradaSalida2);
            cout << "Nomina impresa satisfactoriamente"<<endl;
            cout << "Presiona Enter para aceptar"<<endl;}
        else {
            cout << "Nomina NO autorizada"<<endl;
            break;
        }
        break;
	case 3:
	    control.nuevaActividadTxt(11);
        control.nuevaActividad(11);
        gesPoliza.menu();
		break;
	case 4:
	    control.nuevaActividadTxt(15);
        control.nuevaActividad(15);
        menuTransferencia();
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 5:
	    control.nuevaActividadTxt(13);
        control.nuevaActividad(13);
        gesConcepto.menu();
		break;
    case 6:
	    cout<<"Presiona enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    }getch();
    empleadosEntradaSalida.clear();
    empleadosEntradaSalida2.clear(); // reinicializar indicador de fin de archivo
    }while(choice!= 6);
}

menus::menuEmpleados()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    GESTION EMPLEADOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Empleados"<<endl;
	cout<<"\t\t\t 2. Busqueda de Empleados"<<endl;
	cout<<"\t\t\t 3. Agregar Empleados"<<endl;
	cout<<"\t\t\t 4. Modificar Empleados"<<endl;
	cout<<"\t\t\t 5. Eliminar Empleados"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Empleados"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(16);
        control.nuevaActividad(16);
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(17);
        control.nuevaActividad(17);
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
	    control.nuevaActividadTxt(18);
        control.nuevaActividad(18);
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    control.nuevaActividadTxt(19);
        control.nuevaActividad(19);
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
	    control.nuevaActividadTxt(20);
        control.nuevaActividad(20);
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        control.nuevaActividadTxt(21);
        control.nuevaActividad(21);
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}

menus::menuSeguridad()
{
    Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    SEGURIDAD    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Cambio de Usuario"<<endl;
	cout<<"\t\t\t 2. Cambio de Contraseña"<<endl;
	cout<<"\t\t\t 3. Bitacoras"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(22);
        control.nuevaActividad(22);
        cout<<"Estamos trabajando en el Cambio de Usuario"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 2:
	    control.nuevaActividadTxt(23);
        control.nuevaActividad(23);
        cout<<"Estamos trabajando en la Cambio de Contraseña"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 3:
	    control.nuevaActividadTxt(24);
        control.nuevaActividad(24);
        cout<<"Archivo Bitacora creado satisfactoriamente"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 4:
	    cout <<"Presiona Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}getch();
    }while(choice!= 4);
}

menus::menuTransferencia()
{
    Persona empleado;
    Bitacora control;

    int choice;
    int noCuenta;
    double cantidad;
    double estCuenta = empleado.obtenerBanco();
    double resultado;
    fstream empleadosEntradaSalida = empleado.inicioArchivo();
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    TRANSFERENCIAS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Estado de Cuenta"<<endl;
	cout<<"\t\t\t 2. Pago a Empleado"<<endl;
	cout<<"\t\t\t 3. Deposito"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(39);
        control.nuevaActividad(39);
        cout << "ESTADO DE CUENTA:"<< endl;
        cout << "Q." << estCuenta << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(40);
        control.nuevaActividad(40);
        empleado.consultarRegistro3(empleadosEntradaSalida);
        cout << "Ingrese el numero de cuenta del empleado:" << endl;
        cin >> noCuenta;
        cout << "Ingrese la cantidad en quetzales a ser pagada:"<<endl;
        cout << "Q. ";
        cin >> cantidad;
        //Se realiza la operacion correspondiente y se actualiza el valor para todo el programa
        resultado = estCuenta - cantidad;
        empleado.establecerBanco(resultado);
        estCuenta = empleado.obtenerBanco();
        cout << "Se han pagado Q." << cantidad << "a la cuenta No. " << noCuenta<< endl;
        cout << "El estado de cuenta actual es de Q." << estCuenta <<  endl;
        cout << "Presiona enter para continuar"<<endl;
        getch();
		break;
	case 3:
	    control.nuevaActividadTxt(41);
        control.nuevaActividad(41);
        cout << "El estado de Cuenta actual es de Q." << estCuenta<<endl;
        cout << "Ingrese la cantidad a depositar:"<<endl;
        cout << "Q. ";
        cin >> cantidad;
        //Se realiza la operacion correspondiente y se actualiza el valor para todo el programa
        resultado = estCuenta + cantidad;
        empleado.establecerBanco(resultado);
        estCuenta = empleado.obtenerBanco();
        cout << "Se han depositado Q." << cantidad << endl;
        cout << "El estado de cuenta actual es de Q." << estCuenta <<  endl;
        cout << "Presiona enter para continuar"<<endl;
        getch();
		break;
	case 4:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    getch();
    empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    }while(choice!= 4);
}


