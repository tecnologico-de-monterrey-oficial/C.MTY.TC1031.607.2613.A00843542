#pragma once

#include "LinkedList.h"

template <typename T>
class Stack {
private:
    LinkedList<T> lista;

public:
    Stack();

    void push(const T& data);
    T pop();

    T peek();
    T top();

    bool isEmpty();
    int size();

    void print();
};


template <typename T>
Stack<T>::Stack() {
}


template <typename T>
void Stack<T>::push(const T& data) {
    lista.addFirst(data);
}


template <typename T>
T Stack<T>::pop() {
    return lista.deleteFirst();
}


template <typename T>
T Stack<T>::peek() {
    return lista.getFirst();
}


template <typename T>
T Stack<T>::top() {
    return peek();
}


template <typename T>
bool Stack<T>::isEmpty() {
    return lista.isEmpty();
}


template <typename T>
int Stack<T>::size() {
    return lista.getSize();
}


template <typename T>
void Stack<T>::print() {
    lista.print();
}
