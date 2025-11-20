#ifndef BST_H
#define BST_H

#include <iostream>
#include "BinaryNode.h"
#include "Queue_LinkedList.h" // Clase para poder desplegar los datos del BST nivel por nivel
using namespace std;

// María Fernanda García Bushbeck A01199490, César Tadeo Bernal Sauceda A00841810, Regina Aguilar García A00841923
// Fecha: 20 / 11 / 2025
// Descripción: Clase para implementar un Árbol Binario de Búsqueda (BST) con operaciones de insertar, borrar, búsqueda, recorridos y funciones adicionales

template <class T>
class BST{
    private:
        BinaryNode<T> *root;
        BinaryNode<T> *searchRecursive(BinaryNode<T> *parent, T value);
        BinaryNode<T> *insertRecursive(BinaryNode<T> *parent, T value);
        BinaryNode<T> *removeRecursive(BinaryNode<T> *parent, T value);
        BinaryNode<T> *replace(BinaryNode<T> *curr);
        void preorderRecursive(BinaryNode<T> *parent);
        void inorderRecursive(BinaryNode<T> *parent);
        void postorderRecursive(BinaryNode<T> *parent);
        void destroyRecursive(BinaryNode<T> *parent);

        // Metodo privado para calcular la altura del arbol
        int heightRecursive(BinaryNode<T> *parent);
    public:
        BST();
        BinaryNode<T> *search(T value);
        void insert(T value);
        void remove(T value);
        void destroy();
        void preorder();
        void inorder();
        void postorder();
        ~BST();

        // Nuevas funciones implementadas para la tarea
        void visit(int opcion);
        int height();
        void ancestors(T value);
        int level(T value);

        // Getter para la raíz del árbol
        BinaryNode<T>* getRoot() {
            return root;
        }
};

// Constructor: Inicializa el árbol vacío
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(1)
template <class T>
BST<T>::BST(){
    root = nullptr;
}

// Busca un nodo en el árbol
// Entrada: value - valor a buscar
// Salida: puntero al nodo si existe, nullptr si no existe
// Complejidad: O(n)
template <class T>
BinaryNode<T> *BST<T>::search(T value){
    return searchRecursive(root, value);
}

// Búsqueda recursiva de un valor
// Entrada: parent - nodo actual, value - valor a buscar
// Salida: puntero al nodo si se encuentra, nullptr si no
// Complejidad: O(n)
template <class T>
BinaryNode<T> *BST<T>::searchRecursive(BinaryNode<T> *parent, T value){
    if(parent == nullptr){
        return nullptr;
    } else{
        if(value < parent->data){
            // Buscar en el subarbol izquierdo
            return searchRecursive(parent->left, value);
        } else if(value > parent->data){
            // Buscar en el subarbol derecho
            return searchRecursive(parent->right, value);
        } else{
            return parent;
        }
    }
}

// Inserta un valor en el árbol
// Entrada: value - valor a insertar
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void BST<T>::insert(T value){
    root = insertRecursive(root, value);
}

// Función insertar de forma recursiva
// Entrada: parent - nodo actual, value - valor a insertar
// Salida: puntero al nodo actualizado
// Complejidad: O(n)
template <class T>
BinaryNode<T> *BST<T>::insertRecursive(BinaryNode<T> *parent, T value){
    if(parent == nullptr){
        parent = new BinaryNode<T>(value);
    } else{
        if(value < parent->data){
            parent->left = insertRecursive(parent->left, value);
        } else if(value > parent->data){
            parent->right = insertRecursive(parent->right, value);
        }
    }
    return parent;
}

// Elimina un nodo del árbol
// Entrada: value - valor a eliminar
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void BST<T>::remove(T value){
    root = removeRecursive(root, value);
}

// Elimina de forma recursiva un nodo
// Entrada: parent - nodo actual, value - valor a eliminar
// Salida: puntero al nodo actualizado
// Complejidad: O(n)
template <class T>
BinaryNode<T> *BST<T>::removeRecursive(BinaryNode<T> *parent, T value){
    if(parent == nullptr){
        cout << "The element does not exists, it cannot be removed" << endl;
    } else{
        if(value < parent->data){
            parent->left = removeRecursive(parent->left, value);
        } else if(value > parent->data){
            parent->right = removeRecursive(parent->right, value);
        } else{
            BinaryNode<T> *rem = parent;
            if(rem->left == nullptr){
                parent = rem->right;
            } else if(rem->right == nullptr){
                parent = rem->left;
            } else{
                rem = replace(rem);
            }
            delete rem;
        }
    }
    return parent;
}

// Encuentra el nodo reemplazo para un nodo con dos hijos
// Entrada: curr - nodo a reemplazar
// Salida: puntero al nodo que reemplaza al actual
// Complejidad: O(n)
template <class T>
BinaryNode<T> *BST<T>::replace(BinaryNode<T> *curr){
    BinaryNode<T> *parent, *child;
    parent = curr;
    child = curr->left;
    while(child->right != nullptr){
        parent = child;
        child = child->right;
    }
    curr->data = child->data;
    if(parent == curr){
        parent->left = child->left;
    } else{
        parent->right = child->left;
    }
    return child;
}

