#include <iostream>
using namespace std;
//binary search and sequencial search

int secuencial(int n){
    for(int i=0;i<n;i++){
        if(list[i]==n){
            return i;
        }
        return 0;
    }
}
int binaria (int n){
    int left=0;
    int right=0;
    int mid= (right+left)/2;
    for (int i=0;i<=n;i++){
        if(list[i]>n){
            left=mid+1;
        }
        else(list[i]<n){
            right=mid-1;
        }
        }
    }
    return i;
};

//Busqueda Secuencial
int seqSearch(vector<int>&list, int data){
    for(int i=0;i<list.size();i++){
        if(list[i]==data){
            return i;
        }
    }
    throw out_of_range("no se ecncontró el valor;");
}

//Busqueda BinARIA (La lista ya está ordenada)
template<typename Y>
int binSearch(vector<T> &list, T data){
    obtenemos left
    int left=0;
    //obtenemos right
    int right=list.size()-1;
    //buscamos el elemento mientras left<=right
    while(left<=right){
        //obtenemos la mitad
        int mid=(left+right)/2;
        //comparamos el valor buscando con el valor de la mitad
        if(data==list[mid]{
            //regresamos el valor de mid que es el índice del valor encontrado
            return mid;
        }else{
            //preguntamos si el valor buscado es menor que el valor de mid
            if(data<list[mid]){
                //si es menor
                right=mid-1;
            }else{
                //es mayot
                left=mid+1;
            }
        }
        
    }
    //no lo enocntramos
    throw out_of_range("no se encontró el valor");

}

int main(){
    vector<int>list={3,5,6,8,11,12,13,16,27,35};
    try{
        int index=binarySearch(list,14);
        cout<<"El valor se encuentra en: "<<index<<endl;
    }catch(const out_of_range& e){
        cout<<e.what()<<endl;
    }
    return 0;

    }
    algoritmo de ordenamiento