#include <iostream>
#include <vector>
using namespace std;
//orden o(n)
int iterative(vector<int>&list){
    int suma=0;
    for(int i=0;i<list.size();i++){
        if(list[i]%2!=0){
           suma+= list[i];
        };
    }  return suma;
}

//orden o(n)
int recursive(vector<int>&list, int pos){
    if(pos>=list.size()){
         return 0;  
    }
    if(list[pos]%2!=0){
        return list[pos] + recursive(list,pos+1);
    }
    return recursive(list,pos+1);
}

int main(){
    vector<int>list={1,2,3,4,5,6,7,8,9,10};
    cout<<iterative(list)<<endl;
    cout<<recursive(list,0)<<endl;
    return 0;
    
}