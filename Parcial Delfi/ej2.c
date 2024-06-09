#include "tdanario.h"
#include <stdio.h>





int main(){
    int k1;
    int k2;
    arbol a;
    posicion p;
    inicia_arbol(&a);
    p = raiz(a);
    analiza(a,p,k1,k2,0);
}

float analiza(arbol a, posicion p, int k1, int k2, int nivelact){
    if (!Nulo(p)){
        if (nivelact < k1){
            return analiza(a,hijomasizq(p,a),k1,k2,nivelact+1) + analiza(a,hermanoder(p,a),k1,k1,nivelact);
        }else{
            if (nivelact >= k1 && nivelact <= k2){
                return info(p,a) + analiza(a,hijomasizq(p,a),k1,k2,nivelact+1) + analiza(a,hermanoder(p,a),k1,k2,nivelact+1);
            }else{
                reutnr 0;
            }
        }
    }else{
        return 0;
    }
}