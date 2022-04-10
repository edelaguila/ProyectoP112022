#ifndef DEPARTAMENTOS_H
#define DEPARTAMENTOS_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class Departamentos
{
    public:
        string Dpuesto,Crpuesto,Spuesto,Hentrada,Hsalida;
        void menu:
            void mostrar;
            void imprimir:

        Departamentos();
        virtual ~Departamentos();

    protected:

    private:
        int numeroId;
   char apellido[ 15 ];
   char primerNombre[ 10 ];
   char telefono[ 9 ];
   char dpi [ 14 ];
   char email[31];
   char direccion[3];
   char departamento[21];
   char genero[2];
};

#endif // DEPARTAMENTOS_H
