#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>
using namespace std;

// María Fernanda García Bushbeck A01199490, César Tadeo Bernal Sauceda A00841810, Regina Aguilar García A00841923
// Fecha: 19 / 11 / 2025
// Descripción: Clase para representar un nodo de un árbol binario

template <class T>
class BinaryNode{
    public:
        T data;
        BinaryNode<T> *left;
        BinaryNode<T> *right;
        BinaryNode(T value);
};

// Constructor del nodo
// Entrada: value - valor a almacenar en el nodo
// Salida: ninguno
// Complejidad: O(1)
template <class T>
BinaryNode<T>::BinaryNode(T value){
    data = value;
    left = nullptr;
    right = nullptr;
}

# endif