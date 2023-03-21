//
// Created by Alexander on 27/08/2022.
//

#ifndef LISTICAS_LISTA_H
#define LISTICAS_LIST_H
#include <fstream>
#include <iostream>
#include <cstddef>
#include "Node.h"
#include <list>
using namespace std;

class List {
int size;
Node* head;
list<Node*> alpha;
public:

    List();//Constructor de la lista. Al crearse la lista se debe inicializar el puntero *primero (head)  de modo que apunte a NULL

    int getSize() const;

    void setSize(int size);

    Node* getHead() const;

    void setHead(Node* head);

    void setAlpha(string name, int num);

    void getAlpha() const;

    void addTop(string name,int num);

    void addBottom(string name, int num);

    void addByIndex(int index,string name,int num);

    void deleteTop();

    void deleteBottom();

    void deleteByIndex(int index);

    void deleteByData(string name,int num);

    void printList();

    void searchName(string name);

    void searchNum(int num);

    void listaAlfabetica();

    void consultarVecinos(int num);

    bool booked(int num);

    bool checkIn(string name,int num);
};


#endif //LISTICAS_LISTA_H
