#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo{
    char dato;
    struct nodo *izq;
    struct nodo *der;
}nodo;

typedef nodo *arbol;
void addnodo(arbol *a, char dato);
int recorre(arbol a, int k);
int analiza(arbol a, int k);
int grado(arbol a);
int todasvocales(arbol a);
int esvocal(char dato);
void muestraarbol(arbol a);

int main(){
    int k;
    arbol a;
    addnodo(&a,'F');
    addnodo(&a->izq,'A');
    addnodo(&a->izq->izq,'A');
    addnodo(&a->izq->izq->der,'A');
    addnodo(&a->izq->der,'A');
    addnodo(&a->izq->der->izq,'A');
    addnodo(&a->izq->der->izq->der,'A');
    addnodo(&a->izq->der->izq->der->der,'A');
    addnodo(&a->izq->der->der,'A');
    addnodo(&a->izq->der->der->izq,'A');
    addnodo(&a->der,'F');
    addnodo(&a->der->izq,'A');
    addnodo(&a->der->izq->der,'A');
    addnodo(&a->der->izq->der->der,'A');


    printf("ingrese k: \n");
    scanf("%d",&k);
    if(recorre(a,k)){
        printf("existen.");
    }else{
        printf("no existen.");
    }

    return 0;
}

void addnodo(arbol *a, char dato){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = dato;
    (*a)->der = NULL;
    (*a)->izq = NULL;
}

void muestraarbol(arbol a){
    if (a != NULL){
        printf("%c",a->dato);
        muestraarbol(a->izq);
        muestraarbol(a->der);
    }
}

int recorre(arbol a, int k){
    int cont = 0;
    while (a != NULL && cont < 2){
        if(analiza(a,k)){
            cont++;
        }
        a = a->der;
    }
    if (cont == 2){
        return 1;
    }else{
        return 0;
    }
}
int analiza(arbol a, int k){
    if (a != NULL){
        if (grado(a) == k && todasvocales(a)){
            return 1;
        }else{
            return analiza(a->izq,k) + analiza(a->der,k);
        }
    }else{
        return 0;
    }
}

int grado(arbol a){
    a = a->izq;
    int cont = 0;
    if (a != NULL){
        while (a != NULL){
            cont++;
            a = a->der;
        }
        return cont;
    }else{
        return 0;
    }
}
int todasvocales(arbol a){
    a = a->izq;
    if (a != NULL){
        while (a != NULL){
            if (!esvocal(a->dato)){
                return 0;
            }else{
                a = a->der;
            }
        }
        return 1;
    }else{
        return 0;
    }
}
int esvocal(char dato){
    if (dato == 'A' || dato == 'E' || dato == 'I' || dato == 'O' || dato == 'U'){
        return 1;
    }else{
        return 0;
    }
}
