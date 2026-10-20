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

    int numeroMes() const {
        if (mes == "Jan") return 1;
        if (mes == "Feb") return 2;
        if (mes == "Mar") return 3;
        if (mes == "Apr") return 4;
        if (mes == "May") return 5;
        if (mes == "Jun") return 6;
        if (mes == "Jul") return 7;
        if (mes == "Aug") return 8;
        if (mes == "Sep") return 9;
        if (mes == "Oct") return 10;
        if (mes == "Nov") return 11;
        if (mes == "Dec") return 12;

        return 0;
    }

    bool operator<(const Registro& otro) const {

        if (anio != otro.anio) {
            return anio < otro.anio;
        }

        if (numeroMes() != otro.numeroMes()) {
            return numeroMes() < otro.numeroMes();
        }

        if (dia != otro.dia) {
            return dia < otro.dia;
        }

        return hora < otro.hora;
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