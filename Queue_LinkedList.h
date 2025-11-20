#ifndef QUEUE_LINKEDLIST
#define QUEUE_LINKEDLIST

#include <iostream>
#include "LinkedList.h"

using namespace std;

// María Fernanda García Bushbeck A01199490, César Tadeo Bernal Sauceda A00841810, Regina Aguilar García A00841923
// Fecha: 20 / 11 / 2025
// Descripción: Clase para implementar una fila usando listas enlazadas

template <class T>
class Queue{
    private:
        Node<T> *front;
        int size;
    public:
        Queue();
        void enqueue(T value);
        bool dequeue();
        T getFront();
        int getSize();
        bool isEmpty();
};

// Constructor: Inicializa variables
// Entrada: ninguna
// Salida: ninguna
// Complejidad: O(1)
template <class T>
Queue<T>::Queue(){
    front = nullptr;
    size = 0;
}

// Inserta un nodo al final de la fila
// Entrada: value - valor a insertar
// Salida: ninguna
// Complejidad: O(n)
template <class T>
void Queue<T>::enqueue(T value){
    Node<T> *newNode = new Node<T>(value);
    if(front == nullptr){
        front = newNode;
    } else{
        Node<T> *curr = front;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}

// Elimina el nodo del frente de la fila
// Entrada: ninguna
// Salida: true si se eliminó, false si la cola estaba vacía
// Complejidad: O(1)
template <class T>
bool Queue<T>::dequeue(){
    if(isEmpty()){
        return false;
    } else{
        Node<T> *del = front;
        front = front->next;
        delete del;
        size--;
        return true;
    }
}

// Devuelve el dato del nodo del frente
// Entrada: ninguna
// Salida: valor del nodo del frente
// Complejidad: O(1)
template <class T>
T Queue<T>::getFront(){
    if(isEmpty()){
        cerr << "Error: La estructura de datos esta vacia. Saliendo del programa..." << endl;
        exit(1);
    }
    return front->data;
}

// Devuelve el tamaño actual de la fila
// Entrada: ninguna
// Salida: tamaño de la fila
// Complejidad: O(1)
template <class T>
int Queue<T>::getSize(){
    return size;
}

// Verifica si la fila está vacía
// Entrada: ninguna
// Salida: true si la fila está vacía, false si tiene al menos un elemento
// Complejidad: O(1)
template <class T>
bool Queue<T>::isEmpty(){
    if(front != nullptr){
        return false;
    } else{
        return true;
    }
}

#endif