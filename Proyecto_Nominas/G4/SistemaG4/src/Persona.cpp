#include "Persona.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include<string>


// constructor Persona
Persona::Persona( int valorNumeroId,
   string valorApellido, string valorPrimerNombre,
   int valorSueldo, int valorCuenta, string valorPuesto, string valorEmail, string valorRAlimenticio,
   int valorHoras, int valorDias, int ValorVHoras, double ValorSueldoEx, double ValorComisiones, double ValorDevengado, double ValorIGSS, double ValorISR,
  double ValorAnticipos, double ValorTDescuentos, double ValorBincentivo, double ValorLiquido, double ValorAlimenticio)
{
   establecerId( valorNumeroId );
   establecerApellido( valorApellido );
   establecerPrimerNombre( valorPrimerNombre );
   establecerPuesto( valorPuesto );
   establecerEmail(valorEmail);
   establecerCuenta(valorCuenta);
   establecerHoras(valorHoras);
   establecerDias(valorDias);
   establecerSueldo( valorSueldo );
   establecerVhoras( ValorVHoras );
   establecerSueldoEx(ValorSueldoEx);
   establecerComisiones( ValorComisiones );
   establecerTDevengado( ValorDevengado );
   establecerIGSS( ValorIGSS );
   establecerISR( ValorISR );
   establecerAnticipos( ValorAnticipos);
   establecerTDescuentos( ValorTDescuentos);
   establecerBincentivo( ValorBincentivo );
   establecerLiquidoR(ValorLiquido);
   establecerPAlimenticia(ValorAlimenticio);
   establecerRAlimenticio(valorRAlimenticio);
}

// obtener el valor del ID
int Persona::obtenerNumeroId() const
{
   return numeroId;

}

// establecer el valor del ID
void Persona::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

}

// obtener el valor del apellido
string Persona::obtenerApellido() const
{
   return apellido;

}

// establecer el valor del apellido
void Persona::establecerApellido( string apellidoString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorApellido = apellidoString.data();
   int longitud = strlen( valorApellido );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( apellido, valorApellido, longitud );

   // anexar caracter nulo al apellido
   apellido[ longitud ] = '\0';

}

// obtener el valor del primer nombre
string Persona::obtenerPrimerNombre() const
{
   return primerNombre;

}

// establecer el valor del primer nombre
void Persona::establecerPrimerNombre( string primerNombreString )
{

   const char *valorPrimerNombre = primerNombreString.data();
   int longitud = strlen( valorPrimerNombre );
   longitud = ( longitud < 10 ? longitud : 9 );
   strncpy( primerNombre, valorPrimerNombre, longitud );


   primerNombre[ longitud ] = '\0';

}

string Persona::obtenerPuesto() const
{
   return puesto;

}


void Persona::establecerPuesto( string puestoString )
{

   const char *valorPuesto = puestoString.data();
   int longitud = strlen( valorPuesto );
   longitud = ( longitud < 15 ? longitud : 15 );
   strncpy( puesto, valorPuesto, longitud );


   puesto[ longitud ] = '\0';

}

int Persona::obtenerSueldo() const
{
   return sueldo;

}


void Persona::establecerSueldo( int valorSueldo )
{
   sueldo = valorSueldo;

}


int Persona::obtenerCuenta() const
{
   return noCuenta;

}

void Persona::establecerCuenta( int valorCuenta )
{
   noCuenta = valorCuenta;

}

string Persona::obtenerEmail() const
{
   return email;

}


void Persona::establecerEmail( string emailString )
{

   const char *valorEmail = emailString.data();
   int longitud = strlen( valorEmail );
   longitud = ( longitud < 32 ? longitud : 31 );
   strncpy( email, valorEmail, longitud );


   email[ longitud ] = '\0';

}

int Persona::obtenerHoras() const
{
   return hExtra;

}


void Persona::establecerHoras( int valorHoras )
{
   hExtra = valorHoras;

}

