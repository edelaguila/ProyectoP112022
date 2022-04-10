#include "Persona.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>



// constructor Persona
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

string Persona::obtenerTelefono() const
{
   return telefono;

}


void Persona::establecerTelefono( string telefonoString )
{

   const char *valorTelefono = telefonoString.data();
   int longitud = strlen( valorTelefono );
   longitud = ( longitud < 9 ? longitud : 8 );
   strncpy( telefono, valorTelefono, longitud );


   telefono[ longitud ] = '\0';

}

string Persona::obtenerDpi() const
{
   return dpi;

}


void Persona::establecerDpi( string dpiString )
{

   const char *valorDpi = dpiString.data();
   int longitud = strlen( valorDpi );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( dpi, valorDpi, longitud );


   dpi[ longitud ] = '\0';

}


string Persona::obtenerDepartamento() const
{
   return departamento;

}

void Persona::establecerDepartamento( string departamentoString )
{

   const char *valorDepartamento = departamentoString.data();
   int longitud = strlen( valorDepartamento );
   longitud = ( longitud < 22 ? longitud : 21 );
   strncpy( departamento, valorDepartamento, longitud );

   departamento[ longitud ] = '\0';

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

string Persona::obtenerDireccion() const
{
   return direccion;

}


void Persona::establecerDireccion( string direccionString )
{

   const char *valorDireccion = direccionString.data();
   int longitud = strlen( valorDireccion );
   longitud = ( longitud < 4 ? longitud : 3 );
   strncpy( direccion, valorDireccion, longitud );


   direccion[ longitud ] = '\0';

}

string Persona::obtenerGenero() const
{
   return genero;

}


void Persona::establecerGenero( string generoString )
{

   const char *valorGenero = generoString.data();
   int longitud = strlen( valorGenero );
   longitud = ( longitud < 3 ? longitud : 2 );
   strncpy( genero, valorGenero, longitud );


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

   }

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
            //cambio de departamento
            {cout << "Ingrese el nuevo departamento: "<<endl;
            string cambioDpto;
            cin >> cambioDpto;
            empleado.establecerDepartamento( cambioDpto );}
            break;
        case 2:
            //cambio de direccion
            {cout << "Ingrese la nueva zona: "<<endl;
            string cambioAdress;
            cin >> cambioAdress;
            empleado.establecerDireccion( cambioAdress );}
            break;
        case 3:
            //cambio de telefono
            {cout << "Ingrese el nuevo telefono: "<<endl;
            string cambioTel;
            cin >> setw( 9 )>> cambioTel;
            empleado.establecerTelefono( cambioTel );}
            break;
        case 4:
            {cout << "Ingrese el nuevo Email: "<<endl;
            string cambioEmail;
            cin >> cambioEmail;
            empleado.establecerEmail( cambioEmail );}
            break;
        case 5:
            cout << "Modificacion cancelada, empleado sin cambios: "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

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
      char telefono[ 9 ];
      char dpi[ 14 ];
      char departamento[21];
      char email[31];
      char direccion[21];
      char genero[2];

      // el usuario introduce los datos
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

      // usar valores para llenar los valores del empleado
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

   }
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}

// eliminar un registro existente
void Persona::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de ID a eliminar
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

   }

   else
      cerr << "No existe ningun empleado con el ID #" << numeroId<<endl;

}
//Consulta de los empleados
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

   }

}

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

}
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
}

// obtener el valor del número ID del usuario
int Persona::obtenerId( const char * const indicador )
{
   int numeroId;

   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

}
void Persona::crearArchivoEmpleados()
{
    ofstream empleadosSalida( "empleados.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !empleadosSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   // crear espacios sin informacion
   Persona empleadoEnBlanco;

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

//Funcion para encontrar empleado especifico
void Persona::busquedaRegistro(fstream &actualizarArchivo)
{
//Se obtiene el ID a buscar
       int numeroId = obtenerId( "Escriba el ID del empleado a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
if ( empleado.obtenerNumeroId() != 0 ) {
      //MOstrar la informacion obtenida
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"DPI"<<setw(21)<<"Departamento"<<setw(31)<<"Email"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"Genero" << endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
