//Regina Mugica
//a00843642

#include <iostream>
using namespace std;

int sumItertuve (int n){
    int suma=0;
    for (int i=1;i<=n;i++){
        suma+=i;
    }
    return suma;
}

int sumRecursive(int n){
    if(n==1){
        return 1;
    }
    return n + sumRecursive(n-1);
}

int sumFormula(int n){
    return n*(n+1)/2;
}

int fibonacciIterative(int n){
    int a=1;
    int b=1;
    int c;
    for(int i=2;i<n;i++){
       c=a+b;
       a=b;
       b=c;
    }
    return b;
}

int fibonacciRecursive(int n){
    if(n<=2){
        return 1;
    }
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
 }


 int bacteriasIterative(int n){
    int bacteriasFinales=1;
    for(int i=0;i<n;i++){
        int nacimientos=bacteriasFinales*3.78;
        int fallecimientos= bacteriasFinales*2.34;
        bacteriasFinales=bacteriasFinales+nacimientos-fallecimientos;
    }
    return bacteriasFinales;
 }

int bacteriasRecursive(int n){
    if(n == 0){
        return 1;
    }
    int bacteria = bacteriasRecursive(n-1);
    int born = bacteria * 3.78;
    int died = bacteria * 2.34;

    return bacteria + born - died;
}

 float investmentIterative(int n, float cant){
    float interes=0.1875;
    for(int i=0;i<n;i++){
       cant+=(cant*interes);
    }
    return cant;
 }

 float investmentRecursive(int n, float cant){
    if(n==0){
        return cant;
    }
    float interes=0.1875;
    return investmentRecursive(n-1,cant+=(cant*interes));
 }

int powIterative(int n, int y){
    int resultado = 1;
    for(int i = 0; i < y; i++){
        resultado = resultado * n;
    }
    return resultado;
}

int powRecursive(int n,int y){
    if(y==1){
        return n;
    }
    return n*powRecursive(n,y-1);
}
 
int main(){
    //suma iterativa
    cout<<"La suma iterativa de 5 es: "<<sumItertuve(5)<<endl;
    //suma recursiva
     cout<<"La suma recursiva de 5 es: "<<sumRecursive(5)<<endl;
     //suma con formula
     cout<<"La suma con la formula de 5 es: "<<sumFormula(5)<<endl;
     //fibonacci Iterativa
     cout<<"La suma de fibonacci de 7 es: "<<fibonacciIterative(7)<<endl;
     // fibonacci Recursiva
     cout << "El fibonacci recursivo de 7 es: "<< fibonacciRecursive(7) << endl;
     //bacterias Iterative
     cout<<"Las bacterias finales son: "<< bacteriasIterative(5)<<endl;
     //bacterias Recursiva
     cout << "Las bacterias finales son: "<< bacteriasRecursive(5) << endl;
     //investment Iterative
     cout<<"El monto final después de 5 meses es: "<< investmentIterative(5,100)<<endl;
     //investment Recursive
     cout<<"El monto final después de 5 meses es: "<< investmentRecursive(5,100)<<endl;
     //power Iterative
     cout<<"3 elevado al cuadrado es: "<<powIterative(3, 2)<<endl;
     //power Recursive
     cout<<"3 elevado al cuadrado es: "<<powRecursive(3,2)<<endl;

     
    return 0;
}

