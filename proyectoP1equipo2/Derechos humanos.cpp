#include <iostream>
using namespace std;
class Persona{
private:
    string Nombre;
    string Correo;
    int Id;
    int edad;
    int nit;
    int telefono;
public: Persona(string,string,int,int,int,int);
    void obtener_edad();
    void registrar();
    void modificar();
    void eliminar();
    void consultar();
};
Persona::Persona(string iNombre,string iCorreo, int iId,  int iEdad, int iNit, int iTelefono){
    Nombre = iNombre;
    Correo = iCorreo;
    Id = iId;
    edad = iEdad;
    nit = iNit;
    telefono = iTelefono;

}
class Empleado : public Persona{
public :
    Empleado(string,string,int,int,int,int);
    void mostrarEmpleado();

};


void Persona::obtener_edad(){
cout <<"Mi nombre es" <<Nombre<<"mi edad es de"<<edad<< endl;
}
void Persona::registrar(){
cout <<"Mi nombre es" <<Nombre<<"este es el metodo de registrar"<< endl;
}
void Persona::modificar(){
cout <<"Mi nombre es" <<Nombre<<"este es el metodo de modificar"<< endl;
}
void Persona::eliminar(){
cout <<"Mi nombre es" <<Nombre<<"este es el metodo de eliminar"<< endl;
}
void Persona::consultar(){
cout <<"Mi nombre es" <<Nombre<<"este es el metodo de consultar"<< endl;
}



int main()
{
    Persona p1 = Persona("DiegoCulajay","diegoofranciss@gmail.com", 312091910101, 18 , 11124294,22405515);
    p1.obtener_edad();
    p1.registrar();
    p1.modificar();
    p1.eliminar();
    p1.consultar();


return 0;


}
