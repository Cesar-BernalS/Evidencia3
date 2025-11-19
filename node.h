#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

// María Fernanda García Bushbeck A01199490, César Tadeo Bernal Sauceda A00841810, Regina Aguilar García A00841923
// Fecha: 01 / 01 / 2025
// Descripción: Implementación de nodos para luego trabajar con listas enlazadas

template <class T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node(T value);
};

// Constructor: Inicializa variables
// Entrada: value - valor a almacenar en el nodo
// Salida: ninguno
// Complejidad: O(1)
template <class T>
Node<T>::Node(T value){
    data = value;
    next = nullptr;
}

# endif