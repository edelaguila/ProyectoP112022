#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class persona {
public:
    void registrar();
    void modificar();
    void eliminar();
    void mostrarDatos();
    void menuPrincipal();
private:
    string nombre, documentoIdentificacion, direccion, edad, estudios, correo, telefono, puesto, sueldo, desicion, busquedaDatos;
    string *modnombre, *moddocumentoIdentificacion, *moddireccion, *modedad, *modestudios, *modcorreo, *modtelefono, *modpuesto, *modsueldo;
};

void persona::registrar(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\tEntrando al menu --REGISTRAR--" << endl;
    cout << "\n\t¿Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {
        cout << "\n\t\t\t\t==========IMPORTANTE==========" << "\n\t\t\tNO DEBE COLOCAR ESPACIOS NI CARACTERES ESPECIALES";
        cout << "\n\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
        cout << "\t\tIngrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
        cout << "\t\tIngrese el puesto de la persona a registrar: "; cin >> puesto;
        cout << "\t\tIngrese el sueldo de la persona a registrar: "; cin >> sueldo;
        cout << "\n\t--Registro completado--\n" << endl;
        baseDatos.open("base de datos temporal.txt", ios::app | ios::out);
	    baseDatos << documentoIdentificacion << "\n" << nombre << "\n" << edad << "\n" << correo << "\n" << telefono << "\n" << direccion << "\n" << estudios << "\n" << puesto << "\n" << sueldo <<"\n";
	    baseDatos.close();
        cout << "\tRegresando al --MENU PRINCIPAL--" << endl;
        return menuPrincipal();
    }
}

void persona::modificar(){
    system("cls");
    string nuevonombre, nuevodocumentoIdentificacion, nuevodireccion, nuevoedad, nuevoestudios, nuevocorreo, nuevotelefono, nuevopuesto, nuevosueldo;
    int opcion;
    ifstream baseDatos;
    baseDatos.open("base de datos temporal.txt", ios::in);
    ofstream auxBaseDatos ("auxiliar base datos.txt", ios::out);
    if (baseDatos.is_open()){
        cout << "\n\tIngrese el numero del Documento de Identificacion de la persona que quiere buscar: "; cin >> busquedaDatos;
        cout << "\t\tEntrando al menu --MODIFICAR--" << endl;
        cout << "\n\tIngrese el numero correspondiente a lo que quiere modificar\n" << endl;
        cout << "\t\t[1] Nombre" << endl;
        cout << "\t\t[2] Documento Identificacion" << endl;
        cout << "\t\t[3] Direccion" << endl;
        cout << "\t\t[4] Edad" << endl;
        cout << "\t\t[5] Estudios" << endl;
        cout << "\t\t[6] Correo Electronico" << endl;
        cout << "\t\t[7] Numero de telefono" << endl;
        cout << "\t\t[8] Puesto o cargo" << endl;
        cout << "\t\t[9] Sueldo" << endl;
        cout << "\t\t[0] Salir" << endl;
        cin >> opcion;
        switch (opcion){
        case 1:
            baseDatos>>nombre;
            while (!baseDatos.eof()){
                baseDatos>>documentoIdentificacion;
                baseDatos>>direccion;
                baseDatos>>edad;
                baseDatos>>estudios;
                baseDatos>>correo;
                baseDatos>>telefono;
                baseDatos>>puesto;
                baseDatos>>sueldo;
                if (documentoIdentificacion==busquedaDatos){
                    cout << "\n\tIngrese el nuevo nombre: "; cin >> nuevonombre; cout << endl;
                    auxBaseDatos<<nuevonombre<<"\n"<<documentoIdentificacion<<"\n"<<direccion<<"\n"<<edad<<"\n"<<estudios<<"\n"<<correo<<"\n"<<telefono<<"\n"<<puesto<<"\n"<<sueldo<<"\n";
                }
                else {
                    auxBaseDatos<<nombre<<"\n"<<documentoIdentificacion<<"\n"<<direccion<<"\n"<<edad<<"\n"<<estudios<<"\n"<<correo<<"\n"<<telefono<<"\n"<<puesto<<"\n"<<sueldo<<"\n";
                }
                baseDatos>>nombre;
            }
            baseDatos.close();
            auxBaseDatos.close();
            remove("base datos temporal.txt");
            rename("auxiliar base de datos.txt", "base de datos temporal.txt");
                cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
                if (desicion=="si"){
                    return modificar();
                }
                else return menuPrincipal();
                break;
        case 2:
            cout << "\n\tIngrese el nuevo Documento de Identificacion: "; cin >> nuevodocumentoIdentificacion; cout << endl;
            cout << "\tMostrando el nuevo Documento de Identificcacion: " << documentoIdentificacion << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 3:
            cout << "\n\tIngrese la nueva direccion: "; cin >> nuevodireccion; cout << endl;
            cout << "\tMostrando nueva Direccion: " << direccion << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 4:
            cout << "\n\tIngrese la nueva edad: "; cin >> nuevoedad; cout << endl;
            cout << "\tMostrando nueva edad: " << edad << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 5:
            cout << "\n\tIngrese el nuevo nivel de estudios: "; cin >> nuevoestudios; cout << endl;
            cout << "\tMostrando el nuevo nivel de estudios: " << estudios << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 6:
            cout << "\n\tIngrese el nuevo Correo Electronico: "; cin >> nuevocorreo; cout << endl;
            cout << "\tMostrando nuevo Correo Electronico: " << correo << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 7:
            cout << "\n\tIngrese el nuevo Numero de telefono: "; cin >> nuevotelefono; cout << endl;
            cout << "\tMostrando nuevo Numero de telefono: " << telefono << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 8:
            cout << "\n\tIngrese el nuevo Puesto o cargo: "; cin >> nuevopuesto; cout << endl;
            cout << "\tMostrando el nuevo Puesto o cargo: " << puesto << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 9:
            cout << "\n\tIngrese el nuevo Salario: "; cin >> nuevosueldo; cout << endl;
            cout << "\tMostrando el nuevo Sueldo: " << sueldo << endl;
            cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
            if (desicion=="si"){
                return modificar();
            }
            else return menuPrincipal();
            break;
        case 0:
            cout << "\n\tRegresando al MENU PRINCIPAL\n";
            return menuPrincipal();
            break;
        }
    }else {cout << "Error" << endl;}
remove("base datos temporal.txt");
rename("auxiliar base de datos.txt","base de datos temporal.txt");
}

void persona::eliminar(){
    system("cls");
    //falta terminar
    cout << "\n\t¿Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {}
}

void persona::mostrarDatos(){
    system("cls");
    //falta terminar
    cout << "\n\t¿Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {}
}

void persona::menuPrincipal(){
    system("cls");
    int menu;
    persona prueba;
    cout << "\n\tBienvenido al programa de --RECURSOS HUMANOS--" << endl;
    cout << "\tElija el numero del menu al que quiere ingresar" << endl << "\t\t[1] Registrar\n" << "\t\t[2] Modificar\n" << "\t\t[3] Eliminar\n" << "\t\t[4] Mostrar Datos\n" << "\t\t[5] Salir del programa\n";
    cin >> menu;
    switch (menu){
    case 1:
        prueba.registrar();
        break;
    case 2:
        prueba.modificar();
        break;
    case 3:
        prueba.eliminar();
        break;
    case 4:
        prueba.mostrarDatos();
        break;
    case 5:
        cout << "\tSaliendo del programa" << endl;
        exit(0);
        }
}

 int main(){
    persona prueba;
    prueba.menuPrincipal();
};
