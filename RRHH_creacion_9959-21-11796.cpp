#include <iostream>
using namespace std;

class persona
{
public:
    string mNombre;
    int mEdad, mIdentificacion, mTelefono;
    persona(string nombre, int identificacion, int telefono, int edad)
    {
        mNombre = nombre;
        mIdentificacion = identificacion;
        mTelefono = telefono;
        mEdad = edad;
    }
    void registrar()
    {
        cout <<"estas en el metodo registrar"<<endl;
    }
    int getEdad()
    {
        return mEdad;
    }
    void modificar()
    {
        cout <<"estas en el metodo modificar"<<endl;
    }
    void eliminar()
    {
        cout <<"estas en el metodo eliminar"<<endl;
    }
    void consultar()
    {
        cout <<"estas en el metodo consultar"<<endl;
    }
};
