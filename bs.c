#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int partition(int *arr, int start, int end) {
    int p = arr[end];
    int partition_idx = start;
    int i;
    int tmp;
    for(i=start; i<end; i++) {
        if(arr[i]<=p) {
            tmp = arr[i];
            arr[i]=arr[partition_idx];
            arr[partition_idx]=tmp;
            partition_idx++;
        }
    }
    // partition_idx--;
    tmp = arr[end];
    arr[end] = arr[partition_idx];
    arr[partition_idx]=tmp;
    return partition_idx;
}

void quick_sort(int *arr, int start, int end) {
    if(start < end) {
        int idx = partition(arr, start, end);
        quick_sort(arr, start, idx-1);
        quick_sort(arr, idx+1, end);
    }
}

void queue_bs(int *bs, int *arr_queue, int tok1, int tok2) {
    int left = 0;
    int right = tok1-1;
    for(int i=0;i<tok2;i++) {
        while(left<=right) {
            int mid = (left+right)/2;
            if(bs[mid]==arr_queue[i]) break;
            if(bs[mid]<arr_queue[i]) {
                left = mid + 1;
            }
            else right = mid-1;
        }
    }
}

void bs(int *arr_input, int *arr_queue, int tok1, int tok2) {
    int *bs;
    bs = (int*)malloc(tok1*sizeof(int));
    struct timeval start;
    struct timeval end;
    unsigned long time_input;
    unsigned long time_queue;
    gettimeofday(&start,NULL);
    for(int i=0;i<tok1;i++) {
        bs[i]=arr_input[i];
    }
    quick_sort(bs, 0, tok1-1);
    gettimeofday(&end,NULL);
    time_input = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    gettimeofday(&start,NULL);
    queue_bs(bs, arr_queue, tok1, tok2);
    gettimeofday(&end,NULL);
    time_queue = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("bs:\nbuilding time: %f sec\nquery time: %f sec\n", time_input/1000000.0, time_queue/1000000.0);
}