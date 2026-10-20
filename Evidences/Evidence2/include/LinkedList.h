#pragma once

#include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();

    void addFirst(const T& data);
    void addLast(const T& data);

    T deleteFirst();
    T getFirst();

    bool isEmpty();
    int getSize();

    void print();
};


template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


template <typename T>
void LinkedList<T>::addFirst(const T& data) {

    Node<T>* nuevo = new Node<T>(data);

    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;
    }
    else {
        nuevo->next = head;
        head = nuevo;
    }

    size++;
}


template <typename T>
void LinkedList<T>::addLast(const T& data) {

    Node<T>* nuevo = new Node<T>(data);

    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;
    }
    else {
        tail->next = nuevo;
        tail = nuevo;
    }

    size++;
}


template <typename T>
T LinkedList<T>::deleteFirst() {

    if (head == nullptr) {
        throw out_of_range("La lista esta vacia");
    }

    Node<T>* borrar = head;
    T dato = head->data;

    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete borrar;
    size--;

    return dato;
}


template <typename T>
T LinkedList<T>::getFirst() {

    if (head == nullptr) {
        throw out_of_range("La lista esta vacia");
    }

    return head->data;
}


template <typename T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}


template <typename T>
int LinkedList<T>::getSize() {
    return size;
}


template <typename T>
void LinkedList<T>::print() {

    Node<T>* actual = head;

    while (actual != nullptr) {
        cout << actual->data << " ";
        actual = actual->next;
    }

    cout << endl;
}