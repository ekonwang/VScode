#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "cachelab.h"

typedef struct _cash{
    long long ind;
    int use_t;
}cash;

int s, S, E, b, B, CACHE_NUM;

int hit_count = 0, miss_count = 0, eviction_count = 0; 
long long flag = 0, mask = 0, rmask = 0;
char *filepath = NULL;
cash **CACHE = NULL;

void str2ins(char* ch, long long* ans, char *first, char *second);
long long str2num(char *hex);

void free_cache();
void init_cache();
int if_miss(long long addr, long long *ind, long long *p);
int if_evict(long long ind, long long p);
void miss() ;
void hit();
void cache_put(long long ind, long long p);
int warm_up(long long ind, long long p);
int evict(long long ind, long long p);
void run();

void test_file_stream() ;

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
    CACHE_NUM = S * E;
    
    init_cache();  
    run();
    free_cache();
    printSummary(hit_count, miss_count, eviction_count);
    
    return 0;
}

void run() {
    FILE *F = NULL;
    long long addl, ind, p;
    char first[15], second[15], instr;

    F = freopen(filepath, "r", stdin);
    if(!F) 
        exit(233);

    while(scanf("%s%s", &first[0], &second[0]) != EOF){
        if(flag) 
            printf("\n%s %s", first, second);
        str2ins(&instr, &addl, first, second);

        switch (instr)
        {
        case 'L':
            if(if_miss(addl, &ind, &p)){
                miss();
                if( if_evict(ind, p) ) {
                    evict(ind, p);
                }else   
                    warm_up(ind, p);
            }
            else 
                hit();
            break;
        case 'S':
            if(if_miss(addl, &ind, &p)){
                miss();
                if( if_evict(ind, p) ) {
                    evict(ind, p);
                }else   
                    warm_up(ind, p);
            }
            else 
                hit();
            break;
        case 'M':
            if(if_miss(addl, &ind, &p)){
                miss();
                if( if_evict(ind, p) ) {
                    evict(ind, p);
                }else   
                    warm_up(ind, p);
            }
            else 
                hit();
            hit();
            break;
        default:
            exit(23); //;)
            break;
        }

        if(flag)
            printf("\n");
    }
    fclose(F);
}

int evict(long long ind, long long p) {

    if(flag) printf(" eviction");
    eviction_count++;
    cache_put(ind, p);
    return 1;
}

int warm_up(long long ind, long long p) {
    cache_put(ind, p);
    return 1;
}

void cache_put(long long ind, long long p) {
    if(E == 1) {
        CACHE[p][0].ind = ind;
        return;
    }

    long long max = -1, min = 0x7fffffffffff, p_min;
    for(int i = 0; i < E; ++i) {
        long long val = CACHE[p][i].use_t;
        if(val > max) max = val;
        if(val < min) { min = val; p_min = i; }
    }
    CACHE[p][p_min].use_t = max+1;
    CACHE[p][p_min].ind = ind;
}

void hit(){
    if(flag)
        printf(" hit");
    hit_count++;
}

void miss() {
    if(flag) 
        printf(" miss");
    miss_count ++;
}

int if_evict(long long ind, long long p){

    for(int i = 0; i < E; ++i) {
        if(CACHE[p][i].ind == -1) return i;
    }
    return -1;
}

int if_miss(long long addr, long long *ind, long long *p) {
    addr = addr >> b;
    long long x_ind = addr & mask;
    long long x_p = addr & rmask;
    *ind = x_ind;
    *p = x_p;

    for(int i = 0; i < E; ++i) {
        if( CACHE[x_p][i].ind == x_ind)  return 0;
    }
    return 1;
}

void init_cache() {

    mask = (-1 << s);
    rmask = ~mask;
    CACHE = (cash**) malloc(sizeof(cash*) * S);
    for(int i = 0; i < S; ++i){
        CACHE[i] = (cash*) malloc(sizeof(cash) * E);
        for(int j = 0; j < E; j++) {
            CACHE[i][j].ind = -1;
            CACHE[i][j].use_t = 0;
        }
    }

}

void free_cache(){
    for(int i = 0; i < S; i++)
        free(CACHE[i]);
    free(CACHE);
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

void str2ins(char* ch, long long* ans, char *first, char *second){
    int commaPOS = 0;
    char addr[15];

    *ch = first[0];
    while(second[commaPOS] != ','){
        commaPOS ++;
    }
    for(int i = 0; i < commaPOS; ++i) 
        addr[i] = second[i];
    addr[commaPOS] = '\0';
    *ans = str2num(addr);
}

