#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include<math.h>
#include <conio.h>

class empresa{
public:
    void mostrarLog();//funcion creada por Carlos Gonzalez
    void menuPrincipal();//funcion creada pro Carlos Gonzalez
    void menuMantenimiento();//funcion creada pro Carlos Gonzalez
    void menuEmpleados();//funcion creada pro Carlos Gonzalez
    void registrarEmpleado();//funcion creada pro Carlos Gonzalez
    void modificarEmpleado();//funcion creada pro Carlos Gonzalez
    void eliminarEmpleado();//funcion creada pro Carlos Gonzalez
    void mostrarDatosEmpleados();//funcion creada pro Carlos Gonzalez
    void menuDepartamentos();//funcion creada pro Carlos Gonzalez
    void registrarDepto();//funcion creada pro Carlos Gonzalez
    void modificarDepto();//funcion creada pro Carlos Gonzalez
    void eliminarDepto();//funcion creada pro Carlos Gonzalez
    void mostrarDatosDepto();//funcion creada pro Carlos Gonzalez
private:
    string documentoIdentificacion, nombre, direccion, edad, correo, telefono, estudios, puesto, sueldo, desicion, busquedaDatos, numDepto, nombreDepto, telefonoDepto, direccionDepto;
};

const std::string currentDateTime() {//funcion creada pro Carlos Gonzalez
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
};

void empresa::mostrarLog(){//funcion creada pro Carlos Gonzalez
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro a mostrar bitacora, ";
    log.close();
    string line;
    log.open("bitacora.dat");
    if(log.is_open()){
        system("cls");
        while( getline(log, line)){
            cout << "\n"<<line << endl;
        }
        log.close();
    }
    cout<<"\n\n\t\tGRACIAS POR USAR EL RPOGRAMA DEL GRUPO 2 :)";
    cout << "\n\t\t";system("pause");
}

void empresa::menuPrincipal(){//funcion creada pro Carlos Gonzalez
    system ("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu principal, ";
    log.close();
    int menu;
    cout << "\n\t\t\tBienvenido al programa de ==RECURSOS HUMANOS==";
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Mantenimiento\n" << "\t\t[2] Nomina\n" << "\t\t[3] Poliza\n" << "\t\t[4] Impuestos\n" << "\t\t[6] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuMantenimiento();
        break;
    case 2:
        menuNomina();
        break;
    case 3:
        cout<<"hola";
        break;
    case 4:
        cout<<"hola";
        break;
    case 5:
        mostrarLog();
        break;
    case 6:
        cout << "\n\t\t¿Quiere salir del programa? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            cout<<"\n\n\t\tGRACIAS POR USAR EL RPOGRAMA DEL GRUPO 2 :)";
            cout<<"\n\n\t\t";system("pause");
            return exit (1);
        }
        else {
            return menuPrincipal();
        break;
        }
    }
}

void empresa::menuMantenimiento(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mantenimiento, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Empleados\n" << "\t\t[2] Departamentos\n" << "\t\t[3] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        menuEmpleados();
        break;
    case 2:
        menuDepartamentos();
        break;
    case 3:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system("pause");
        return menuPrincipal();
        break;
    }
}

void empresa::menuEmpleados(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu empleados, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO EMPLEADO--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Empleados\n" << "\t\t[2] Modificar Empleados\n" <<  "\t\t[3] Eliminar Empleado\n" << "\t\t[4] Mostrar Datos Empleados\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarEmpleado();
        break;
    case 2:
        modificarEmpleado();
        break;
    case 3:
        eliminarEmpleado();
        break;
    case 4:
        mostrarDatosEmpleados();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU MANTENIMIENTO--" << endl;
        cout<<"\t";system ("pause");
        return menuMantenimiento();
        break;
    }
}

