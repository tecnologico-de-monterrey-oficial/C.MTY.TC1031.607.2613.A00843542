#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <limits>
#include <cmath>

#include "../include/Heap.h"
#include "../include/Registro.h"
#include "../include/BSTIP.h"
#include "../include/LogReader.h"

using namespace std;


// Comparador para MinHeap
struct RegistroMenor {
    bool operator()(const Registro& a, const Registro& b) const {
        return a < b;
    }
};


// Comparador para MaxHeap
struct RegistroMayor {
    bool operator()(const Registro& a, const Registro& b) const {
        return a > b;
    }
};


// Estructura para guardar una IP y su frecuencia
struct IPFrecuencia {
    unsigned int ip;
    string ipTexto;
    int cantidad;
};


// Comparador para obtener primero las IPs con mas accesos
struct MayorFrecuencia {
    bool operator()(const IPFrecuencia& a,
                    const IPFrecuencia& b) const {

        if (a.cantidad != b.cantidad) {
            return a.cantidad > b.cantidad;
        }

        // Si tienen la misma cantidad,
        // la IP numericamente menor tiene prioridad
        return a.ip < b.ip;
    }
};


void mostrarMenu() {
    cout << endl;
    cout << "========== EVIDENCIA 3 ==========" << endl;
    cout << "1. Ordenar registros descendente (MaxHeap)" << endl;
    cout << "2. Ordenar registros ascendente (MinHeap)" << endl;
    cout << "3. Top 10 IPs con mas accesos" << endl;
    cout << "4. Buscar una IP" << endl;
    cout << "5. Salir" << endl;
    cout << "Selecciona una opcion: ";
}


int pedirPrediccion() {
    int opcion;

    cout << endl;
    cout << "Si el archivo tuviera el doble de registros," << endl;
    cout << "como crees que cambiaria el numero de comparaciones?" << endl;
    cout << "1. Seria igual" << endl;
    cout << "2. Seria aproximadamente el doble" << endl;
    cout << "3. Seria un poco mas del doble" << endl;
    cout << "4. Seria aproximadamente cuatro veces" << endl;
    cout << "Prediccion: ";

    while (!(cin >> opcion) || opcion < 1 || opcion > 4) {
        cout << "Opcion invalida. Intenta de nuevo: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return opcion;
}


string textoPrediccion(int opcion) {
    if (opcion == 1) {
        return "Seria igual";
    } else if (opcion == 2) {
        return "Seria aproximadamente el doble";
    } else if (opcion == 3) {
        return "Seria un poco mas del doble";
    } else {
        return "Seria aproximadamente cuatro veces";
    }
}


// OPCION 1
void ordenarDescendente(vector<Registro>& registros) {

    cout << endl;
    cout << "===== ORDEN DESCENDENTE =====" << endl;

    int prediccion = pedirPrediccion();

    Heap<Registro, RegistroMayor> heap;

    auto inicio = chrono::high_resolution_clock::now();

    // Insertar todos los registros en el MaxHeap
    for (int i = 0; i < registros.size(); i++) {
        heap.push(registros[i]);
    }

    int altura = heap.height();

    ofstream archivo("out/output608-1.out");

    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo de salida." << endl;
        return;
    }

    // Al sacar los elementos del MaxHeap
    // obtenemos los registros de mayor a menor
    while (!heap.empty()) {
        Registro actual = heap.top();

        archivo << actual.toString() << endl;

        heap.pop();
    }

    archivo.close();

    auto fin = chrono::high_resolution_clock::now();

    double tiempo =
        chrono::duration<double, milli>(fin - inicio).count();

    cout << endl;
    cout << "Archivo generado: out/output608-1.out" << endl;

    cout << "Tiempo: "
         << tiempo
         << " ms"
         << endl;

    cout << "Comparaciones del Heap: "
         << heap.getComparisons()
         << endl;

    cout << "Altura maxima del Heap: "
         << altura
         << endl;

    cout << "Tu prediccion: "
         << textoPrediccion(prediccion)
         << endl;

    cout << "Complejidad esperada de Heap Sort: O(n log n)"
         << endl;

    if (prediccion == 3) {
        cout << "La prediccion coincide con el comportamiento "
             << "esperado de O(n log n)."
             << endl;
    } else {
        cout << "La prediccion no coincide exactamente con el "
             << "comportamiento esperado de O(n log n)."
             << endl;
    }
}


// OPCION 2
void ordenarAscendente(vector<Registro>& registros) {

    cout << endl;
    cout << "===== ORDEN ASCENDENTE =====" << endl;

    int prediccion = pedirPrediccion();

    Heap<Registro, RegistroMenor> heap;

    auto inicio = chrono::high_resolution_clock::now();

    // Insertar todos los registros en el MinHeap
    for (int i = 0; i < registros.size(); i++) {
        heap.push(registros[i]);
    }

    int altura = heap.height();

    ofstream archivo("out/output608-2.out");

    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo de salida." << endl;
        return;
    }

    // Al sacar los elementos del MinHeap
    // obtenemos los registros de menor a mayor
    while (!heap.empty()) {
        Registro actual = heap.top();

        archivo << actual.toString() << endl;

        heap.pop();
    }

    archivo.close();

    auto fin = chrono::high_resolution_clock::now();

    double tiempo =
        chrono::duration<double, milli>(fin - inicio).count();

    cout << endl;
    cout << "Archivo generado: out/output608-2.out" << endl;

    cout << "Tiempo: "
         << tiempo
         << " ms"
         << endl;

    cout << "Comparaciones del Heap: "
         << heap.getComparisons()
         << endl;

    cout << "Altura maxima del Heap: "
         << altura
         << endl;

    cout << "Tu prediccion: "
         << textoPrediccion(prediccion)
         << endl;

    cout << "Complejidad esperada de Heap Sort: O(n log n)"
         << endl;

    if (prediccion == 3) {
        cout << "La prediccion coincide con el comportamiento "
             << "esperado de O(n log n)."
             << endl;
    } else {
        cout << "La prediccion no coincide exactamente con el "
             << "comportamiento esperado de O(n log n)."
             << endl;
    }
}


