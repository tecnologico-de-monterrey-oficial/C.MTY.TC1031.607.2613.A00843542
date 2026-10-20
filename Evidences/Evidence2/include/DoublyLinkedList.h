#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <stdexcept>
#include "NodeD.h"

using namespace std;
template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size = 0;

    NodeD<T>* dividir(NodeD<T>* inicio);
    NodeD<T>* unir(NodeD<T>* izquierda, NodeD<T>* derecha, long long& comparaciones);
    NodeD<T>* mergeSort(NodeD<T>* inicio, long long& comparaciones, int profundidad, int& profundidadMaxima);

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addFirst(T data);
    void addLast(T data);
    void mergeSort(long long& comparaciones, int& profundidadMaxima);
    void insert(int index, T data);
    bool deleteAt(int index);
    int findData(T data);
    bool deleteData(T data);
    T getData(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T data);
    T& operator[](int index);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& list);
    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();
};

template <typename T>
void DoublyLinkedList<T>::addFirst(T data) {
    // validamos si la lista está vacía
    if (head == nullptr) {
        // si está vacía la lista
        // apunto head a un nuevo nodo con data
        head = new NodeD<T>(data);
        // apunto tail a head
        tail = head;
        // incremento size
        size++;
    } else {
        // la lista no está vacía
        // creamos un nuevo nodo
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el next de aux a head
        aux->next = head;
        // apuntamos el prev de head a aux
        head->prev = aux;
        // apuntamos head a aux
        head = aux;
        // incrementamos size
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    // validamos si la lista está vacía
    if (head == nullptr) {
        // si está vacía la lista
        // apunto head a un nuevo nodo con data
        head = new NodeD<T>(data);
        // apunto tail a head
        tail = head;
        // incremento size
        size++;
    } else {
        // la lista no está vacía
        // creamos un nuevo nodo
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el prev de aux a tail
        aux->prev = tail;
        // apuntamos el next de tail a aux
        tail->next = aux;
        // apuntamos tail a aux
        tail = aux;
        // incrementamos size
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // validamos que él índice sea válido
    if (index >= 0 && index <= size-1) {
        // validamos que el indice sea desde 0 hasta el penúltimo
        if (index != size-1) {
            // el index es desde 0 hasta el penúltimo (en medio)
            // creamos un indice auxiliar igual a 0
            int auxIndex = 0;
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // iteramos hasta encontrar el índice dato
            while (auxIndex < index) {
                // recorremos aux
                aux = aux->next;
                // incrementamos el indice auxiliar
                auxIndex++;
            }
            // creamos un nodo nuevo
            NodeD<T>* auxNew = new NodeD<T>(data);
            // el prev del nuevo lo apuntamos a aux
            auxNew->prev = aux;
            // el next del nuevo lo apuntamos a aux->next
            auxNew->next = aux->next;
            // el prev del siguiente de aux lo apuntamos al nuevo
            aux->next->prev = auxNew;
            // apuntamos aux next al nuevo
            aux->next = auxNew;
            // incrmenetamos size
            size++;
        } else {
            // el index es igual a size -1
            // hacemos como si fuera addLast
            // creamos un nuevo nodo
            NodeD<T>* aux = new NodeD<T>(data);
            // apuntamos el prev de aux a tail
            aux->prev = tail;
            // apuntamos el next de tail a aux
            tail->next = aux;
            // apuntamos tail a aux
            tail = aux;
            // incrementamos size
            size++;
        }
    } else {
        throw out_of_range("Índice inválido");
    }
}

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    // validamos si el índice es válido
    if (index >= 0 && index < size) {
        // índíce válido
        // validamos si solo hay un elemento
        if (head->next == nullptr) {
            // solo hay un elemento
            // creamos un nodo auxiliar que apunte a head
            NodeD<T>* aux = head;
            // apuntamos a nulos head y tail
            head = nullptr;
            tail = nullptr;
            // liberamos aux
            delete aux;
            // decrementamos size
            size--;
            // retornamos verdadero
            return true;
        } else {
            // hay más de un elemento
            // validamos si queremos borrar el primero
            if (index == 0) {
                // queremos borrar el primero
                // creamos un nodo auxiliar que apunte a head
                NodeD<T>* aux = head;  
                // apuntamos head al siguiente elemento
                head = head->next;
                // actualizamos el apuntador prev de head
                head->prev = nullptr;
                // liberamos aux
                delete aux;
                // decrementamos size
                size--;
                // retornamos verdadero
                return true; 
            } else {
                // validamos si queremos borrar el último elemento
                if (index ==size -1) {
                    // borramos el último
                    // creamos un nodo auxiliar que apunte a tail
                    NodeD<T>* aux = tail;  
                    // apuntamos tail al elemento previo
                    tail = tail->prev;
                    // actualizamos el apuntador prev de head
                    tail->next = nullptr;
                    // liberamos aux
                    delete aux;
                    // decrementamos size
                    size--;
                    // retornamos verdadero
                    return true; 
                } else {
                    // borramos el de en medio
                    // revisamos por donde empezamos a recorrer la lista
                    if (index <= (size-1)/2) {
                        // recorremos por la izquierda
                        // creamos un indice auxliar = 1
                        int auxIndex = 1;
                        // creamos un apuntador auxiliar igual a head->next
                        NodeD<T>* aux = head->next;
                        // recorremos la lista mientras auxIndex < index
                        while (auxIndex < index) {
                            // recorremos aux
                            aux = aux->next;
                            // incrementamos auxIndex
                            auxIndex++;
                        }
                        // ya llegue al nodo deseado
                        // actualizamos el next de aux->prev que apunte a aux->next
                        aux->prev->next = aux->next;
                        // actualizamos el prev de aux->next que apunte a aux->prev
                        aux->next->prev = aux->prev;
                        // libero aux
                        delete aux;
                        // decremento size
                        size--;
                        // regreso true
                        return true;
                    } else {
                        // recorremos por la derecha
                        // creamos un indice auxliar = size -2
                        int auxIndex = size - 2;
                        // creamos un apuntador auxiliar igual a tail->prev
                        NodeD<T>* aux = tail->prev;
                        // recorremos la lista mientras indez < auxIndex
                        while (index < auxIndex) {
                            // recorremos aux
                            aux = aux->prev;
                            // decrementamos auxIndex
                            auxIndex--;
                        }
                        // ya llegue al nodo deseado
                        // actualizamos el next de aux->prev que apunte a aux->next
                        aux->prev->next = aux->next;
                        // actualizamos el prev de aux->next que apunte a aux->prev
                        aux->next->prev = aux->prev;
                        // libero aux
                        delete aux;
                        // decremento size
                        size--;
                        // regreso true
                        return true;
                    }
                }
            }
        }
    } else {
        // índice inválido
        return false;
    }
}

template <typename T>
int DoublyLinkedList<T>::findData(T data) {
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;
    // incializamos un indice auxialiar en 0
    int auxIndex = 0;
    // recorremos la lista mientras sea diferente
    while (auxIndex < size) {
        // validamos si lo encontramos
        if (aux->data == data) {
            // si lo encontramos
            return auxIndex;
        }
        // recorremos aux e incrmentamos auxIndex
        auxIndex++;
        aux = aux->next;
    }
    // data no se encuentra en la lista
    return -1;
}

template <typename T>
bool DoublyLinkedList<T>::deleteData(T data) {
    // find Data
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;
    // incializamos un indice auxialiar en 0
    int auxIndex = 0;
    // recorremos la lista mientras sea diferente
    while (auxIndex < size) {
        // validamos si lo encontramos
        if (aux->data == data) {
            // si lo encontramos, hay que borrarlo
            // valiamos si es el único
            if (head == tail) {
                // apuntamos a nulos head y tail
                head = nullptr;
                tail = nullptr;
                // liberamos aux
                delete aux;
                // decrementamos size
                size--;
                // retornamos verdadero
                return true;
            } else {
                // validamos si vamos a borrar head
                if (aux == head) {
                    // si es el primer elemento
                    // apuntamos head al siguiente elemento
                    head = head->next;
                    // actualizamos el apuntador prev de head
                    head->prev = nullptr;
                    // liberamos aux
                    delete aux;
                    // decrementamos size
                    size--;
                    // retornamos verdadero
                    return true; 
                } else {
                    // validamos si el último elemento
                    if (aux == tail) {
                        // si es el último elemento
                        // apuntamos tail al elemento previo
                        tail = tail->prev;
                        // actualizamos el apuntador prev de head
                        tail->next = nullptr;
                        // liberamos aux
                        delete aux;
                        // decrementamos size
                        size--;
                        // retornamos verdadero
                        return true; 
                    } else {
                        // boramos el de en medio
                        // actualizamos el next de aux->prev que apunte a aux->next
                        aux->prev->next = aux->next;
                        // actualizamos el prev de aux->next que apunte a aux->prev
                        aux->next->prev = aux->prev;
                        // libero aux
                        delete aux;
                        // decremento size
                        size--;
                        // regreso true
                        return true;
                    }
                }
            }
        }
        // recorremos aux e incrmentamos auxIndex
        auxIndex++;
        aux = aux->next;
    }
    // data no se encuentra en la lista
    return false;

}

template <typename T>
T DoublyLinkedList<T>::getData(int index) {
    // validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // creamos un apuntador auxiliar igual a head
        NodeD<T>* aux = head;
        // creamos un indice auxiliar igual a 0
        int auxIndex = 0;
        // recorremos la lista hasta llegar al indice
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        // regresamos el dato encontrado
        return aux->data;
    }
    else {
        // indice invalido
        throw out_of_range("Indice invalido");
    }
}

