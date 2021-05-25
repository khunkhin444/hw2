#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define max_hash 1000000

struct h_node {
    int data;
    struct h_node *link;
};

int hash0(char *data) {
    int hv;
    char *ptr = data;
    hv = 0;
    while(*ptr) {
        hv = hv*5 + *ptr;
        ptr++;
    }
    return hv;
}
char  *reverse(char *s) {
    int i,j;
    char c;
    for(i=0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

char *myitoa(int n, char *s) {
    int tmp = abs(n);
    int i = 0;
    while(tmp) {
        int r = tmp % 10;
        if (r>=10) {
            s[i++] = 65 + (r-10);
        }
        else {
            s[i++] = 48 + r;
        }
        tmp = tmp / 10;
    }
    if(i==0) {
        s[i++] = '0';
    }
    if(n<0) {
        s[i++] = '-';
    }
    s[i]='\0';
    return reverse(s);
}  

void l_find(struct h_node *ptr, int num) {
    if(ptr==NULL) return;
    struct h_node *tmp = ptr;
    while(tmp) {
        if(num == (*tmp).data) return;
        tmp = (*tmp).link;
    }
}

void hash_find(struct h_node **hash_tab, int num) {
    unsigned long hv;
    struct h_node *ptr;
    char s[32];
    myitoa(num, s);
    hv = hash0(s) % max_hash;
    ptr = hash_tab[hv];
    l_find(ptr, num);
}

struct h_node *l_insert(struct h_node *ptr, int num) {
    struct h_node *tmp = (struct h_node*)malloc(sizeof(struct h_node));
    (*tmp).data = num;
    (*tmp).link = ptr;
    ptr = tmp;
    return tmp;
}

void hash_insert(struct h_node **hash_tab, int num) {
    int hv;
    struct h_node *ptr;
    char s[32];
    myitoa(num, s);
    hv = hash0(s) % max_hash;
    ptr = hash_tab[hv];
    hash_tab[hv] = l_insert(ptr, num);
}

void hash(int *arr_input, int *arr_queue, int tok1, int tok2) {
    struct h_node **hash_tab;
    struct h_node *ptr;
    int i;
    struct timeval start;
    struct timeval end;
    unsigned long time_input;
    unsigned long time_queue;
    hash_tab = (struct h_node **)malloc(sizeof(struct h_node*)*max_hash);
    for(int i=0; i<max_hash;i++) {
        hash_tab[i]=NULL;
    }
    gettimeofday(&start,NULL);
    for(i=0;i<tok1;i++) {
        hash_insert(hash_tab, arr_input[i]);
    }
    gettimeofday(&end,NULL);
    time_input = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    gettimeofday(&start,NULL);
    for(i=0;i<tok2;i++) {
        hash_find(hash_tab, arr_queue[i]);
    }
    gettimeofday(&end,NULL);
    time_queue = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("hash:\nbuilding time: %f sec\nquery time: %f sec\n", time_input/1000000.0, time_queue/1000000.0);
}