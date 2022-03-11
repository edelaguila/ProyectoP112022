#include <iostream>
using namespace std;

class Persona
{
    public:
        int Edad, Id, Direccion, telefono;
        Persona ( int iEdad, int iId, int iDireccion, int itelefono)

        {
            Edad= iEdad ;
            Id = iId;
            Direccion = iDireccion;
            telefono = itelefono;


        }
    void Mostrar()
    {
        cout<<"Mostrar datos de edad: " <<Edad<< endl;
        cout<<"Mostrar datos de Identificación: " <<Id<< endl;
        cout<<"Mostrar datos de Direccion: " <<Direccion<< endl;
        cout<<"Mostrar datos de numero telefonico: " <<telefono<< endl;
    }

private:


};
class empleado : public Persona
{
public:
    empleado (int iEdad, int iId,int iDireccion,int itelefono) : Persona( iEdad, iId, iDireccion, itelefono)
    {
            Edad= iEdad + 1;
            Id = iId;
            Direccion = iDireccion;
            telefono = itelefono;

    }
private:

};

int main ()
{
    Persona Juanito( 10, 1005, 1997, 4147222);
    empleado Carlos( 10, 1005, 1997, 4147222);
    Juanito.Mostrar();
    Carlos.Mostrar();
    return 0;
}
