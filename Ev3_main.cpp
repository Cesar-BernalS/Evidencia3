#include <iostream>
#include <fstream>
#include <string>

#include "BST_Ev3.h"
#include "DefDatos.h"
using namespace std;

struct IPGroup{
    string ip;
    int count;

    bool operator<(const IPGroup& other) const {
        return count < other.count;
    }

    bool operator>(const IPGroup& other) const {
        return count > other.count;
    }

    bool operator==(const IPGroup& other) const {
        return count == other.count;
    }
};

void inorderReverse(BinaryNode<IPGroup>* node, int &printed) {
    if (node == nullptr || printed >= 5) return;

    // Recorre derecha primero para tener los más grandes primero
    inorderReverse(node->right, printed);
    if (printed < 5) {
        cout << "IP: " << node->data.ip << ", Counter: " << node->data.count << endl;
        printed++;
    }
    inorderReverse(node->left, printed);
}

int main(){
    ifstream archivo("sortedBitacoraV2.txt");
    string linea;
    string IPs[20000];
    int count = 0;

    // En caso de que el archivo no pueda ser abierto, se desplegará un mensaje
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer cada línea del archivo y agregarla a la lista
    while (getline(archivo, linea)) {
        if(!linea.empty()) {
            DefDatos dato(linea);
            IPs[count] = dato.getIp();
            count++;
        }
    }

    archivo.close();

    BST<IPGroup> IPKeys;

    string ipPrev = IPs[0];
    int repeat = 1;

    for (int i = 1; i <= count; i++) {
        string ipCurr = IPs[i];

        if (ipCurr == ipPrev) {
            repeat++;
        } 
        else {
            // Creamos el grupo para la IP anterior
            IPGroup group;
            group.ip = ipPrev;
            group.count = repeat;

            // Insertarlo en el BST
            IPKeys.insert(group);

            // Reiniciar para nueva IP
            ipPrev = ipCurr;
            repeat = 1;
        }
    }

    int printed = 0;
    cout << "Top 5 IPs mas frecuentes:" << endl;
    inorderReverse(IPKeys.getRoot(), printed);

    return 0;
}