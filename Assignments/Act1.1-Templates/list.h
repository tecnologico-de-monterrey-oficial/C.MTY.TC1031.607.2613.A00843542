#ifndef LIST_H // instruccion para el compilador
#define LIST_H

#include<vector>
#include <iostream>
using namespace std;

template<typename T> //
class List{
private:
//atributos
 vector<T>list;
    int size;
public:
//constructor
    List();
//metodos

    void insert(T data);
    void removeLast();
    
    T getData(int pos);
    int getSize();
    T getMax();

    void print();

    void insertAt(int pos, T valor);
    void removeAt(int pos);
};

//inicializar constructor
template<typename T>
List<T>::List(){
    size=0;
}

//definir metodos
template<typename T>
void List<T>:: insert(T data){
    list.push_back(data);
    size++;
}

template<typename T>
void List<T>::removeLast(){
    if(size > 0){
        cout << "el ultimo elemento de la lista es: " << list[size-1]<<endl;
        list.pop_back();
        size--;
    }
    else{
        cout << "No hay elementos";
    }
}

template<typename T>
T List<T>::getData(int pos){
        return list[pos];
}

template <typename T>
int List<T>::getSize(){
    return size;
}

template<typename T>
T List<T>::getMax(){
    T max= list[0];
    for(int i =0; i<size;i++){
        if(list[i]>max){
            max=list[i];
        }
    }
    return max;
}

template<typename T>
void List<T>::print(){
    for(int i=0;i<size;i++){
        cout<<"["<<i<<"]"<<" - "<<list[i]<<endl;
    }
}

template<typename T>
void List<T>::insertAt( int pos, T valor){
    if(pos >= 0 && pos <= size){
        list.push_back(valor);
        for(int i=size; i>pos;i--){
        list[i]=list[i-1];
    }
    list[pos]=valor;
    size++;     
}
else{
    cout << "POSICION INVALIDA";
}
}

template<typename T>
void List<T>::removeAt(int pos){

    if(size == 0){
        cout << "NO HAY ELEMENTOS";
    }
    else if(pos >= 0 && pos < size){
        cout << list[pos]<<endl;

        for(int i = pos; i < size-1; i++){
            list[i] = list[i+1];
        }

        list.pop_back();
        size--;
    }
    else{
        cout << "POSICION INVALIDA";
    }
}

#endif // LIST_H