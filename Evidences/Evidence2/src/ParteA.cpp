#include <iostream>

#include "../include/LinkedList.h"
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/DoublyLinkedList.h"

using namespace std;

int main() {

    cout << "PRUEBAS PARTE A" << endl;
    cout << endl;


    // LINKED LIST
    cout << "LINKED LIST" << endl;

    LinkedList<int> lista;

    cout << "Lista vacia. Size: " << lista.getSize() << endl;

    lista.addFirst(20);
    lista.addFirst(10);
    lista.addLast(30);

    cout << "Despues de agregar 10, 20 y 30: ";
    lista.print();

    cout << "Size: " << lista.getSize() << endl;

    cout << "Se elimina el primero: "
         << lista.deleteFirst() << endl;

    cout << "Lista final: ";
    lista.print();

    cout << endl;


    // QUEUE
    cout << "QUEUE" << endl;

    Queue<int> fila;

    cout << "Queue vacia: " << fila.isEmpty() << endl;

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    cout << "Queue: ";
    fila.print();

    cout << "Front: " << fila.front() << endl;
    cout << "Size: " << fila.size() << endl;

    cout << "Dequeue: " << fila.dequeue() << endl;

    cout << "Queue despues de dequeue: ";
    fila.print();

    cout << endl;


    // STACK
    cout << "STACK" << endl;

    Stack<int> pila;

    cout << "Stack vacio: " << pila.isEmpty() << endl;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "Stack: ";
    pila.print();

    cout << "Peek: " << pila.peek() << endl;
    cout << "Size: " << pila.size() << endl;

    cout << "Pop: " << pila.pop() << endl;

    cout << "Stack despues de pop: ";
    pila.print();

    cout << endl;


    // DOUBLY LINKED LIST
cout << "DOUBLY LINKED LIST" << endl;

DoublyLinkedList<int> listaDoble;

cout << "Lista vacia. Size: "
     << listaDoble.getSize() << endl;

listaDoble.addFirst(20);
listaDoble.addFirst(10);
listaDoble.addLast(30);

cout << "Recorrido hacia adelante: ";
listaDoble.printForward();

cout << "Recorrido hacia atras: ";
listaDoble.printBackward();

cout << "Size: "
     << listaDoble.getSize() << endl;

listaDoble.insert(1, 25);

cout << "Despues de insertar 25: ";
listaDoble.printForward();

listaDoble.deleteAt(1);

cout << "Despues de eliminar: ";
listaDoble.printForward();

cout << endl;


    // PRUEBAS CON ESTRUCTURAS VACIAS
    cout << "PRUEBAS CON ESTRUCTURAS VACIAS" << endl;

    Queue<int> filaVacia;
    Stack<int> pilaVacia;

    try {
        filaVacia.dequeue();
    }
    catch (out_of_range& error) {
        cout << "Queue: " << error.what() << endl;
    }

    try {
        pilaVacia.pop();
    }
    catch (out_of_range& error) {
        cout << "Stack: " << error.what() << endl;
    }

    return 0;
}


