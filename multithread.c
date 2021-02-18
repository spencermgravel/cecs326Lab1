#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barrier1;
int SharedVariable = 0 ;
/*
Originally this just creates a thread and counts up to 20. 

modified args and return for pthread
todo: Fix syncronization

*/
void* SimpleThread(void* which){
    int num, val;

    for(num = 0; num < 20 ; num ++){
        #ifdef PTHREAD_SYNC
            if (random() > RAND_MAX / 2)
                usleep(500);
        #endif
        pthread_mutex_lock(&mutex1);
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", *(int *)which, val);
        SharedVariable = val + 1;
        pthread_mutex_unlock(&mutex1);
    }
    pthread_barrier_wait(&barrier1);
    val = SharedVariable;
    printf("Thread %d sees final value %d\n", *(int*) which, val);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Invalid number of inputs");
        return 0;
    }

    int thread_count = atoi(argv[1]);
    int r = pthread_barrier_init(&barrier1, NULL, thread_count);

    pthread_t thread_arr[thread_count];
    int int_arr[thread_count];
    for (int i = 0; i < thread_count; i++)
    {
        int_arr[i] = i;
        pthread_create(&thread_arr[i], NULL, SimpleThread, &int_arr[i]);
    }
    for (int i = 0; i < thread_count; i++)
    {
        pthread_join(thread_arr[i], NULL);
    }

    exit(0);
}