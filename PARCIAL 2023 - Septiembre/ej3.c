#include <stdio.h>
#define N 3
int verifica(int mat[][N], int x, int i, int j, int cont, int cant);
int main(){
    int x = 2;
    int mat[N][N]={
        {0,4,6},
        {0,2,0},
        {5,0,7}
    };

    printf("la cantidad de vertices que cumplen es: %d",verifica(mat,x,0,0,0,0));

    return 0;
}

int verifica(int mat[][N], int x, int i, int j, int cont, int cant){
    if (i<N){
        if (mat[i][i] > 0){
            return verifica(mat, x, i+1, 0, 0,cant);
        }else{
            if (j<N){
                if (mat[j][i] > 0){
                    return verifica(mat,x,i,j+1,cont+1,cant);
                }else{
                    return verifica(mat,x,i,j+1,cont,cant);
                }
            }else{
                if (cont < x){
                    return 1 + verifica(mat,x,i+1,0,0,cant+1);
                }else{
                    return verifica(mat,x,i+1,0,0,cant);
                }
            }
        }
    }else{
        return 0;
    }
}