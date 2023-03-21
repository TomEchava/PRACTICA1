//
// Created by ASUS on 13/03/2023.
//
/*
#include "Menu.h"
#include <iostream>
#include <cstddef>
#include "List.h"
using namespace std;
void Menu::mostrarMenu() {
    int opcion;
    cout<<"BIENVENIDO AL CHECK IN DE HOTEL"<<endl;
    cout<<"1. Ingresar un nuevo huesped"<<endl;
    cout<<"2. Buscar usuario existente"<<endl;
    cout<<"3. Mostrar lista de usuarios en orden alfabetico"<<endl;
    cout<<"4. Mostrar lista de usuarios en orden de llegada"<<endl;
    cout<<"5. Consultar vecinos"<<endl;
    cin>>opcion;
    if(opcion==1){
        nuevoHuesped();
    }else if(opcion==2){
        buscarHuesped();
    }else if(opcion==3){
        listaAlfabetica();
    }else if(opcion==4) {
        listaLlegada();
    }else if(opcion==5) {
        consultarVecinos();
    }else{
        cout<<"Opcion no valida"<<endl;
    }
}
void Menu::nuevoHuesped() {
    string nombre;
    int habitacion;
    cout<<"Ingrese el nombre del huesped"<<endl;
    cin>>nombre;
    cout<<"Ingrese el numero de habitacion"<<endl;
    cin>>habitacion;
    List::addBottom(nombre,habitacion);
}
string Menu::buscarHuesped() {
    cout<<"1. Buscar por nombre"<<endl;
    cout<<"2. Buscar por numero de habitacion"<<endl;
    int opcion;
    cin>>opcion;
    if(opcion==1){
        string nombre;
        cout<<"Ingrese el nombre del huesped:"<<endl;
        cin>>nombre;
        List::search(nombre);
    }else if(opcion==2){
        int habitacion;
        cout<<"Ingrese el numero de habitacion:"<<endl;
        cin>>habitacion;
        List::search(habitacion);
    }
}*/