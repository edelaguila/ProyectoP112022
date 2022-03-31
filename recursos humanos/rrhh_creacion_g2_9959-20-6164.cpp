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
private:
    string documentoIdentificacion, nombre, direccion, edad, correo, telefono, estudios, puesto, sueldo, desicion, busquedaDatos;;
};

void persona::registrar(){
    system("cls");
    fstream baseDatos;
    cout << "\n\tEntrando al menu --REGISTRAR--" << endl;
    cout << "\n\t�Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
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
        cout << "\tRegresando al --MENU PRINCIPAL--" << endl;
        return menuPrincipal();
    }
}

void persona::modificar(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\tEntrando al menu --MODIFICAR--" << endl;
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
                cout <<"\t\t\nRegresando al --MENU PRINCIPAL--";
                return menuPrincipal();
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
            cout <<"\t\t\nRegresando al --MENU PRINCIPAL--";
            return menuPrincipal();
        }
    //}
}

void persona::eliminar(){
    //falta terminar
    system("cls");
    cout << "\n\t�Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {}
}

void persona::mostrarDatos(){
    //falta terminar
    system("cls");
    cout << "\n\t�Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {}
}

void persona::menuPrincipal(){
    system("cls");
    int menu;
    cout << "\n\tBienvenido al programa de --RECURSOS HUMANOS--" << endl;
    cout << "\tElija el numero del menu al que quiere ingresar" << endl << "\t\t[1] Registrar\n" << "\t\t[2] Modificar\n" << "\t\t[3] Eliminar\n" << "\t\t[4] Mostrar Datos\n" << "\t\t[5] Salir del programa\n"; cin >> menu;
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
        cout << "\tSaliendo del programa" << endl;
        exit(0);
        }
}

main(){
    persona prueba;
    prueba.menuPrincipal();
    };
