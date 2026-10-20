#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "../include/Queue.h"
#include "../include/DoublyLinkedList.h"
#include "../include/Registro.h"

using namespace std;

int convertirNumero(string texto) {

    int numero = 0;

    for (int i = 0; i < texto.length(); i++) {

        if (texto[i] < '0' || texto[i] > '9') {
            return -1;
        }

        numero = numero * 10 + (texto[i] - '0');
    }

    return numero;
}

bool separarLinea(string linea, Registro& registro) {

    string datos[5];
    int posicion = 0;

    for (int dato = 0; dato < 5; dato++) {

        while (posicion < linea.length() && linea[posicion] == ' ') {
            posicion++;
        }

        while (posicion < linea.length() && linea[posicion] != ' ') {
            datos[dato] += linea[posicion];
            posicion++;
        }
    }

    while (posicion < linea.length() && linea[posicion] == ' ') {
        posicion++;
    }

    string evento = "";

    while (posicion < linea.length()) {
        evento += linea[posicion];
        posicion++;
    }

    if (datos[0] == "" || datos[1] == "" || datos[2] == "" ||
        datos[3] == "" || datos[4] == "" || evento == "") {
        return false;
    }

    int dia = convertirNumero(datos[1]);
    int anio = convertirNumero(datos[2]);

    if (dia == -1 || anio == -1) {
        return false;
    }

    registro.mes = datos[0];
    registro.dia = dia;
    registro.anio = anio;
    registro.hora = datos[3];
    registro.ip = datos[4];
    registro.evento = evento;

    return true;
}

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

    while (getline(archivo, linea)) {
        fila.push(linea);
    }

    archivo.close();

    DoublyLinkedList<Registro> registros;

    int numeroLinea = 0;
    int cargados = 0;
    int omitidos = 0;

    while (!fila.isEmpty()) {

        linea = fila.pop();
        numeroLinea++;

        Registro registro;

        if (separarLinea(linea, registro)) {
            registros.addLast(registro);
            cargados++;
        }
        else {
            cout << "Linea " << numeroLinea << " invalida." << endl;
            omitidos++;
        }
    }

    cout << endl;
    cout << "Registros cargados: " << cargados << endl;
    cout << "Registros omitidos: " << omitidos << endl;
    cout << endl;
    cout << "Ordenando registros..." << endl;

        long long comparaciones;
    int profundidadMaxima;

    auto inicio = chrono::high_resolution_clock::now();

    registros.mergeSort(comparaciones, profundidadMaxima);

    auto fin = chrono::high_resolution_clock::now();

    auto tiempo = chrono::duration_cast<chrono::microseconds>(fin - inicio);

    cout << endl;
    cout << "Algoritmo: Merge Sort" << endl;
    cout << "Archivo: " << nombreArchivo << endl;
    cout << "Registros: " << cargados << endl;
    cout << "Tiempo: " << tiempo.count() << " microsegundos" << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Profundidad maxima: " << profundidadMaxima << endl;

    cout << endl;
    cout << "Primeros 5 registros ordenados:" << endl;

    for (int i = 0; i < 5; i++) {
        registros[i].print();
    }

return 0;

}