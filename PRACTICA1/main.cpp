#include <iostream>
#include "List.h"
#include <fstream>
using namespace std;

void lectura( List& lista){
    fstream hotel;
    string line;
    string name;
    int num;
    hotel.open("hotel.txt", ios::in);
    while (getline(hotel, line)) {                                        // sea distinto de fin de archivo
        name = line.substr(0, line.find(" "));
        //num =stoi(line.substr(line.find(" ") + 1, line.length()));//"se busca un substring desde la linea siguiente a nombre hasta el final de la linea
        lista.addBottom(name, num);
    }
    hotel.close();
}
string persistencia(const List& lista){
    string persistencia;
    Node* current=lista.getHead();
    while(current!=nullptr){
        persistencia+=current->getData1()+" "+to_string(current->getData2())+"\n";
        current=current->getNext();
    }
    return persistencia;
}
void guardar(string datos){
    fstream hotel;
    string line;
    hotel.open("hotel.txt", ios::trunc);
    if(hotel.is_open()){
        hotel.close();
    } else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    hotel.open("hotel.txt", ios::out);
    hotel<<datos;
    hotel.close();
}
int main() {
    List lista;
    string name;
    int num;
    int index;
    int opcion;
    string line;
    string datos;
    fstream hotel;
    bool close=false;
    //lectura(lista);
    datos=persistencia(lista);
    while (close==false) {
        cout << "BIENVENIDO AL CHECK-IN DE HOTEL" << endl;
        cout << "1. Ingresar un nuevo huesped" << endl;
        cout << "2. Buscar usuario existente" << endl;
        cout << "3. Mostrar lista de usuarios en orden alfabetico" << endl;
        cout << "4. Mostrar lista de usuarios en orden de llegada" << endl;
        cout << "5. Consultar vecinos" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        if (opcion == 1) {
            hotel.open("hotel.txt", ios::out);
            cout << "Ingrese el nombre del huesped" << endl;
            cin >> name;
            cout << "Ingrese el numero de habitacion" << endl;
            cin >> num;
            if(lista.checkIn(name, num)) { ;
                datos += name + "\n";
                datos += to_string(num) + "\n";
                hotel << datos << endl;
                hotel.close();
            }
        } else if (opcion == 2) {
            cout << "1. Buscar por nombre" << endl;
            cout << "2. Buscar por numero de habitacion" << endl;
            cin >> opcion;
            if (opcion == 1) {
                cout << "Ingrese el nombre del huesped:" << endl;
                cin >> name;
                lista.searchName(name);
            } else if (opcion == 2) {
                cout << "Ingrese el numero de habitacion:" << endl;
                cin >> num;
                lista.searchNum(num);
            }
        } else if (opcion == 3) {
            lista.listaAlfabetica();
        } else if (opcion == 4) {
            lista.printList();
        } else if (opcion == 5) {
            cout << "Ingrese numero de habitacion:" << endl;
            cin >> num;
            lista.consultarVecinos(num);
        } else if(opcion==6) {
            cout << "Gracias por usar el programa" << endl;
            close = true;
            return 0;
        } else {
            cout << "Opcion no valida" << endl;
            return 0;
        }
    }
    guardar(datos);
}