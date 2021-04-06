//#include "cachelab.h"  // es
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

typedef struct _cash{
    long long begin;
    int use_t;
}cash;

typedef struct _heap_node{
    int id;
    int use_t;
}node;

int hit_count = 0, miss_count = 0, eviction_count = 0; 
int s = 0, S, E = 0, b = 0, B, CACHE_NUM, HEAP_NUM, CNT_COUNT;
int flag = 0;
char *filepath = NULL;
cash **CACHE = NULL;
node *HEAP = NULL;

int if_evit(); //return id
int if_miss(long long addr_l);
int cache_put(long long addr_h);
int evit(long long addr_l);
int warm_up(long long addr_l);
int hit();
int miss();


void init_cache();
void free_cache();

int init_heap();
int heap_pushdown(int i);
int heap_pushup(int i);
int heap_insert(int i, int u_t);
int heap_out();
int heap_check();

void run();
void test_file_stream();
void test_heap_effects();
void test_hitmiss_flow();
void printHeap();

long long str2num(char*hex);

int main(int argc, char *argv[]){
    char *opt = "s:E:b:t:v";
    int in;
    while( (in = getopt(argc, argv, opt)) != -1 ) {
        switch (in)
        {
        case 's':
            s = atoi(optarg);
            S = 1 << s;
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            B = 1 << b;
            break;
        case 't':
            filepath = optarg;
            break;
        case 'v':
            flag = 1;
            break;
        default:
            printf("unknown opt: %c\n", (char)optopt);
            exit(123);
            break;
        }
    }

    //test_file_stream();
    //test_heap_effects();
    
    init_cache();               // es
    run();
    free_cache();
    //printSummary(hit_count, miss_count, eviction_count);  
    printf("\n%d %d %d\n", hit_count, miss_count, eviction_count);
      
    return 0;
}

void test_heap_effects(){
    init_cache();

    for(int i = 0; i < S * E; ++i) {
        int j = i & 0x7;
        heap_insert(0, j);
    }
    for(int i = 0; i < 8; ++i)
        heap_out();

    printf("\nheapcheck : %d\n", heap_check());
    printHeap();

    free_cache();
}

void test_file_stream() {
    FILE *F = NULL;
    F = freopen(filepath, "r", stdin);
    if(!F) 
        exit(3);

    int commaPOS = 0;
    char first[40], second[40], addr[20], instr;
    long long addl;
    while(scanf("%s%s", &first[0], &second[0]) != EOF){
        commaPOS = 0;
        instr = first[0];
        while(second[commaPOS] != ','){
            commaPOS ++;
        }
        for(int i = 0; i < commaPOS; ++i) 
            addr[i] = second[i];
        addr[commaPOS] = '\0';
        addl = str2num(addr);
        printf("\n%c\t%llx" ,instr, addl);

        // switch (instr)
        // {
        // case 'L':
        //     if(if_miss(addl)){
        //         miss();
        //         if( if_evit() ) {
        //             evit(addl);
        //         }else   
        //             warm_up(addl);
        //     }
        //     else 
        //         hit();
        //     break;
        // case 'M':
        //     if(if_miss(addl)) {
        //         miss();
        //         if( if_evit() ) {
        //             evit(addl);
        //         }else
        //             warm_up();
        //     }
        //     else 
        //         hit();
        //     hit();
        //     break;
        // case 'S':
        //     if(if_miss(addl)) {
        //         miss();
        //         if( if_evit()) ) {
        //             evit(addl);
        //         }else
        //             warm_up(addl);
        //     }
        //     else
        //         hit();
        //     break;
        // default:
        //     exit(233); //;)
        //     break;
        // }
    }
    fclose(F);
}

long long str2num(char *hex) {
    int val = 0;
    int len = strlen(hex);
    for(int i = 0; i < len; ++i) {
        val = val << 4;
        char ch = hex[i];
        if(ch >= '0' && ch <= '9') val += (ch - '0');
        else if(ch >= 'a' && ch <= 'f') val += (ch - 'a' + 10);
        else return -1;
    }
    return val;
}

