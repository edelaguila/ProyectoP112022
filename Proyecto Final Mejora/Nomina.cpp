#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;
class persona
{
	private:
		string numeroid,nombre,telefono;
		int sueldo,sueldototal,bonificacion,hora,horaextra,totalhoras,horatr;
	public:
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
};
void persona::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PERSONAS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Registrar"<<endl;
	cout<<"\t\t\t 2. Mostrar"<<endl;
	cout<<"\t\t\t 3. Modificar"<<endl;
	cout<<"\t\t\t 4. Buscar"<<endl;
	cout<<"\t\t\t 5. Eliminar"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void persona::insert()
{
	system("cls");
	fstream file;
	cout<<"\n Agregar detalles Persona "<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";
	cin>>numeroid;
	cout<<"\t\t\tIngresa Nombre Persona     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Telefono Persona   : ";
	cin>>telefono;
	cout<<"\t\t\tIngresa las Horas Trabajadas: ";
	cin>>horatr;
	cout<<"\t\t\tIngresa la Cantidad que Gana por Hora  : ";
	cin>>hora;
	cout<<"\t\t\tIngresa la Cantidad de Horas Extras Trabajadas (si no tiene horas extras ingrese 0) : ";
	cin>>horaextra;
	file.open("Empleados.dad", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
	file.close();
}
void persona::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("Empleados.dad",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Persona: "<<numeroid<<endl;
			cout<<"\t\t\t Nombre Persona: "<<nombre<<endl;
			cout<<"\t\t\t Telefono Persona: "<<telefono<<endl;
			cout<<"\t\t\t Horas Trabajadas de la Persona: "<<horatr<<endl;
			cout<<"\t\t\t Cantidad que Gana por Hora: "<<hora<<endl;
			cout<<"\t\t\t Horas extas trabajadas: "<<horaextra<<endl;
			sueldo = horatr+horaextra;
			sueldototal= sueldo*hora;
			bonificacion= sueldototal+250;
			cout<<"\t\t\t Bonificacion Incentiva de Q250.00 "<<endl;
			cout<<"\t\t\t Sueldo total a recibir "<< bonificacion<<endl;
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra >> sueldototal >> bonificacion;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void persona::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("Empleados.dad",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.dad",ios::app|ios::out|ios::binary);
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id!=numeroid)
			{
			 file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Id Persona         : ";
	            cin>>numeroid;
                cout<<"\t\t\tIngresa Nombre Persona     : ";
	            cin>>nombre;
	            cout<<"\t\t\tIngresa Telefono Persona   : ";
	            cin>>telefono;
	            cout<<"\t\t\tIngresa las Horas Trabajadas: ";
	            cin>>horatr;
	            cout<<"\t\t\tIngresa la Cantidad que Gana por Hora  : ";
	            cin>>hora;
	            cout<<"\t\t\tIngresa la Cantidad de Horas Extras Trabajadas (si no tiene horas extras ingrese 0) : ";
                cin>>horaextra;
                sueldo = horatr+horaextra;
			    sueldototal= sueldo*hora;
			    bonificacion= sueldototal+250;
			    cout<<"\t\t\t Bonificacion Incentiva de Q250.00 "<<endl;
			    cout<<"\t\t\t Sueldo total a recibir "<< bonificacion<<endl;

				file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << std::left<<std::setw(15)<< sueldototal << std::left<<std::setw(15)<< bonificacion <<"\n";
				found++;
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra >> sueldototal >> bonificacion;

		}
		file1.close();
		file.close();
		remove("Empleados.dad");
		rename("Record.dad","Empleados.dad");
	}
}
void persona::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Empleados.dad",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id==numeroid)
			{
				cout<<"\n\n\t\t\t Id Persona: "<<numeroid<<endl;
			    cout<<"\t\t\t Nombre Persona: "<<nombre<<endl;
			    cout<<"\t\t\t Telefono Persona: "<<telefono<<endl;
			    cout<<"\t\t\t Horas Trabajadas de la Persona: "<<horatr<<endl;
			    cout<<"\t\t\t Cantidad que Gana por Hora: "<<hora<<endl;
			    cout<<"\t\t\t Horas extas trabajadas: "<<horaextra<<endl;
				found++;
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void persona::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("Empleados.dad",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app|ios::out|ios::binary);
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id!=numeroid)
			{
				file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora <<std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Empleados.dad");
		rename("Record.dad","Empleados.dad");
	}
}
main()
{
	persona estudiante;
	estudiante.menu();
	return 0;
}
