#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
}nodo;

typedef nodo *arbol;
void addnodo(arbol *a, int dato);
int analiza(arbol a);

int main(){
    arbol a = NULL;
    printf("%d",analiza(a));
}

void addnodo(arbol *a, int dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->der = NULL;
    (*a)->izq = NULL;
}

int analiza(arbol a){
    arbol aux;
    int bandera = 1;
    if (a == NULL){
        return 0;
    }else{
        if (a->izq != NULL){
            aux = a->izq;
            while (aux != NULL && bandera){
                if (aux->dato > aux->der->dato || ((aux->dato)*-1) < aux->der->dato){
                    bandera = 0;
                }
                aux = aux->der;
            }
            if (bandera){
                return 1;
            }else{
                return analiza(a->izq) + analiza(a->der);
            }
        }
    }
}