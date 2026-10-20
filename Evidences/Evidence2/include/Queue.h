#pragma once

#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> lista;

public:
    Queue();

    void enqueue(const T& data);
    T dequeue();
    T front();

    bool isEmpty();
    int size();

    // Para conservar compatibilidad con main.cpp
    void push(const T& data);
    T pop();

    void print();
};


template <typename T>
Queue<T>::Queue() {
}


template <typename T>
void Queue<T>::enqueue(const T& data) {
    lista.addLast(data);
}


template <typename T>
T Queue<T>::dequeue() {
    return lista.deleteFirst();
}


template <typename T>
T Queue<T>::front() {
    return lista.getFirst();
}


template <typename T>
bool Queue<T>::isEmpty() {
    return lista.isEmpty();
}


template <typename T>
int Queue<T>::size() {
    return lista.getSize();
}


template <typename T>
void Queue<T>::push(const T& data) {
    enqueue(data);
}


template <typename T>
T Queue<T>::pop() {
    return dequeue();
}


template <typename T>
void Queue<T>::print() {
    lista.print();
}
