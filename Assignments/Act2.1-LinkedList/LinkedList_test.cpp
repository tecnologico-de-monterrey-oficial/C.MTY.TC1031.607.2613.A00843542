#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "LinkedList.h"


// MENU PARA LISTA DE ENTEROS
void menuInt(LinkedList<int>& list) {

    int opcion = -1;
    int dato;
    int nuevoDato;
    int index;

    while (opcion != 0) {

        cout << endl;
        cout << "----- MENU LISTA -----" << endl;
        cout << "1. Agregar elemento al inicio" << endl;
        cout << "2. Agregar elemento al final" << endl;
        cout << "3. Insertar elemento despues de un indice" << endl;
        cout << "4. Borrar un elemento" << endl;
        cout << "5. Borrar elemento por posicion" << endl;
        cout << "6. Obtener elemento por posicion" << endl;
        cout << "7. Actualizar un elemento" << endl;
        cout << "8. Actualizar elemento por posicion" << endl;
        cout << "9. Buscar elemento" << endl;
        cout << "10. Obtener elemento con []" << endl;
        cout << "11. Actualizar elemento con []" << endl;
        cout << "12. Duplicar lista con =" << endl;
        cout << "13. Imprimir lista" << endl;
        cout << "0. Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        try {

            switch (opcion) {

                case 1:
                    cout << "Dato: ";
                    cin >> dato;

                    list.addFirst(dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 2:
                    cout << "Dato: ";
                    cin >> dato;

                    list.addLast(dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 3:
                    cout << "Indice: ";
                    cin >> index;

                    cout << "Dato: ";
                    cin >> dato;

                    list.insert(index, dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 4:
                    cout << "Dato a borrar: ";
                    cin >> dato;

                    if (list.deleteData(dato)) {
                        cout << "Dato eliminado" << endl;
                    }
                    else {
                        cout << "No se encontro el dato" << endl;
                    }

                    cout << "Lista: ";
                    list.print();
                    break;


                case 5:
                    cout << "Posicion a borrar: ";
                    cin >> index;

                    if (list.deleteAt(index)) {
                        cout << "Dato eliminado" << endl;
                    }
                    else {
                        cout << "Posicion invalida" << endl;
                    }

                    cout << "Lista: ";
                    list.print();
                    break;


                case 6:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato: " << list.getData(index) << endl;
                    break;


                case 7:
                    cout << "Dato que quieres actualizar: ";
                    cin >> dato;

                    cout << "Dato nuevo: ";
                    cin >> nuevoDato;

                    list.updateData(dato, nuevoDato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 8:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato nuevo: ";
                    cin >> dato;

                    list.updateAt(index, dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 9:
                    cout << "Dato a buscar: ";
                    cin >> dato;

                    index = list.findData(dato);

                    if (index == -1) {
                        cout << "No se encontro el dato" << endl;
                    }
                    else {
                        cout << "El dato esta en la posicion: "
                             << index << endl;
                    }
                    break;


                case 10:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato: " << list[index] << endl;
                    break;


                case 11:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato nuevo: ";
                    cin >> dato;

                    list[index] = dato;

                    cout << "Lista: ";
                    list.print();
                    break;


                case 12: {
                    LinkedList<int> copia;

                    copia = list;

                    cout << "Lista original: ";
                    list.print();

                    cout << "Lista duplicada: ";
                    copia.print();

                    break;
                }


                case 13:
                    cout << "Lista: ";
                    list.print();
                    break;


                case 0:
                    cout << "Programa terminado" << endl;
                    break;


                default:
                    cout << "Opcion invalida" << endl;
            }
        }

        catch (out_of_range& error) {
            cout << error.what() << endl;
        }
    }
}


// MENU PARA LISTA DE STRINGS
void menuString(LinkedList<string>& list) {

    int opcion = -1;
    int index;

    string dato;
    string nuevoDato;

    while (opcion != 0) {

        cout << endl;
        cout << "----- MENU LISTA -----" << endl;
        cout << "1. Agregar elemento al inicio" << endl;
        cout << "2. Agregar elemento al final" << endl;
        cout << "3. Insertar elemento despues de un indice" << endl;
        cout << "4. Borrar un elemento" << endl;
        cout << "5. Borrar elemento por posicion" << endl;
        cout << "6. Obtener elemento por posicion" << endl;
        cout << "7. Actualizar un elemento" << endl;
        cout << "8. Actualizar elemento por posicion" << endl;
        cout << "9. Buscar elemento" << endl;
        cout << "10. Obtener elemento con []" << endl;
        cout << "11. Actualizar elemento con []" << endl;
        cout << "12. Duplicar lista con =" << endl;
        cout << "13. Imprimir lista" << endl;
        cout << "0. Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        try {

            switch (opcion) {

                case 1:
                    cout << "Dato: ";
                    cin >> dato;

                    list.addFirst(dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 2:
                    cout << "Dato: ";
                    cin >> dato;

                    list.addLast(dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 3:
                    cout << "Indice: ";
                    cin >> index;

                    cout << "Dato: ";
                    cin >> dato;

                    list.insert(index, dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 4:
                    cout << "Dato a borrar: ";
                    cin >> dato;

                    if (list.deleteData(dato)) {
                        cout << "Dato eliminado" << endl;
                    }
                    else {
                        cout << "No se encontro el dato" << endl;
                    }

                    cout << "Lista: ";
                    list.print();
                    break;


                case 5:
                    cout << "Posicion a borrar: ";
                    cin >> index;

                    if (list.deleteAt(index)) {
                        cout << "Dato eliminado" << endl;
                    }
                    else {
                        cout << "Posicion invalida" << endl;
                    }

                    cout << "Lista: ";
                    list.print();
                    break;


                case 6:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato: " << list.getData(index) << endl;
                    break;


                case 7:
                    cout << "Dato que quieres actualizar: ";
                    cin >> dato;

                    cout << "Dato nuevo: ";
                    cin >> nuevoDato;

                    list.updateData(dato, nuevoDato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 8:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato nuevo: ";
                    cin >> dato;

                    list.updateAt(index, dato);

                    cout << "Lista: ";
                    list.print();
                    break;


                case 9:
                    cout << "Dato a buscar: ";
                    cin >> dato;

                    index = list.findData(dato);

                    if (index == -1) {
                        cout << "No se encontro el dato" << endl;
                    }
                    else {
                        cout << "El dato esta en la posicion: "
                             << index << endl;
                    }
                    break;


                case 10:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato: " << list[index] << endl;
                    break;


                case 11:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato nuevo: ";
                    cin >> dato;

                    list[index] = dato;

                    cout << "Lista: ";
                    list.print();
                    break;


                case 12: {
                    LinkedList<string> copia;

                    copia = list;

                    cout << "Lista original: ";
                    list.print();

                    cout << "Lista duplicada: ";
                    copia.print();

                    break;
                }


                case 13:
                    cout << "Lista: ";
                    list.print();
                    break;


                case 0:
                    cout << "Programa terminado" << endl;
                    break;


                default:
                    cout << "Opcion invalida" << endl;
            }
        }

        catch (out_of_range& error) {
            cout << error.what() << endl;
        }
    }
}


int main() {

    srand(time(0));

    int tipo;
    int forma;
    int cantidad;

    cout << "----- CREACION DE LISTA -----" << endl;
    cout << "1. Lista de enteros" << endl;
    cout << "2. Lista de strings" << endl;
    cout << "Selecciona el tipo: ";
    cin >> tipo;

    cout << endl;
    cout << "1. Crear con datos aleatorios" << endl;
    cout << "2. Capturar datos" << endl;
    cout << "Selecciona una opcion: ";
    cin >> forma;

    cout << "Cantidad de datos: ";
    cin >> cantidad;


    // LISTA DE ENTEROS
    if (tipo == 1) {

        LinkedList<int> list;

        if (forma == 1) {

            for (int i = 0; i < cantidad; i++) {
                list.addLast(rand() % 100);
            }
        }
        else {

            for (int i = 0; i < cantidad; i++) {

                int dato;

                cout << "Dato " << i << ": ";
                cin >> dato;

                list.addLast(dato);
            }
        }

        cout << endl;
        cout << "Lista creada: ";
        list.print();

        menuInt(list);
    }


    // LISTA DE STRINGS
    else if (tipo == 2) {

        LinkedList<string> list;

        if (forma == 1) {

            for (int i = 0; i < cantidad; i++) {

                string dato = "dato" + to_string(rand() % 100);

                list.addLast(dato);
            }
        }
        else {

            for (int i = 0; i < cantidad; i++) {

                string dato;

                cout << "Dato " << i << ": ";
                cin >> dato;

                list.addLast(dato);
            }
        }

        cout << endl;
        cout << "Lista creada: ";
        list.print();

        menuString(list);
    }

    else {
        cout << "Tipo de lista invalido" << endl;
    }

    return 0;
}