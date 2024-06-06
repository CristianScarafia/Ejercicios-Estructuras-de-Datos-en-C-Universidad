
#include <stdio.h>
#define N 4
int analiza(int mat[][N],int i, int j, int gradoant,int gradoact);
int main(){
    int mat[N][N] = {
        {1,0,1,0},
        {0,1,0,1},
        {1,0,0,1},
        {1,0,0,1}
    };

    if (analiza(mat,0,0,0,0)){
        printf("cumple");
    }else{
        printf("no cumple");
    }
    
    return 0;
}

int analiza(int mat[][N],int i, int j, int gradoant,int gradoact){
    if (i < N){
        if (j < N){
            gradoact = gradoact + mat[i][j];
            return analiza(mat,i,j+1,gradoant,gradoact);
        }
        if (mat[i][i] == 0){
            return 0;
        }
        if (i == 0){
            return analiza(mat,i+1,0,gradoact,0);
        }else{
            if (gradoact == gradoant){
                return analiza(mat,i+1,0,gradoant,0);
            }else{
                return 0;
            }
        }
    }else{
        return 1;
    }    
}