template <typename T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    // creamos un apuntador auxiliar igual a head
    NodeD<T>* aux = head;
    // recorremos la lista
    while (aux != nullptr) {
        // validamos si encontramos el dato
        if (aux->data == data) {
            // actualizamos el dato
            aux->data = newData;
            return;
        }
        // recorremos aux
        aux = aux->next;
    }
    // no se encontro el dato
    throw out_of_range("Dato no encontrado");
}

template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T data) {
    // validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // creamos un apuntador auxiliar igual a head
        NodeD<T>* aux = head;
        // creamos un indice auxiliar igual a 0
        int auxIndex = 0;
        // recorremos la lista hasta llegar al indice
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        // actualizamos el dato
        aux->data = data;
    }
    else {
        // indice invalido
        throw out_of_range("Indice invalido");
    }
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    // validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // creamos un apuntador auxiliar igual a head
        NodeD<T>* aux = head;
        // creamos un indice auxiliar igual a 0
        int auxIndex = 0;
        // recorremos la lista hasta llegar al indice
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        // regresamos el dato encontrado
        return aux->data;
    }
    else {
        // indice invalido
        throw out_of_range("Indice invalido");
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& list) {

    // validamos que no sea la misma lista
    if (this != &list) {
        // borramos los elementos de la lista actual
        while (head != nullptr) {
            NodeD<T>* aux = head;
            head = head->next;
            delete aux;
        }
        // reiniciamos tail y size
        tail = nullptr;
        size = 0;
        // creamos un apuntador auxiliar a la lista recibida
        NodeD<T>* aux = list.head;
        // recorremos la lista recibida
        while (aux != nullptr) {
            // agregamos cada dato a la lista actual
            addLast(aux->data);
            // recorremos aux
            aux = aux->next;
        }
    }
    // regresamos la lista actual
    return *this;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    // borramos todos los elementos de la lista
    while (head != nullptr) {
        // creamos un apuntador auxiliar igual a head
        NodeD<T>* aux = head;
        // recorremos head al siguiente nodo
        head = head->next;
        // liberamos aux
        delete aux;
    }
    // reiniciamos tail y size
    tail = nullptr;
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::sort() {
    // recorremos la lista
    for (int i = 0; i < size - 1; i++) {
        // creamos un apuntador auxiliar igual a head
        NodeD<T>* aux = head;

        // comparamos los elementos
        for (int j = 0; j < size - 1 - i; j++) {
            // validamos si estan en el orden incorrecto
            if (aux->data > aux->next->data) {
                // intercambiamos los datos
                T temp = aux->data;
                aux->data = aux->next->data;
                aux->next->data = temp;
            }
            // recorremos aux
            aux = aux->next;
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::duplicate() {
    // creamos un apuntador auxiliar igual a head
    NodeD<T>* aux = head;
    // recorremos la lista
    while (aux != nullptr) {

        // creamos un nuevo nodo con el mismo dato
        NodeD<T>* auxNew = new NodeD<T>(aux->data);
        // apuntamos el next del nuevo al siguiente de aux
        auxNew->next = aux->next;
        // apuntamos el prev del nuevo a aux
        auxNew->prev = aux;
        // validamos si aux no es el ultimo
        if (aux->next != nullptr) {
            aux->next->prev = auxNew;
        }
        else {
            // actualizamos tail
            tail = auxNew;
        }
        // apuntamos el next de aux al nuevo
        aux->next = auxNew;
        // incrementamos size
        size++;
        // recorremos aux al siguiente elemento original
        aux = auxNew->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeDuplicates() {
    // ordenamos la lista
    sort();
    // creamos un apuntador auxiliar igual a head
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr && aux->next != nullptr) {
        // validamos si el dato actual es igual al siguiente
        if (aux->data == aux->next->data) {
            // creamos un apuntador al nodo duplicado
            NodeD<T>* auxDelete = aux->next;
            // saltamos el nodo duplicado
            aux->next = auxDelete->next;
            // validamos si el duplicado no era el ultimo
            if (auxDelete->next != nullptr) {
                auxDelete->next->prev = aux;
            }
            else {
                // actualizamos tail
                tail = aux;
            }
            // liberamos el nodo duplicado
            delete auxDelete;
            // decrementamos size
            size--;
        }
        else {
            // recorremos aux
            aux = aux->next;
        }
    }
}

template <typename T>
NodeD<T>* DoublyLinkedList<T>::dividir(NodeD<T>* inicio) {

    NodeD<T>* lento = inicio;
    NodeD<T>* rapido = inicio->next;

    while (rapido != nullptr && rapido->next != nullptr) {
        lento = lento->next;
        rapido = rapido->next->next;
    }

    NodeD<T>* segundaMitad = lento->next;

    lento->next = nullptr;

    if (segundaMitad != nullptr) {
        segundaMitad->prev = nullptr;
    }

    return segundaMitad;
}

template <typename T>
NodeD<T>* DoublyLinkedList<T>::unir(NodeD<T>* izquierda, NodeD<T>* derecha, long long& comparaciones) {

    if (izquierda == nullptr) {
        return derecha;
    }

    if (derecha == nullptr) {
        return izquierda;
    }

    comparaciones++;

    if (!(derecha->data < izquierda->data)) {

        izquierda->next = unir(izquierda->next, derecha, comparaciones);

        if (izquierda->next != nullptr) {
            izquierda->next->prev = izquierda;
        }

        izquierda->prev = nullptr;

        return izquierda;
    }
    else {

        derecha->next = unir(izquierda, derecha->next, comparaciones);

        if (derecha->next != nullptr) {
            derecha->next->prev = derecha;
        }

        derecha->prev = nullptr;

        return derecha;
    }
}

template <typename T>
NodeD<T>* DoublyLinkedList<T>::mergeSort(NodeD<T>* inicio, long long& comparaciones, int profundidad, int& profundidadMaxima) {

    if (profundidad > profundidadMaxima) {
        profundidadMaxima = profundidad;
    }

    if (inicio == nullptr || inicio->next == nullptr) {
        return inicio;
    }

    NodeD<T>* segundaMitad = dividir(inicio);

    inicio = mergeSort(
        inicio,
        comparaciones,
        profundidad + 1,
        profundidadMaxima
    );

    segundaMitad = mergeSort(
        segundaMitad,
        comparaciones,
        profundidad + 1,
        profundidadMaxima
    );

    return unir(inicio, segundaMitad, comparaciones);
}

template <typename T>
void DoublyLinkedList<T>::mergeSort(long long& comparaciones, int& profundidadMaxima) {

    comparaciones = 0;
    profundidadMaxima = 0;

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    head = mergeSort(
        head,
        comparaciones,
        1,
        profundidadMaxima
    );

    NodeD<T>* aux = head;

    while (aux->next != nullptr) {
        aux = aux->next;
    }

    tail = aux;
}

#endif /* DoublyLinkedList_h */