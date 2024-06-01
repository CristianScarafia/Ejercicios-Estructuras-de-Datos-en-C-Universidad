#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct nodo{
    int dato;
    struct nodo *der;
    struct nodo *izq;
}nodo;

typedef nodo *arbol;
void addnodo(arbol *a, int dato);
int fhojas0(arbol a);
int fgrado3(arbol a);
void informe(arbol a);

int main(){

    arbol a;
    addnodo(&a,1);
    addnodo(&a->izq,0);
    addnodo(&a->izq->der,1);
    addnodo(&a->izq->der->der,1);
    addnodo(&a->izq->der->izq,0);
    addnodo(&a->izq->der->izq->der,1);
    addnodo(&a->izq->der->izq->der->der,1);
    addnodo(&a->der,1);
    addnodo(&a->der->der,1);
    addnodo(&a->der->der->der,1);
    addnodo(&a->der->der->der->izq,0);
    addnodo(&a->der->der->der->izq->der,1);
    addnodo(&a->der->der->der->izq->der->der,1);
    informe(a);
    return 0;
}

void addnodo(arbol *a, int dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
void informe(arbol a){
    int hojas0, grado3, cont=0;
    printf("Arbol | Cantidad de hojas calve 0\n");
    while (a != NULL){
        cont++;
        hojas0 = fhojas0(a->izq);
        grado3 = fgrado3(a);
        if (hojas0 > 0 && grado3 > 0){
            printf("%d          %d\n",cont,hojas0);
        }
        a = a->der;
    }
}
int fhojas0(arbol a){
    if (a != NULL){
        if (a->izq == NULL && a->dato == 0){
            return 1 + fhojas0(a->der);
        }else{
            return fhojas0(a->izq) + fhojas0(a->der);
        }
    }else{
        return 0;
    }
}
int fgrado3(arbol a){
    int cont = 0;
    if (a != NULL){
        if (a->izq != NULL){
            a = a->izq;
            while (a != NULL && cont > 3){
                cont++;
                a = a->der;
            }
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}