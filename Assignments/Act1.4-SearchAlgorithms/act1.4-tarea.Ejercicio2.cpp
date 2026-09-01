#include <iostream>
#include <string>
using namespace std;

char secuencial(string texto, int &comparaciones){
    int comp=0;
    for(int i=0;i<texto.size()-1;i+=2){
        comp++;
        if(texto[i]!=texto[i+1]){
            comparaciones=comp;
            return texto[i];
        }
    }
    comparaciones=comp;
    return texto[texto.size()-1];
}

char binaria(string texto, int &comparaciones){
    int comp=0;
    int left=0;
    int right=texto.size()-1;
    int mid;
    while(left<right){
        mid=(left+right)/2;
        comp++;
        bool izquierda=(mid==0 || texto[mid]!=texto[mid-1]);
        bool derecha=(mid==texto.size()-1 || texto[mid]!=texto[mid+1]);
        if(izquierda && derecha){
            comparaciones=comp;
            return texto[mid];
        }
        if(mid%2==0){
            if(texto[mid]==texto[mid+1]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        else{
            if(texto[mid]==texto[mid-1]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    comparaciones=comp;
    return texto[left];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string texto;
        cin>>texto;
        int comparacionesSec=0;
        int comparacionesBin=0;
        char resultadoSec=secuencial(texto,comparacionesSec);
        char resultadoBin=binaria(texto,comparacionesBin);
        cout<<resultadoSec<<" "<<comparacionesSec<<" "<<resultadoBin<<" "<<comparacionesBin<<endl;
    }
    return 0;
}