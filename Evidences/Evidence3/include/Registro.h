#ifndef Registro_h
#define Registro_h

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Registro {

    string month;
    int day;
    int year;
    string time;
    string ip;
    string message;

    unsigned int ipNumerica;

    Registro() {
        day = 0;
        year = 0;
        ipNumerica = 0;
    }

    int numeroMes() const {

        string meses[12] = {
            "Jan", "Feb", "Mar", "Apr",
            "May", "Jun", "Jul", "Aug",
            "Sep", "Oct", "Nov", "Dec"
        };

        for (int i = 0; i < 12; i++) {

            if (month == meses[i]) {
                return i + 1;
            }
        }

        return 0;
    }

    bool operator<(const Registro& otro) const {

        if (ipNumerica != otro.ipNumerica)
            return ipNumerica < otro.ipNumerica;

        if (year != otro.year)
            return year < otro.year;

        if (numeroMes() != otro.numeroMes())
            return numeroMes() < otro.numeroMes();

        if (day != otro.day)
            return day < otro.day;

        if (time != otro.time)
            return time < otro.time;

        return message < otro.message;
    }

    bool operator>(const Registro& otro) const {
        return otro < *this;
    }

    string toString() const {

        return month + " " +
               to_string(day) + " " +
               to_string(year) + " " +
               time + " " +
               ip + " " +
               message;
    }
};

#endif