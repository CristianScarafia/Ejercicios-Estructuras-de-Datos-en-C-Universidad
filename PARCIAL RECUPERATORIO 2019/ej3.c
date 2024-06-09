#include <stdio.h>
#include <stdlib.h>

typedef struct arista{
    int i;
    int j;
}arista;

typedef arista vecaristas;
void analiza(int mat[][3], vecaristas aristas[],int n, int *k, int vertices[]);
void recorrevector(vecaristas aristas[], int n,int vecvertices[]);
int main(){
    int n = 3;
    int i = 0;
    int mat[3][3] = {
        {0,1,1},
        {0,0,1},
        {1,0,0},
    };
    int vecvertices[3];
    vecaristas aristas[3];
    analiza(mat,aristas,n,&i,vecvertices);
    recorrevector(aristas,i,vecvertices);
    return 0;
}

void analiza(int mat[][3], vecaristas aristas[],int n, int *k, int vertices[]){
    int i = 0;
    int j = 0;
    while (i < n){
        j = i;
        while (j < n){
            if (mat[i][j] != mat[j][i]){
                aristas[*k].i = i+1;
                aristas[*k].j = j+1;
                (*k)++;
                vertices[i] = 1;
                vertices[j] = 1;
            }
            j++;
        }
        i++;
    }
}
void recorrevector(vecaristas aristas[], int n,int vecvertices[]){
    int i;
    if (n>0){
        printf("aristas en conflicto:\n");
        for (i=0;i<n;i++){
            printf("(%d,",aristas[i].i);
            printf("%d)\n",aristas[i].j);
        }
        printf("vertices en conflicto:\n");
        for (i=0;i<3;i++){
            if (vecvertices[i] == 1){
                printf("%d ",i+1);
            }
        }
    }
}
