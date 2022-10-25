#include <stdio.h>
#include <stdlib.h>
#define N 4

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
            int sum = 0;
            for(int k=0; k<N; k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
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