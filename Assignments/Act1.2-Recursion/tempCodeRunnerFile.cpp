int investmentRecursive(int n, float cant){
    if(n==0){
        return cant;
    }
    float interes=0.1875;
    return cant+investmentRecursive(n-1,cant);
 }