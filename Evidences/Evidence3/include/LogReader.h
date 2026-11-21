#ifndef LogReader_h
#define LogReader_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Registro.h"
#include "BSTIP.h"

using namespace std;


struct RegistroInvalido {

    int posicion;
    string razon;
};


class LogReader {

private:

    vector<Registro> registros;
    vector<RegistroInvalido> invalidos;

    int totalLeidos;


    int mesNumero(string month) {

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


    bool bisiesto(int year) {

        return (year % 400 == 0 ||
               (year % 4 == 0 && year % 100 != 0));
    }


    bool fechaValida(string month, int day, int year) {

        int monthNumber = mesNumero(month);

        if (monthNumber == 0) {
            return false;
        }

        int dias[12] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        if (bisiesto(year)) {
            dias[1] = 29;
        }

        return day >= 1 && day <= dias[monthNumber - 1];
    }


    bool horaValida(string time) {

        if (time.size() != 8) {
            return false;
        }

        if (time[2] != ':' || time[5] != ':') {
            return false;
        }

        try {

            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            int second = stoi(time.substr(6, 2));

            return hour >= 0 && hour <= 23 &&
                   minute >= 0 && minute <= 59 &&
                   second >= 0 && second <= 59;

        } catch (...) {

            return false;
        }
    }


public:

    LogReader() {

        totalLeidos = 0;
    }


    bool convertirIP(string ip, unsigned int& result) {

        stringstream ss(ip);
        string part;

        int values[4];
        int count = 0;

        while (getline(ss, part, '.')) {

            if (count >= 4 || part.empty()) {
                return false;
            }

            for (int i = 0; i < part.size(); i++) {

                if (part[i] < '0' || part[i] > '9') {
                    return false;
                }
            }

            try {

                int value = stoi(part);

                if (value < 0 || value > 255) {
                    return false;
                }

                values[count] = value;
                count++;

            } catch (...) {

                return false;
            }
        }

        if (count != 4) {
            return false;
        }

        result =
            ((unsigned int)values[0] << 24) |
            ((unsigned int)values[1] << 16) |
            ((unsigned int)values[2] << 8) |
            (unsigned int)values[3];

        return true;
    }


    bool cargar(string filename, BSTIP& tree) {

        ifstream file(filename);

        if (!file.is_open()) {

            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }

        string line;

        while (getline(file, line)) {

            // Ignoramos los corchetes del arreglo JSON
            if (line == "[" || line == "]") {
                continue;
            }

            if (line.empty()) {
                continue;
            }

            totalLeidos++;

            Registro r;
            string razon = "";

            try {

                auto obtenerTexto = [&](string key) -> string {

                    string buscar = "\"" + key + "\"";
                    size_t pos = line.find(buscar);

                    if (pos == string::npos) {
                        throw runtime_error("Campo faltante: " + key);
                    }

                    pos = line.find(":", pos);
                    pos = line.find("\"", pos);

                    if (pos == string::npos) {
                        throw runtime_error("Campo invalido: " + key);
                    }

                    size_t end = line.find("\"", pos + 1);

                    return line.substr(pos + 1, end - pos - 1);
                };


                auto obtenerNumero = [&](string key) -> int {

                    string buscar = "\"" + key + "\"";
                    size_t pos = line.find(buscar);

                    if (pos == string::npos) {
                        throw runtime_error("Campo faltante: " + key);
                    }

                    pos = line.find(":", pos);

                    size_t start = line.find_first_of("0123456789-", pos);

                    if (start == string::npos) {
                        throw runtime_error("Campo invalido: " + key);
                    }

                    size_t end = line.find_first_not_of("0123456789-", start);

                    return stoi(line.substr(start, end - start));
                };


                r.month = obtenerTexto("month");
                r.day = obtenerNumero("day");
                r.year = obtenerNumero("year");
                r.time = obtenerTexto("time");
                r.ip = obtenerTexto("ip");
                r.message = obtenerTexto("message");


                if (mesNumero(r.month) == 0) {

                    razon = "Mes invalido";

                } else if (!fechaValida(r.month, r.day, r.year)) {

                    razon = "Fecha invalida";

                } else if (!horaValida(r.time)) {

                    razon = "Hora invalida";

                } else if (!convertirIP(r.ip, r.ipNumerica)) {

                    razon = "IP invalida";

                } else if (r.message.empty()) {

                    razon = "Mensaje vacio";
                }


                if (razon.empty()) {

                    registros.push_back(r);

                    tree.insert(r.ipNumerica, r.ip);

                } else {

                    invalidos.push_back(
                        {totalLeidos, razon}
                    );
                }

            } catch (exception& e) {

                invalidos.push_back(
                    {totalLeidos, e.what()}
                );
            }
        }

        file.close();

        return true;
    }


    vector<Registro>& getRegistros() {

        return registros;
    }


    vector<RegistroInvalido>& getInvalidos() {

        return invalidos;
    }


    int getTotalLeidos() const {

        return totalLeidos;
    }


    void mostrarReporte() {

        cout << endl;
        cout << "===== REPORTE DE LECTURA =====" << endl;

        cout << "Total leidos: "
             << totalLeidos << endl;

        cout << "Registros validos: "
             << registros.size() << endl;

        cout << "Registros invalidos: "
             << invalidos.size() << endl;


        if (!invalidos.empty()) {

            cout << endl;
            cout << "Registros invalidos:" << endl;

            for (int i = 0; i < invalidos.size(); i++) {

                cout << "Posicion "
                     << invalidos[i].posicion
                     << ": "
                     << invalidos[i].razon
                     << endl;
            }
        }
    }
};

#endif
