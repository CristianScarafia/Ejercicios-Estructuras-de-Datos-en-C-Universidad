#include <stdio.h>

int analiza(int mat[][4],int i, int j, int sumnodoact,int n, int k);

int main(){
    int n = 4;
    int k = 10;
    int mat[4][4] = {
        {0,5,3,3},
        {4,0,5,0},
        {5,5,0,4},
        {1,1,2,0}
    };
    
    printf("%d",analiza(mat,0,0,0,n,k));

}

int analiza(int mat[][4],int i, int j, int sumnodoact,int n, int k){
    if (i<n){
        if (j<n){
            if (j != i){
                if (mat[i][j] > 0){
                    sumnodoact = sumnodoact + mat[i][j];
                }
            }
            return analiza(mat,i,j+1,sumnodoact,n,k);
        }else{
            if (sumnodoact > k){
                return 1 + analiza(mat,i+1,0,0,n,k);
            }else{
                return analiza(mat,i+1,0,0,n,k);
            }
        }
    }else{
        return 0;
    }

}