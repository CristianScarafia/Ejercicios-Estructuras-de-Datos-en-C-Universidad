#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
}nodo;

typedef nodo *arbol;
void analiza(arbol a, int nivelact, int n, int *min);

int main(){
    arbol a;
    int n = 3;
    int min = 999;

    addnodo(&a,200);
    addnodo(&a->izq,200);
    addnodo(&a->izq->der,200);
    addnodo(&a->izq->der->der,200);
    addnodo(&a->izq->der->der->der,200);
    addnodo(&a->izq->der->der->der->izq,1);
    addnodo(&a->izq->der->der->izq,2);
    addnodo(&a->izq->der->izq,3);

    analiza(a,1,n,&min);
    printf("%d",min);
    return 0;
}

void addnodo(arbol *a,int dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->der = NULL;
    (*a)->izq = NULL;
}

void analiza(arbol a, int nivelact, int n, int *min){
    if (a != NULL){
        if (nivelact < n){
            if (a->izq != NULL){
                analiza(a->izq,nivelact+1,n,min);
            }
            if (a->der != NULL){
                analiza(a->der,nivelact,n,min);
            }
        }else{
            if (a->dato < *min){
                *min = a->dato;
            }
            if (a->der != NULL){
                analiza(a->der,nivelact,n,min);
            }
        }
    }
}
//prueba
