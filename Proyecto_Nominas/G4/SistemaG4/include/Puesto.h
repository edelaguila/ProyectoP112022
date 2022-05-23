#ifndef PUESTO_H
#define PUESTO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class Puesto
{

    public:
        string Dpuesto,Crpuesto,Spuesto,Hentrada,Hsalida;
        void menu ();
            void Ingresar();
            void Actualizar ();
            void Consultar ();
            void Imprimir ();
            void Borrar ();
            void consultarDep();

        Puesto();
        virtual ~Puesto();

    protected:

    private:
};

#endif // PUESTO_H

