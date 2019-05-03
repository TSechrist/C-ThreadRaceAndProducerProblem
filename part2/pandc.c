#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

pthread_mutex_t lock;
sem_t empty;
_Atomic int globalP = 0;
_Atomic int globalC = 0;
int n, x, p, c, ptime, consumetime, y;

struct timespec tsP = {};
struct timespec tsC = {};
/* 
 * Function to remove item.
 * Item removed is returned
 */
int dequeue_item()
{
    
}

/*
 * Function to add item.
 * Item added is returned.
 * It is up to you to determine
 * how to use the ruturn value.
 * If you decide to not use it, then ignore
 * the return value, do not change the
 * return type to void. 
 */
int enqueue_item(int item)
{
   
}

void* thread_func_producer( void* arg ){

    for(int i = 0; i < x; i++)
    {

        /* Aquire semaphore */
        sem_wait(&empty);

/* critical section */
        globalP++;

        printf("Producer: %d  ::  %d\n", (unsigned int)pthread_self(), globalP);

/* release semaphore */
        sem_post(&empty);

        nanosleep(&tsP, 0);
    }

    return NULL;
}

void* thread_func_consumer( void* arg ){


    for(int i = 0; i < y; i++)
    {

        /* Aquire semaphore */
        sem_wait(&empty);

/* critical section */
        globalC++;

        printf("Consumer: %d  ::  %d\n", (unsigned int)pthread_self(), globalC);

/* release semaphore */
        sem_post(&empty);

        nanosleep(&tsC, 0);
    }

    return NULL;
}

int main(int argc, char** argv) {

    if(argc != 7)
    {
        perror("Not correct number of arguments given (7)");
        exit( EXIT_FAILURE );
    }
/* Create semaphore and initialize to 1 */
    sem_init(&empty, 0, 1);

    n = atoi(argv[1]);
    p = atoi(argv[2]);
    c = atoi(argv[3]);
    x = atoi(argv[4]);
    y = x*p/c;
    ptime = atoi(argv[5]);
    consumetime = atoi(argv[6]);

    struct timespec tsP = {ptime, 0};
    struct timespec tsC = {consumetime, 0};

    printf("Number of Buffers :                             %d\n", n);
    printf("Number of Producers :                           %d\n", p);
    printf("Number of Consumers :                           %d\n", c);
    printf("Number of Items Produced by each Producer :     %d\n", x);
    printf("Number of Items Consumed by each Consumer :     %d\n", y);

    if((p * x) - (c * y) > 0)
    {
        printf("Over Consume on? :                              1\n");
        printf("Over Consume amount :                           %d\n", (p * x) - (c * y));
    }
    else
    {
        printf("Over Consume on? :                              0\n");
    }

    printf("Time each Producer Sleeps (seconds) :           %d\n", ptime);
    printf("Time each Consumer Sleeps (seconds) :           %d\n", consumetime);


    pthread_t ids[p + c];

    for(int i = 0 ; i < p ; i++)
    {
        int idx = i;
        pthread_create(&ids[i],
                       NULL,
                       thread_func_producer,
                       (void *)&idx);
    }

    for(int i = 0 ; i < c ; i++)
    {
        int idx = i;
        pthread_create(&ids[i + p],
                       NULL,
                       thread_func_consumer,
                       (void *)&idx);
    }

    for(int i = 0; i < p + c; i++)
    {
        pthread_join(ids[i],NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}