#include <stdio.h>
void analiza(int mat[][3],int i, int j, int cont, int n);
int main(){
    int n = 3;
    int mat[3][3] = {
        {1,0,1},
        {0,0,1},
        {1,1,0}
    };
    analiza(mat,0,0,0,n);
}
void analiza(int mat[][3],int i, int j, int cont, int n){
    if (j < n){
        if (i < n){
            if (mat[i][j] == 1){
                cont++;
            }
            analiza(mat,i+1,j,cont,n);
        }else{
            printf("nodos que inciden en %d: %d \n",j+1,cont);
            analiza(mat,0,j+1,0,n);
        }
    }
}