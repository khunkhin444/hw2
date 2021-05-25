#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>

struct l_node {
    int data;
    struct l_node *link;
};

struct l_node *ll_insert(struct l_node *head, int num) {
    struct l_node *tmp = (struct l_node*)malloc(sizeof(struct l_node));
    (*tmp).data = num;
    (*tmp).link = head;
    head = tmp;
    return head;
}

bool ll_find(struct l_node *head, int num) {
    struct l_node *tmp = head;
    while(tmp!=NULL) {
        if((*tmp).data==num) return true;
        tmp = (*tmp).link;
    }
    return false;
}

void ll(int *arr_input, int *arr_queue, int tok1, int tok2) {
    int i;
    struct l_node *head = NULL;
    struct timeval start;
    struct timeval end;
    unsigned long time_input;
    unsigned long time_queue;
    gettimeofday(&start,NULL);
    for(i=0;i<tok1;i++) {
        head = ll_insert(head, arr_input[i]);
    }
    gettimeofday(&end,NULL);
    time_input = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    gettimeofday(&start,NULL);
    for(i=0;i<tok2;i++) {
        ll_find(head, arr_queue[i]);
    }
    gettimeofday(&end,NULL);
    time_queue = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("ll:\nbuilding time: %f sec\nquery time: %f sec\n", time_input/1000000.0, time_queue/1000000.0);
    while(head!=NULL) {
        struct l_node *tmp = head;
        head = (*head).link;
        free(tmp);
    }
}