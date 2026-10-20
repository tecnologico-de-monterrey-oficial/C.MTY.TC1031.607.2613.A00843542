#ifndef Registro_h
#define Registro_h

#include <iostream>
#include <string>

using namespace std;

class Registro {
public:
    string mes;
    int dia;
    int anio;
    string hora;
    string ip;
    string evento;

    Registro() {
        mes = "";
        dia = 0;
        anio = 0;
        hora = "";
        ip = "";
        evento = "";
    }

    Registro(string mes, int dia, int anio, string hora, string ip, string evento) {
        this->mes = mes;
        this->dia = dia;
        this->anio = anio;
        this->hora = hora;
        this->ip = ip;
        this->evento = evento;
    }

    void print() {
        cout << mes << " "
             << dia << " "
             << anio << " "
             << hora << " "
             << ip << " "
             << evento << endl;
    }
};

#endif
