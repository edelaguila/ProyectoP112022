#include <iostream>
using namespace std;

class persona {
public:
    void registrar();
    void modificar();
    void eliminar();
    void mostrarDatos();
private:
    string nombre, documentoIdentificacion, direccion, edad, estudios, correo, telefono, puesto, sueldo;
    string *modnombre, *moddocumentoIdentificacion, *moddireccion, *modedad, *modestudios, *modcorreo, *modtelefono, *modpuesto, *modsueldo;
};

void persona::registrar(){
    cout << "\n\tEntrando al menu --REGISTRAR--" << endl;
    cout << "\n Ingrese el nombre de la persona a registrar: "; cin >> nombre;
    cout << " Ingrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
    cout << " Ingrese la edad de la persona a registrar: "; cin >> edad;
    cout << " Ingrese el correo de la persona a registrar: "; cin >> correo;
    cout << " Ingrese el numero de telefono de la persona a registrar: "; cin >> telefono;
    cout << " Ingrese la direccion de la persona a registrar: "; cin >> direccion;
    cout << " Ingrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
    cout << " --Registro completado--" << endl;
    //return main();
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
    cout << "\n\tMostrando el nombre cambiado: " << nombre << endl;
    //return main();
    break;
case 2:
    cout << "\n\tIngrese el nuevo Documento de Identificacion: "; cin >> nuevodocumentoIdentificacion; cout << endl;
    moddocumentoIdentificacion=&documentoIdentificacion;
    *moddocumentoIdentificacion=nuevodocumentoIdentificacion;
    cout << "\n\tMostrando el nuevo Documento de Identificcacion: " << documentoIdentificacion << endl;
    //return main();
    break;
case 3:
    cout << "\n\tIngrese la nueva direccion: "; cin >> nuevodireccion; cout << endl;
    moddireccion=&direccion;
    *moddireccion=nuevodireccion;
    cout << "\n\tMostrando nueva Direccion: " << direccion << endl;
    //return main();
    break;
case 4:
    cout << "\n\tIngrese la nueva edad: "; cin >> nuevoedad; cout << endl;
    modedad=&edad;
    *modedad=nuevoedad;
    cout << "\n\tMostrando nueva edad: " << edad << endl;
    //return main();
    break;
case 5:
    cout << "\n\tIngrese el nuevo nivel de estudios: "; cin >> nuevoestudios; cout << endl;
    modestudios=&estudios;
    *modestudios=nuevoestudios;
    cout << "\n\tMostrando el nuevo nivel de estudios: " << estudios << endl;
    //return main();
    break;
case 6:
    cout << "\n\tIngrese el nuevo Correo Electronico: "; cin >> nuevocorreo; cout << endl;
    modcorreo=&correo;
    *modcorreo=nuevocorreo;
    cout << "\n\tMostrando nuevo Correo Electronico: " << correo << endl;
    //return main();
    break;
case 7:
    cout << "\n\tIngrese el nuevo Numero de telefono: "; cin >> nuevotelefono; cout << endl;
    modtelefono=&telefono;
    *modtelefono=nuevotelefono;
    cout << "\n\tMostrando nuevo Numero de telefono: " << telefono << endl;
    break;
case 8:
    cout << "\n\tIngrese el nuevo Puesto o cargo: "; cin >> nuevopuesto; cout << endl;
    modpuesto=&puesto;
    *modpuesto=nuevopuesto;
    cout << "\n\tMostrando el nuevo Puesto o cargo: " << puesto << endl;
    break;
case 9:
    cout << "\n\tIngrese el nuevo Salario: "; cin >> nuevosueldo; cout << endl;
    modsueldo=&sueldo;
    *modsueldo=nuevosueldo;
    cout << "\n\tMostrando el nuevo Sueldo: " << sueldo << endl;
    break;
case 0:
    cout << "\n\tSaliendo al menu principal\n";
    //falta terminar
    break;
    }
}

void persona::eliminar(){
    //falta terminar
}

void persona::mostrarDatos(){
    //falta terminar
}

main(){
    persona prueba;
    int menu;
    cout << "\n\tBienvenido al programa de --RECURSOS HUMANOS--" << endl;
    cout << "\tElija el numero del menu al que quiere ingresar" << endl << "\t\t[1] Registrar\n" << "\t\t[2] Modificar\n" << "\t\t[3] Eliminar\n" << "\t\t[4] Mostrar Datos\n" << endl;
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
        }
        return 0;
    };
