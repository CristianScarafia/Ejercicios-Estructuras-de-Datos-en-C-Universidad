#include <stdlib.h>
#include <stdio.h>
typedef struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
}nodo;

typedef nodo *arbol;
void addnodo(arbol *a, int dato);
//int analiza(arbol a, int nivelact, int k);
int grado(arbol a);
int analizadelf(arbol a, int nivelact, int k);
int main(){
    arbol a;
    int k = 3;
    addnodo(&a,1);
    addnodo(&a->izq,1);//1
    addnodo(&a->izq->der,1);
    addnodo(&a->izq->der->der,1);
    addnodo(&a->izq->der->der->izq,1);//2
    addnodo(&a->izq->der->der->izq->der,1);
    addnodo(&a->izq->der->der->izq->der->izq,1);//3
    addnodo(&a->izq->der->der->izq->der->izq->izq,1);
    addnodo(&a->izq->der->der->izq->der->izq->izq->der,1);
    addnodo(&a->izq->der->der->izq->der->izq->izq->der->der,1);
    printf("cantidad que cumplen: %d",analizadelf(a,0,k));
    return 0; 
}

void addnodo(arbol *a, int dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->der = NULL;
    (*a)->izq = NULL;
}


int analizadelf(arbol a, int nivelact, int k){
    if (a == NULL || nivelact != k){
        return analizadelf(a->der,nivelact,k) + analizadelf(a->izq,nivelact+1,k);
    }else{
        return grado(a) + analizadelf(a->der,nivelact,k) + analizadelf(a->izq,nivelact+1,k);
    }
}
/*int analiza(arbol a, int nivelact, int k){
    if (a != NULL){
        if (nivelact == k){
            if (grado(a)){
                return 1 + analiza(a->der,nivelact,k);
            }else{
                return analiza(a->der,nivelact,k);
            }
        }else{
            return analiza(a->der,nivelact,k) + analiza(a->izq,nivelact+1,k);
        }
    }else{
        return 0;
    }
}*/

int grado(arbol a){
    arbol aux;
    int cont = 0;
    if (a != NULL){
        if (a->izq != NULL){
            aux = a->izq;
            while (aux != NULL){
                cont++;
                aux = aux->der;
            }
            return cont;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}