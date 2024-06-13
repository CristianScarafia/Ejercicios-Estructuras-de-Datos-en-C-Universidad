#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
}nodo;

typedef nodo *arbol;
arbol mayor(arbol a, int k, arbol aux);
void addnodo(arbol *a,int dato);

int main(){
    arbol a, m;
    int k = 2;
    addnodo(&a,8);
    addnodo(&a->izq,3);
    addnodo(&a->der,10);
    addnodo(&a->der->der,14);
    addnodo(&a->der->der->izq,13);
    addnodo(&a->izq->izq,1);
    addnodo(&a->izq->der,6);
    addnodo(&a->izq->der->izq,4);
    addnodo(&a->izq->der->der,7);

    m = mayor(a,k,NULL);
    printf("%d",m->dato);
    return 0;
}
void addnodo(arbol *a,int dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->der = NULL;
    (*a)->izq = NULL;
}
arbol mayor(arbol a, int k, arbol aux){
    if (a == NULL){
        return NULL;
    }else{
        if (a->dato == k){
            return a;
        }else{
            if (a->dato < k){
                if (a->der == NULL){
                    return a;
                }else{
                    aux = a;
                    return mayor(a->der,k,aux);
                }
            }else{
                if (a->izq == NULL){
                    return aux;
                }else{
                    return mayor(a->izq, k, aux);
                }
            }
        }
    }





}