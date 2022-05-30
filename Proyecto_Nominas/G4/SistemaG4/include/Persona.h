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
   Persona( int = 0, string = "", string = "", int = 0, int = 0, string = "", string = "", string = "", int = 0, int = 0, int = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);

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

   void establecerVhoras( int );
   int obtenerVhoras() const;

   void establecerSueldoEx( double );
   double obtenerSueldoEx() const;

   void establecerComisiones( double );
   double obtenerComisiones() const;

   void establecerTDevengado( double );
   double obtenerTDevengado() const;

   void establecerIGSS( double );
   double obtenerIGSS() const;

   void establecerISR ( double );
   double obtenerISR() const;

   void establecerAnticipos( double );
   double obtenerAnticipos() const;

   void establecerTDescuentos( double );
  double obtenerTDescuentos() const;

   void establecerBincentivo ( double );
   double obtenerBincentivo() const;

   void establecerLiquidoR( double );
   double obtenerLiquidorR() const;

   void establecerPAlimenticia(double);
   double obtenerPAlimenticia() const;

   void establecerRAlimenticio( string );
   string obtenerRAlimenticio() const;

   void establecerresultIGSS (double);
   double obtenerresultIGSS () const;

   double obtenerPerIgss () const;
   double obtenerPerISR () const;
   double obtenerPerAlim () const;
   double obtenerPerAnticipo () const;
   double obtenerBanco () const;
   void establecerBanco( double );



   //Funciones para el tratado de archivos
    void imprimirRegistro( fstream& );
    void imprimirRegistro2( fstream& );
    void imprimirRegistro3(fstream& );
    void actualizarRegistro( fstream& );
    void nuevoRegistro( fstream& );
    void eliminarRegistro( fstream& );
    void mostrarLinea( ostream&, const Persona & );
    void mostrarLinea2( ostream&, const Persona & );
    void mostrarLinea4( ostream&, const Persona & );
    int obtenerId( const char * const );
    void crearArchivoEmpleados();
    void consultarRegistro( fstream& );
    void consultarRegistro2( fstream& );
    void consultarRegistro3( fstream& );
    void busquedaRegistro(fstream&);
    void busquedaRegistro2(fstream&);
    void mostrarLineaPantalla( const Persona &);
    void mostrarLineaPantalla2( const Persona &);
    void mostrarLineaPantalla3( const Persona &);
    fstream inicioArchivo();
    void menuTransferencia();

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
   int Vhoras;
   double SueldoEx;
   double Comisiones;
   double TDevengado;
   double IGSS;
   double ISR;
   double Anticipos;
   double TDescuentos;
   double Bincentivo;
   double LiquidoR;
   double PAlimenticia;
   char RAlimenticio[5] ;
   double estBancario = 100000;




};

#endif

