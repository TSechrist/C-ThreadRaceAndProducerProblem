#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>


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

int main(int argc, char** argv) {

    if(argc != 7)
    {
        perror("Not enough arguments given.");
        exit( EXIT_FAILURE );
    }

    int n = atoi(argv[1]);
    int p = atoi(argv[2]);
    int c = atoi(argv[3]);
    int x = atoi(argv[4]);
    int y = x*p/c;
    int ptime = atoi(argv[5]);
    int ctime = atoi(argv[6]);

    printf("Number of Buffers :                             %d\n", n);
    printf("Number of Producers :                           %d\n", p);
    printf("Number of Consumers :                           %d\n", c);
    printf("Number of Items Produced by each Producer :     %d\n", x);
    printf("Number of Items Consumed by each Consumer :     %d\n", y);
    printf("Time each Producer Sleeps (seconds) :           %d\n", ptime);
    printf("Time each Consumer Sleeps (seconds) :           %d\n", ctime);



}
