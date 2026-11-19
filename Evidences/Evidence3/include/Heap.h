#ifndef Heap_h
#define Heap_h

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

template <typename T, typename Compare>
class Heap {
private:
    vector<T> heap;
    Compare compare;
    long long comparisons;

    void swapValues(int a, int b);
    void shiftUp(int index);
    void shiftDown(int index);

public:
    Heap();

    void push(T data);
    void pop();
    T top() const;

    int size() const;
    bool empty() const;
    int height() const;

    long long getComparisons() const;
    void resetComparisons();

    void print() const;
};


// Constructor
template <typename T, typename Compare>
Heap<T, Compare>::Heap() {
    comparisons = 0;
}


// Intercambia dos elementos
template <typename T, typename Compare>
void Heap<T, Compare>::swapValues(int a, int b) {

    T temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}


// Sube un elemento mientras deba estar arriba de su padre
template <typename T, typename Compare>
void Heap<T, Compare>::shiftUp(int index) {

    while (index > 0) {

        int father = (index - 1) / 2;

        comparisons++;

        if (compare(heap[index], heap[father])) {

            swapValues(index, father);
            index = father;

        } else {

            break;
        }
    }
}


// Baja un elemento comparandolo con sus hijos
template <typename T, typename Compare>
void Heap<T, Compare>::shiftDown(int index) {

    int heapSize = heap.size();

    while (true) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int selected = index;

        if (left < heapSize) {

            comparisons++;

            if (compare(heap[left], heap[selected])) {
                selected = left;
            }
        }

        if (right < heapSize) {

            comparisons++;

            if (compare(heap[right], heap[selected])) {
                selected = right;
            }
        }

        if (selected == index) {
            break;
        }

        swapValues(index, selected);
        index = selected;
    }
}


// Agrega un elemento al Heap
template <typename T, typename Compare>
void Heap<T, Compare>::push(T data) {

    heap.push_back(data);

    int index = heap.size() - 1;

    shiftUp(index);
}


// Elimina el elemento de arriba
template <typename T, typename Compare>
void Heap<T, Compare>::pop() {

    if (heap.empty()) {
        throw runtime_error("El Heap esta vacio");
    }

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    if (!heap.empty()) {
        shiftDown(0);
    }
}


// Regresa el elemento de arriba
template <typename T, typename Compare>
T Heap<T, Compare>::top() const {

    if (heap.empty()) {
        throw runtime_error("El Heap esta vacio");
    }

    return heap[0];
}


// Regresa la cantidad de elementos
template <typename T, typename Compare>
int Heap<T, Compare>::size() const {

    return heap.size();
}


// Revisa si el Heap esta vacio
template <typename T, typename Compare>
bool Heap<T, Compare>::empty() const {

    return heap.empty();
}


// Regresa la altura del Heap
template <typename T, typename Compare>
int Heap<T, Compare>::height() const {

    if (heap.empty()) {
        return 0;
    }

    return floor(log2(heap.size())) + 1;
}


// Regresa el numero de comparaciones
template <typename T, typename Compare>
long long Heap<T, Compare>::getComparisons() const {

    return comparisons;
}


// Reinicia el contador de comparaciones
template <typename T, typename Compare>
void Heap<T, Compare>::resetComparisons() {

    comparisons = 0;
}


// Imprime los elementos
template <typename T, typename Compare>
void Heap<T, Compare>::print() const {

    for (int i = 0; i < heap.size(); i++) {

        cout << heap[i] << " ";
    }

    cout << endl;
}

#endif