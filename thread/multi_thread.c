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
    pthread_exit(NULL);
}

int main(void){
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, child, "Child1");
    pthread_create(&t2, NULL, child, "Child2");
    pthread_create(&t3, NULL, child, "Child3");
    
    for(int i=0; i<3; i++){
        printf("Master\n");
        sleep(1);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}