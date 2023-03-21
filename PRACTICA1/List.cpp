//
// Created by Alexander on 27/08/2022.
//
#include <fstream>
#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;
List::List() {
     this->head= nullptr;
     this->size=0;
}
int List::getSize() const{
    return this->size;
}
void List::setSize(int size) {
    this->size=size;
}
Node* List::getHead() const{
    return this->head;
}
void List::setHead(Node *head) {
    this->head=head;
}
void List::setAlpha(string name, int num){
    Node* nuevo=new Node(nullptr,name,num, nullptr);
    this->alpha.push_back(nuevo);
}
void List::getAlpha() const{
    for(auto i:alpha){
        cout<<i->getData1()<<" "<<i->getData2()<<endl;
    }
}
void List::addTop(string name, int num) {
    Node *nuevo = new Node(nullptr, name, num, this->head);
    this->head = nuevo;
    this->size++;
}
void List::addBottom(string name, int num) {
    if(num<0||num>101){
        cout<<"Numero invalido"<<endl;
        cout<<"Ingrese un numero entre 1 y 100"<<endl;
        int numero;
        cin>>numero;
        num=numero;
    }
    Node* nuevo=new Node(nullptr,name,num, nullptr);
    if(this->head!=nullptr){           //SI la lista no esta vacia:
        Node *current=this->head;
        while(current->getNext()!=nullptr){
            current=current->getNext();
        }
        current->setNext(nuevo);
        nuevo->setPrev(current);
    } else{
        this->head=nuevo;
    }
    this->size++;
}
void List::addByIndex(int index, string name, int num) {
        if(index>=0 && index<=this->size){
            if(index==0){
                addTop(name,num);
            } else if(index==this->size){
                addBottom(name,num);
            }else{
                Node*current=this->head;
                Node*prev;
                for(int i=0;i<index;i++){
                    prev=current;
                    current=current->getNext();
                }
                Node* nuevo=new Node(prev,name,num,current);
                prev->setNext(nuevo);
                current->setPrev(nuevo);
                this->size++;
            }

        }else{
            cout<<"Index out of range"<<endl;
        }
}
void List::deleteTop() {
    if(this->head!= nullptr){
        Node* current=this->head;
        this->head=this->head->getNext();
        current->setNext(nullptr);
        this->head->setPrev(nullptr);
        delete current;
        this->size--;
    }else{
        cout <<"This list is empty"<<endl;
    }
}
void List::deleteBottom() {
    if(this->head!= nullptr) {
        if (size == 1) {
            deleteTop();
        } else {
            Node *current = this->head;
            Node *prev;
            while (current->getNext() != nullptr) {
                prev = current;
                current = current->getNext();
            }
            current->setPrev(nullptr);
            prev->setNext(nullptr);
            delete current;
        }
    }else{
        cout <<"This list is empty"<<endl;
    }
}
void List::deleteByIndex(int index) {
    if(this->head!= nullptr){
        Node* current=this->head;
        Node* prev;
        for(int i=0;i<index;i++){
            prev=current;
            current=current->getNext();
        }
        prev->setNext(current->getNext());
        current->getNext()->setPrev(prev);
        current->setPrev(nullptr);
        delete current;
    }else{
        cout <<"This list is empty"<<endl;
    }
}
void List::deleteByData(string name, int num) {

}

void List::printList() {
    Node *current = this->head;
    while (current) {
        cout << current->getData1() << ","<<current->getData2()<<"|";
        current = current->getNext();
    }
    cout << endl;
}
void List::searchName(string name) {
    bool found=false;
    Node* current=this->head;
    while(current){
        if(current->getData1()==name){
            cout<<"Name: "<<current->getData1()<<", Number: "<<current->getData2()<<endl;
            found=true;
            break;
        }
        current=current->getNext();
    }if(!found){
        cout<<"No se encontró ese huesped"<<endl;
    }
}
void List::searchNum(int num) {
    bool found=false;
    Node* current=this->head;
    while(current){
        if(current->getData2()==num){
            cout<<"Name: "<<current->getData1()<<", Number: "<<current->getData2()<<endl;
            found=true;
            break;
        }
        current=current->getNext();
    }if(!found){
        cout<<"No se encontró ese huesped"<<endl;
    }
}
void List::listaAlfabetica(){
    Node* current=this->head;
    while(current){
        this->alpha.push_back(current);
        current=current->getNext();
    }
    alpha.sort([](Node* a, Node* b) { return a->getData1() < b->getData1(); });
    //lambda function that compares the data1 of the nodes and if "a" is less than "b" it returns true this is how it sorts the list
    for(auto i: alpha){
        cout<<i->getData1()<<i->getData2()<<endl;
    }//auto allows to iterate through the list without having to specify the type of variable inside each node
    //i is the variable that will store the data of each node
}
void List::consultarVecinos(int num) {
    if(this->head!= nullptr){
        Node* current=this->head;
        Node* prev= this->head;
        while(current->getData2()!=num+1){
            current=current->getNext();
        }
        while(prev->getData2()!=num-1){
            prev=prev->getNext();
        }
        string texto=prev->getData1()+","+ to_string(prev->getData2())+"|"+current->getData1()+","+ to_string(current->getData2());
        cout<<texto<<endl;
    }else{
        cout<<"no hay habitaciones ocupadas"<<endl;
    }
}
bool List::booked(int num) {
    Node* current=this->head;
    while(current){
        if(current->getData2()==num){
            cout<<"Name: "<<current->getData1()<<", Number: "<<current->getData2()<<endl;
            return true;
            break;
        }
        current=current->getNext();
    }return false;
}
bool List::checkIn(string name, int num) {
    if(!booked(num)){
        addBottom(name,num);
        return true;
    }else if(!booked(num-1)){
            int opcion;
            cout<<"La habitacion ya esta ocupada"<<endl;
            cout<<"Desea comprar la habitacion anterior? ("<<num-1<<")"<<endl;
            cout<<"1.Si 2.Regresar"<<endl;
            while (true) {
                cin>>opcion;
                if (opcion == 1) {
                    addBottom(name, num - 1);
                    return true;
                    break;
                } else if (opcion == 2) {
                    return false;
                    break;
                }else{
                    cout<<"Opcion invalida"<<endl;
                }
            }
        }else if(!booked(num+1)){
            int opcion;
            cout<<"La habitacion ya esta ocupada"<<endl;
            cout<<"Desea comprar la habitacion siguiente? ("<<num+1<<")"<<endl;
            cout<<"1.Si 2.Regresar"<<endl;
            while (true) {
                cin>>opcion;
                if (opcion == 1) {
                    addBottom(name, num + 1);
                    return true;
                    break;
                } else if (opcion == 2) {
                    return false;
                    break;
                }else{
                    cout<<"Opcion invalida"<<endl;
                }
            }
        }else{
        cout<<"No esta disponible esa habitacion"<<endl;
        return false;
    }
}