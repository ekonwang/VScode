#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

typedef struct _cash{
    int begin;
    int use_t;
}cash;

typedef struct _heap_node{
    int id;
    int use_t;
}node;

int hit_count = 0, miss_count = 0, eviction_count = 0; 
int s, E, b, v, CACHE_NUM, HEAP_NUM;
char *filepath = NULL;
cash **CACHE = NULL;
node *HEAP = NULL;

int if_miss();
int evit();
int if_put();

void init_cache();
void free_cache();

int init_heap();
int heap_pushdown(int i);
int heap_pushup(int i);
int heap_insert(int i, int u_t);
int heap_out();

void run();
void test_file_stream();
void test_heap_effects();
void printHeap();

int main(int argc, char *argv[]){
    char *opt = "s:E:b:t:";
    int in;
    while( (in = getopt(argc, argv, opt)) != -1 ) {
        switch (in)
        {
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            filepath = optarg;
            break;
        default:
            printf("unknown opt: %c\n", (char)optopt);
            exit(123);
            break;
        }
    }
    
    init_cache();
    run();
    free_cache();
    printSummary(hit_count, miss_count, eviction_count);    
    return 0;
}

void run() {
    FILE *F = freopen(filepath, "r", stdin);
    
}

void printHeap() {
    printf("\n HEAP: \n");
    for(int i = 0; i < HEAP_NUM; i++) {
        printf(" %d%s", HEAP[i].use_t, i == HEAP_NUM - 1 ? "":"\n");
    }
}

int heap_pushup(int i) {
    if(i < 0 || i >= HEAP_NUM) return 0;
    int j = (i-1) >> 1;
    while(j >= 0) {
        if(HEAP[j].use_t > HEAP[i].use_t) {
            int t_u_t, t_i;

            t_u_t = HEAP[j].use_t;
            t_i = HEAP[j].id;
            HEAP[j].use_t = HEAP[i].use_t;
            HEAP[j].id = HEAP[i].id;
            HEAP[i].use_t = t_u_t;
            HEAP[i].id = t_i; 
        }
        i = j;
        j = (i-1) >> 1;
    }
    return 1;
}

int heap_pushdown(int i) {
    if(i < 0 || i >= HEAP_NUM) return 0;
    int j = (i << 1) + 1;
    while(j < HEAP_NUM) {
        if(j + 1 < HEAP_NUM && HEAP[j+1].use_t < HEAP[j].use_t) j++;
        if(HEAP[j].use_t < HEAP[i].use_t) {
            int t_u, t_i;

            t_u = HEAP[j].use_t;
            t_i = HEAP[j].id;
            HEAP[j].use_t = HEAP[i].use_t;
            HEAP[j].id = HEAP[i].id;
            HEAP[i].use_t = t_u;
            HEAP[i].id = t_i;
        }
        i = j;
        j = (i << 1) + 1;
    }
    return 1;
}

int init_heap(){
    HEAP_NUM = 0;

    HEAP = (node *)malloc(sizeof(node) * (CACHE_NUM + 1));
    for(int i = 0; i < CACHE_NUM; i++) {
        heap_insert(i, 0);
    }
}

int heap_out(){
    HEAP[0].id = HEAP[--HEAP_NUM].id;
    HEAP[0].use_t = HEAP[HEAP_NUM].use_t;
    heap_pushdown(0);
    return 1;
}

int heap_insert(int i, int u_t){
    HEAP[HEAP_NUM].id = i;
    HEAP[HEAP_NUM].use_t = u_t;
    heap_pushup(HEAP_NUM);
    HEAP_NUM++;
    return 1;
}

void init_cache(){
    CACHE = NULL;
    CACHE = (cash **)malloc(sizeof(cash *) * s);

    for(int i = 0; i < s; i++) {
        CACHE[i] = (cash*)malloc(sizeof(cash) * E);
        for(int j = 0; j < E; j++) {
            CACHE[i][j].begin = -1;
            CACHE[i][j].use_t = 0;
        }
    }
    
    CACHE_NUM = s*E;
    init_heap();

}

void free_cache(){
    for(int i = 0; i < s; i++)
        free(CACHE[i]);
    free(CACHE);
    free(HEAP);
}