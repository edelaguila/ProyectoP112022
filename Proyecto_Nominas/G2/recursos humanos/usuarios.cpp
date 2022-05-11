/*#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    string usu, contra, numU;
    fstream usuario;
    cout<<"ingrese el numero de usuario a asignar: ";cin>>numU;
    cout<<"ingrese el nombre de usuario: "; cin>>usu;
    cout<<"ingrese la contraseña: "; cin>>contra;
    usuario.open("seguridad.dat",ios::app | ios::out | ios::binary);
    usuario<<std::left<<std::setw(5)<< numU <<std::left<<std::setw(50)<< usu <<std::left<<std::setw(50)<< contra << "\n";
    usuario.close();
}*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

int main(){
    std::cout << "currentDateTime()=" << currentDateTime() << std::endl;
    getchar();
}
