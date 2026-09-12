#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template<typename T>
void swap(vector<T> &list, int i, int j){
    if(i!=j){
        T aux=list[i];
        list[i]=list[j];
        list[j]=aux;
    }
}

// SWAP SORT
template<typename T>
void swapSort(vector<T> &list, long long &comparaciones, long long &intercambios){
    comparaciones=0;
    intercambios=0;

    for(int i=0;i<list.size()-1;i++){
        for(int j=i+1;j<list.size();j++){
            comparaciones++;

            if(list[j]<list[i]){
                swap(list,i,j);
                intercambios++;
            }
        }
    }
}

// BUBBLE SORT
template<typename T>
void bubbleSort(vector<T> &list, long long &comparaciones, long long &intercambios){
    comparaciones=0;
    intercambios=0;

    bool change=true;

    for(int i=list.size()-1;i>0 && change;i--){
        change=false;

        for(int j=0;j<i;j++){
            comparaciones++;

            if(list[j]>list[j+1]){
                change=true;
                swap(list,j,j+1);
                intercambios++;
            }
        }
    }
}

// SELECTION SORT
template<typename T>
void selectionSort(vector<T> &list, long long &comparaciones, long long &intercambios){
    comparaciones=0;
    intercambios=0;

    for(int i=0;i<list.size()-1;i++){
        int min=i;

        for(int j=i+1;j<list.size();j++){
            comparaciones++;

            if(list[j]<list[min]){
                min=j;
            }
        }

        if(min!=i){
            swap(list,min,i);
            intercambios++;
        }
    }
}

// INSERTION SORT
template<typename T>
void insertionSort(vector<T> &list, long long &comparaciones, long long &intercambios){
    comparaciones=0;
    intercambios=0;

    for(int i=1;i<list.size();i++){
        bool exit=false;

        for(int j=i;j>0 && !exit;j--){
            comparaciones++;

            if(list[j]<list[j-1]){
                swap(list,j,j-1);
                intercambios++;
            }
            else{
                exit=true;
            }
        }
    }
}

// QUICK SORT
template<typename T>
int getPivot(vector<T> &list, int left, int right){
    int aux=left-1;
    int pivot=right;

    for(int i=left;i<pivot;i++){
        if(list[pivot]>list[i]){
            aux++;
            swap(list,aux,i);
        }
    }

    aux++;
    swap(list,aux,pivot);

    return aux;
}

template<typename T>
void quickSort(vector<T> &list, int left, int right){
    if(left<right){
        int pivot=getPivot(list,left,right);

        quickSort(list,left,pivot-1);
        quickSort(list,pivot+1,right);
    }
}

// MERGE SORT
template<typename T>
void merge(vector<T> &list, int left, int mid, int right){
    vector<T> leftList;

    for(int i=left;i<=mid;i++){
        leftList.push_back(list[i]);
    }

    vector<T> rightList;

    for(int j=mid+1;j<=right;j++){
        rightList.push_back(list[j]);
    }

    int index=left;
    int i=0;
    int j=0;

    while(i<leftList.size() && j<rightList.size()){
        if(leftList[i]<rightList[j]){
            list[index]=leftList[i];
            i++;
        }
        else{
            list[index]=rightList[j];
            j++;
        }

        index++;
    }

    while(i<leftList.size()){
        list[index]=leftList[i];
        i++;
        index++;
    }

    while(j<rightList.size()){
        list[index]=rightList[j];
        j++;
        index++;
    }
}

template<typename T>
void mergeSort(vector<T> &list, int left, int right){
    if(left<right){
        int mid=(left+right)/2;

        mergeSort(list,left,mid);
        mergeSort(list,mid+1,right);

        merge(list,left,mid,right);
    }
}

// IMPRIMIR VECTOR
template<typename T>
void print(vector<T> &list){
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<" ";
    }

    cout<<endl;
}

// SHELL SORT
template<typename T>
void shellSort(vector<T> &list){
    int n=list.size();

    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            T temp=list[i];
            int j=i;

            while(j>=gap && list[j-gap]>temp){
                list[j]=list[j-gap];
                j-=gap;
            }

            list[j]=temp;
        }
    }
}

vector<int> generarInt(int n){
    vector<int> list;

    for(int i=0;i<n;i++){
        list.push_back(rand()%100000+1);
    }

    return list;
}

vector<double> generarDouble(int n){
    vector<double> list;

    for(int i=0;i<n;i++){
        double numero=(rand()%100000+1)/100.0;
        list.push_back(numero);
    }

    return list;
}

