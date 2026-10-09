#include <iostream>
#include <stdexcept>
using namespace std;

#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<int> lista;
    DoublyLinkedList<int> lista2;

    int opcion;
    int dato;
    int nuevoDato;
    int index;

    do {
        cout << "\n--- DOUBLY LINKED LIST ---" << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Eliminar un dato" << endl;
        cout << "5. Eliminar dato en una posicion" << endl;
        cout << "6. Obtener dato en una posicion" << endl;
        cout << "7. Actualizar un dato" << endl;
        cout << "8. Actualizar dato en una posicion" << endl;
        cout << "9. Buscar un dato" << endl;
        cout << "10. Obtener dato con []" << endl;
        cout << "11. Actualizar dato con []" << endl;
        cout << "12. Copiar lista con =" << endl;
        cout << "13. Limpiar lista" << endl;
        cout << "14. Ordenar lista" << endl;
        cout << "15. Duplicar elementos" << endl;
        cout << "16. Eliminar duplicados" << endl;
        cout << "17. Mostrar lista" << endl;
        cout << "18. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Dato: ";
            cin >> dato;

            lista.addFirst(dato);

            cout << "Dato agregado al inicio." << endl;
        }

        else if (opcion == 2) {
            cout << "Dato: ";
            cin >> dato;

            lista.addLast(dato);

            cout << "Dato agregado al final." << endl;
        }

        else if (opcion == 3) {
            cout << "Indice: ";
            cin >> index;

            cout << "Dato: ";
            cin >> dato;

            try {
                lista.insert(index, dato);
                cout << "Dato insertado." << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 4) {
            cout << "Dato a eliminar: ";
            cin >> dato;

            if (lista.deleteData(dato)) {
                cout << "Dato eliminado." << endl;
            }
            else {
                cout << "Dato no encontrado." << endl;
            }
        }

        else if (opcion == 5) {
            cout << "Indice: ";
            cin >> index;

            if (lista.deleteAt(index)) {
                cout << "Dato eliminado." << endl;
            }
            else {
                cout << "Indice invalido." << endl;
            }
        }

        else if (opcion == 6) {
            cout << "Indice: ";
            cin >> index;

            try {
                cout << "Dato: " << lista.getData(index) << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 7) {
            cout << "Dato a actualizar: ";
            cin >> dato;

            cout << "Nuevo dato: ";
            cin >> nuevoDato;

            try {
                lista.updateData(dato, nuevoDato);
                cout << "Dato actualizado." << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 8) {
            cout << "Indice: ";
            cin >> index;

            cout << "Nuevo dato: ";
            cin >> dato;

            try {
                lista.updateAt(index, dato);
                cout << "Dato actualizado." << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 9) {
            cout << "Dato a buscar: ";
            cin >> dato;

            index = lista.findData(dato);

            if (index != -1) {
                cout << "Dato encontrado en el indice: " << index << endl;
            }
            else {
                cout << "Dato no encontrado." << endl;
            }
        }

        else if (opcion == 10) {
            cout << "Indice: ";
            cin >> index;

            try {
                cout << "Dato: " << lista[index] << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 11) {
            cout << "Indice: ";
            cin >> index;

            cout << "Nuevo dato: ";
            cin >> dato;

            try {
                lista[index] = dato;
                cout << "Dato actualizado." << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 12) {
            lista2 = lista;

            cout << "Lista copiada correctamente." << endl;
        }

        else if (opcion == 13) {
            lista.clear();

            cout << "Lista vaciada." << endl;
        }

        else if (opcion == 14) {
            lista.sort();

            cout << "Lista ordenada." << endl;
        }

        else if (opcion == 15) {
            lista.duplicate();

            cout << "Elementos duplicados." << endl;
        }

        else if (opcion == 16) {
            lista.removeDuplicates();

            cout << "Duplicados eliminados." << endl;
        }

        else if (opcion == 17) {
            cout << "Lista: ";

            int i = 0;

            try {
                while (true) {
                    cout << lista[i] << " ";
                    i++;
                }
            }
            catch (out_of_range& e) {
                cout << endl;
            }
        }

        else if (opcion == 18) {
            cout << "Programa terminado." << endl;
        }

        else {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 18);

    return 0;
}