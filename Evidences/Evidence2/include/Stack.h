#if !defined(Stack_h)
#define Stack_h

#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}

    T pop();
    void push(const T& data);
    T top();
    void print();
};

template <typename T>
T Stack<T>::pop() {
    // validamos que no este vacio
    if (topNode == nullptr) {
        throw std::out_of_range("El stack esta vacio");
    }

    // guardamos el dato que vamos a eliminar
    T data = topNode->data;

    // creamos un apuntador auxiliar
    Node<T>* aux = topNode;

    // actualizamos el top
    topNode = topNode->next;

    // borramos el nodo
    delete aux;

    // regresamos el elemento eliminado
    return data;
}

template <typename T>
void Stack<T>::push(const T& data) {
    // creamos un nuevo nodo
    Node<T>* node = new Node<T>(data);

    // el nuevo nodo apunta al top actual
    node->next = topNode;

    // actualizamos el top
    topNode = node;
}

template <typename T>
T Stack<T>::top() {
    // validamos que no este vacio
    if (topNode == nullptr) {
        throw std::out_of_range("El stack esta vacio");
    }

    // regresamos el ultimo elemento agregado
    return topNode->data;
}

template <typename T>
void Stack<T>::print() {
    Node<T>* aux = topNode;

    while (aux != nullptr) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

#endif // Stack_h