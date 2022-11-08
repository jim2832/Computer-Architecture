#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *print_hello(void *input){
	char *str = (char*)input;
	printf("%s%s\n", "Hello world", str);
	pthread_exit(NULL);
}

 main(void){
	pthread_t thread_1, thread_2, thread_3;
	pthread_create(&thread_1, NULL, print_hello, "1");
	pthread_create(&thread_2, NULL, print_hello, "2");
	pthread_create(&thread_3, NULL, print_hello, "3");

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	
	return 0;
}
