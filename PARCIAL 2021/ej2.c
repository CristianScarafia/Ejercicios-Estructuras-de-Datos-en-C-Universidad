#include "tdanario.h"
#include <stdio.h>


int main(){
    arbol a;
    inicia_arbol(&a);
    posicion p;
    p = raiz(a);

    if(analiza(a)){
        printf("Existe.");
    }else{
        printf("No existe.");
    }   
}

int analiza(arbol a, posicion p){
    if (!Nulo(p)){
        if (comprueba(a,p)){
            return 1;
        }else{
            return analiza(a,hijomasizq(p,a)) + analiza(a,hermanoder(p,a));
        }
    }
}

int comprueba(arbol a, posicion p){
    posicion c;
    int cont = 0;
    int bandera = 0;
    if (!Nulo(p)){
        c = hijomasizq(p,a);
        while(!Nulo(c) && bandera == 0){
            cont++;
            if (info(c) < info(p)){
                bandera = 1;
            }
            c = hermanoder(c,a);
        }  
        if (cont>3 && bandera == 0){ 
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}