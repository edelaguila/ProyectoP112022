#include <iostream>
using namespace std;

class Persona
{
    public:

        int Edad, Id, Direccion, telefono;
        Persona (int iEdad, int iId, int iDireccion, int itelefono)

        {
            Edad= iEdad ;
            Id = iId;
            Direccion = iDireccion;
            telefono = itelefono;

        }
    void Mostrar()
    {

        cout<<"Mostrar datos de edad: " <<Edad<< endl;
        cout<<"Mostrar datos de Identificacion: " <<Id<< endl;
        cout<<"Mostrar datos de Direccion: " <<Direccion<< endl;
        cout<<"Mostrar datos de numero de telefono: " <<telefono<< endl;
    }

    private:

};

 class Empleado : public Persona
 {
    public:

        Empleado(int iEdad, int iId, int iDireccion, int itelefono): Persona(iEdad,iId,iDireccion,itelefono){


            Edad= iEdad ;
            Id = iId;
            Direccion = iDireccion;
            telefono = itelefono;

    };
};

int main ()
{
    Persona Maria (18,898238,03,82327456);
    Empleado Jose(20,938923,10,92938128);
    Maria.Mostrar();
    Jose.Mostrar ();
    return 0;
}
