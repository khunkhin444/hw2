#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "arr.h"
#include "bs.h"
#include "not_bs.h"
#include "ll.h"
#include "hash.h"

int main(int argc, char **argv) {
    int arr_input[1000000];
    int arr_queue[100000];
    int tok1;
    int tok2;
    int i;
    srand(time(NULL)); //seed for rand
    for(i=0;i<1000000;i++) {
        arr_input[i] = '\0';
    }
    for(i=0;i<100000;i++) {
        arr_queue[i]='\0';
    }
    
    //command line
    if(strcmp(argv[1],"-d")==0) {
        if(strcmp(argv[2],"1e4")==0) tok1 = 10000;
        else if(strcmp(argv[2],"1e5")==0) tok1 = 100000;
        else if(strcmp(argv[2],"1e6")==0) tok1 = 1000000;
        else {
            usage();
            exit(1);
        }
    }
    for(i=0;i<tok1;i++) {
        arr_input[i] = rand();
    }
    if(strcmp(argv[3],"-q")==0) {
        if(strcmp(argv[4],"1e3")==0) tok2 = 1000;
        else if(strcmp(argv[4],"1e4")==0) tok2 = 10000;
        else if(strcmp(argv[4],"1e5")==0) tok2 = 100000;
        else {
            usage();
            exit(1);
        }
    }
    for(i=0;i<tok2;i++) {
        arr_queue[i] = rand();
    }
    for(i=5;i<argc;i++) {
        if(strcmp(argv[i],"-bs")==0) {
            bs(arr_input, arr_queue, tok1, tok2);
        }
        if(strcmp(argv[i],"-bst")==0) {
            not_bs(arr_input, arr_queue, tok1, tok2);
        }
        if(strcmp(argv[i],"-ll")==0) {
            ll(arr_input, arr_queue, tok1, tok2);
        }
        if(strcmp(argv[i],"-arr")==0) {
            arr(arr_input, arr_queue, tok1, tok2);
        }
        if(strcmp(argv[i],"-hash")==0) {
            hash(arr_input, arr_queue, tok1, tok2);
        }
    }
    //commandline
}