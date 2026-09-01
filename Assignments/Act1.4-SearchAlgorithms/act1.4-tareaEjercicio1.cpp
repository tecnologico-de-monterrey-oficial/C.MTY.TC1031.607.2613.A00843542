#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>

using namespace std;

bool secuencial(vector<int>& list, int n){
    for(int i=0;i<list.size();i++){
        if(list[i]==n){
            return true;
        }
    }
    return false;
}

bool binaria(vector<int>& list, int n){
    int left=0;
    int right=list.size()-1;

    while(left<=right){
        int mid=(left+right)/2;

        if(list[mid]==n){
            return true;
        }

        if(n<list[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return false;
}

int main(){
    int n;
    vector<int> list;

    for(int i=0;i<10000;i++){
        list.push_back(rand()%1000000+1);
    }

    sort(list.begin(),list.end());

    do{
        cout<<"Escribe un numero entre 1 y 1,000,000 (0 para salir): ";
        cin>>n;

        if(n!=0){
            auto inicioSec=chrono::high_resolution_clock::now();
            bool resultadoSec=secuencial(list,n);
            auto finSec=chrono::high_resolution_clock::now();
            auto tiempoSec=chrono::duration_cast<chrono::nanoseconds>(finSec-inicioSec);

            auto inicioBin=chrono::high_resolution_clock::now();
            bool resultadoBin=binaria(list,n);
            auto finBin=chrono::high_resolution_clock::now();
            auto tiempoBin=chrono::duration_cast<chrono::nanoseconds>(finBin-inicioBin);

            if(resultadoSec){
                cout<<n<<" si esta en la lista"<<endl;
            }
            else{
                cout<<n<<" no esta en la lista"<<endl;
            }

            cout<<"Tiempo busqueda secuencial: "<<tiempoSec.count()<<" nanosegundos"<<endl;
            cout<<"Tiempo busqueda binaria: "<<tiempoBin.count()<<" nanosegundos"<<endl;
        }

    }while(n!=0);

    return 0;
}


