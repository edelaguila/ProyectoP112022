#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class persona {
public:
    void registrar();
    void modificar();
    void eliminar();
    void mostrarDatos();
    void menuPrincipal();
private:
    string nombre, documentoIdentificacion, direccion, edad, estudios, correo, telefono, puesto, sueldo, desicion;
    string *modnombre, *moddocumentoIdentificacion, *moddireccion, *modedad, *modestudios, *modcorreo, *modtelefono, *modpuesto, *modsueldo;
};

void persona::registrar(){
    //fstream baseDatos;
    cout << "\n\tEntrando al menu --REGISTRAR--" << endl;
    cout << "\n\t¿Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {
        cout << "\n\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
        cout << "\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
        cout << "\t\tIngrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
        cout << "\n\t--Registro completado--\n" << endl;
        //baseDatos.open("base de datos temporal.txt", ios::app | ios::out);
	    //baseDatos <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	    //baseDatos.close();
        cout << "\tRegresando al --MENU PRINCIPAL--" << endl;
        return menuPrincipal();
    }
}

void persona::modificar(){
    string nuevonombre, nuevodocumentoIdentificacion, nuevodireccion, nuevoedad, nuevoestudios, nuevocorreo, nuevotelefono, nuevopuesto, nuevosueldo;
    int opcion;
    cout << "\tEntrando al menu --MODIFICAR--" << endl;
    cout << "\tIngrese el numero correspondiente a lo que quiere modificar\n" << endl;
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
    cout << "\n\tIngrese el nuevo nombre: "; cin >> nuevonombre; cout << endl;
    modnombre=&nombre;
    *modnombre=nuevonombre;
    cout << "\tMostrando el nombre cambiado: " << nombre << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 2:
    cout << "\n\tIngrese el nuevo Documento de Identificacion: "; cin >> nuevodocumentoIdentificacion; cout << endl;
    moddocumentoIdentificacion=&documentoIdentificacion;
    *moddocumentoIdentificacion=nuevodocumentoIdentificacion;
    cout << "\tMostrando el nuevo Documento de Identificcacion: " << documentoIdentificacion << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 3:
    cout << "\n\tIngrese la nueva direccion: "; cin >> nuevodireccion; cout << endl;
    moddireccion=&direccion;
    *moddireccion=nuevodireccion;
    cout << "\tMostrando nueva Direccion: " << direccion << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 4:
    cout << "\n\tIngrese la nueva edad: "; cin >> nuevoedad; cout << endl;
    modedad=&edad;
    *modedad=nuevoedad;
    cout << "\tMostrando nueva edad: " << edad << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 5:
    cout << "\n\tIngrese el nuevo nivel de estudios: "; cin >> nuevoestudios; cout << endl;
    modestudios=&estudios;
    *modestudios=nuevoestudios;
    cout << "\tMostrando el nuevo nivel de estudios: " << estudios << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 6:
    cout << "\n\tIngrese el nuevo Correo Electronico: "; cin >> nuevocorreo; cout << endl;
    modcorreo=&correo;
    *modcorreo=nuevocorreo;
    cout << "\tMostrando nuevo Correo Electronico: " << correo << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 7:
    cout << "\n\tIngrese el nuevo Numero de telefono: "; cin >> nuevotelefono; cout << endl;
    modtelefono=&telefono;
    *modtelefono=nuevotelefono;
    cout << "\tMostrando nuevo Numero de telefono: " << telefono << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 8:
    cout << "\n\tIngrese el nuevo Puesto o cargo: "; cin >> nuevopuesto; cout << endl;
    modpuesto=&puesto;
    *modpuesto=nuevopuesto;
    cout << "\tMostrando el nuevo Puesto o cargo: " << puesto << endl;
    cout << "\n\t¿Quiere modificar otro campo? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return modificar();
    }
    else return menuPrincipal();
    break;
case 9:
    cout << "\n\tIngrese el nuevo Salario: "; cin >> nuevosueldo; cout << endl;
    modsueldo=&sueldo;
    *modsueldo=nuevosueldo;
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
}

void persona::eliminar(){
    //falta terminar
    cout << "\n\t¿Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {}
}

void persona::mostrarDatos(){
    //falta terminar
    cout << "\n\t¿Quires salir al --MENU PRINCIPAL--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPrincipal();
    }
    else {}
}

void persona::menuPrincipal(){
    persona prueba;
    int menu;
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
        //falta opcion de autoguardado antes de salir
        exit(0);
        }
}

main(){
    persona prueba;
    prueba.menuPrincipal();
    };
