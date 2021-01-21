#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define N 1000010

int dp[N];
int p;

int main()
{
    int t;
    scanf("%d", &t);
    dp[1] = 1;
    dp[0] = 1;
    while (t--)
    {
        scanf("%d", &p);
        long long cnt = 1;
        for (int i = 2; i < p; i++)
            dp[i] = dp[p % i] + 1, cnt += dp[i];
        printf("%.8f\n", 1. * cnt / (p - 1));
    }

    return 0;
}