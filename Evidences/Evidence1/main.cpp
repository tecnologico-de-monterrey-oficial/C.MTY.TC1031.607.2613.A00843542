#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Log.h"
#include "Sorts.h"
using namespace std;

int main(){

    ifstream archivo("data/log607-1.txt");

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    vector<Log> logs;
    string linea;

    while(getline(archivo, linea)){

        stringstream ss(linea);

        string month;
        int day;
        int year;
        string time;
        string ip;
        string message;

        ss >> month >> day >> year >> time >> ip;

        getline(ss, message);

        if(message.size() > 0 && message[0] == ' '){
            message.erase(0, 1);
        }

        Log nuevoLog(year, month, day, time, ip, message, "");
        nuevoLog.createKey();

        logs.push_back(nuevoLog);
    }

    archivo.close();

    cout << "Cantidad de registros: " << logs.size() << endl;

    cout << endl;
    cout << "Primer registro:" << endl;
    cout << "Mes: " << logs[0].month << endl;
    cout << "Dia: " << logs[0].day << endl;
    cout << "Anio: " << logs[0].year << endl;
    cout << "Hora: " << logs[0].time << endl;
    cout << "IP: " << logs[0].ip << endl;
    cout << "Mensaje: " << logs[0].message << endl;
    cout << "Key: " << logs[0].key << endl;

    swapSort(logs);

    cout << endl;
    cout << "Primer registro despues de ordenar:" << endl;
    cout << logs[0].month << " "
         << logs[0].day << " "
         << logs[0].year << " "
         << logs[0].time << endl;

    return 0;
}