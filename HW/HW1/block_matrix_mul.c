#include <stdio.h>
#include <stdlib.h>
#define N 4
#define BLOCK_SIZE 2

void show_matrix(int matrix[N][N]);

int main(void){
    int A[N][N], B[N][N], C[N][N];

    //init
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = 0;
            B[i][j] = 0;
            C[i][j] = 0;
        }
    }
    */

    //input
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &B[i][j]);
        }
    }

    //multiplication
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                // 2*2 block matrix multiplications
                for(int i1=i; i1<i+BLOCK_SIZE; i1++){
                    for(int j1=j; j1<j+BLOCK_SIZE; j1++){
                        for(int k1=i; k1<k+BLOCK_SIZE; k1++){
                            C[i1][j1] += A[i1][k1] * B[k1][j1];
                        }
                    }
                }
            }
        }
    }

    //show C matrix
    show_matrix(C);

    return 0;
}

void show_matrix(int matrix[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%-5d", matrix[i][j]);
        }
        printf("\n");
    }
}