// OPCION 3
void mostrarTop10(BSTIP& tree) {

    cout << endl;
    cout << "===== TOP 10 IPs =====" << endl;

    // Obtener las IPs que ya estan guardadas en el BST
    vector<NodeIP*> ips = tree.getInorder();

    Heap<IPFrecuencia, MayorFrecuencia> heap;

    // Pasar las IPs del BST al MaxHeap
    for (int i = 0; i < ips.size(); i++) {

        IPFrecuencia dato;

        dato.ip = ips[i]->ip;
        dato.ipTexto = ips[i]->ipTexto;
        dato.cantidad = ips[i]->count;

        heap.push(dato);
    }

    int posicion = 1;
    int cantidadLugar10 = -1;

    // Mostrar los primeros 10
    while (!heap.empty() && posicion <= 10) {

        IPFrecuencia actual = heap.top();
        heap.pop();

        cout << posicion
             << ". "
             << actual.ipTexto
             << " - "
             << actual.cantidad
             << " accesos"
             << endl;

        if (posicion == 10) {
            cantidadLugar10 = actual.cantidad;
        }

        posicion++;
    }

    // Revisar si existen mas IPs empatadas
    // con la cantidad del lugar 10
    int empatesExtra = 0;

    while (!heap.empty() &&
           heap.top().cantidad == cantidadLugar10) {

        IPFrecuencia empate = heap.top();
        heap.pop();

        cout << "Empate con lugar 10: "
             << empate.ipTexto
             << " - "
             << empate.cantidad
             << " accesos"
             << endl;

        empatesExtra++;
    }

    if (empatesExtra == 0) {
        cout << "No hubo IPs adicionales empatadas "
             << "con el lugar 10."
             << endl;
    }
}


// OPCION 4
void buscarIP(BSTIP& tree, LogReader& reader) {

    cout << endl;
    cout << "===== BUSQUEDA DE IP =====" << endl;

    string ip;

    cout << "Ingresa la IP que quieres buscar: ";
    cin >> ip;

    unsigned int ipNumerica;

    // Validar que la IP tenga un formato correcto
    if (!reader.convertirIP(ip, ipNumerica)) {

        cout << "La IP ingresada no es valida."
             << endl;

        return;
    }

    int comparaciones = 0;

    int cantidad =
        tree.search(ipNumerica, comparaciones);

    if (cantidad > 0) {

        cout << "IP encontrada." << endl;

        cout << "Numero de apariciones: "
             << cantidad
             << endl;

    } else {

        cout << "La IP no se encuentra en los registros."
             << endl;
    }

    cout << "Comparaciones realizadas: "
         << comparaciones
         << endl;

    cout << "Altura real del BST: "
         << tree.height()
         << endl;

    int alturaIdeal = 0;

    if (tree.size() > 0) {
        alturaIdeal =
            ceil(log2((double)tree.size()));
    }

    cout << "Altura aproximada de un arbol balanceado: "
         << alturaIdeal
         << endl;

    if (tree.height() > alturaIdeal) {

        cout << "El BST tiene una altura mayor que la "
             << "de un arbol perfectamente balanceado."
             << endl;

    } else {

        cout << "La altura del BST es cercana a la de "
             << "un arbol balanceado."
             << endl;
    }
}


int main() {

    BSTIP tree;
    LogReader reader;

    cout << "Cargando archivo..." << endl;

    // Leer el archivo y construir el BST
    if (!reader.cargar("log607-3.json", tree)) {
        return 1;
    }

    // Mostrar resultados de la validacion
    reader.mostrarReporte();

    cout << endl;

    cout << "IPs diferentes en BST: "
         << tree.size()
         << endl;

    cout << "Altura del BST: "
         << tree.height()
         << endl;

    vector<Registro>& registros =
        reader.getRegistros();

    int opcion = 0;

    while (opcion != 5) {

        mostrarMenu();

        // Validacion de la opcion del menu
        if (!(cin >> opcion)) {

            cout << "Entrada invalida." << endl;

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        switch (opcion) {

            case 1:

                ordenarDescendente(registros);

                break;


            case 2:

                ordenarAscendente(registros);

                break;


            case 3:

                mostrarTop10(tree);

                break;


            case 4:

                buscarIP(tree, reader);

                break;


            case 5:

                cout << endl;
                cout << "Programa terminado."
                     << endl;

                break;


            default:

                cout << "Opcion invalida."
                     << endl;
        }
    }

    return 0;
}