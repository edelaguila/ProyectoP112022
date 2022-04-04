#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>


class Persona
{
	private:

	public:
        int numeroId, numeroDpi, numeroTelefono;
		string apellido, nombre, email, direccion, genero, departamento;
		void agregar();
		void mostrar();
		void modificar();
		void buscar();
		void eliminar();
        persona();
};


#endif
