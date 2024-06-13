#include "tdanario.h"
#include <string,h>




typedef struct nodo *nodo;
int main(){


}


typedef struct nodos{
    int dato;
    char cadena[20];
}nodos;

int verifica(arbol a, posicion p, int k, int nivelact){
    int cont = 0, aux = 0, contvocales, i, tamanio;
    string cadena;

    nodos nodo = info(p);

    if(Nulo(p)){
        return 0;
    }
    
    if (nivelact % 2 == 0){
        contvocales = 0;
        strcpy(cadena, nod->cadena);
        tamanio = strlen(nod->cadena);
        while (i<tamanio && contvocales <= nod->dato){
            i++;
            if (cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U'){
                contvocales++;
            }
        }
        if (contvocales == nod->cadena){
            cont++;
            aux = 1;
        }
        c = hijomasizq(p,A);
        while (!Nulo(C) && aux < k){
            aux = verifica(a,c,k,nivelact+1);
            if (aux){
                cont++;
            }
            c = hermanoder(c,A);
        }
        return aux;
    }
}