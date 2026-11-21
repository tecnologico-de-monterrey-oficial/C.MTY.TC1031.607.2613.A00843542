#include <iostream>
#include <functional>
#include "../include/Heap.h"

using namespace std;

int main() {

    cout << "===== PRUEBAS HEAP =====" << endl;

    // Prueba 1: MinHeap
    cout << endl;
    cout << "1. MinHeap normal" << endl;

    Heap<int, less<int>> minHeap;

    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(40);
    minHeap.push(10);
    minHeap.push(30);

    cout << "Esperado: 5 10 20 30 40" << endl;
    cout << "Obtenido: ";

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << endl;


    // Prueba 2: MaxHeap
    cout << endl;
    cout << "2. MaxHeap normal" << endl;

    Heap<int, greater<int>> maxHeap;

    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(40);
    maxHeap.push(10);
    maxHeap.push(30);

    cout << "Esperado: 40 30 20 10 5" << endl;
    cout << "Obtenido: ";

    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;


    // Prueba 3: Heap vacio
    cout << endl;
    cout << "3. Heap vacio" << endl;

    Heap<int, less<int>> heapVacio;

    cout << "Esperado size: 0" << endl;
    cout << "Obtenido size: " << heapVacio.size() << endl;

    cout << "Esperado empty: 1" << endl;
    cout << "Obtenido empty: " << heapVacio.empty() << endl;

    cout << "Esperado height: 0" << endl;
    cout << "Obtenido height: " << heapVacio.height() << endl;


    // Prueba 4: Un solo elemento
    cout << endl;
    cout << "4. Heap con un elemento" << endl;

    Heap<int, less<int>> heapUno;

    heapUno.push(15);

    cout << "Esperado top: 15" << endl;
    cout << "Obtenido top: " << heapUno.top() << endl;

    cout << "Esperado size: 1" << endl;
    cout << "Obtenido size: " << heapUno.size() << endl;

    cout << "Esperado height: 1" << endl;
    cout << "Obtenido height: " << heapUno.height() << endl;


    // Prueba 5: Valores repetidos
    cout << endl;
    cout << "5. Heap con valores repetidos" << endl;

    Heap<int, less<int>> heapRepetidos;

    heapRepetidos.push(10);
    heapRepetidos.push(5);
    heapRepetidos.push(10);
    heapRepetidos.push(5);
    heapRepetidos.push(20);

    cout << "Esperado: 5 5 10 10 20" << endl;
    cout << "Obtenido: ";

    while (!heapRepetidos.empty()) {
        cout << heapRepetidos.top() << " ";
        heapRepetidos.pop();
    }

    cout << endl;


    // Prueba 6: Datos ya ordenados
    cout << endl;
    cout << "6. Datos ya ordenados" << endl;

    Heap<int, less<int>> heapOrdenado;

    heapOrdenado.push(1);
    heapOrdenado.push(2);
    heapOrdenado.push(3);
    heapOrdenado.push(4);
    heapOrdenado.push(5);

    cout << "Esperado: 1 2 3 4 5" << endl;
    cout << "Obtenido: ";

    while (!heapOrdenado.empty()) {
        cout << heapOrdenado.top() << " ";
        heapOrdenado.pop();
    }

    cout << endl;


    // Prueba 7: Datos en orden inverso
    cout << endl;
    cout << "7. Datos en orden inverso" << endl;

    Heap<int, less<int>> heapInverso;

    heapInverso.push(5);
    heapInverso.push(4);
    heapInverso.push(3);
    heapInverso.push(2);
    heapInverso.push(1);

    cout << "Esperado: 1 2 3 4 5" << endl;
    cout << "Obtenido: ";

    while (!heapInverso.empty()) {
        cout << heapInverso.top() << " ";
        heapInverso.pop();
    }

    cout << endl;

    cout << endl;
    cout << "===== FIN DE PRUEBAS =====" << endl;

    return 0;
}