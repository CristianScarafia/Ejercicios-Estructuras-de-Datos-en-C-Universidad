#include <mysql.h>



int analiza(arbol a, posicion p, int nivel){

    int cont,bandera,nivelmax = 0;
    posicion c;
    if (p == NULL){
        return 0;
    }else{
        cont = 0;
        bandera = 0;
        c = hijomasizq(p,A);
        while (!Nulo(c) && cont <= 4){
            cont++;
            c = hermanoder(c,A);
        }
        if (cont == 4 && nivel > nivelmax){
            nivelmax = nivel;
        }else{
            c = hijomasizq(p,A);
            while (!Nulo(c) && band == 0){
                nivelmax = analiza(a,c,nivel+1);
                c = hermanoder(p,A);
            }
        }
        return nivelmax;
    }
}