#include <iostream>
#include <fstream>
#include <string>
#include "../include/Queue.h"

using namespace std;

int main() {

    string nombreArchivo;

    cout << "Archivo a cargar: ";
    cin >> nombreArchivo;

    ifstream archivo("data/" + nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 0;
    }

    Queue<string> fila;
    string linea;
    int totalLineas = 0;

    while (getline(archivo, linea)) {
        fila.push(linea);
        totalLineas++;
    }

    archivo.close();

    cout << "Lineas cargadas en Queue: " << totalLineas << endl;

    if (!fila.isEmpty()) {
        cout << "Primera linea: " << fila.front() << endl;

        fila.pop();

        cout << "Segunda linea: " << fila.front() << endl;
    }

    return 0;
}