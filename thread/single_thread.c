#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//child process
void* child(void* data){
    char *str = (char*) data;
    for(int i=0; i<3; i++){
        printf("%s\n", str);
        sleep(1);
    }
    //printf("test\n");
    pthread_exit(NULL);
}

int main(void){
    pthread_t t;
    pthread_create(&t, NULL, child, "output");

    for(int i=0; i<3; i++){
        printf("Master\n");
        sleep(1);
    }

    pthread_join(t, NULL);

    return 0;
}