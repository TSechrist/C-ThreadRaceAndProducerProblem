#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

static int shared = 0;

/**
 * THESE DEFINE VALUES CANNOT BE CHANGED.
 * DOING SO WILL CAUSE POINTS TO BE DEDUCTED
 * FROM YOUR GRADE
 */
 /** BEGIN VALUES THAT CANNOT BE CHANGED */
#define MAX_THREADS 16
#define MAX_ITERATIONS 40
/** END VALUES THAT CANNOT BE CHANGED */


/**
 * use this struct as a parameter for the function
 * nanosleep. 
 * For exmaple : nanosleep(&ts, NULL);
 */
struct timespec ts = {0, 123456 };

void* thread_func_add( void* arg ){
//    int idx = *((int *)arg);
    int num = shared;

    for(int i = 0; i < MAX_ITERATIONS; i++)
    {
        num = shared;
        nanosleep(&ts, NULL);
        num = num + 10;
        shared = num;
        printf("Current Value written to Global Variables by ADDER thread id: %u is %d\n", (unsigned int)pthread_self(), num);
    }
    return NULL;
}

void* thread_func_sub( void* arg ){
//    int idx = *((int *)arg);
    int num = shared;

    for(int i = 0; i < MAX_ITERATIONS; i++)
    {
        num = shared;
        nanosleep(&ts, NULL);
        num = num - 10;
        shared = num;
        printf("Current Value written to Global Variables by SUBTRACTOR thread id: %u is %d\n", (unsigned int)pthread_self(), num);

    }
    return NULL;
}


int
main(int argc, char** argv)
{
    pthread_t ids[MAX_THREADS];
    int i;

    for(i = 0 ; i < MAX_THREADS ; i = i + 2)
    {
        int idx = i;
        pthread_create(&ids[i],
                       NULL,
                       thread_func_add,
                       (void *)&idx);

        pthread_create(&ids[i + 1],
                       NULL,
                       thread_func_sub,
                       (void *)&idx);

    }


    for(i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(ids[i],NULL);
    }


    printf("shared: %d\n", shared);


    return 0;
}
