#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void analiza(int mat[][4]);

int main(){
    int mat[4][4] = {
        {0,1,1,0},
        {0,1,0,1},
        {1,1,1,0},
        {0,0,1,1}
    };

    analiza(mat);
}

void analiza(int mat[][4]){
    int i,j;
    int max = 0;
    int cont = 0;
    int nodomax = 0;
    for (i=0;i<4;i++){
        for(j=0;i<4;j++){
            if (j != i){
                if(mat[j][i] == 1){
                    cont++;
                }
            }
        }
        if (cont > max){
            max = cont;
            nodomax = i;
        }
    }

    printf("nodo que es alcanzado por más nodos: %d",nodomax);
}