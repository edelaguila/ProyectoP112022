#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

class persona {
public:
    void registrar();
    void modificar();
    void eliminar();
    void mostrarDatos();
    void menuPrincipal();
    void menuMantenimiento();
    void menuNomina();
    void menuPoliza();
    void menuImpuestos();
    void menuDepartamentos();
private:
    string documentoIdentificacion, nombre, direccion, edad, correo, telefono, estudios, puesto, sueldo, desicion, busquedaDatos;;
};

void persona::registrar(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR--\n" << endl;
    cout << "\n\t¿Quires salir al --MENU MANTENIMIENTO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuMantenimiento();
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
        baseDatos.open("empleados.txt", ios::app | ios::out);
	    baseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
	    baseDatos.close();
	    cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
    }
}

void persona::modificar(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR--" << endl;
    //cout << "\n\t�Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    //if (desicion=="si"){
      //  return menuPrincipal();
    //}
    //else {
        baseDatos.open("empleados.txt",ios::in);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout << "\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
        }
        else {
            cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporal.txt",ios::app|ios::out);
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
                    modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            }
            modBaseDatos.close();
            baseDatos.close();
            remove("empleados.txt");
            rename("temporal.txt","empleados.txt");
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
        }
    //}
}

void persona::eliminar(){
    system("cls");
    int datos=0;
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --ELIMINAR--" << endl;
    //cout << "\n\t�Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    //if (desicion=="si"){
      //  return menuPrincipal();
    //}
    //else {}
        baseDatos.open("empleados.txt",ios::in);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout << "\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
        }
        else {
            cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporal.txt",ios::app|ios::out);
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            while (!baseDatos.eof()){
                if (busquedaDatos!=documentoIdentificacion){
                        //esto me esta dando un error y no sé porqué...
                        //no se puede eliminar un registro guardado
                        //terminar despues
                        cout << "\n\t\tPersona no encontrada...";
                }
                else {
                    datos++;
                    modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< sueldo <<"\n";
                    cout << "\n\t\tLa informacion se a borrado con exito...";
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            }
            if (datos==0){
                cout << "\n\t\t\tNo se encontraron coincidencias, Revise el numero del Documento de Identificacion e intentelo de nuevo...";
                cout << "\n\n\t\tPresione s para intentarlo de nuevo "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
                }
            }
            modBaseDatos.close();
            baseDatos.close();
            remove("empleados.txt");
            rename("temporal.txt","empleados.txt");
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
        }
}

void persona::mostrarDatos(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS--";
    cout << "\n\n\t\t¿Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("empleados.txt",ios::in);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
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
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
            }
            cout << "\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\t\nRegresando al --MENU MOSTRAR DATOS--";
                return mostrarDatos();
            }
            baseDatos.close();
        }
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS"<<endl;
        baseDatos.open("empleados.txt",ios::in);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            baseDatos.close();
            cout << "\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
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
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
            }
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
            if (desicion=="s"){
                cout <<"\t\t\nRegresando al --MENU MANTENIMIENTO--";
                return menuMantenimiento();
            }
        }
        baseDatos.close();
    }
}

void persona::menuPrincipal(){
    system ("cls");
    int menu;
    cout << "\n\t\t\tBienvenido al programa de ==RECURSOS HUMANOS==";
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Mantenimiento\n" << "\t\t[2] Nomina\n" << "\t\t[3] Poliza\n" << "\t\t[4] Impuestos\n" << "\t\t[5] Departamentos\n" << "\t\t[6] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuMantenimiento();
        break;
    case 2:
        menuNomina();
        break;
    case 3:
        menuPoliza();
        break;
    case 4:
        menuImpuestos();
        break;
    case 5:
        menuDepartamentos();
        break;
    case 6:
        cout << "\n\t\t¿Quiere salir del programa? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            return exit (0);
        }
        else {
            return menuPrincipal();
        break;
        }
    }
}

void persona::menuMantenimiento(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar\n" << "\t\t[2] Modificar\n" << "\t\t[3] Eliminar\n" << "\t\t[4] Mostrar Datos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrar();
        break;
    case 2:
        modificar();
        break;
    case 3:
        eliminar();
        break;
    case 4:
        mostrarDatos();
        break;
    case 5:
        cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
        return menuPrincipal();
        break;
        }
}

void persona::menuNomina(){
    cout << "hola";
}

void persona::menuPoliza(){
    cout << "hola";
}

void persona::menuImpuestos(){
    cout << "hola";
}

void persona::menuDepartamentos(){
    cout << "hola";
}

main(){
    persona prueba;
    prueba.menuPrincipal();
    };