// Recorridos

// Preorden
// Entrada: ninguno
// Salida: imprime valores en preorden
// Complejidad: O(n)
template <class T>
void BST<T>::preorder(){
    preorderRecursive(root);
    cout << endl;
}

// Preorden recursivo
// Entrada: parent - nodo actual
// Salida: imprime valores en preorden
// Complejidad: O(n)
template <class T>
void BST<T>::preorderRecursive(BinaryNode<T> *parent){
    if(parent != nullptr){
        cout << parent->data << " ";
        preorderRecursive(parent->left);
        preorderRecursive(parent->right);
    }
}

// Inorden
// Entrada: ninguno
// Salida: imprime valores en inorden
// Complejidad: O(n)
template <class T>
void BST<T>::inorder(){
    inorderRecursive(root);
    cout << endl;
}

// Inorden recursivo
// Entrada: parent - nodo actual
// Salida: imprime valores en inorden
// Complejidad: O(n)
template <class T>
void BST<T>::inorderRecursive(BinaryNode<T> *parent){
    if(parent != nullptr){
        inorderRecursive(parent->left);
        cout << parent->data << " ";
        inorderRecursive(parent->right);
    }
}

// Postorden
// Entrada: ninguno
// Salida: imprime valores en postorden
// Complejidad: O(n)
template <class T>
void BST<T>::postorder(){
    postorderRecursive(root);
}

// Postorden recursivo
// Entrada: parent - nodo actual
// Salida: imprime valores en postorden
// Complejidad: O(n)
template <class T>
void BST<T>::postorderRecursive(BinaryNode<T> *parent){
    if(parent != nullptr){
        postorderRecursive(parent->left);
        postorderRecursive(parent->right);
        cout << parent->data << " ";
    }
}

// Destruye todos los nodos del árbol
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void BST<T>::destroy(){
    destroyRecursive(root);
    root = nullptr;
}

// Destrucción recursiva
// Entrada: parent - nodo actual
// Salida: ninguno
// Complejidad: O(n)
template <class T>
void BST<T>::destroyRecursive(BinaryNode<T> *parent){
    if(parent != nullptr){
        destroyRecursive(parent->left);
        destroyRecursive(parent->right);
        delete parent;
    }
}

// Destructor: elimina todos los nodos
// Entrada: ninguno
// Salida: ninguno
// Complejidad: O(n)
template <class T>
BST<T>::~BST(){
    destroy();
}

// Nuevos métodos implementados:

// Permite visitar el árbol según la opción elegida
// Entrada: opcion - 1=preorden, 2=inorden, 3=postorden, 4=por niveles
// Salida: imprime los elementos según el recorrido
// Complejidad: O(n)
template <class T>
void BST<T>::visit(int opcion){
    if(opcion == 1){
        preorder();
    } else if(opcion == 2){
        inorder();
    } else if(opcion == 3){
        postorder();
    } else if(opcion == 4){
        if(root == nullptr) return;

        Queue<BinaryNode<T>*> fila;
        fila.enqueue(root);

        while(!fila.isEmpty()){
            BinaryNode<T>* curr = fila.getFront();
            fila.dequeue();

            cout << curr->data << " ";

            if(curr->left != nullptr){
                fila.enqueue(curr->left);
            }
            if(curr->right != nullptr){
                fila.enqueue(curr->right);
            }
        }
        cout << endl;
    } else{
        cout << "Opcion no valida" << endl;
    }
}

// Calcula la altura del árbol recursivamente
// Entrada: parent - nodo actual
// Salida: altura del árbol
// Complejidad: O(n)
template <class T>
int BST<T>::heightRecursive(BinaryNode<T>* parent) {
    if(parent == nullptr){
        return 0;
    }

    int leftHeight, rightHeight;
    leftHeight = heightRecursive(parent->left);
    rightHeight = heightRecursive(parent->right);

    if (leftHeight > rightHeight){
        return 1 + leftHeight;
    }else{
        return 1 + rightHeight;
    }
}

// Devuelve altura del árbol
// Entrada: ninguno
// Salida: altura
// Complejidad: O(n)
template <class T>
int BST<T>::height(){
    return heightRecursive(root);
}

// Imprime ancestros de un nodo
// Entrada: value - valor del nodo
// Salida: imprime ancestros
// Complejidad: O(n)
template <class T>
void BST<T>::ancestors(T value){
    BinaryNode<T> *curr = root;

    while(curr != nullptr){
        if(value < curr->data){
            cout << curr->data << " ";
            curr = curr->left;
        } else if(value > curr->data){
            cout << curr->data << " ";
            curr = curr->right;
        } else{
            break;
        }
    }
    cout << endl;
}

// Devuelve el nivel de un nodo
// Entrada: value - valor del nodo
// Salida: nivel del nodo, -1 si no existe
// Complejidad: O(n)
template <class T>
int BST<T>::level(T value){
    BinaryNode<T> *curr = root;
    int level = 1;

    while(curr != nullptr){
        if(value < curr->data){
            curr = curr->left;
            level++;
        } else if(value > curr->data){
            curr = curr->right;
            level++;
        } else{
            return level;
        }
    }
    return -1;
}

#endif