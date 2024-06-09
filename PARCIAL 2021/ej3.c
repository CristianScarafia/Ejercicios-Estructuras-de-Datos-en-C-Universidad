#include <stdio.h>
#define N 3

void inicializavec(int vec[N]);
void muestravec(int vec[N]);
void grados_bucles(int mat[][N],int vec_grados[], int vec_bucles[]);
int analiza(int vec_grados[], int vec_bucles[]);
int main(){
    int mat[N][N] = {
        {0,1,0},
        {0,0,0},
        {0,0,0}
    };
    int vec_grados[N];
    int vec_bucles[N];
    inicializavec(vec_grados);
    inicializavec(vec_bucles);
    grados_bucles(mat,vec_grados,vec_bucles);
    muestravec(vec_grados);
    muestravec(vec_bucles);
    int vertice = analiza(vec_grados,vec_bucles);
    if(vertice){
        printf("El vercies es: %d", vertice);
    }else{
        printf("No existe vertice que cumpla con las condiciones.");
    }
}

void inicializavec(int vec[N]){
    int i;
    for (i=0;i<N;i++){
        vec[i] = 0;
    }
}
void muestravec(int vec[N]){
    int i;
    for (i=0;i<N;i++){
        printf("%d ",vec[i]);
    }
    printf("\n");
}
void grados_bucles(int mat[][N],int vec_grados[], int vec_bucles[]){
    int i,j;

    for (i=0;i<N;i++){
        for (j=i;j<N;j++){
            if (mat[i][j] > 0){
                vec_grados[i]++;
                vec_grados[j]++;
            }
        }
        if (mat[i][i] > 0){
            vec_bucles[i] = 1;
        }
    }
}

int analiza(int vec_grados[], int vec_bucles[]){
    int i,max=0,vertice=0;
    for (i=0;i<N;i++){
        if (vec_bucles[i] == 0){
            if ((vec_grados[i] % 2) != 0){
                if (vec_grados[i] > max){
                    max = vec_grados[i];
                    vertice = i+1;
                }
            }
        }
    }
    return vertice;
}