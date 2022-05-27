#include <iostream>
#ifndef PUESTOS_H
#define PUESTOS_H
using namespace std;
//Headers de CRUD de puestos, Victor Jerez 9959-21-2081
class Puestos
{
    public:
        Puestos();
        virtual ~Puestos();
        void menu();
        void insertar();
        void desplegar();
        void buscar();
        void modificar();
        void borrar();

    protected:
        private:
};

#endif
