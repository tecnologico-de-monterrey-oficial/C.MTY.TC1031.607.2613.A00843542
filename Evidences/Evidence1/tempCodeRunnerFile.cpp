#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Log.h"
#include "Sorts.h"
using namespace std;

int main(){

int opcionArchivo;
string nombreArchivo;

cout << "Selecciona el archivo:" << endl;
cout << "1. log607-1.txt" << endl;
cout << "2. log607-2.txt" << endl;
cout << "Opcion: ";
cin >> opcionArchivo;

if(opcionArchivo == 1){
    nombreArchivo = "data/log607-1.txt";
}
else if(opcionArchivo == 2){
    nombreArchivo = "data/log607-2.txt";
}
else{
    cout << "Opcion invalida" << endl;
    return 1;
}

ifstream archivo(nombreArchivo);

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

    int opcion;

    cout << endl;
    cout << "Selecciona un algoritmo de ordenamiento:" << endl;
    cout << "1. Swap Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Insertion Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "7. Shell Sort" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion){

        case 1:
            swapSort(logs);
            break;

        case 2:
            bubbleSort(logs);
            break;

        case 3:
            selectionSort(logs);
            break;

        case 4:
            insertionSort(logs);
            break;

        case 5:
            mergeSort(logs, 0, logs.size() - 1);
            break;

        case 6:
            quickSort(logs, 0, logs.size() - 1);
            break;

        case 7:
            shellSort(logs);
            break;

        default:
            cout << "Opcion invalida" << endl;
            return 1;
}

    cout << endl;
    cout << "Primer registro despues de ordenar:" << endl;
    cout << logs[0].month << " "
         << logs[0].day << " "
         << logs[0].year << " "
         << logs[0].time << endl;

    return 0;
}