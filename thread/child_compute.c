#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *child(void *arg){
    int *input = (int *) arg; //get the input
    int *result = malloc(sizeof(int) * 1); //memory allocation
    result[0] = input[0] + input[1]; //computation
    pthread_exit((void *) result); //return the result
}

int main(void){
    pthread_t t;
    void *ret; //the result returned by the child thread
    int input[2] = {1, 2}; //input data

    //create the child thread
    pthread_create(&t, NULL, child, (void*) input);

    //wait for the child thread
    pthread_join(t, &ret);

    //get the result
    int *result = (int *) ret;

    //output the computation result
    printf("%d + %d = %d\n", input[0], input[1], result[0]);

    //free the memory
    free(result);

    return 0;
}