int Persona::obtenerDias() const
{
   return dias;

}


void Persona::establecerDias( int valorDias)
{
   dias = valorDias;

}

int Persona::obtenerVhoras() const
{
 return Vhoras;
}

void Persona::establecerVhoras( int ValorVHoras)
{
    Vhoras = ValorVHoras;
}

double Persona::obtenerSueldoEx() const
{
 return SueldoEx;
}

void Persona::establecerSueldoEx( double ValorSueldoEx)
{
    SueldoEx = ValorSueldoEx;
}

double Persona::obtenerComisiones() const
{
    return Comisiones;
}

void Persona::establecerComisiones( double ValorComisiones )
{
    Comisiones = ValorComisiones;
}

double Persona::obtenerTDevengado() const
{
    return TDevengado;
}

void Persona::establecerTDevengado( double ValorDevengado )
{
    TDevengado = ValorDevengado;
}

double Persona::obtenerIGSS() const
{
    return IGSS;
}

void Persona::establecerIGSS( double ValorIGSS )
{
    IGSS = ValorIGSS;
}

double Persona::obtenerISR() const
{
    return ISR;
}

void Persona::establecerISR( double ValorISR )
{
    ISR = ValorISR;
}

double Persona::obtenerAnticipos() const
{
    return Anticipos;
}

void Persona::establecerAnticipos( double ValorAnticipos)
{
    Anticipos = ValorAnticipos;
}

double Persona::obtenerTDescuentos() const
{
    return TDescuentos;
}

void Persona::establecerTDescuentos( double ValorTDescuentos )
{
     TDescuentos = ValorTDescuentos;
}

double Persona::obtenerBincentivo() const
{
    return Bincentivo;
}

void Persona::establecerBincentivo( double ValorBicentivo )
{
    Bincentivo = ValorBicentivo;
}

double Persona::obtenerLiquidorR() const
{
    return LiquidoR ;
}

void Persona::establecerLiquidoR( double ValorLiquido )
{
    LiquidoR = ValorLiquido;
}
double Persona::obtenerPAlimenticia () const
{
    return PAlimenticia;
}

void Persona::establecerPAlimenticia ( double ValorAlimenticio)
{
    PAlimenticia = ValorAlimenticio;

}

string Persona::obtenerRAlimenticio() const
{
   return RAlimenticio;

}

// establecer el valor del primer nombre
void Persona::establecerRAlimenticio( string RAlimenticioString )
{

   const char *valorRAlimenticio = RAlimenticioString.data();
   int longitud = strlen( valorRAlimenticio );
   longitud = ( longitud < 10 ? longitud : 9 );
   strncpy( RAlimenticio, valorRAlimenticio, longitud );


   RAlimenticio[ longitud ] = '\0';

}



// crear archivo de texto con formato para imprimirlo
void Persona::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   }

   archivoImprimirSalida<< left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Sueldo(Q)"<<setw(16)<<"No. Cuenta"<<setw(27)<<"Email"
       <<setw( 12 )<< "Puesto"<<setw(12)<<"Horas Extra"<<setw(24)<<"Dias Laburados del Mes" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLinea( archivoImprimirSalida, empleado );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }


}

void Persona::imprimirRegistro2( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "planilla.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   }
   archivoImprimirSalida<< left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Sueldo(Q)"<<setw(12)<<"Horas Extra"<<setw(15)<<"Dias Laborados"<<setw(11)<<"Comisiones"<<setw(12)<<"Valor Horas"
       <<setw(26)<<"Sueldo Extraordinario (Q)"<<setw(16)<<"Total Devengado"<<setw(9)<<"IGSS"
        <<setw(9)<<"ISR"<<setw(10)<<"Anticipos"<<setw(17)<<"Total Descuento"<<setw(16)<<"Bono Incentivo"<<setw(17)<<"Liquido Recibir"<<setw(8)<<"Pension A."<< endl;
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLinea2( archivoImprimirSalida, empleado );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }


}

