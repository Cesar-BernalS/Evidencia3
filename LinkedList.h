#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"
using namespace std;

// María Fernanda García Bushbeck A01199490, César Tadeo Bernal Sauceda A00841810, Regina Aguilar García A00841923
// Fecha: 20 / 11 / 2025
// Descripción: Clase para implementar listas enlazadas con operaciones de insertar, borrar, búsqueda y actualización

// Definición de la clase
template <class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        void addFirst(T value);
        void addLast(T value);
        bool addAtIndex(T value, int index);
        bool deleteFirst();
        bool deleteLast();
        bool deleteAtIndex(int index);
        void deleteAll();
        void print();
        int getSize();
        ~LinkedList();

        // Métodos añadidos
        // Buscar:
        T getData(int index);
        int getIndex(T value);

        // Actualizar:
        bool setAtIndex(T value, int index);
        bool swapData(int index1, int index2);
};

// Constructor: Inicializa variables
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(1)
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

// Agrega un nodo al inicio de la lista
// Entrada: value - valor a insertar
// Salida: ninguno
// Complejidad: O(1)
template <class T>
void LinkedList<T>::addFirst(T value){
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    size++;
}

// Agrega un nodo al final de la lista
// Entrada: value - valor a insertar
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void LinkedList<T>::addLast(T value){
    Node<T> *newNode = new Node<T>(value);
    Node<T> *curr;
    curr = head;
    if(head == nullptr){
        head = newNode;
    } else{
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}

// Agrega un nodo en un índice
// Entrada: value - valor a insertar, index - posición donde se inserta
// Salida: true si se pudo insertar, false si lo anterior no fue posible
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::addAtIndex(T value, int index){
    if(index > size){
        return false;
    }
    if(index == 0){
        addFirst(value);
    } else if(index == size){
        addLast(value);
    } else{
        Node<T> *newNode = new Node<T>(value);
        Node<T> *curr;
        curr = head;
        for(int i = 1; i < index; i++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    return true;
}

// Elimina el primer nodo de la lista
// Entrada: ninguna
// Salida: true si se pudo eliminar, false si la lista está vacía
// Complejidad: O(1)
template <class T>
bool LinkedList<T>::deleteFirst(){
    Node<T> *del;
    if(head == nullptr){
        return false;
    } else{
        del = head;
        head = head->next;
        delete del;
        size--;
        return true;
    }
}

// Elimina el último nodo de la lista
// Entrada: ninguno
// Salida: true si se pudo eliminar, false si la lista está vacía
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::deleteLast(){
    Node<T> *curr, *del;
    curr = head;
    if(head == nullptr){
        return false;
    } else if(curr->next == nullptr){
        del = curr;
        head = nullptr;
    } else{
        while((curr->next)->next != nullptr){
            curr = curr->next;
        }
        del = curr->next;
        curr->next = nullptr;
    }
    delete del;
    size--;
    return true;
}

// Elimina un nodo en un índice
// Entrada: index - índice del nodo a eliminar
// Salida: true si se pudo eliminar, false en caso contrario
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::deleteAtIndex(int index){
    if(index >= size){
        return false;
    }
    if(index == 0){
        deleteFirst();
    } else if(index == size-1){
        deleteLast();
    } else{
        Node<T> *curr, *del;
        curr = head;
        for(int i = 1; i < index; i++){
            curr = curr->next;
        }
        del = curr->next;
        curr->next = del->next;
        delete del;
        size--;
    }
    return true;
}

// Elimina todos los nodos de la lista
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void LinkedList<T>::deleteAll(){
    Node<T> *curr;
    while(head != nullptr){
        curr = head->next;
        delete head;
        head = curr;
        size--;
    }
}

// Imprime todos los elementos de la lista
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void LinkedList<T>::print(){
    Node<T> *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Devuelve el tamaño de la lista
// Entrada: ninguno
// Salida: tamaño actual de la lista
// Complejidad: O(1)
template <class T>
int LinkedList<T>::getSize(){
    return size;
}

// Destructor: elimina por completo todos los nodos de la lista
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(n)
template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

// Métodos nuevos implementados:

// Obtiene el dato que se encuentra en un índice
// Entrada: index - índice del elemento
// Salida: valor en el índice, -1 si no existe
// Complejidad: O(n)
template <class T>
T LinkedList<T>::getData(int index){
    if(index < 0 || index >= size){
        cout << "No existe un elemento con el indice dado" << endl;
        return -1; // Devuelve -1 si no se encontró el índice
    } else{
        Node<T> *curr = head;
        for (int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr->data;
    }
}

// Devuelve el índice de un dato que se encuentra en la lista
// Entrada: value - valor a buscar
// Salida: índice del valor, -1 si no existe
// Complejidad: O(n)
template <class T>
int LinkedList<T>::getIndex(T value){
    Node<T> *curr = head;
    for (int i = 0; i < size; i++){
        if(curr->data == value){
            return i;
        }
        curr = curr->next;
    }
    cout << "No existe el elemento" << endl;
    return -1; // Devuelve -1 si no se encontró el elemento
}

// Actualiza el dato de un nodo en un índice
// Entrada: value - nuevo valor, index - posición del dato a actualizar
// Salida: true si se actualizó, false si no existe
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::setAtIndex(T value, int index){
    if(index < 0 || index >= size){
        return false;
    }

    Node<T> *curr = head;
    for (int i = 0; i < index; i++){
        curr = curr->next;
    }
    curr->data = value;
    return true;
}

// Intercambia los datos de dos nodos
// Entrada: index1 - índice del primer nodo, index2 - índice del segundo nodo
// Salida: true si se intercambiaron, false si no fue posible hacer el cambio
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::swapData(int index1, int index2){
    if(index1 < 0 || index1 >= size || index2 < 0 || index2 >= size){
        return false;
    }

    Node<T> *curr1 = head;
    Node<T> *curr2 = head;
    for (int i = 0; i < index1; i++){
        curr1 = curr1->next;
    }

    for (int i = 0; i < index2; i++){
        curr2 = curr2->next;
    }

    T actual = curr1->data;
    curr1->data = curr2->data;
    curr2->data = actual;
    return true;
}

#endif