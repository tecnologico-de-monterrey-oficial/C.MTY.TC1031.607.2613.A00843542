int iterative(vector<int>&list){
    int suma=0;
    for(int i=0;i<list.size();i++){
        if(list[i]%2!=0){
           suma+= list[i]+list[i+1];
        };
}  return suma;

}

int main(){
    vector<int>list={1,2,3,4,5,6,7,8,9,10};
    iterative();
}