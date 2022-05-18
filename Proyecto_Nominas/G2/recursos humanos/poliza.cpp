
 #include <stdlib.h>
 #include <iostream>
 #include <fstream>
 #include <windows.h>
 
 using namespace std;
 int menu(){
 	int opt;
 	system("cls");
 	cout<<"+----------------------------------+\n";
 	cout<<"|      Clinica Salud Segura        |\n";
 	cout<<"+----------------------------------+\n";
 	cout<<"| 1) Ver reclamaciones acumuladas  |\n";
 	cout<<"| 2) Reclamaciones pendientes      |\n";
 	cout<<"| 3) Modificar plan                |\n";
 	cout<<"| 4) Salir                         |\n";
 	cout<<"+----------------------------------+\n";
 	cout<<"Opcion:  ";
 	cin>>opt;
 	return opt;
 }
 
 bool verificar(string ced, string num){
 	ifstream leer("pendientes.txt", ios::in);
 	string Num, Nom, Ape, Ced, Plan;
 	leer>>Num;
 	while(!leer.eof()){
 		leer>>Nom;
 	    leer>>Ape;
 	    leer>>Ced;
 	    leer>>Plan;
 	    if(Ced == ced || Num == num){
 	    	cout<<"Este registro ya existe.\n";
 		system("pause");
 		leer.close();
 		return false;
		 }
	 }
 	leer.close();
 	return true;
 }

void agregar(ofstream &es){
	system("cls");
	cout<<"<--------- nuevo registro de reclamante ---------->\n";
	string num, nom, ape, ced, plan;
	es.open("pendientes.txt", ios::out | ios::app);
	cout<<"Numero de poliza: ";
	cin>>num;
	cout<<"Nombre: ";
	cin>>nom;
	cout<<"Apellido: ";
	cin>>ape;
	cout<<"Cedula: ";
	cin>>ced;
	system("cls");
	cout<<"A) Plan A tiene deducible de $100 y restar copago de 40% de la reclamacion\n";
	cout<<"B) Plan B tiene deducible de $50 y restar copago de 60% de la reclamacion\n";
	cout<<"C) No quiero plan";
	cout<<"Selecciona un plan: ";
	cin>>plan;
	if(verificar(ced, num))
	es<<num<<" "<<nom<<" "<<ape<<" "<<ced<<" "<<plan<<"\n";
	es.close();
}

void VerPoliza(ifstream &Lec){
	system("cls");
	string num, nom, ape, ced, plan;
	Lec.open("acumulada.txt", ios::in);
	cout<<"+----------------------------------------+\n";
	cout<<"|       Reclamaciones acumuladas         |\n";
	cout<<"+----------------------------------------+\n";
	if(Lec.is_open()){
		Lec>>num;
		while(!Lec.eof()){
			Lec>>nom;
			Lec>>ape;
			Lec>>ced;
			Lec>>plan;
			cout<<"Numero de poliza--: "<<num<<endl;
			cout<<"Nombre------------: "<<nom<<endl;
			cout<<"Apellido----------: "<<ape<<endl;
			cout<<"Cedula------------: "<<ced<<endl;
			cout<<"Plan de poliza----: "<<plan<<"\n\n";
			Lec>>num;
		}
		Lec.close();
		system("pause");
	}else{
		cout<<"No se pudo acceder a la base de datos\n";
		system("pause");
	}
}

void reclamaciones(ofstream &Esc, ifstream &Lec){
	system("cls");
	string num, nom, ape, ced, plan, numaux;
	Lec.open("pendientes.txt", ios::in);
	bool encontrado = false;
	cout<<"Digite el numero de poliza: ";
	cin>>numaux;
	if(Lec.is_open()){
		Lec>>num;
		while(!Lec.eof() && !encontrado){
			Lec>>nom;
			Lec>>ape;
			Lec>>ced;
			Lec>>plan;
			if(num == numaux){
				if(plan =="A" || plan =="a" || plan == "B" || plan == "b"){
					Esc.open("acumulada.txt", ios::out | ios::app);
					Esc<<num<<" "<<ape<<" "<<ced<<" "<<plan<<"\n";
					Esc.close();
					cout<<"Se añadio una reclamacion acumulada\n";
					system("pause");
					encontrado = true;
				}else{
					cout<<"ERROR: Usted no cuenta con un plan para su poliza\n";
					system("pause");
					encontrado = true;
				}
			}
			Lec>>num;
		}
		Lec.close();
		if(!encontrado){
			cout<<"Registro no encontrado.\n";
			system("pause");
			system("cls");
			agregar(Esc);
		}
	}else{
		cout<<"No se pudo acceder a la base de Datos\n";
		system("pause");
	}
}

void ModificarPlan(ifstream &Lec){
	system("cls");
	string num, nom, ape, ced, plan, numaux, planaux;
	Lec.open("pendientes.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Digite el numero de poliza a modificiar: ";
		cin>>numaux<
		Lec>>num;
		while(!Lec.eof()){
			Lec>>nom;
			Lec>>ape;
			Lec>>ced;
			Lec>>plan;
			if(num == numaux){
				system("cls");
				cout<<"A) Plan A tiene deducible de RD$100 y restar copago de 40% de la reclamacion\n";
				cout<<"B) Plan B tiene deducible de RD$50 y restar copago de 60% de la reclamacion\n";
				cout<<"Seleccione un plan: ";
				cin>>planaux;
				aux<<num<<" "<<nom<<" "<<ape<<" "<<ced<<" "<<planaux<<"\n";
			}else{
				aux<<num<<" "<<nom<<" "<<ape<<" "<<ced<<" "<<plan<<"\n";
			}
			Lec>>num;
		}
		Lec.close();
		aux.close();
	}else{
		cout<<"No se pudo acceder a la base de datos\n";
		system("pause");
	}
	remove("pendientes.txt");
	rename("auxiliar.txt", "pendientes.txt");
}
main(){
	ofstream Esc;
	ifstream Lec;
	int opt;
	do{
		system("cls");
		opt = menu();
		switch(opt){
			case 1:
				VerPoliza(Lec);
			break;
			case 2:
				reclamaciones(Esc, Lec);
			break;
			case 3:
				ModificarPlan(Lec);
			break;	
		}
	}while(opt != 4);
}


























