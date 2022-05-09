#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    string usu, contra;
    fstream usuario;
    cout<<"ingrese el nombre de usuario: "; cin>>usu;
    cout<<"ingrese la contraseña: "; cin>>contra;
    usuario.open("seguridad.dat",ios::app | ios::out | ios::binary);
    usuario<<std::left<<std::setw(15)<< usu <<std::left<<std::setw(15)<< contra << "\n";
    usuario.close();
}