void run() {
    FILE *F = NULL;
    F = freopen(filepath, "r", stdin);
    if(!F) 
        exit(3);

    int commaPOS = 0;
    char first[40], second[40], addr[20], instr;
    long long addl;
    while(scanf("%s%s", &first[0], &second[0]) != EOF){
        if(flag) 
            printf("%s %s", first, second);

        commaPOS = 0;
        instr = first[0];
        while(second[commaPOS] != ','){
            commaPOS ++;
        }
        for(int i = 0; i < commaPOS; ++i) 
            addr[i] = second[i];
        addr[commaPOS] = '\0';
        addl = str2num(addr);
        
        switch (instr)
        {
        case 'L':
            if(if_miss(addl)){
                miss();
                if( if_evit() ) {
                    evit(addl);
                }else   
                    warm_up(addl);
            }
            else 
                hit();
            printf("\n");
            break;
        case 'M':
            if(if_miss(addl)) {
                miss();
                if( if_evit() ) {
                    evit(addl);
                }else
                    warm_up(addl);
            }
            else 
                hit();
            hit();
            printf("\n");
            break;
        case 'S':
            if(if_miss(addl)) {
                miss();
                if ( if_evit() ) {
                    evit(addl);
                }else
                    warm_up(addl);
            }
            else
                hit();
            printf("\n");
            break;
        default:
            exit(233); //;)
            break;
        }
    }
    fclose(F);
}

int if_miss(long long addr_l) {
    addr_l &= (-1 << b);
    //printf(" %llx", addr_l);

    for(int i = 0; i < S; ++i ) {
        for(int j = 0; j < E; ++j) {
            if(CACHE[i][j].begin == addr_l) 
                return 0;
        }
    }
    return 1;
}

int if_evit() {
    return HEAP_NUM == CACHE_NUM;
}

int evit(long long addr_l) {

    CNT_COUNT++;
    eviction_count++;

    if(flag) 
        printf(" eviction");

    cache_put(addr_l);
    return 1;
}

int miss() {
    miss_count++; 

    if(flag) 
        printf(" miss");

    return 1;
}

int hit() {
    hit_count++;

    if(flag)
        printf(" hit");

    return 1;
}

int warm_up(long long addr_l) {
    CNT_COUNT++;
    HEAP_NUM ++;

    cache_put(addr_l);
    return 1; 
}

int cache_put(long long addr_h) {
    int heap_id = HEAP[0].id, row, col;
    col = heap_id & ~(-1 << s);
    row = heap_id / S;
    addr_h &= (-1 << b);

    CACHE[row][col].begin = addr_h;
    CACHE[row][col].use_t = CNT_COUNT;
    heap_insert(heap_id, CNT_COUNT);
    return 1;
}

void printHeap() {
    printf("\n HEAP: \n");
    for(int i = 0; i < HEAP_NUM; i++) {
        printf(" %d%s", HEAP[i].use_t, i == HEAP_NUM - 1 ? "\n":"");
    }
}

int heap_check() {
    int limit = HEAP_NUM >> 1;
    for(int i = 0; i <= limit; ++i) {
        int lson = (i << 1) + 1;
        int rson = (i << 1) + 2;
        if(lson < HEAP_NUM && HEAP[lson].use_t < HEAP[i].use_t) 
            return -1;
        if(rson < HEAP_NUM && HEAP[rson].use_t < HEAP[i].use_t)
            return -1;
    }
    return 1;
}

int heap_pushup(int i) {

    //printf("\n%d %d", i, HEAP_NUM);
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
    CNT_COUNT = 0;

    HEAP = (node *)malloc(sizeof(node) * (CACHE_NUM + 1));
}

int heap_out(){
    if(!HEAP_NUM) 
        return 0;

    HEAP[0].id = HEAP[--HEAP_NUM].id;
    HEAP[0].use_t = HEAP[HEAP_NUM].use_t;
    heap_pushdown(0);
    return 1;
}

int heap_insert(int i, int u_t){
    if(HEAP_NUM == CACHE_NUM) 
        return 0;

    HEAP[HEAP_NUM].id = i;
    HEAP[HEAP_NUM].use_t = u_t;
    HEAP_NUM++;
    heap_pushup(HEAP_NUM-1);        //one data update bug 
    
    return 1;
}

void init_cache(){
    hit_count = 0;
    miss_count = 0;
    eviction_count = 0;
    CACHE = NULL;
    CACHE = (cash **)malloc(sizeof(cash *) * S);

    for(int i = 0; i < S; i++) {
        CACHE[i] = (cash*)malloc(sizeof(cash) * E);
        for(int j = 0; j < E; j++) {
            CACHE[i][j].begin = -1;
            CACHE[i][j].use_t = 0;
        }
    }
    
    CACHE_NUM = S*E;
    init_heap();

}

void free_cache(){
    for(int i = 0; i < S; i++)
        free(CACHE[i]);
    free(CACHE);
    free(HEAP);
}







