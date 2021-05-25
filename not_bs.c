#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int num) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    (*tmp).data = num;
    (*tmp).left = (*tmp).right = NULL;
    return tmp;
}

struct node *bst_insert(struct node *parent, int num) {    	
    if(parent==NULL) parent = newNode(num);
    else if(num<=(*parent).data) (*parent).left = bst_insert((*parent).left, num);
    else (*parent).right = bst_insert((*parent).right, num);
    return parent;
}

	
void bst_find(struct node *parent, int num) {
    while(parent) {
        int tok = (*parent).data;
        if(num<tok) parent = (*parent).left;
        else if(num>tok) parent = (*parent).right;
        else return;
    }
}

void rmTree(struct node *parent) {
    if((*parent).left!=NULL) rmTree((*parent).left);
    if((*parent).right!=NULL) rmTree((*parent).right);
    free(parent);
}

void not_bs(int *arr_input, int *arr_queue, int tok1, int tok2) {
    int i;
    struct node *root = NULL;
    struct timeval start;
    struct timeval end;
    unsigned long time_input;
    unsigned long time_queue;
    gettimeofday(&start,NULL);
    for(i=0;i<tok1;i++) {
        root = bst_insert(root, arr_input[i]);
    }
    gettimeofday(&end,NULL);
    time_input = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    gettimeofday(&start,NULL);
    for(i=0;i<tok2;i++) {
        bst_find(root, arr_queue[i]);
    }
    gettimeofday(&end,NULL);
    time_queue = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("bst:\nbuilding time: %f sec\nquery time: %f sec\n", time_input/1000000.0, time_queue/1000000.0);
    rmTree(root);
}