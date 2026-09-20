#ifndef Search_h
#define Search_h
#include <vector>
#include <string>
#include "Log.h"
using namespace std;

int busquedaInicio(vector<Log> &logs, string key){

    int left = 0;
    int right = logs.size() - 1;
    int resultado = logs.size();

    while(left <= right){

        int mid = (left + right) / 2;

        if(logs[mid].key >= key){
            resultado = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return resultado;
}

int busquedaFin(vector<Log> &logs, string key){

    int left = 0;
    int right = logs.size() - 1;
    int resultado = -1;

    while(left <= right){

        int mid = (left + right) / 2;

        if(logs[mid].key <= key){
            resultado = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return resultado;
}

#endif