void empresa::registrarEmpleado(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu registrar empleado, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --REGISTRAR EMPLEADOS--\n" << endl;
    cout << "\n\t¿Quires salir al --MENU EMPLEADO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuEmpleados();
    }
    else {
        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
        cout << "\t\tIngrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
        cout << "\t\tIngrese el puesto de la persona a registrar: "; cin>>puesto;
        cout << "\t\tIngrese el sueldo de la persona a registrar: "; cin>>sueldo;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<< "registro a: "<<documentoIdentificacion<<", ";
        log.close();
        baseDatos.open("empleados.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void empresa::modificarEmpleado(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream baseDatos, modBaseDatos, log;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR EMPLEADOS--" << endl;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu modificar empleados, ";
    log.close();
    baseDatos.open("empleados.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
        cout<<"\n\t";system("pause");
        return menuEmpleados();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalEmpleados.dat",ios::out|ios::binary);
        baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
        while (!baseDatos.eof()){
            if (busquedaDatos!=documentoIdentificacion){
                modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                cout << "\t\tIngrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
                cout << "\t\tIngrese el puesto de la persona a registrar: "; cin>>puesto;
                cout << "\t\tIngrese el sueldo de la persona a registrar: "; cin>>sueldo;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"busco a: "<<busquedaDatos<<" y la modificacion es: "<<documentoIdentificacion<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
            }
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "empleados.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalEmpleados.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void empresa::eliminarEmpleado(){//funcion creada pro Carlos Gonzalez
  system("cls");
	fstream baseDatos,modBaseDatos,log;
	log.open("bitacora.dat",ios::app|ios::out|ios::binary);
  log<<"entro al menu eliminar empleado, ";
  log.close();
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR EMPLEADOS--" << endl;
	baseDatos.open("empleados.dat",ios::in|ios::binary);
	if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
		baseDatos.close();
	}
	else
	{
		cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
		modBaseDatos.open("temporalEmpleados.dat", ios::app | ios::out | ios::binary);
		baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
		while(!baseDatos.eof())
		{
			if(busquedaDatos!=documentoIdentificacion)
			{
				modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<<"elimino a: "<<busquedaDatos<<", ";
        log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...\a";
		}
		baseDatos.close();
		modBaseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "empleados.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalEmpleados.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void empresa::mostrarDatosEmpleados(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mostrar datos empleado, ";
    log.close();
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS--";
    cout << "\n\n\t\t¿Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("empleados.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
            cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            while(!baseDatos.eof()){
                if(busquedaDatos==documentoIdentificacion){
                    cout<<"\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tNivel de estudios: "<< estudios;
                    cout<<"\n\t\tPuesto o cargo: "<< puesto;
                    cout<<"\n\t\tSueldo: "<< sueldo;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU EMPLEADO--";
                    cout<<"\n\t";system("pause");
                    return menuEmpleados();
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                cout<<"\n\t";system("pause");
                return mostrarDatosEmpleados();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS"<<endl;
        baseDatos.open("empleados.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
            cout<<"\n\t";system("pause");
            return menuEmpleados();
        }
        else
        {
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                cout<<"\n\t\tNombre: " << nombre;
                cout<<"\n\t\tEdad: "<< edad;
                cout<<"\n\t\tCorreo Electronico: "<< correo;
                cout<<"\n\t\tTelefono: "<< telefono;
                cout<<"\n\t\tDireccion: "<< direccion;
                cout<<"\n\t\tNivel de estudios: "<< estudios;
                cout<<"\n\t\tPuesto o cargo: "<< puesto;
                cout<<"\n\t\tSueldo: "<< sueldo;
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
            cout<<"\n\t";system("pause");
            return menuEmpleados();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}

void empresa::menuDepartamentos(){//funcion creada pro Carlos Gonzalez
    system("cls");
    int menu;
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu departamentos, ";
    log.close();
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO DEPPARTAMENTOS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Departamento\n" << "\t\t[2] Modificar Departamento\n" << "\t\t[3] Eliminar Departamento\n" << "\t\t[4] Mostrar Datos Departamentos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarDepto();
        break;
    case 2:
        modificarDepto();
        break;
    case 3:
        eliminarDepto();
        break;
    case 4:
        mostrarDatosDepto();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system("pause");
        return menuMantenimiento();
        break;
    }
}

void empresa::registrarDepto(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream baseDatos, log;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR DEPARTAMENTOS--\n" << endl;
    cout << "\n\t¿Quires salir al --MENU DEPARTAMENTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuDepartamentos();
    }
    else {
        cout << "\n\t\tIngrese el numero del Departamento a registrar: "; cin >>numDepto;
        cout << "\t\tIngrese el nombre del Departamento a registrar: "; cin >> nombreDepto;
        cout << "\t\tIngrese el numero telefonico del Departamento a registrar: "; cin >> telefonoDepto;
        cout << "\t\tIngrese la direccion del Departamento a registrar: "; cin >> direccionDepto;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<<"registro el Depto: "<<numDepto<<", ";
        log.close();
        baseDatos.open("departamentos.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto <<"\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
    cout<<"\n\t";system("pause");
    return menuDepartamentos();
}

void empresa::modificarDepto(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream baseDatos, modBaseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu modificar Depto, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --MODIFICAR DEPARTAMENTOS--" << endl;
    baseDatos.open("departamentos.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU DEPARTAMENTOS--";
        cout<<"\n\t";system("pause");
        return menuDepartamentos();
    }
    else {
        cout << "\n\t\t\tIngrese el numero del Departamento que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalDeptos.dat",ios::out|ios::binary);
        baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
        while (!baseDatos.eof()){
            if (busquedaDatos!=documentoIdentificacion){
                modBaseDatos <<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto <<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero del Departamento a registrar: "; cin >>numDepto;
                cout << "\t\tIngrese el nombre del Departamento a registrar: "; cin >> nombreDepto;
                cout << "\t\tIngrese el numero telefonico del Departamento a registrar: "; cin >> telefonoDepto;
                cout << "\t\tIngrese la direccion del Departamento a registrar: "; cin >> direccionDepto;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"modifico el Depto: "<<busquedaDatos<<", ahora es: "<<numDepto<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto <<"\n";
            }
            baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "departamentos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalDeptos.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
    cout<<"\n\t";system("pause");
    return menuDepartamentos();
}

void empresa::eliminarDepto(){//funcion creada pro Carlos Gonzalez
    system("cls");
	fstream file,file1,log;
	log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu eliminar Depto, ";
    log.close();
	int found=0;
	cout<<"\n\t\t\tEntrando al --MENU ELIMINAR DEPARTAMENTO--"<<endl;
	file.open("departamentos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el numero de Departamento que quiere borrar: ";cin>>busquedaDatos;
		file1.open("temporalDeptos.dat",ios::binary|ios::app | ios::out);
		file >> numDepto >> nombreDepto >> telefonoDepto >> direccionDepto;
		while(!file.eof())
		{
			if(busquedaDatos!=numDepto)
			{
				file1<<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto << "\n";
			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"elimino el Depto: "<<busquedaDatos<<", ";
                log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> numDepto >> nombreDepto  >> telefonoDepto >> direccionDepto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t numero de Departamento no encontrado...";
		}
		file1.close();
		file.close();
    if (file.is_open())
        file.close();
    if (file1.is_open())
        file1.close();

    if( remove( "departamentos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalDeptos.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
	cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
    cout<<"\n\t";system("pause");
    return menuDepartamentos();
}

void empresa::mostrarDatosDepto(){//funcion creada pro Carlos Gonzalez
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mostrar datos Depto, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS DEPARTAMENTOS--";
    cout << "\n\n\t\t¿Quiere buscar a un Departamento en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("departamentos.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
            cout << "\n\t\tIngrese el numero del Departamento a buscar: "; cin >> busquedaDatos;
            baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
            while(!baseDatos.eof()){
                if(busquedaDatos==numDepto){
                    cout<<"\n\t\tNumero de Departamento: "<< numDepto;
                    cout<<"\n\t\tNombre del Departamento: " << nombreDepto;
                    cout<<"\n\t\tTelefono del Departamento: "<< telefonoDepto;
                    cout<<"\n\t\tDireccion del Departamento: "<< direccionDepto;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU DEPARTAMENTOS--";
                    cout<<"\n\t";system("pause");
                    return menuDepartamentos();
                }
                baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                cout<<"\n\t";system("pause");
                return mostrarDatosDepto();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS DEPARTAMENTOS"<<endl;
        baseDatos.open("departamentos.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU DEPARTAMENTOS--";
            cout<<"\n\t";system("pause");
            return menuDepartamentos();
        }
        else
        {
            baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\t\tNumero de Departamento: "<< numDepto;
                cout<<"\n\t\tNombre del Departamento: " << nombreDepto;
                cout<<"\n\t\tTelefono del Departamento: "<< telefonoDepto;
                cout<<"\n\t\tDireccion del Departamento: "<< direccionDepto;
                baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
            cout<<"\n\t";system("pause");
            return menuDepartamentos();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}

void empresa::menuNomina()
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro al MENU NOMINA ";
log.close();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |  SISTEMA DE NOMINA EMPLEADOS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Registrar"<<endl;
	cout<<"\t\t\t 2. Mostrar"<<endl;
	cout<<"\t\t\t 3. Modificar"<<endl;
	cout<<"\t\t\t 4. Buscar"<<endl;
	cout<<"\t\t\t 5. Eliminar"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertNomina();
    		cout<<"\n\t\t\t Agrega otro empleado a la nomina (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		displayNomina();
		break;
	case 3:
		modifyNomina();
		break;
	case 4:
		searchNomina();
		break;
	case 5:
		deletNomina ();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void empresa::insertNomina()
{
fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro REGISTRAR EMPLEADOS EN NOMINA ";
    log.close();

	system("cls");
	fstream file;
	cout<<"\n Agregar detalles Empleados a Nomina "<<endl;
	cout<<"\t\t\tIngresa Id de Empleado        : ";
	cin>>numeroid;
	cout<<"\t\t\tIngresa Nombre del Empleado     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Telefono del Empleado   : ";
	cin>>telefono;
	cout<<"\t\t\tIngresa las Horas Trabajadas del Empleado ";
	cin>>horatr;
	cout<<"\t\t\tIngresa la Cantidad que Gana por Hora el Empleado  : ";
	cin>>hora;
	cout<<"\t\t\tIngresa la Cantidad de Horas Extras Trabajadas (si no tiene horas extras ingrese 0) : ";
	cin>>horaextra;

    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"registro a: "<<numeroid<<", ";
    log.close();
	file.open("Empleados.dat", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
	file.close();

}
void empresa::displayNomina()
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro MOSTRAR EMPLEADOS EN NOMINA ";
log.close();

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Empleados -------------------------"<<endl;
	file.open("Empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Empleado: "<<numeroid<<endl;
			cout<<"\t\t\t Nombre Empleado: "<<nombre<<endl;
			cout<<"\t\t\t Telefono Empleado: "<<telefono<<endl;
			cout<<"\t\t\t Horas Trabajadas del Empleado: "<<horatr<<endl;
			cout<<"\t\t\t Cantidad que Gana por Hora: "<<hora<<endl;
			cout<<"\t\t\t Horas extas trabajadas: "<<horaextra<<endl;
			sueldo1 = horatr+horaextra;
			sueldototal= sueldo1*hora;
			bonificacion= sueldototal+250;
			cout<<"\t\t\t Bonificacion Incentiva de Q250.00 "<<endl;
			cout<<"\t\t\t Sueldo total a recibir "<< bonificacion<<endl;
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra >> sueldototal >> bonificacion;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void empresa::modifyNomina()
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro MODIFICAR EMPLEADOS EN NOMINA ";
log.close();

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Empleado-------------------------"<<endl;
	file.open("Empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Empleado que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.dat",ios::app|ios::out|ios::binary);
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id!=numeroid)
			{
			 file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Id Empleado        : ";
	            cin>>numeroid;
                cout<<"\t\t\tIngresa Nombre del Empleado     : ";
	            cin>>nombre;
	            cout<<"\t\t\tIngresa Telefono del Empleado   : ";
	            cin>>telefono;
	            cout<<"\t\t\tIngresa las Horas Trabajadas: ";
	            cin>>horatr;
	            cout<<"\t\t\tIngresa la Cantidad que Gana por Hora  : ";
	            cin>>hora;
	            cout<<"\t\t\tIngresa la Cantidad de Horas Extras Trabajadas (si no tiene horas extras ingrese 0) : ";
                cin>>horaextra;
                sueldo1 = horatr+horaextra;
			    sueldototal= sueldo1*hora;
			    bonificacion= sueldototal+250;
			    cout<<"\t\t\t Bonificacion Incentiva de Q250.00 "<<endl;
			    cout<<"\t\t\t Sueldo total a recibir "<< bonificacion<<endl;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"registro a: "<<numeroid<<", ";
                log.close();
				file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << std::left<<std::setw(15)<< sueldototal << std::left<<std::setw(15)<< bonificacion <<"\n";
				found++;
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra >> sueldototal >> bonificacion;

		}

		file1.close();
		file.close();
		remove("Empleados.dat");
		rename("Record.dat","Empleados.dat");
	}
}
void empresa::searchNomina()
{
    fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro BUSCAR EMPLEADOS EN NOMINA ";
log.close();
	system("cls");
	fstream file;
	int found=0;
	file.open("Empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Empleado buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Empleado buscada------------------------"<<endl;
		cout<<"\nIngrese Id del Empleado que quiere buscar: ";
		cin>>participant_id;
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id==numeroid)
			{
				cout<<"\n\n\t\t\t Id del Empleado: "<<numeroid<<endl;
			    cout<<"\t\t\t Nombre del Empleado: "<<nombre<<endl;
			    cout<<"\t\t\t Telefono del Empleado: "<<telefono<<endl;
			    cout<<"\t\t\t Horas Trabajadas del Empleado: "<<horatr<<endl;
			    cout<<"\t\t\t Cantidad que Gana por Hora: "<<hora<<endl;
			    cout<<"\t\t\t Horas extas trabajadas: "<<horaextra<<endl;
				found++;
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}
void empresa::deletNomina()
{
    fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro ELIMINAR EMPLEADOS EN NOMINA ";
log.close();

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles de Empleado a Borrar-------------------------"<<endl;
	file.open("Empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Empleado que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.dat",ios::app|ios::out|ios::binary);
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id!=numeroid)
			{
				file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora <<std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
               log.open("bitacora.dat",ios::app|ios::out|ios::binary);
               log<<"registro a: "<<numeroid<<", ";
               log.close();

				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}

		file1.close();
		file.close();
		remove("Empleados.dat");
		rename("Record.dad","Empleados.dad");
	}

 int main(){

     //bitacora, log in, creado por Carlos Gonzalez

    system ("cls");
    int contador=0;
    bool ingresa=false;
    string usuario, config0, config1, config2, contra, numU;
    fstream config, log;
    int datos=0;
    config.open("seguridad.dat",ios::in|ios::binary);
    if(!config){
        cout<<"\n\n\t\tError, no se encuentra un archivo escencial del programa...\a\n\n";
        exit(1);
    }
    else{
        cout << "\n\t\t\tBIENVENIDO AL PROGRAMA DE RECURSOS HUMANOS DEL GRUPO 2\n" << endl;
        cout << "\n\t\tIngrese el numero de usuario asignado: "; cin >> numU;
        config>>config0>>config1>>config2;
        while(!config.eof()){
            if(numU==config0){
                do{
                    cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
                    cout << "\n\t\tIngrese su contrasena: ";
                    char caracter;
                    caracter = getch();
                    contra="";
                    while (caracter != 13) //ASCII TECLA ENTER
                    {
                        if (caracter != 8) //ASCII TECLA RETROCESO
                        {
                            contra.push_back(caracter);
                            cout<<"*";
                        } else
                        {
                            if (contra.length() > 0)
                            {
                                cout<<"\b \b"; //Efecto caracter borrado en pantalla
                                contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                            }
                        }
                        caracter = getch();
                    }
                    //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña
                    if (usuario==config1 && contra==config2){
                        system("cls");
                        ingresa=true;
                    } else {
                        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                        log<<"\n\n\nUsuario: " << usuario <<", El usuario y/o contrasena son incorrectos, ";
                        log.close();
                        cout<<"\n\t\tEl usuario y/o contrasena son incorrectos\a"<<endl;
                        cin.get();
                        contador++;
                        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                        log<<"intentos: "<<contador<<", ";
                        log.close();
                    }
                } while (ingresa==false && contador<3);
                if (ingresa==false){
                    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                    log<<"\n\n\nUsuario: " << usuario <<", Lo siento, no puede ingresar al sistema, agoto intentos. ";
                    log.close();
                    cout<<"\n\t\tLo siento, no puede ingresar al sistema, agoto intentos"<<endl;
                    cin.get();
                } else {
                    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                    log<<"\n\n\nUsuario: " << usuario <<"Fecha AAMMDD / Hora, minutos, segundos: " <<currentDateTime() <<", ";
                    log.close();
                    fstream bienvenida;
                    string line, desicion;
                    bienvenida.open("bienvenidos.txt");
                    if(bienvenida.is_open()){
                        cout << "\n";
                        while( getline(bienvenida, line)){
                            cout << "\t"<<line << endl;
                        }
                        cout<<"\n\t\t";system("pause");
                        bienvenida.close();
                    }
                    bienvenida.close();
                    empresa empleado;
                    empleado.menuPrincipal();
                    cin.get();
                }
                return ingresa;
                datos++;
                config.close();
            }
            config>>config0>>config1>>config2;
            config.close();
        }
        config.close();
    }
    config.close();
};
