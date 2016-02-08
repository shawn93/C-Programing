#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// #include "timer.h"

/* Global variables */
int thread_count;
int n;
double* A;
double min,max;

/* Serial functions */
void Usage(char* prog_name);
void Gen_array(double A[], int n);

/* Parallel function */
void *Find_MinMax(void* rank);

int main(int argc, char* argv[]) {
    long       thread;
    pthread_t* thread_handles;
    // double start, finish;

    if (argc != 3) Usage(argv[0]);
    thread_count = strtol(argv[1], NULL, 10);
    n = strtol(argv[2], NULL, 10);

    thread_handles = malloc(thread_count*sizeof(pthread_t));
    A = malloc(n*sizeof(double));
   
    srandom(1);
    Gen_array(A,n);

    // GET_TIME(start);
    for (thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, Find_MinMax, (void*) thread);

    for (thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);
    // GET_TIME(finish);

    // printf("Elapsed time = %e seconds\n", finish-start);
    printf("Min: %f, Max: %f\n", min, max);

    free(A);
    free(thread_handles);
    return 0;
}  /* main */

void Usage (char* prog_name) {
    fprintf(stderr, "Usage: %s <Thread_Count> <Array_Size>\n", prog_name);
    exit(0);
}  /* Usage */

void Gen_array(double A[], int n) {
    int i;
    for (i = 0; i < n; i++)
        A[i] = random()/((double) RAND_MAX);
}  /* Gen_array */

void* Find_MinMax(void* rank) {
    long my_rank = (long) rank;
    int i;
    long long local_n = n / thread_count;
    long long my_first_i = local_n * my_rank;
    long long my_last_i = my_first_i + local_n;
    //Initialized min, max.
    min = A[0];
    max = A[0];
    for (i = my_first_i; i < my_last_i; i++) {
        if (A[i] < min) {
            min = A[i];
        }
        if (A[i] > max) {
            max = A[i];
        }
    }

    return NULL;
} /* Find_MinMax */