#include <stdio.h>
#include <stdlib.h>



typedef struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
}nodo;

typedef nodo *arbol;
void clavemax(arbol a, int max, int nivelact, int *nivel, int *clavem);
void addnodo(arbol *a,int dato);
int main(){
    arbol a;
    addnodo(&a,3);
    addnodo(&a->izq,5);
    addnodo(&a->der,5);
    addnodo(&a->der->izq,10);
    addnodo(&a->der->izq->izq,8);
    addnodo(&a->der->izq->izq->der,9);
    int nivel = 0;
    int clavem = 0;
    clavemax(a,0,0,&nivel,&clavem);
    printf("%d %d",clavem,nivel);
    return 0;
}


void addnodo(arbol *a,int dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->der = NULL;
    (*a)->izq = NULL;
}
void clavemax(arbol a, int max, int nivelact, int *nivel, int *clavem){
    if (a != NULL){
        if (a->izq == NULL){
            if ((a->dato) > (*clavem)){
                *clavem = a->dato;
                *nivel = nivelact;
            }
        }
        clavemax(a->der,max,nivelact+1,nivel,clavem);
        clavemax(a->izq,max,nivelact+1,nivel,clavem);
    }
}