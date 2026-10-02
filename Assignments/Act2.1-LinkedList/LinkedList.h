#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <memory>
#include <stdexcept>
#include "Node.h"
using namespace std;

template <typename T>
class LinkedList {
private:
    unique_ptr<Node<T>> head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void addFirst(T data);
    void addLast(T data);
    void print();

    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);

    T getData(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T data);
    int findData(T data);

    T& operator[](int index);
    LinkedList<T>& operator=(const LinkedList<T>& other);
};


// AGREGAR AL INICIO
template <typename T>
void LinkedList<T>::addFirst(T data) {

    unique_ptr<Node<T>> node = make_unique<Node<T>>(data);

    node->next = std::move(head);
    head = std::move(node);

    size++;
}


// AGREGAR AL FINAL
template <typename T>
void LinkedList<T>::addLast(T data) {

    // validamos si la lista esta vacia
    if (head == nullptr) {
        head = make_unique<Node<T>>(data);
    }
    else {
        Node<T>* aux = head.get();

        // recorremos hasta el ultimo nodo
        while (aux->next != nullptr) {
            aux = aux->next.get();
        }

        aux->next = make_unique<Node<T>>(data);
    }

    size++;
}


// IMPRIMIR
template <typename T>
void LinkedList<T>::print() {

    Node<T>* aux = head.get();

    while (aux != nullptr) {

        cout << aux->data;

        aux = aux->next.get();

        if (aux != nullptr) {
            cout << "-";
        }
    }

    cout << endl;
}


// INSERTAR DESPUES DE UN INDICE
template <typename T>
void LinkedList<T>::insert(int index, T data) {

    // el indice debe existir
    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head.get();

    // llegamos al nodo del indice indicado
    for (int i = 0; i < index; i++) {
        aux = aux->next.get();
    }

    unique_ptr<Node<T>> node = make_unique<Node<T>>(data);

    node->next = std::move(aux->next);
    aux->next = std::move(node);

    size++;
}


// BORRAR POR DATO
template <typename T>
bool LinkedList<T>::deleteData(T data) {

    // lista vacia
    if (head == nullptr) {
        return false;
    }

    // si queremos borrar el primero
    if (head->data == data) {
        head = std::move(head->next);
        size--;
        return true;
    }

    Node<T>* aux = head.get();

    // buscamos el nodo anterior al que queremos borrar
    while (aux->next != nullptr) {

        if (aux->next->data == data) {
            aux->next = std::move(aux->next->next);
            size--;
            return true;
        }

        aux = aux->next.get();
    }

    return false;
}


// BORRAR POR POSICION
template <typename T>
bool LinkedList<T>::deleteAt(int index) {

    if (index < 0 || index >= size) {
        return false;
    }

    // borrar el primero
    if (index == 0) {
        head = std::move(head->next);
        size--;
        return true;
    }

    Node<T>* aux = head.get();

    // llegamos al nodo anterior
    for (int i = 0; i < index - 1; i++) {
        aux = aux->next.get();
    }

    aux->next = std::move(aux->next->next);
    size--;

    return true;
}


// OBTENER DATO POR POSICION
template <typename T>
T LinkedList<T>::getData(int index) {

    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head.get();

    for (int i = 0; i < index; i++) {
        aux = aux->next.get();
    }

    return aux->data;
}


// ACTUALIZAR POR DATO
template <typename T>
void LinkedList<T>::updateData(T data, T newData) {

    Node<T>* aux = head.get();

    while (aux != nullptr) {

        if (aux->data == data) {
            aux->data = newData;
            return;
        }

        aux = aux->next.get();
    }

    throw out_of_range("No se encontro el dato");
}


// ACTUALIZAR POR POSICION
template <typename T>
void LinkedList<T>::updateAt(int index, T data) {

    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head.get();

    for (int i = 0; i < index; i++) {
        aux = aux->next.get();
    }

    aux->data = data;
}


// BUSCAR DATO
template <typename T>
int LinkedList<T>::findData(T data) {

    Node<T>* aux = head.get();
    int index = 0;

    while (aux != nullptr) {

        if (aux->data == data) {
            return index;
        }

        aux = aux->next.get();
        index++;
    }

    return -1;
}


// OPERADOR []
template <typename T>
T& LinkedList<T>::operator[](int index) {

    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head.get();

    for (int i = 0; i < index; i++) {
        aux = aux->next.get();
    }

    return aux->data;
}


// OPERADOR =
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {

    // evitamos copiar la lista sobre ella misma
    if (this == &other) {
        return *this;
    }

    // borramos la lista actual
    head = nullptr;
    size = 0;

    Node<T>* aux = other.head.get();

    // copiamos los elementos
    while (aux != nullptr) {
        addLast(aux->data);
        aux = aux->next.get();
    }

    return *this;
}

#endif /* LinkedList_h */