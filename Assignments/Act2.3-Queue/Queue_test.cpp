#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include "Queue.h"

// Estructura para guardar los datos de cada cliente
struct Cliente {
    string nombre;
    int boletos;
};

int main() {

    Queue<Cliente> fila;
    int opcion;
    int personas = 0;

    do {
        cout << "\n--- TAQUILLA DE BOLETOS ---" << endl;
        cout << "1. Llegada de un nuevo cliente" << endl;
        cout << "2. Atender al siguiente cliente" << endl;
        cout << "3. Ver al siguiente cliente" << endl;
        cout << "4. Mostrar cuantas personas hay en la fila" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            Cliente nuevoCliente;

            cout << "Nombre del cliente: ";
            cin >> nuevoCliente.nombre;

            cout << "Cantidad de boletos: ";
            cin >> nuevoCliente.boletos;

            fila.push(nuevoCliente);
            personas++;

            cout << "Cliente agregado a la fila." << endl;
        }

        else if (opcion == 2) {

            try {
                // Obtenemos al cliente antes de eliminarlo
               Cliente cliente = fila.pop();
                personas--;

                cout << "Cliente atendido: " << cliente.nombre << endl;
                cout << "Boletos solicitados: " << cliente.boletos << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 3) {

            try {
                Cliente cliente = fila.front();

                cout << "Siguiente cliente: " << cliente.nombre << endl;
                cout << "Boletos solicitados: " << cliente.boletos << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 4) {

            cout << "Personas en la fila: " << personas << endl;
        }

        else if (opcion == 5) {

            cout << "Programa terminado." << endl;
        }

        else {

            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}