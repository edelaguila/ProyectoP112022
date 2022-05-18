#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

class Persona {

public:

   // constructor clase Persona
   Persona( int = 0, string = "", string = "", int = 0, int = 0, string = "", string = "", int = 0, int = 0);

   // Funciones para obtener el ID
   void establecerId( int );
   int obtenerNumeroId() const;

   // Funciones para acceder a los datos privados
   void establecerApellido( string );
   string obtenerApellido() const;

   void establecerPrimerNombre( string );
   string obtenerPrimerNombre() const;

   void establecerPuesto( string );
   string obtenerPuesto() const;

   void establecerSueldo( int );
   int obtenerSueldo() const;

   void establecerEmail( string );
   string obtenerEmail() const;

   void establecerHoras( int );
   int obtenerHoras() const;

   void establecerDias( int );
   int obtenerDias() const;

   void establecerCuenta( int );
   int obtenerCuenta() const;


   //Funciones para el tratado de archivos
    void imprimirRegistro( fstream& );
    void imprimirRegistro2( fstream& );
    void actualizarRegistro( fstream& );
    void nuevoRegistro( fstream& );
    void eliminarRegistro( fstream& );
    void mostrarLinea( ostream&, const Persona & );
    void mostrarLinea2( ostream&, const Persona & );
    int obtenerId( const char * const );
    void crearArchivoEmpleados();
    void consultarRegistro( fstream& );
    void consultarRegistro2( fstream& );
    void busquedaRegistro(fstream&);
    void mostrarLineaPantalla( const Persona &);
    void mostrarLineaPantalla2( const Persona &);
    fstream inicioArchivo();





private:
   int numeroId;
   char apellido[ 15 ];
   char primerNombre[ 10 ];
   char puesto[ 15 ];
   int  sueldo;
   char email[31];
   int hExtra;
   int noCuenta;
   int dias;

};

#endif

