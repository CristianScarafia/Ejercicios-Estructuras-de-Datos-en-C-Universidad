#include <tdanario.h>
#include <stdlib.h>

int analiza(arbol a, posicion p, int nivelact, int k);

int main(){

int k;
arbol a;
iniciararbol(&a);
posicion p;
p = raiz(a);

printf("cantidad de nodos que cumplen: %d",analiza(a,p,1,k));

}

int analiza(arbol a, posicion p, int nivelact, int k){
    if (a != NULL){
        if (!Nulo(p)){
            if (nivelact < k){
                return analiza(a,hermanoder(p,a),nivelact,k) + analiza(a,hijomasizq(p,a),nivelact+1,k);
            }else{
                if (todosmenores(a,p)){
                    return 1 + analiza(a,hermanoder(p,a),nivelact,k);
                }else{
                    return analiza(a,hermanoder(p,a),nivelact,k);
                }
            }
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int todosmenores(arbol a, posicion p){
    posicion c;
    int bandera = 1;
    if (a != NULL){
        if (!Nulo(p)){
            c = hijomasizq(p,a);
            while (!Nulo(c) && bandera == 1){
                if (info(c) > info(p)){
                    bandera = 0;
                }
                c = hermanoder(c,a);
            }
            return bandera;
        }else{
            return 0;
        }
    }else{
        return 0;
    }

}