#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/DoublyLinkedList.h"
#include "../include/Registro.h"

using namespace std;


// Convierte un string con numeros a int
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


// Separa una linea del archivo en los datos del registro
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


    // Primero las lineas se guardan en una Queue
    Queue<string> fila;
    string linea;

    while (getline(archivo, linea)) {
        fila.push(linea);
    }

    archivo.close();


    // Los registros se guardan en la lista doblemente ligada
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


    int opcion = 0;
    bool ordenado = false;

    bool hayBusqueda = false;
    string ultimoMes = "";
    int ultimoDia = 0;
    int ultimoAnio = 0;


    while (opcion != 5) {

        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Ordenar registros por fecha y hora" << endl;
        cout << "2. Buscar registros por dia" << endl;
        cout << "3. Mostrar resultados en orden descendente" << endl;
        cout << "4. Mostrar estadisticas" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;


        // OPCION 1
        if (opcion == 1) {

            if (ordenado) {

                cout << "Los registros ya estan ordenados." << endl;
            }
            else {

                cout << endl;
                cout << "Antes de ordenar, cual es tu prediccion de complejidad?" << endl;
                cout << "1. O(n log n)" << endl;
                cout << "2. O(n^2)" << endl;
                cout << "Prediccion: ";

                int prediccion;
                cin >> prediccion;

                cout << endl;
                cout << "Ordenando registros..." << endl;

                long long comparaciones;
                int profundidadMaxima;

                auto inicio = chrono::high_resolution_clock::now();

                registros.mergeSort(comparaciones, profundidadMaxima);

                auto fin = chrono::high_resolution_clock::now();

                ordenado = true;

                auto tiempo =
                    chrono::duration_cast<chrono::microseconds>(fin - inicio);

                cout << endl;
                cout << "Algoritmo: Merge Sort" << endl;
                cout << "Archivo: " << nombreArchivo << endl;
                cout << "Registros: " << cargados << endl;
                cout << "Tiempo: " << tiempo.count()
                     << " microsegundos" << endl;
                cout << "Comparaciones: " << comparaciones << endl;
                cout << "Profundidad maxima: "
                     << profundidadMaxima << endl;

                if (prediccion == 1) {

                    cout << "La prediccion fue correcta: "
                         << "Merge Sort es O(n log n)." << endl;
                }
                else {

                    cout << "La prediccion no fue correcta: "
                         << "Merge Sort es O(n log n)." << endl;
                }
            }
        }


        // OPCION 2
        else if (opcion == 2) {

            if (!ordenado) {

                cout << "Primero debes ordenar los registros." << endl;
            }
            else {

                string mesBusqueda;
                int diaBusqueda;
                int anioBusqueda;

                cout << "Ingresa el dia a buscar "
                     << "(ejemplo: Sep 14 2024): ";

                cin >> mesBusqueda >> diaBusqueda >> anioBusqueda;

                Registro prueba(
                    mesBusqueda,
                    diaBusqueda,
                    anioBusqueda,
                    "00:00:00",
                    "",
                    ""
                );

                if (prueba.numeroMes() == 0 ||
                    diaBusqueda < 1 ||
                    diaBusqueda > 31 ||
                    anioBusqueda <= 0) {

                    cout << "Dia invalido." << endl;
                }
                else {

                    Registro inicioDia(
                        mesBusqueda,
                        diaBusqueda,
                        anioBusqueda,
                        "00:00:00",
                        "",
                        ""
                    );

                    Registro finDia(
                        mesBusqueda,
                        diaBusqueda,
                        anioBusqueda,
                        "23:59:59",
                        "",
                        ""
                    );

                    NodeD<Registro>* actual = registros.getHead();

                    int encontrados = 0;

                    // Avanza hasta llegar al dia buscado
                    while (actual != nullptr &&
                           actual->data < inicioDia) {

                        actual = actual->next;
                    }

                    // Recorre solamente los registros de ese dia
                    while (actual != nullptr &&
                           !(finDia < actual->data)) {

                        actual->data.print();
                        encontrados++;

                        actual = actual->next;
                    }

                    if (encontrados == 0) {

                        cout << "No se encontraron registros "
                             << "para ese dia." << endl;
                    }
                    else {

                        cout << "Total encontrados: "
                             << encontrados << endl;
                    }

                    hayBusqueda = true;
                    ultimoMes = mesBusqueda;
                    ultimoDia = diaBusqueda;
                    ultimoAnio = anioBusqueda;
                }
            }
        }


        // OPCION 3
        else if (opcion == 3) {

            if (!ordenado) {

                cout << "Primero debes ordenar los registros." << endl;
            }
            else {

                // Si no se ha hecho una busqueda, se pide el dia
                if (!hayBusqueda) {

                    cout << "No hay una busqueda anterior." << endl;
                    cout << "Ingresa el dia "
                         << "(ejemplo: Sep 14 2024): ";

                    cin >> ultimoMes >> ultimoDia >> ultimoAnio;

                    Registro prueba(
                        ultimoMes,
                        ultimoDia,
                        ultimoAnio,
                        "00:00:00",
                        "",
                        ""
                    );

                    if (prueba.numeroMes() == 0 ||
                        ultimoDia < 1 ||
                        ultimoDia > 31 ||
                        ultimoAnio <= 0) {

                        cout << "Dia invalido." << endl;
                        continue;
                    }

                    hayBusqueda = true;
                }


                Registro inicioDia(
                    ultimoMes,
                    ultimoDia,
                    ultimoAnio,
                    "00:00:00",
                    "",
                    ""
                );

                Registro finDia(
                    ultimoMes,
                    ultimoDia,
                    ultimoAnio,
                    "23:59:59",
                    "",
                    ""
                );

                NodeD<Registro>* actual = registros.getHead();

                Stack<Registro> pila;


                while (actual != nullptr &&
                       actual->data < inicioDia) {

                    actual = actual->next;
                }


                // Los registros encontrados se meten al Stack
                while (actual != nullptr &&
                       !(finDia < actual->data)) {

                    pila.push(actual->data);
                    actual = actual->next;
                }


                if (pila.isEmpty()) {

                    cout << "No se encontraron registros "
                         << "para ese dia." << endl;
                }
                else {

                    cout << endl;
                    cout << "Registros en orden descendente:"
                         << endl;

                    // Stack los saca en orden inverso
                    while (!pila.isEmpty()) {

                        Registro registro = pila.pop();
                        registro.print();
                    }
                }
            }
        }


        // OPCION 4
        else if (opcion == 4) {

            vector<string> eventos;
            vector<int> cantidadEventos;

            vector<string> ips;
            vector<int> cantidadIps;

            vector<string> dias;
            vector<int> cantidadDias;

            NodeD<Registro>* actual = registros.getHead();


            while (actual != nullptr) {

                // CONTAR EVENTOS

                bool encontradoEvento = false;

                for (int i = 0; i < eventos.size(); i++) {

                    if (eventos[i] == actual->data.evento) {

                        cantidadEventos[i]++;
                        encontradoEvento = true;
                    }
                }

                if (!encontradoEvento) {

                    eventos.push_back(actual->data.evento);
                    cantidadEventos.push_back(1);
                }


                // CONTAR IPS

                bool encontradaIp = false;

                for (int i = 0; i < ips.size(); i++) {

                    if (ips[i] == actual->data.ip) {

                        cantidadIps[i]++;
                        encontradaIp = true;
                    }
                }

                if (!encontradaIp) {

                    ips.push_back(actual->data.ip);
                    cantidadIps.push_back(1);
                }


                // CONTAR DIAS

                string diaActual =
                    actual->data.mes + " " +
                    to_string(actual->data.dia) + " " +
                    to_string(actual->data.anio);

                bool encontradoDia = false;

                for (int i = 0; i < dias.size(); i++) {

                    if (dias[i] == diaActual) {

                        cantidadDias[i]++;
                        encontradoDia = true;
                    }
                }

                if (!encontradoDia) {

                    dias.push_back(diaActual);
                    cantidadDias.push_back(1);
                }


                actual = actual->next;
            }


            // BUSCAR MAYOR EVENTO

            int mayorEvento = 0;

            for (int i = 0; i < cantidadEventos.size(); i++) {

                if (cantidadEventos[i] > mayorEvento) {

                    mayorEvento = cantidadEventos[i];
                }
            }


            // BUSCAR MAYOR IP

            int mayorIp = 0;

            for (int i = 0; i < cantidadIps.size(); i++) {

                if (cantidadIps[i] > mayorIp) {

                    mayorIp = cantidadIps[i];
                }
            }


            // BUSCAR DIA CON MAS INCIDENTES

            int mayorDia = 0;

            for (int i = 0; i < cantidadDias.size(); i++) {

                if (cantidadDias[i] > mayorDia) {

                    mayorDia = cantidadDias[i];
                }
            }


            // MOSTRAR ESTADISTICAS

            cout << endl;
            cout << "ESTADISTICAS" << endl;

            cout << "Total de registros: "
                 << cargados << endl;


            cout << "Dia(s) con mas incidentes:" << endl;

            for (int i = 0; i < dias.size(); i++) {

                if (cantidadDias[i] == mayorDia) {

                    cout << dias[i] << ": "
                         << cantidadDias[i] << endl;
                }
            }


            cout << "Evento(s) mas frecuente(s):" << endl;

            for (int i = 0; i < eventos.size(); i++) {

                if (cantidadEventos[i] == mayorEvento) {

                    cout << eventos[i] << ": "
                         << cantidadEventos[i] << endl;
                }
            }


            cout << "IP(s) mas frecuente(s):" << endl;

            for (int i = 0; i < ips.size(); i++) {

                if (cantidadIps[i] == mayorIp) {

                    cout << ips[i] << ": "
                         << cantidadIps[i] << endl;
                }
            }
        }


        // OPCION 5
        else if (opcion == 5) {

            cout << "Saliendo del programa..." << endl;
        }


        // OPCION INVALIDA
        else {

            cout << "Opcion invalida." << endl;
        }
    }


    return 0;
}