#if !defined(Queue_h)
#define Queue_h
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    T pop();
    void push(const T& data);
    T front();
    void print();
};

template <typename T>
T Queue<T>::pop() {
    // validamos que no este vacio
    if (head == nullptr) {
        throw std::out_of_range("La fila esta vacia");
    }

    // guardamos el dato que vamos a eliminar
    T data = head->data;

    // validamos si solo hay un elemento
    if (head == tail) {
        Node<T>* aux = head;
        delete aux;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }

    // regresamos el elemento eliminado
    return data;
}

template <typename T>
void Queue<T>::push(const T& data) {
    // validamos que no este vacia
    if (head != nullptr) {

        // actualizamos el next de tail con un nodo nuevo
        tail->next = new Node<T>(data);

        // actualizamos tail con tail->next
        tail = tail->next;
    }
    else {

        // apunto head a un nuevo nodo
        head = new Node<T>(data);

        // apunto tail a head
        tail = head;
    }
}

template <typename T>
T Queue<T>::front() {
    // validamos que no este vacia
    if (head == nullptr) {
        throw std::out_of_range("La fila esta vacia");
    }

    // regresamos el dato del primer nodo
    return head->data;
}

template <typename T>
void Queue<T>::print() {
    // creamos un apuntador auxiliar
    Node<T>* aux = head;

    // recorremos la fila
    while (aux != nullptr) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

#endif // Queue_h