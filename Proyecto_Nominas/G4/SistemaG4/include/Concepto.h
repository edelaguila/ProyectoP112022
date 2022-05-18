#define PUESTO_H
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
        string IdNomina,CrNomina,SNomina, Hentrada,Hsalida,Htotal,Hextra,Vhora,CComisiones, CIGG,CISR,CAnticipo,CBono,CLiquido,Dlaborados,Ncuenta;
        void menu ();
            void IngresarNomina();
            void ConsultarNomina();
            void ActualizarNomina();
            void EliminarNomina();
            void ConsultarPlanilla();
        Concepto();
        virtual ~Concepto();

    protected:

    private:
};
