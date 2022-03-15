#include <iostream>
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
