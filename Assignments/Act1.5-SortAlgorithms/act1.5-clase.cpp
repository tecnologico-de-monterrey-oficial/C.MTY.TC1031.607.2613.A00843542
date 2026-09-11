#include <iostream>
#include <vector>

using namespace std;

// // SWAP SORT
// /* 
// template<typename T>
// void swap(vector<T>& list, int i, int j){

//     // creamos una variable temporal
//     T aux = list[i];

//     // cambiamos i por j
//     list[i] = list[j];

//     // cambiamos j por aux
//     list[j] = aux;
// }

// template<typename Y>
// void swapSort(vector<Y>& list){

//     for(int i = 0; i < list.size() - 1; i++){

//         for(int j = i + 1; j < list.size(); j++){

//             if(list[j] < list[i]){

//                 // si es menor
//                 // intercambiamos los valores
//                 swap(list, i, j);
//             }
//         }
//     }
// }


// // BUBBLE SORT

// template<typename T>
// void bubbleSort(vector<T>& list){

//     // definimos un booleano como verdadero
//     bool change = true;

//     // iterar desde n hasta 1
//     for(int i = list.size() - 1; i > 0 && change; i--){

//         // cambiamos el valor de change a falso
//         change = false;

//         // iteramos desde 0 hasta que sea menor que i
//         for(int j = 0; j < i; j++){

//             // comparamos j con j+1
//             if(list[j] > list[j+1]){

//                 // si es mayor
//                 // cambiamos change a verdadero
//                 change = true;

//                 // intercambiamos los valores
//                 swap(list, j, j+1);
//             }
//         }
//     } */
// //}

template<typename T>
void selectionSort(vector<T>& list){
    //iteremos toda la lista desde el principio hasta uno ances del final
    for(int i=0;i<list.size()-1;i++){
        //iteramos donde el siguiente índice hasta el final
        int min=i;
        //iteramos desde el sig indice hasta el final
        for(int j=i+1;j<list.size();j++){
            //comparamos el valor de j contra el min 
            if(list[j]<list[min]){
                //si es menir
                //actualizamos el valor de min
                min=j;
            }
        }

        swap(list[i],list[min]);
    }
}

template<typename T>
void insertionSort(vector<T>& list){
    //el primero asumimos que ya está ordenado
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

template<typename T>
void quickSort(vector<T>& arr, int left, int right){
    //se ejecuta la recursividad si left<right
    if(low<high){
        int pi=partition(arr,left,right);
        //ordenamos la lista del lado izq de pivote
        quickSort(arr,left,pi-1);
        //ordenamos la lista del lado del pivote
        quickSort(arr,pi+1,right);
    }
}
template <typename T>
int getPivot( vector<T>&arr, int left, int right){
    //creamos una variable auxiliar cin el valor de left -1
    int aux=left-1;
    //creamos una variable pvot con el valor de right
    int pivot=right;
    for(int i=left;i<pivot;i++){
        if(list[pivot]>list[i]){
            //incrementamos el valor de i
            aux++;
            //intercambiamos aux con i
            swap(arr,aux,i);

        }
    }
    //incrementamos  aux 
    aux++;
    //intercambiamos aux con pivot
    swap(list,aux,pivot);
    //regresamos aux
    return aux;
}

template <typename T>
void merge(vector<T>&list, int left,int mid, int right){
    //generamos la lista de left a mid
    //creamos una lista para los valores del lazo izquiero
    //generamos la lista de mid+1 a right
    vector<T>leftlist;
    for(int i=left;i<=mid;i++){
        leftList.push_back(list[i]);
    }
    vector<T>rightlist;
    for(int i=left;i<=mid;i++){
        rightlist.push_back(list[i]);
    }
    
}


template <typename T>
void mergeSort(vector<T>&list, int left,int right){
    //la condicion de control ess que left <right
    if(left<right){
        //calculamos mid
        int mid=(left+right)/2;
        //ordenamos de left a mid (separamos)
        mergeSort(list,left,mid);
        //ordeamos de mid+1 a right
        mergeSort (list,mid+1,right);
        //combinamso las dos partes de la lista
        merge(list,left,mid,right);

    }
}





int main(){
    vector<int> list={15,7,3,9,12,5,2};
    vector<int> listOriginal=list;

    cout<<"Selection Sort:"<<endl;
    cout<<listOriginal<<endl;
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