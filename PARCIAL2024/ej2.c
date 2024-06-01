
#include <TDANARIO.h>;
#include <stdio.h>

int main(){
    arbol a;
    inicializararbol(&a);
    posicion p = raiz(a);

    printf("%d",analiza(a,p));
    return 0;
}

int analiza(arbol a, posicion p, int k, int nivelact){
    arbol c = p;
    if (!Nulo(p)){
        if (nivelact < k){
            if (grado(a,c) > 2 && secuenciahijos(a,c)){
                return 1;
            }else{
                return analiza(a,hermanoder(p,a),k,nivelact) + analiza(a,hijomasizq(p,a),k,nivelact+1);
            }
        }else{
            return 0;
        } 
    }else{
        return 0;
    }

}

int grado(arbol a, posicion p){
    int cont = 0;
    pocicion c = hijomasizq(p,a);
    while (!Nulo(C) && cont < 2){
        cont++;
        c = hermanoder(c,a);
    }
}

int secuenciahijos(arbol a, posicion p){
    arbol c;
    int bandera = 1;
    if (!Nulo(p)){
        c = hijomasizq(p,a);
        while (!Nulo(c) && (bandera == 1)){
            if (Info(c) < Info(hermanoder(c,a))){
                c = hermanoder(c,a);
            }else{
                bandera = 0;
            }
        }
        return bandera;
    }else{
        return 0;
    }
}