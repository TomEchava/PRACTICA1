 //
// Created by Alexander on 27/08/2022.
//
#include "Node.h"
#include <fstream>
Node::Node(Node* prev,string name, int num,Node* next)
{
    this->prev = prev;
    this->data1 = name;
    this->data2 = num;
    this->next = next; // 0 es el puntero NULL en C++
}
string Node::getData1()const{
    return data1;
}
int Node::getData2( ) const {
    return data2;
}
Node *Node::getNext() const {
    return next;
}
Node *Node::getPrev() const {
    return prev;
}
void Node:: setNext(Node* next){
    this->next = next;
}
void Node:: setPrev(Node* prev){
    this->prev=prev;
}