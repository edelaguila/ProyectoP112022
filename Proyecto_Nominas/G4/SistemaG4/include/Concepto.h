#ifndef CONCEPTO_H
#define CONCEPTO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class Concepto
{
    public:
        void menu();
            void Ingresar();
            void Actualizar();
            void Consultar();
            void Consultar2();
        Concepto();
        virtual ~Concepto();
           double eIGSS;
        double eISR;
        double eAnticipos;
            double ePension;



    protected:

    private:
         string anio;
   double PIGSS;
   double PISR;
   double PAnticipos;
   double Ppension;
   double resultIGSS;
   double resultISR;
   double resultAnticipo;
   double resultpension;




};

#endif // CONCEPTO_H

