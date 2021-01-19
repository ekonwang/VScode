#ifndef _FACTORIAL_H_
#define _FACTORIAL_H_

#include<bits/stdc++.h>

#ifndef N
#define N 30
int factorial(int a[], int n, int restrait = N){
    int k, i;
    memset(a, 0, sizeof(int) * restrait);
    a[0] = 1;
    for(k = 2; k <= n; k++){
        for(i = 0; i < N; i++) a[i] = a[i] * k; //log1 + log2 + log3
        for(i = 0; i < N - 1; i++){
            a[i + 1] += a[i] / 10;
            a[i] = a[i] % 10;
        }
        a[i] = a[i] % 10;
    }
    int high = restrait;
    while(!a[high]) high--;
    return high;
}
#endif //#define N
#endif //#define _CLOCK_H_