// Regina Mugica Limon
// A00843542

#include <iostream>

using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;

    int opcion;
    int dato;

    do {

        cout << endl;
        cout << "------ BST ------" << endl;
        cout << "1. Insertar valor" << endl;
        cout << "2. Mostrar recorridos" << endl;
        cout << "3. Buscar valor" << endl;
        cout << "4. Mostrar altura" << endl;
        cout << "5. Mostrar ancestros" << endl;
        cout << "6. Consultar nivel de un nodo" << endl;
        cout << "7. Eliminar valor" << endl;
        cout << "8. Salir" << endl;
        cout << "Selecciona una opcion: ";

        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "Ingresa el valor a insertar: ";
                cin >> dato;

                bst.insert(dato);

                cout << "Valor insertado." << endl;

                break;


            case 2:

                cout << endl;

                bst.visit("preOrder");
                bst.visit("inOrder");
                bst.visit("postOrder");
                bst.visit("levelByLevel");

                break;


            case 3:

                cout << "Ingresa el valor a buscar: ";
                cin >> dato;

                if (bst.find(dato)) {
                    cout << "El valor si se encuentra en el BST." << endl;
                } else {
                    cout << "El valor no se encuentra en el BST." << endl;
                }

                break;


            case 4:

                cout << "Altura del BST: " << bst.height() << endl;

                break;


            case 5:

                cout << "Ingresa el valor para conocer sus ancestros: ";
                cin >> dato;

                bst.ancestors(dato);

                break;


            case 6:

                cout << "Ingresa el valor para conocer su nivel: ";
                cin >> dato;

                if (bst.whatLevelAmI(dato) == -1) {
                    cout << "El valor no se encuentra en el BST." << endl;
                } else {
                    cout << "El valor se encuentra en el nivel "
                         << bst.whatLevelAmI(dato) << "." << endl;
                }

                break;


            case 7:

                cout << "Ingresa el valor a eliminar: ";
                cin >> dato;

                bst.remove(dato);

                break;


            case 8:

                cout << "Fin del programa." << endl;

                break;


            default:

                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 8);

    return 0;
}