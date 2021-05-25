#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void usage() {
	printf("input format wrong\n");
}

void create_arr(int *arr, int *arr_input, int tok1) {
    for(int i=0; i<tok1;i++) {
        arr[i] = arr_input[i];
    }
}

void queue_arr(int *arr, int *arr_queue, int tok1, int tok2) {
    int i,j;
    for(i=0; i<tok2; i++) {
        for(j=0;j<tok1;j++) {
            if(arr[j]==arr_queue[i]) break;
        }
    }
}

void arr(int *arr_input, int *arr_queue, int tok1, int tok2) {
    struct timeval start;
    struct timeval end;
    unsigned long time_input;
    unsigned long time_queue;
    int *arr;
    arr = (int*)malloc(tok1*sizeof(int));
    gettimeofday(&start,NULL);
    create_arr(arr, arr_input ,tok1);
    gettimeofday(&end,NULL);
    time_input = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    gettimeofday(&start,NULL);
    queue_arr(arr, arr_queue, tok1, tok2);
    gettimeofday(&end,NULL);
    time_queue = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("arr:\nbuilding time: %f sec\nquery time: %f sec\n", time_input/1000000.0, time_queue/1000000.0);
}
