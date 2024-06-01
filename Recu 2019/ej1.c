#include <stdio.h>
#include <stdlib.h>


int main(){
    /*arbol a;
    cargararbol (a);
    posicion p = raiz(a);
    */
    int k;
    printf("ingrese el nivel k:");
    scanf("%d",&k);
    printf("%d",k);

    int verifica = verif(a,p,k,1);
    if (verifica == 1){
        printf("todos los nodos en k tiene al menos dos hijos cuyas claves son vocales.");
    }else{
        printf("no todos los nodos en k tiene al menos dos hijos cuyas claves son vocales.");
    }
    return 0;
}

int verif(arbol a, posicion p, int k, int nivelact){
    posicion c;
    int cont;
    if (a == NULL){
        return 0;
    }else{
        if (k > nivelact){
            c = hijomasizq(p,a);
            return verif(a,c,k,nivelact+1);
        }else{
            if (k == nivelact){
                c = hijomasizq(p,a);
                cont = 0;
                while (c != NULL && cont<2){
                    if (esvocal(info(c,a))){
                        cont++;
                    }
                    c = hermanoder(c,a);
                }
                if (cont<2){
                    return 0;
                }else{
                    c = hermanoder(p,a);
                    if (Nulo(c)){
                        return 1;
                    }else{
                        return verif(a,c,k,nivelact);
                    }
                }
            }
        }
    }
}