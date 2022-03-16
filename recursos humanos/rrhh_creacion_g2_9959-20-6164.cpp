/*#include <iostream>
using namespace std;

class persona {
public:
    persona(string, int, int , int , string , int , string , string);
    string strRegistrar();
    string strModificar();
    string strEliminar();
    string strDatos();

private:
    string strNombre, strCorreoElectronico, strNivelEstudios, strDireccion;
    int intNumeroTelefono, intEdad, intDocumentoIdentificacion, intSalario;

};

persona::persona(string strNombre, int intDocumentoIdentificacion, int intSalario, int intEdad, string strDireccion, int intNumeroTelefono, string strCorreoElectronico, string strNivelEstudios){
    Nombre=strNombre;
    DocumentoIdentificacion=intDocumentoIdentificacion;
    Salario=intSalario;
    Edad=intEdad;
    Direccion=strDireccion;
    NumeroTelefono=intNumeroTelefono;
    CorreoElectronico=strCorreoElectronico;
    NivelEstudios=strNivelEstudios;
}

string persona::strRegistrar(){
cout << "Entrando al menu REGISTRAR" << endl;
cout << "Nombre supervisor: " << Nombre << ", edad: " << Edad << endl;
}

string persona::strModificar(){
cout << "Entrando al menu MODIFICAR" << endl;
string Nombre=nuevoNombre;
cout << "Ingrese el nuevo nombre del supervisor: "; cin << Nombre;
}

string persona::strEliminar(){
cout << "Entrando al menu ELIMINAR" << endl;
cout << "¿Que desea eliminar?" << endl;
//falta terminar
}

string persona::strDatos(){
cout << "Entrando al menu DATOS" << endl;
cout << "Nombre: " << Nombre << " . Su ID es: " << DocumentoIdentificacion << " . Su numero de telefono es: " << NumeroTelefono << " . Su correo electronico es: " << CorreoElectronico << " . Su puesto es: " << Puesto;
}

class empleado:public persona {
public:
    empleado(string, int, int , int , string , int , string , string, string);
    string datosEmpleado();
private:
    int salario;
};

contador::empleado(string strNombre, int intDocumentoIdentificacion, int intSalario, int intEdad, string strDireccion, int intNumeroTelefono, string strCorreoElectronico, string strNivelEstudios, string strPuesto):persona(strNombre,intDocumentoIdentificacion,intSalario,intEdad,strDireccion,intNumeroTelefono,strCorreoElectronico,strNivelEstudios){
Puesto=strPuesto;
}

int main(){
    persona primeraPersona("juan", 55569, 5300, 19, "45654", 45678, "5623@gmail.com", "universitario" );
    cout << primeraPersona.strRegistrar();
    cout << primeraPersona.strModificar("pedro");
    cout << primeraPersona.strEliminar();
    cout << primeraPersona.strDatos();
    return 0;
}
*/
#include <iostream>
using namespace std;

class persona {
public:
    void registrar(){
        string nombre=" ", correo=" ", identificacion=" ";
        int telefono, edad;
        cout << "Entrando al menu --REGISTRAR--" << endl;
        cout << "Ingrese el nombre de la persona a registrar: "; cin >> nombre; cout << endl;
        cout << "Ingrese el numero de documento de identificacion de la persona: "; cin >> identificacion; cout << endl;
        cout << "Ingrese la edad de la persona a registrar: "; cin >> edad; cout << endl;
        cout << "Ingrese el correo de la persona a registrar: "; cin >> correo; cout << endl;
        cout << "Ingrese el numero de telefono de la persona a registrar: "; cin >> telefono; cout << endl;
        cout << "Ingrese la direccion de la persona a registrar: "; cin >> direccion; cout << endl;
        cout << "Ingrese el nivel de estudios de la persona a registrar: "; cin >> estudios; cout << endl;
        cout << "--Registro completado--" << endl;
        //return main();
    }
    void modificar(){
        string nuevoNombre=" ";
        int nuevaEdad, nuevoTelefono,opcion=0;
        cout << "Entrando al menu --MODIFICAR--" << endl;
        cout << "Ingrese el numero correspondiente a lo que quiere modificar" << endl;
        cout << "(1) Nombre\t" << endl;
        cout << "(2) Edad\t" << endl;
        cout << "(3) Telefono" << endl;
        cout << "(4) Salir al menu principal" << endl;
        switch (opcion){
    case (1):
        cout << "Ingrese el nuevo nombre: "; cin >> nuevoNombre; cout << endl;
        //return main();
        break;
    case (2):
        cout << "ingrese la nueva edad: "; cin >> nuevaEdad; cout << endl;
        //return main();
        break;
    case (3):
        cout << "Ingrese el nuevo numero de telefono: "; cin >> nuevoTelefono; cout << endl;
        //return main();
        break;
    case (4):
        cout << "Saliendo..." << endl;
        //return main();
        break;
        }
    }
    void eliminar(){
        cout << "Entrando al menu --ELIMINAR--" << endl;
        int opcion=0;
        cout << "Ingrese el numero correspondiente a lo que quiere modificar" << endl;
        cout << "(1) Nombre\t" << endl;
        cout << "(2) Edad\t" << endl;
        cout << "(3) Telefono" << endl;
        cout << "(4) Salir al menu principal" << endl;
        //falta terminar
        switch (opcion){
    case (1):
        cout << "Ingrese el nuevo nombre: \n"; //cin >> ;
        //return main();
        break;
    case (2):
        cout << "ingrese la nueva edad: \n"; //cin >> ;
        //return main();
        break;
    case (3):
        cout << "Ingrese el nuevo numero de telefono: \n"; //cin >> ;
        //return main();
        break;
    case (4):
        cout << "Saliendo..." << endl;
        //return main();
        break;
        }
    }

    /*void mostrarDatos(){
        cout << "Entrando al menu --MOSTRAR DATOS--" << endl;
        if (nuevoNombre==" "){
            cout << "El nombre es: " << nombre;
        else
        cout << "El nombre es: " << nuevoNombre;
        }
        cout << " . El numero de documento de identificacion es: " << identificacion << " . El correo electronico es: " << correo << " . El numero de telefono es: " << telefono << endl;
        cout << "Saliendo..." << endl;
        return main();*/
    //}
private:
    string direccion=" ", estudios=" ";
};
int main(){
    char p1;
    int menu=0;
    cout << "Bienvenido al programa de recursos humanos" << endl;
    cout << "Elija el numero del menu al que quiere ingresar" << endl << "(1) Registrar\t" << "(2) Modificar\t" << "(3) Eliminar\t" << "(4) Mostrar Datos\t" << endl;
    switch (menu){
    case '1':
        persona p1.registrar();
        break;
    case '2':
        p1.modificar();
        break;
    case '3':
        p1.eliminar();
        break;
    case '4':
        p1.mostrar();
        break;
        }
        return main();
    };
