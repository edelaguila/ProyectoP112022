#include <iostream>
#ifndef EMPLEADOS_H
#define EMPLEADOS_H
using namespace std;
//Headers para el CRUD de empleados, Bryan Ariana 9959-21-2832
class empleados
{
    public:
        public:
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
        empleados();
        virtual ~empleados();

    protected:
    private:string id,nombre,telefono;
};

#endif // EMPLEADOS_H
