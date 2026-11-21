#include <iostream>

#include "../include/LogReader.h"

using namespace std;

int main() {

    BSTIP tree;
    LogReader reader;

    if (!reader.cargar("log607-3.json", tree)) {

        return 1;
    }

    reader.mostrarReporte();

    cout << endl;
    cout << "IPs diferentes en BST: "
         << tree.size() << endl;

    cout << "Altura del BST: "
         << tree.height() << endl;

    return 0;
}