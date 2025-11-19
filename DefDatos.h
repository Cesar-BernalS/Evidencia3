/* María Fernanda García Bushbeck A01199490
César Tadeo Bernal Sauceda A00841810
Regina Aguilar García A00841923

Fecha: 19/11/2025

Este archivo tiene como finalidad el facilitar el ordenamiento de IPs. Permite
separar las direcciones IP en sus componentes como manejar la mimsa y compararla. */

#ifndef DEFDATOS_H
#define DEFDATOS_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DefDatos {
    private:
        string mes;
        int dia;
        string hora;
        string IP;
        string mensaje;
        int a, b, c, d; // Componentes de la IP. Las divide en a, b, c, d.
        void dividirIP(string ip);
    public:
        DefDatos() = default;
        DefDatos(string linea);
        DefDatos(string ip, bool soloIP);
        string getIp();
        string toString();
};

// Inicialización de variables
// Complejidad: O(1)
DefDatos::DefDatos(string ip, bool soloIP) {
    IP = ip;
    mensaje = "";
    mes = "";
    hora = "";
    dia = 0;
    dividirIP(ip);
}

// Separación de variables
// Complejidad: O(1)
DefDatos::DefDatos(string linea){
    stringstream ss(linea);
    ss >> mes;
    ss >> dia;
    ss >> hora;
    ss >> IP;
    string ipSolo; // Nueva variable para adjuntarle solo la IP. 
    stringstream ipStream(IP); // Permite extraer cada componente del registro.
    getline(ipStream, ipSolo, ':');
    IP = ipSolo;
    
    getline(ss, mensaje); 
    // En caso de que el mensaje contenga un espacio al inicio...
    if(!mensaje.empty() && mensaje[0] == ' '){
        mensaje.erase(0,1);
    }
    dividirIP(IP);
}

/* División de IP tomando en cuenta los puntos y cada
fracción de la IP, como a, b, c & d. */
// Complejidad: O(1)
void DefDatos::dividirIP(string ip) {
    stringstream ss(ip); // Para extraer cada conjunto de números
    char punto; // Para capturar los puntos
    ss >> a >> punto >> b >> punto >> c >> punto >> d;
}

// Método para obtener la IP
// Complejidad: O(1)
string DefDatos::getIp() {
    return IP;
}

// Devuelve las IPs como string
// Complejidad: O(1)
string DefDatos::toString() {
    stringstream ss;
    ss << mes << " " << dia << " " << hora << " " << IP << " " << mensaje;
    return ss.str();
}

#endif 
