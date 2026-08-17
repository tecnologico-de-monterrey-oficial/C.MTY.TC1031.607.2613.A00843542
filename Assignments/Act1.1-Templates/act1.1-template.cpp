#include <iostream>
using namespace std;

#include "list.h"

int main(){

    // PRUEBA CON INT

    List<int> list;

    cout << "PRUEBA FUNCION INSERT" << endl;
    list.insert(15);
    list.insert(10);
    list.insert(12);
    list.print();

    cout << endl << "PRUEBA FUNCION REMOVELAST" << endl;
    list.removeLast();
    list.print();

    cout << endl << "PRUEBA FUNCION GETDATA" << endl;
    cout << "EL DATO EN LA POSICION 1 ES: " << list.getData(1) << endl;

    cout << endl << "PRUEBA FUNCION GETSIZE" << endl;
    cout << "EL TAMAÑO DE LA LISTA ES: " << list.getSize() << endl;

    cout << endl << "PRUEBA FUNCION GETMAX" << endl;
    cout << "EL VALOR MAYOR DE LA LISTA ES: " << list.getMax() << endl;

    cout << endl << "PRUEBA FUNCION INSERTAT" << endl;
    list.insertAt(1, 20);
    list.print();

    cout << endl << "PRUEBA FUNCION REMOVEAT" << endl;
    list.removeAt(0);
    list.print();

    cout << endl << "PRUEBA FUNCION PRINT" << endl;
    list.print();

    cout<<"---------PRUEBA CON STRING---------------";
    // PRUEBA CON STRING
    List<string> list2;

    cout << endl << "PRUEBA FUNCION INSERT" << endl;
    list2.insert("Laptop");
    list2.insert("Bottle");
    list2.insert("Phone");
    list2.print();

    cout << endl << "PRUEBA FUNCION REMOVELAST" << endl;
    list2.removeLast();
    list2.print();

    cout << endl << "PRUEBA FUNCION GETDATA" << endl;
    cout << "EL DATO EN LA POSICION 1 ES: " << list2.getData(1) << endl;

    cout << endl << "PRUEBA FUNCION GETSIZE" << endl;
    cout << "EL TAMAÑO DE LA LISTA ES: " << list2.getSize() << endl;

    cout << endl << "PRUEBA FUNCION GETMAX" << endl;
    cout << "EL VALOR MAYOR DE LA LISTA ES: " << list2.getMax() << endl;

    cout << endl << "PRUEBA FUNCION INSERTAT" << endl;
    list2.insertAt(1, "Tablet");
    list2.print();

    cout << endl << "PRUEBA FUNCION REMOVEAT" << endl;
    list2.removeAt(2);
    list2.print();

    cout << endl << "PRUEBA FUNCION PRINT" << endl;
    list2.print();

    return 0;
}