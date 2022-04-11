#include <iostream>
#ifndef EMPLEADO_H
#define EMPLEADO_H
using namespace std;

class empleado
{
    public:
        public:
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
        empleado();
        virtual ~empleado();

    protected:
    private:string id,nombre,telefono;
};

#endif // EMPLEADO_H
