#include <stdio.h>
void analiza(int mat[][3],int i, int j, int n, int grados[]);
void muestravec(int grados[], int n);
int main(){
    int n = 3;
    int mat[3][3] = {
        {1,0,1},
        {0,0,1},
        {1,1,0}
    };
    int grados[3] = {0,0,0};
    analiza(mat,0,0,n,grados);
    muestravec(grados,n);
}

//analiza toda la matriz en vez de la diagonal principal

void analiza(int mat[][3],int i, int iaux, int n, int grados[]){
    if (i < n){
        if (iaux < n){
            if (iaux < i){
                analiza(mat,i,iaux+1,n,grados);
            }else{
                if (mat[iaux][i] == 1){
                    grados[i]++;
                }
                analiza(mat,i,iaux+1,n,grados);
            }
        }else{
            analiza(mat,i+1,0,n,grados);
        }
    }
}
void muestravec(int grados[], int n){
    int i;
    for (i=0;i<n;i++){
        printf("grados del nodo %d: %d \n",i+1, grados[i]);
    }

}