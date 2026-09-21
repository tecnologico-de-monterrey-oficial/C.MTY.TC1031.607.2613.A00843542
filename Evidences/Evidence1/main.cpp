#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include "Log.h"
#include "Sorts.h"
#include "Search.h"
using namespace std;

int main(){

    int repetir;

    do{

        int opcionArchivo;
        string nombreArchivo;

        cout << "Selecciona el archivo:" << endl;
        cout << "1. log607-1.txt" << endl;
        cout << "2. log607-2.txt" << endl;
        cout << "Opcion: ";
        cin >> opcionArchivo;

        if(opcionArchivo == 1){
            nombreArchivo = "data/log607-1.txt";
        }
        else if(opcionArchivo == 2){
            nombreArchivo = "data/log607-2.txt";
        }
        else{
            cout << "Opcion invalida" << endl;
            return 1;
        }

        ifstream archivo(nombreArchivo);

        if(!archivo.is_open()){
            cout << "No se pudo abrir el archivo" << endl;
            return 1;
        }

        vector<Log> logs;
        string linea;

        while(getline(archivo, linea)){

            stringstream ss(linea);

            string month;
            int day;
            int year;
            string time;
            string ip;
            string message;

            ss >> month >> day >> year >> time >> ip;
            getline(ss, message);

            if(message.size() > 0 && message[0] == ' '){
                message.erase(0, 1);
            }

            Log nuevoLog(year, month, day, time, ip, message, "");
            nuevoLog.createKey();

            logs.push_back(nuevoLog);
        }

        archivo.close();

        cout << "Cantidad de registros: " << logs.size() << endl;

        cout << endl;
        cout << "Primer registro:" << endl;
        cout << "Mes: " << logs[0].month << endl;
        cout << "Dia: " << logs[0].day << endl;
        cout << "Anio: " << logs[0].year << endl;
        cout << "Hora: " << logs[0].time << endl;
        cout << "IP: " << logs[0].ip << endl;
        cout << "Mensaje: " << logs[0].message << endl;
        cout << "Key: " << logs[0].key << endl;

        int opcion;
        string nombreAlgoritmo;
        string mejorCaso;
        string peorCaso;

        cout << endl;
        cout << "Selecciona un algoritmo de ordenamiento:" << endl;
        cout << "1. Swap Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Shell Sort" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        string prediccion;

        cout << endl;
        cout << "Escribe tu prediccion sobre el tiempo de ejecucion:" << endl;
        cout << "(Considera el algoritmo, el tamano y que tan ordenado esta el archivo)" << endl;
        getline(cin, prediccion);

        auto inicio = chrono::high_resolution_clock::now();

        switch(opcion){

            case 1:
                nombreAlgoritmo = "Swap Sort";
                mejorCaso = "O(n^2)";
                peorCaso = "O(n^2)";
                swapSort(logs);
                break;

            case 2:
                nombreAlgoritmo = "Bubble Sort";
                mejorCaso = "O(n)";
                peorCaso = "O(n^2)";
                bubbleSort(logs);
                break;

            case 3:
                nombreAlgoritmo = "Selection Sort";
                mejorCaso = "O(n^2)";
                peorCaso = "O(n^2)";
                selectionSort(logs);
                break;

            case 4:
                nombreAlgoritmo = "Insertion Sort";
                mejorCaso = "O(n)";
                peorCaso = "O(n^2)";
                insertionSort(logs);
                break;

            case 5:
                nombreAlgoritmo = "Merge Sort";
                mejorCaso = "O(n log n)";
                peorCaso = "O(n log n)";
                mergeSort(logs, 0, logs.size() - 1);
                break;

            case 6:
                nombreAlgoritmo = "Quick Sort";
                mejorCaso = "O(n log n)";
                peorCaso = "O(n^2)";
                quickSort(logs, 0, logs.size() - 1);
                break;

            case 7:
                nombreAlgoritmo = "Shell Sort";
                mejorCaso = "Depende de la secuencia de gaps";
                peorCaso = "O(n^2)";
                shellSort(logs);
                break;

            default:
                cout << "Opcion invalida" << endl;
                return 1;
        }

        auto fin = chrono::high_resolution_clock::now();

        auto duracion =
            chrono::duration_cast<chrono::nanoseconds>(fin - inicio);

        string coincidencia;

        cout << endl;
        cout << "El resultado coincidio con tu prediccion? ";
        getline(cin, coincidencia);

        cout << endl;
        cout << "----- RESULTADOS -----" << endl;

        cout << "Algoritmo: " << nombreAlgoritmo << endl;

        if(opcionArchivo == 1){
            cout << "Archivo: log607-1.txt" << endl;
        }
        else{
            cout << "Archivo: log607-2.txt" << endl;
        }

        cout << "Cantidad de registros: " << logs.size() << endl;

        cout << "Tiempo de ejecucion: "
             << duracion.count()
             << " nanosegundos" << endl;

        cout << "Mejor caso: " << mejorCaso << endl;
        cout << "Peor caso: " << peorCaso << endl;
        cout << "Prediccion inicial: " << prediccion << endl;
        cout << "Coincidio con la prediccion: " << coincidencia << endl;

        cout << endl;
        cout << "Primer registro despues de ordenar:" << endl;

        cout << logs[0].month << " "
             << logs[0].day << " "
             << logs[0].year << " "
             << logs[0].time << endl;

        // Crear output607.txt
        ofstream archivoSalida("output607.txt");

        if(!archivoSalida.is_open()){
            cout << "No se pudo crear output607.txt" << endl;
            return 1;
        }

        for(int i = 0; i < logs.size(); i++){

            archivoSalida << logs[i].month << " ";

            if(logs[i].day < 10){
                archivoSalida << "0";
            }

            archivoSalida << logs[i].day << " "
                          << logs[i].year << " "
                          << logs[i].time << " "
                          << logs[i].ip << " "
                          << logs[i].message << endl;
        }

        archivoSalida.close();

        cout << endl;
        cout << "Archivo output607.txt creado correctamente." << endl;

        // Buscar rango de fechas
        string mesInicio;
        int diaInicio;
        int anioInicio;
        string horaInicio;

        string mesFin;
        int diaFin;
        int anioFin;
        string horaFin;

        cout << endl;
        cout << "Ingresa la fecha y hora inicial:" << endl;
        cout << "Formato: Mes Dia Anio HH:MM:SS" << endl;
        cin >> mesInicio >> diaInicio >> anioInicio >> horaInicio;

        cout << endl;
        cout << "Ingresa la fecha y hora final:" << endl;
        cout << "Formato: Mes Dia Anio HH:MM:SS" << endl;
        cin >> mesFin >> diaFin >> anioFin >> horaFin;

        if(!fechaValida(mesInicio, diaInicio, anioInicio, horaInicio) ||
        !fechaValida(mesFin, diaFin, anioFin, horaFin)){

            cout << endl;
            cout << "Formato de fecha invalido." << endl;
        }
        else{

            Log logInicio(anioInicio, mesInicio, diaInicio, horaInicio, "", "", "");
            logInicio.createKey();

            Log logFin(anioFin, mesFin, diaFin, horaFin, "", "", "");
            logFin.createKey();

            int posicionInicio = busquedaInicio(logs, logInicio.key);
            int posicionFin = busquedaFin(logs, logFin.key);

            cout << endl;

            ofstream archivoRango("range607.txt");

            if(!archivoRango.is_open()){
                cout << "No se pudo crear range607.txt" << endl;
                return 1;
            }

        if(posicionInicio <= posicionFin){

    cout << "Posicion inicial: " << posicionInicio << endl;
    cout << "Posicion final: " << posicionFin << endl;
    cout << "Registros encontrados: "
         << posicionFin - posicionInicio + 1 << endl;

    for(int i = posicionInicio; i <= posicionFin; i++){

        cout << logs[i].month << " ";

        if(logs[i].day < 10){
            cout << "0";
        }

        cout << logs[i].day << " "
             << logs[i].year << " "
             << logs[i].time << " "
             << logs[i].ip << " "
             << logs[i].message << endl;

        archivoRango << logs[i].month << " ";

        if(logs[i].day < 10){
            archivoRango << "0";
        }

        archivoRango << logs[i].day << " "
                     << logs[i].year << " "
                     << logs[i].time << " "
                     << logs[i].ip << " "
                     << logs[i].message << endl;
    }

    cout << "Archivo range607.txt creado correctamente." << endl;
}
else{
    cout << "No se encontraron registros en ese rango." << endl;
}

archivoRango.close();

}

// Repetir prueba
cout << endl;
cout << "Deseas realizar otra prueba?" << endl;
cout << "1. Si" << endl;
cout << "2. No" << endl;
cout << "Opcion: ";
cin >> repetir;

cout << endl;

}while(repetir == 1);

cout << "Programa terminado." << endl;

return 0;

} 