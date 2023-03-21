//
// Created by Alexander on 27/08/2022.
//

#ifndef LISTICAS_NODO_H
#define LISTICAS_NODO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Node {
    string data1;
    int data2;
    Node *prev;
    Node *next;
public:

    Node(Node* prev,string n, int numer,Node* next);

    string getData1() const;

    int getData2() const;//const no se modifica nada en el metodo

    Node *getNext() const;

    Node *getPrev() const;

    void setNext(Node *next);

    void setPrev(Node *prev);

};

#endif //LISTICAS_NODO_H
