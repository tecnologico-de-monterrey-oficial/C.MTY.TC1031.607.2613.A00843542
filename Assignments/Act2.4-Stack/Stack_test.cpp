#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include "Stack.h"

// Estructura para guardar los datos de cada pagina
struct PaginaWeb {
    string titulo;
    string url;
};

int main() {

    Stack<PaginaWeb> historial;
    int opcion;
    int paginas = 0;

    do {
        cout << "\n--- HISTORIAL DE NAVEGACION ---" << endl;
        cout << "1. Visitar una nueva pagina" << endl;
        cout << "2. Retroceder a la pagina anterior" << endl;
        cout << "3. Ver la pagina actual" << endl;
        cout << "4. Mostrar cuantas paginas hay en el historial" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            PaginaWeb nuevaPagina;

            cout << "Titulo de la pagina: ";
            cin >> nuevaPagina.titulo;

            cout << "URL de la pagina: ";
            cin >> nuevaPagina.url;

            historial.push(nuevaPagina);
            paginas++;

            cout << "Pagina agregada al historial." << endl;
        }

        else if (opcion == 2) {

            try {
                PaginaWeb pagina = historial.pop();
                paginas--;

                cout << "Pagina cerrada: " << pagina.titulo << endl;
                cout << "URL: " << pagina.url << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 3) {

            try {
                PaginaWeb pagina = historial.top();

                cout << "Pagina actual: " << pagina.titulo << endl;
                cout << "URL: " << pagina.url << endl;
            }
            catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 4) {

            cout << "Paginas en el historial: " << paginas << endl;
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