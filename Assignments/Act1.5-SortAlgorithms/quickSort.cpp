#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    vector<int> arr;
    int n;
    int numero;

    cout<<"Cuantos numeros quieres ordenar? ";
    cin>>n;

    cout<<"Ingresa los numeros:"<<endl;

    for(int i=0;i<n;i++){
        cin>>numero;
        arr.push_back(numero);
    }

    cout<<"Lista original:"<<endl;

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    quickSort(arr,0,arr.size()-1);

    cout<<"Lista ordenada:"<<endl;

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}