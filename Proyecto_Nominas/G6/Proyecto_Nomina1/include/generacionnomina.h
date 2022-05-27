#include <iostream>
#ifndef GENERACIONNOMINA_H
#define GENERACIONNOMINA_H

using namespace std;
//headers de la generacion de nomina, Victor Guzman 9959-21-5648
class generacionnomina
{
    public:
        public:
        void menuprincipalgeneracionnomina();
		void generar();
		void vernominas();
        generacionnomina();
        virtual ~generacionnomina();

    protected:
        private:
            double horast, sueldo, iva, sueldofinal, sueldoiva, bonificacion, sueldobonificacion, isr, sueldoisr, igss, sueldoigss, sueldores;
};

#endif // GENERACIONNOMINA_H