// actualizar el saldo en el registro
void Persona::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de ID a actualizar
   int numeroId = obtenerId( "Escriba el ID del empleado a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
    int choice;
   // actualizar el registro
   if ( empleado.obtenerNumeroId() != 0 ) {

cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Sueldo(Q)"<<setw(16)<<"No. Cuenta"<<setw(27)<<"Email"
       <<setw( 12 )<< "Puesto"<<setw(12)<<"Horas Extra"<<setw(24)<<"Dias Laburados del Mes" << endl;
      mostrarLinea( cout, empleado );

      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. No. Cuenta"<<endl;
	  cout<<"2. Zona"<<endl;
	  cout<<"3. Puesto"<<endl;
	  cout<<"4. Email"<<endl;
	  cout<<"5. Sueldo"<<endl;
	  cout<<"6. Horas Extra"<<endl;
	  cout<<"7. Dias Laburados del Mes"<<endl;
	  cout<<"8. Comisiones"<<endl;
	  cout<<"9. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            //cambio de departamento
            {cout << "Ingrese el nuevo no. de cuenta: "<<endl;
            int cambioCuenta;
            cin >> cambioCuenta;
            empleado.establecerCuenta( cambioCuenta );}
            break;
        case 2:
            //cambio de direccion
            {cout << "Ingrese las horas extra "<<endl;
            int cambioHoras;
            cin >> cambioHoras;
            empleado.establecerHoras( cambioHoras );}
            break;
        case 3:
            //cambio de telefono
            {cout << "Ingrese el nuevo puesto: "<<endl;
            string cambioPuesto;
            cin >> setw( 15 )>> cambioPuesto;
            empleado.establecerPuesto( cambioPuesto );}
            break;
        case 4:
            {cout << "Ingrese el nuevo Email: "<<endl;
            string cambioEmail;
            cin >> cambioEmail;
            empleado.establecerEmail( cambioEmail );}
            break;
        case 5:
            {cout << "Ingrese el nuevo sueldo: "<<endl;
            int cambioSueldo;
            cin >> cambioSueldo;
            empleado.establecerSueldo( cambioSueldo );}
            break;
        case 6:
            {cout << "Ingrese las horas extra: "<<endl;
            int cambioHoras;
            cin >> cambioHoras;
            empleado.establecerHoras( cambioHoras );}
            break;
        case 7:
            {cout << "Ingrese los Dias Laburados del Mes "<<endl;
            int cambioDias;
            cin >> cambioDias;
            empleado.establecerDias( cambioDias );}
            break;
        case 8:
            {cout<< "Ingrese las comisiones del empleado" <<endl;
            int cambioComisiones;
            cin>> cambioComisiones;
            empleado.establecerComisiones ( cambioComisiones );}
            break;
        case 9:
            cout << "Modificacion cancelada, empleado sin cambios: "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Sueldo(Q)"<<setw(16)<<"No. Cuenta"<<setw(27)<<"Email"
       <<setw( 12 )<< "Puesto"<<setw(12)<<"Horas Extra"<<setw(24)<<"Dias Laburados del Mes" << endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}

// crear e insertar registro
void Persona::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de ID a crear
   int numeroId = obtenerId( "Ingrese el ID del nuevo empleado: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona empleado;
   insertarEnArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // crear el registro, si éste no existe ya
   if ( empleado.obtenerNumeroId() == 0 ) {

      char apellido[ 15 ];
      char primerNombre[ 10 ];
      char puesto[ 15 ];
      int sueldo;
      int noCuenta;
      char email[31];
      int hExtra;
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
      int RAlimenticio;

      // el usuario introduce los datos
      cout << "Escriba el apellido : " << endl;
      cin >> setw( 15 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 10 ) >> primerNombre;
      cout<<"¿Tiene vigencia Pensión Alimenticia: 1= Si / 2 = No"<<endl;
      cin>>setw(8)>>RAlimenticio;
      cout << "Escriba el sueldo: "<<endl;
      cin >> setw( 14 ) >> sueldo;
      cout << "Escriba el no. de cuenta: "<<endl;
      cin >> setw(21)>> noCuenta;
      cout << "Escriba el email: "<<endl;
      cin >> setw(21)>> email;
      cout << "Escriba el puesto: " << endl;
      cin >> setw( 15 ) >> puesto;
      cout << "Escriba las horas extra "<<endl;
      cin >> setw(8)>> hExtra;
      cout << "Escriba los Dias Laborados del Mes"<<endl;
      cin >> setw(15)>> dias;
      cout << "Escriba las Comsiones ganadas" <<endl;
      cin>> setw(6)>>Comisiones;
      Bincentivo = 250;
      Vhoras= 25;
      switch(RAlimenticio){
     case 1:
     if (sueldo >= 4000 ){
        SueldoEx = (hExtra*Vhoras);
      TDevengado = (SueldoEx+Comisiones+sueldo);
      IGSS = (TDevengado*0.0483);
      ISR = (((TDevengado*12)-(48000+(IGSS*12)))*0.05)/12;
      Anticipos = (TDevengado*0.4);
      TDescuentos = (IGSS+ISR+Anticipos);
      LiquidoR = (sueldo-TDescuentos+Bincentivo);
      PAlimenticia = ((Anticipos+LiquidoR)*0.4512);
      }
      else{
    ISR = 0;
    SueldoEx = (hExtra*Vhoras);
      TDevengado = (SueldoEx+Comisiones+sueldo);
      IGSS = (TDevengado*0.0483);
      Anticipos = (TDevengado*0.4);
      TDescuentos = (IGSS+ISR+Anticipos);
      LiquidoR = (sueldo-TDescuentos+Bincentivo);
    PAlimenticia = ((Anticipos+LiquidoR)*0.4512);
      }
      case 2:
   if (sueldo >= 4000 ){
        SueldoEx = (hExtra*Vhoras);
      TDevengado = (SueldoEx+Comisiones+sueldo);
      IGSS = (TDevengado*0.0483);
      ISR = (((TDevengado*12)-(48000+(IGSS*12)))*0.05)/12;
      Anticipos = (TDevengado*0.4);
      TDescuentos = (IGSS+ISR+Anticipos);
      LiquidoR = (sueldo-TDescuentos+Bincentivo);
      }
      else{
    ISR = 0;
    SueldoEx = (hExtra*Vhoras);
      TDevengado = (SueldoEx+Comisiones+sueldo);
      IGSS = (TDevengado*0.0483);
      Anticipos = (TDevengado*0.4);
      TDescuentos = (IGSS+ISR+Anticipos);
      LiquidoR = (sueldo-TDescuentos+Bincentivo);
      }
  	}


      // usar valores para llenar los valores del empleado
      empleado.establecerApellido( apellido );
      empleado.establecerPrimerNombre( primerNombre );
      empleado.establecerPuesto( puesto );
      empleado.establecerSueldo( sueldo );
      empleado.establecerId( numeroId );
      empleado.establecerCuenta(noCuenta);
      empleado.establecerEmail(email);
      empleado.establecerHoras(hExtra);
      empleado.establecerDias(dias);
      empleado.establecerVhoras(Vhoras);
      empleado.establecerSueldoEx(SueldoEx);
      empleado.establecerComisiones(Comisiones);
      empleado.establecerTDevengado(TDevengado);
      empleado.establecerIGSS(IGSS);
      empleado.establecerISR(ISR);
      empleado.establecerAnticipos(Anticipos);
      empleado.establecerTDescuentos(TDescuentos);
      empleado.establecerBincentivo(Bincentivo);
      empleado.establecerLiquidoR(LiquidoR);
      empleado.establecerPAlimenticia(PAlimenticia);
      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( Persona ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   }
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}

