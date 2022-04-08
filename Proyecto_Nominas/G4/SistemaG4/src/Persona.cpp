#include "Persona.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>



// constructor predeterminado de DatosCliente
Persona::Persona( int valorNumeroId,
   string valorApellido, string valorPrimerNombre,
   string valorDpi, string valorDepartamento, string valorTelefono, string valorEmail,
   string valorDireccion, string valorGenero)
{
   establecerId( valorNumeroId );
   establecerApellido( valorApellido );
   establecerPrimerNombre( valorPrimerNombre );
   establecerTelefono( valorTelefono );
   establecerEmail(valorEmail);
   establecerDepartamento(valorDepartamento);
   establecerDireccion(valorDireccion);
   establecerGenero(valorGenero);
   establecerDpi( valorDpi );

} // fin del constructor de DatosCliente

// obtener el valor del número de cuenta
int Persona::obtenerNumeroId() const
{
   return numeroId;

} // fin de la función obtenerNumeroCuenta

// establecer el valor del número de cuenta
void Persona::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

} // fin de la función establecerNumeroCuenta

// obtener el valor del apellido
string Persona::obtenerApellido() const
{
   return apellido;

} // fin de la función obtenerApellido

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

} // fin de la función establecerApellido

// obtener el valor del primer nombre
string Persona::obtenerPrimerNombre() const
{
   return primerNombre;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerPrimerNombre( string primerNombreString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorPrimerNombre = primerNombreString.data();
   int longitud = strlen( valorPrimerNombre );
   longitud = ( longitud < 10 ? longitud : 9 );
   strncpy( primerNombre, valorPrimerNombre, longitud );

   // anexar el caracter nulo a primerNombre
   primerNombre[ longitud ] = '\0';

} // fin de la función establecerPrimerNombre

string Persona::obtenerTelefono() const
{
   return telefono;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerTelefono( string telefonoString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorTelefono = telefonoString.data();
   int longitud = strlen( valorTelefono );
   longitud = ( longitud < 9 ? longitud : 8 );
   strncpy( telefono, valorTelefono, longitud );

   // anexar el caracter nulo a primerNombre
   telefono[ longitud ] = '\0';

} // fin de la función establecerPrimerNombre

string Persona::obtenerDpi() const
{
   return dpi;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerDpi( string dpiString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorDpi = dpiString.data();
   int longitud = strlen( valorDpi );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( dpi, valorDpi, longitud );

   // anexar el caracter nulo a primerNombre
   dpi[ longitud ] = '\0';

}


string Persona::obtenerDepartamento() const
{
   return departamento;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerDepartamento( string departamentoString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorDepartamento = departamentoString.data();
   int longitud = strlen( valorDepartamento );
   longitud = ( longitud < 22 ? longitud : 21 );
   strncpy( departamento, valorDepartamento, longitud );

   // anexar el caracter nulo a primerNombre
   departamento[ longitud ] = '\0';

}

string Persona::obtenerEmail() const
{
   return email;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerEmail( string emailString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorEmail = emailString.data();
   int longitud = strlen( valorEmail );
   longitud = ( longitud < 32 ? longitud : 31 );
   strncpy( email, valorEmail, longitud );

   // anexar el caracter nulo a primerNombre
   email[ longitud ] = '\0';

}

string Persona::obtenerDireccion() const
{
   return direccion;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerDireccion( string direccionString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorDireccion = direccionString.data();
   int longitud = strlen( valorDireccion );
   longitud = ( longitud < 4 ? longitud : 3 );
   strncpy( direccion, valorDireccion, longitud );

   // anexar el caracter nulo a primerNombre
   direccion[ longitud ] = '\0';

}

string Persona::obtenerGenero() const
{
   return genero;

} // fin de la función obtenerPrimerNombre

// establecer el valor del primer nombre
void Persona::establecerGenero( string generoString )
{
   // copiar a lo más 10 caracteres de la cadena en primerNombre
   const char *valorGenero = generoString.data();
   int longitud = strlen( valorGenero );
   longitud = ( longitud < 3 ? longitud : 2 );
   strncpy( genero, valorGenero, longitud );

   // anexar el caracter nulo a primerNombre
   genero[ longitud ] = '\0';

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

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Dpi" <<setw( 21 )<<"Departamento"<<setw( 31 )<<"Email"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"Genero"<<endl;

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

   } // fin de instrucción while

} // fin de la función imprimirRegistro

// actualizar el saldo en el registro
void Persona::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
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

         cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"DPI"<<setw(21)<<"Departamento"<<setw(31)<<"Email"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"Genero" << endl;
      mostrarLinea( cout, empleado );


      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Departamento"<<endl;
	  cout<<"2. Zona"<<endl;
	  cout<<"3. Telefono"<<endl;
	  cout<<"4. Email"<<endl;
	  cout<<"5. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            {cout << "Ingrese el nuevo departamento: "<<endl;
            string cambioDpto; // cargo o abono
            cin >> cambioDpto;

        // actualizar el saldo del registro
            empleado.establecerDepartamento( cambioDpto );}
            break;
        case 2:
            {cout << "Ingrese la nueva zona: "<<endl;
            string cambioAdress; // cargo o abono
            cin >> cambioAdress;

      // actualizar el saldo del registro
            empleado.establecerDireccion( cambioAdress );}
            break;
        case 3:
            {cout << "Ingrese el nuevo telefono: "<<endl;
            string cambioTel; // cargo o abono
            cin >> setw( 9 )>> cambioTel;

      // actualizar el saldo del registro
            empleado.establecerTelefono( cambioTel );}
            break;
        case 4:
            {cout << "Ingrese el nuevo Email: "<<endl;
            string cambioEmail; // cargo o abono
            cin >> cambioEmail;

        // actualizar el saldo del registro
            empleado.establecerEmail( cambioEmail );}
            break;
        case 5:
            cout << "Modificacion cancelada, empleado sin cambios: "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"DPI"<<setw(21)<<"Departamento"<<setw(31)<<"Email"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"Genero" << endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

} // fin de la función actualizarRegistro

// crear e insertar registro
void Persona::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
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
      char telefono[ 9 ];
      char dpi[ 14 ];
      char departamento[21];
      char email[31];
      char direccion[21];
      char genero[2];

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el apellido : " << endl;
      cin >> setw( 15 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 10 ) >> primerNombre;
      cout << "Escriba el DPI: "<<endl;
      cin >> setw( 14 ) >> dpi;
      cout << "Escriba el departamento: "<<endl;
      cin >> setw(21)>> departamento;
      cout << "Escriba el email: "<<endl;
      cin >> setw(21)>> email;
      cout << "Escriba el telefono: " << endl;
      cin >> setw( 9 ) >> telefono;
      cout << "Escriba la Zona: "<<endl;
      cin >> setw(3)>> direccion;
      cout << "Escriba el genero M/F: "<<endl;
      cin >> setw(2)>> genero;

      // usar valores para llenar los valores de la cuenta
      empleado.establecerApellido( apellido );
      empleado.establecerPrimerNombre( primerNombre );
      empleado.establecerDpi( dpi );
      empleado.establecerTelefono( telefono );
      empleado.establecerId( numeroId );
      empleado.establecerDepartamento(departamento);
      empleado.establecerEmail(email);
      empleado.establecerDireccion(direccion);
      empleado.establecerGenero(genero);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( Persona ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

} // fin de la función nuevoRegistro

// eliminar un registro existente
void Persona::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroId = obtenerId( "Escriba el ID del empleado a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona empleado;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empleado.obtenerNumeroId() != 0 ) {
      Persona empleadoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( Persona ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Persona ) );

      cout << "Empleado con ID #" << numeroId << " eliminado.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "No existe ningun empleado con el ID #" << numeroId<<endl;

} // fin de eliminarRegistro
void Persona::consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"DPI"<<setw(21)<<"Departamento"<<setw(31)<<"Email"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"Genero" << endl;

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
         mostrarLineaPantalla(empleado);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

// mostrar registro individual
void Persona::mostrarLinea( ostream &salida, const Persona &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 14 ) << registro.obtenerDpi().data()
          << setw( 21 ) << registro.obtenerDepartamento().data()
          << setw( 31 ) << registro.obtenerEmail().data()
          << setw( 9 ) << registro.obtenerTelefono().data()
          << setw( 4 ) << registro.obtenerDireccion().data()
          << setw( 2 ) << registro.obtenerGenero().data()<<endl;

} // fin de la función mostrarLinea
void Persona::mostrarLineaPantalla( const Persona &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 14 ) << registro.obtenerDpi().data()
          << setw( 21 ) << registro.obtenerDepartamento().data()
          << setw( 31 ) << registro.obtenerEmail().data()
          << setw( 9 ) << registro.obtenerTelefono().data()
          << setw( 4 ) << registro.obtenerDireccion().data()
          << setw( 2 ) << registro.obtenerGenero().data()<<endl;
} // fin de la función mostrarLineaPantalla

// obtener el valor del número de cuenta del usuario
int Persona::obtenerId( const char * const indicador )
{
   int numeroId;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

} // fin de la función obtenerCuenta
void Persona::crearArchivoEmpleados()
{
    ofstream empleadosSalida( "empleados.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !empleadosSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   Persona empleadoEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 1000; i++ )
      empleadosSalida.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Persona ) );
}

fstream Persona::inicioArchivo(){
    Persona empleado;
        fstream empleadosEntradaSalida( "empleados.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !empleadosEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      empleado.crearArchivoEmpleados();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return empleadosEntradaSalida;
}

void Persona::busquedaRegistro(fstream &actualizarArchivo)
{

       int numeroId = obtenerId( "Escriba el ID del empleado a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
if ( empleado.obtenerNumeroId() != 0 ) {
      // actualizar el saldo del registro
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"DPI"<<setw(21)<<"Departamento"<<setw(31)<<"Email"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"Genero" << endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