vector<char> generarChar(int n){
    vector<char> list;

    for(int i=0;i<n;i++){
        char letra='A'+rand()%26;
        list.push_back(letra);
    }

    return list;
}

template<typename T>
long long medirTiempo(vector<T> list, int algoritmo){
    long long comparaciones=0;
    long long intercambios=0;

    auto inicio=chrono::high_resolution_clock::now();

    if(algoritmo==1){
        swapSort(list,comparaciones,intercambios);
    }
    else if(algoritmo==2){
        bubbleSort(list,comparaciones,intercambios);
    }
    else if(algoritmo==3){
        selectionSort(list,comparaciones,intercambios);
    }
    else if(algoritmo==4){
        insertionSort(list,comparaciones,intercambios);
    }
    else if(algoritmo==5){
        mergeSort(list,0,list.size()-1);
    }
    else if(algoritmo==6){
        quickSort(list,0,list.size()-1);
    }
    else if(algoritmo==7){
        shellSort(list);
    }

    auto fin=chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(fin-inicio).count();
}

int main(){

    vector<int> int1000;
    vector<int> int10000;
    vector<int> int100000;

    vector<double> double1000;
    vector<double> double10000;
    vector<double> double100000;

    vector<char> char1000;
    vector<char> char10000;
    vector<char> char100000;

    bool listasCreadas=false;
    int opcion;

    do{
        cout<<endl;
        cout<<"========== MENU =========="<<endl;
        cout<<"1. Crear listas"<<endl;
        cout<<"2. Swap Sort"<<endl;
        cout<<"3. Bubble Sort"<<endl;
        cout<<"4. Selection Sort"<<endl;
        cout<<"5. Insertion Sort"<<endl;
        cout<<"6. Merge Sort"<<endl;
        cout<<"7. Quick Sort"<<endl;
        cout<<"8. Shell Sort"<<endl;
        cout<<"9. Generar listado de tiempos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        if(opcion==1){

            int1000=generarInt(1000);
            int10000=generarInt(10000);
            int100000=generarInt(100000);

            double1000=generarDouble(1000);
            double10000=generarDouble(10000);
            double100000=generarDouble(100000);

            char1000=generarChar(1000);
            char10000=generarChar(10000);
            char100000=generarChar(100000);

            listasCreadas=true;

            cout<<endl;
            cout<<"Listas creadas correctamente"<<endl;
        }

        else if(opcion>=2 && opcion<=8){

            if(!listasCreadas){
                cout<<endl;
                cout<<"Primero debes crear las listas con la opcion 1."<<endl;
            }

            else{
                int tipo;
                int tamano;

                cout<<endl;
                cout<<"Tipo de dato:"<<endl;
                cout<<"1. int"<<endl;
                cout<<"2. double"<<endl;
                cout<<"3. char"<<endl;
                cout<<"Opcion: ";
                cin>>tipo;

                cout<<endl;
                cout<<"Tamano de la lista:"<<endl;
                cout<<"1. 1000"<<endl;
                cout<<"2. 10000"<<endl;
                cout<<"3. 100000"<<endl;
                cout<<"Opcion: ";
                cin>>tamano;

                long long comparaciones=0;
                long long intercambios=0;

                if(tipo==1){

                    vector<int> list;

                    if(tamano==1){
                        list=int1000;
                    }
                    else if(tamano==2){
                        list=int10000;
                    }
                    else{
                        list=int100000;
                    }

                    auto inicio=chrono::high_resolution_clock::now();

                    if(opcion==2){
                        swapSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==3){
                        bubbleSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==4){
                        selectionSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==5){
                        insertionSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==6){
                        mergeSort(list,0,list.size()-1);
                    }
                    else if(opcion==7){
                        quickSort(list,0,list.size()-1);
                    }
                    else if(opcion==8){
                        shellSort(list);
                    }

                    auto fin=chrono::high_resolution_clock::now();

                    auto tiempo=
                    chrono::duration_cast<chrono::nanoseconds>(fin-inicio);

                    cout<<endl;
                    cout<<"Lista ordenada:"<<endl;
                    print(list);

                    cout<<"Tiempo: "<<tiempo.count()<<" nanosegundos"<<endl;

                    if(opcion>=2 && opcion<=5){
                        cout<<"Comparaciones: "<<comparaciones<<endl;
                        cout<<"Intercambios: "<<intercambios<<endl;
                    }
                }

                else if(tipo==2){

                    vector<double> list;

                    if(tamano==1){
                        list=double1000;
                    }
                    else if(tamano==2){
                        list=double10000;
                    }
                    else{
                        list=double100000;
                    }

                    auto inicio=chrono::high_resolution_clock::now();

                    if(opcion==2){
                        swapSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==3){
                        bubbleSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==4){
                        selectionSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==5){
                        insertionSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==6){
                        mergeSort(list,0,list.size()-1);
                    }
                    else if(opcion==7){
                        quickSort(list,0,list.size()-1);
                    }
                    else if(opcion==8){
                        shellSort(list);
                    }

                    auto fin=chrono::high_resolution_clock::now();

                    auto tiempo=
                    chrono::duration_cast<chrono::nanoseconds>(fin-inicio);

                    cout<<endl;
                    cout<<"Lista ordenada:"<<endl;
                    print(list);

                    cout<<"Tiempo: "<<tiempo.count()<<" nanosegundos"<<endl;

                    if(opcion>=2 && opcion<=5){
                        cout<<"Comparaciones: "<<comparaciones<<endl;
                        cout<<"Intercambios: "<<intercambios<<endl;
                    }
                }

                else if(tipo==3){

                    vector<char> list;

                    if(tamano==1){
                        list=char1000;
                    }
                    else if(tamano==2){
                        list=char10000;
                    }
                    else{
                        list=char100000;
                    }

                    auto inicio=chrono::high_resolution_clock::now();

                    if(opcion==2){
                        swapSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==3){
                        bubbleSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==4){
                        selectionSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==5){
                        insertionSort(list,comparaciones,intercambios);
                    }
                    else if(opcion==6){
                        mergeSort(list,0,list.size()-1);
                    }
                    else if(opcion==7){
                        quickSort(list,0,list.size()-1);
                    }
                    else if(opcion==8){
                        shellSort(list);
                    }

                    auto fin=chrono::high_resolution_clock::now();

                    auto tiempo=
                    chrono::duration_cast<chrono::nanoseconds>(fin-inicio);

                    cout<<endl;
                    cout<<"Lista ordenada:"<<endl;
                    print(list);

                    cout<<"Tiempo: "<<tiempo.count()<<" nanosegundos"<<endl;

                    if(opcion>=2 && opcion<=5){
                        cout<<"Comparaciones: "<<comparaciones<<endl;
                        cout<<"Intercambios: "<<intercambios<<endl;
                    }
                }

                else{
                    cout<<"Tipo de dato invalido"<<endl;
                }
            }
        }

        else if(opcion==9){

            if(!listasCreadas){
                cout<<endl;
                cout<<"Primero debes crear las listas con la opcion 1."<<endl;
            }

            else{
                string nombres[7]={
                    "Swap Sort",
                    "Bubble Sort",
                    "Selection Sort",
                    "Insertion Sort",
                    "Merge Sort",
                    "Quick Sort",
                    "Shell Sort"
                };

                cout<<endl;
                cout<<"algoritmo, tipo de dato, tiempo1000, tiempo10000, tiempo100000"<<endl;

                for(int algoritmo=1;algoritmo<=7;algoritmo++){

                    long long tiempo1000;
                    long long tiempo10000;
                    long long tiempo100000;

                    tiempo1000=medirTiempo(int1000,algoritmo);
                    tiempo10000=medirTiempo(int10000,algoritmo);
                    tiempo100000=medirTiempo(int100000,algoritmo);

                    cout<<nombres[algoritmo-1]<<", int, "
                        <<tiempo1000<<", "
                        <<tiempo10000<<", "
                        <<tiempo100000<<endl;

                    tiempo1000=medirTiempo(double1000,algoritmo);
                    tiempo10000=medirTiempo(double10000,algoritmo);
                    tiempo100000=medirTiempo(double100000,algoritmo);

                    cout<<nombres[algoritmo-1]<<", double, "
                        <<tiempo1000<<", "
                        <<tiempo10000<<", "
                        <<tiempo100000<<endl;

                    tiempo1000=medirTiempo(char1000,algoritmo);
                    tiempo10000=medirTiempo(char10000,algoritmo);
                    tiempo100000=medirTiempo(char100000,algoritmo);

                    cout<<nombres[algoritmo-1]<<", char, "
                        <<tiempo1000<<", "
                        <<tiempo10000<<", "
                        <<tiempo100000<<endl;
                }
            }
        }

        else if(opcion!=0){
            cout<<"Opcion invalida"<<endl;
        }

    }while(opcion!=0);

    return 0;
}