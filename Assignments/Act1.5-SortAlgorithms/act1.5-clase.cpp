#include <iostream>
#include <vector>

using namespace std;

// SWAP SORT
/* 
template<typename T>
void swap(vector<T>& list, int i, int j){

    // creamos una variable temporal
    T aux = list[i];

    // cambiamos i por j
    list[i] = list[j];

    // cambiamos j por aux
    list[j] = aux;
}

template<typename Y>
void swapSort(vector<Y>& list){

    for(int i = 0; i < list.size() - 1; i++){

        for(int j = i + 1; j < list.size(); j++){

            if(list[j] < list[i]){

                // si es menor
                // intercambiamos los valores
                swap(list, i, j);
            }
        }
    }
}


// BUBBLE SORT

template<typename T>
void bubbleSort(vector<T>& list){

    // definimos un booleano como verdadero
    bool change = true;

    // iterar desde n hasta 1
    for(int i = list.size() - 1; i > 0 && change; i--){

        // cambiamos el valor de change a falso
        change = false;

        // iteramos desde 0 hasta que sea menor que i
        for(int j = 0; j < i; j++){

            // comparamos j con j+1
            if(list[j] > list[j+1]){

                // si es mayor
                // cambiamos change a verdadero
                change = true;

                // intercambiamos los valores
                swap(list, j, j+1);
            }
        }
    } */
//}

template<typename T>
void selectionSort(vector<T>& list){
    for(int i=0;i<list.size();i++){
        int min=i;

        for(int j=i+1;j<list.size();j++){
            if(list[j]<list[min]){
                min=j;
            }
        }

        swap(list[i],list[min]);
    }
}

template<typename T>
void insertionSort(vector<T>& list){
    for(int i=1;i<list.size();i++){
        T key=list[i];
        int j=i-1;

        while(j>=0 && list[j]>key){
            list[j+1]=list[j];
            j=j-1;
        }

        list[j+1]=key;
    }
}

int main(){
    vector<int> list={15,7,3,9,12,5,2};
    vector<int> listOriginal=list;

    cout<<"Selection Sort:"<<endl;

    selectionSort(list);

    for(int i=0;i<list.size();i++){
        cout<<list[i]<<" ";
    }

    cout<<endl;

    list=listOriginal;

    cout<<"Insertion Sort:"<<endl;

    insertionSort(list);

    for(int i=0;i<list.size();i++){
        cout<<list[i]<<" ";
    }

    cout<<endl;

    return 0;
}