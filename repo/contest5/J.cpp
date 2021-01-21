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

#define N 100010

int a[N];
int b[N];
bool vis[N];
map<int, int> ans;
int n, m;
int x, y;

int main()
{
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
        if (a[i])
            cnt1++, x = i;
    for (int i = 0; i < m; i++)
        if (b[i])
            cnt2++, y = i;
    if (cnt1 != 1 || cnt2 != 1)
    {
        puts("No");
        return 0;
    }
    if (a[x] != 1 && b[y] != 1)
    {
        puts("No");
        return 0;
    }
    vis[0] = 1;
    int cnt = 1;
    ans[x * m + y] = 0;
    if (a[x] != 1)
    {
        if (a[x] > m)
        {
            puts("No");
            return 0;
        }
        for (int i = 0; i < m; i++)
        {
            if (i != y)
                ans[x * m + i] = cnt, vis[cnt] = true, cnt++;
            if (cnt == a[x])
                cnt++;
        }
        if (vis[n * m])
        {
            puts("No");
            return 0;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == x)
                continue;
            for (int j = 0; j < m; j++)
            {
                while (vis[cnt])
                    cnt++;
                ans[i * m + j] = cnt++;
            }
        }
    }
    else if (b[y] != 1)
    {
        if (b[y] > n)
        {
            puts("No");
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != x)
                ans[i * m + y] = cnt, vis[cnt] = true, cnt++;
            if (cnt == b[y])
                cnt++;
        }
        if (vis[n * m])
        {
            puts("No");
            return 0;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == y)
                    continue;
                while (vis[cnt])
                    cnt++;
                ans[i * m + j] = cnt++;
            }
        }
    }
    else
    {
        cnt = 2;
        for (int i = 0; i < n; i++)
        {
            if (i != x)
                ans[i * m + y] = cnt, vis[cnt] = true, cnt++;
        }
        for (int i = 0; i < m; i++)
        {
            if (i != y)
                ans[x * m + i] = cnt, vis[cnt] = true, cnt++;
        }
        if (vis[n * m])
        {
            puts("No");
            return 0;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == x)
                continue;
            for (int j = 0; j < m; j++)
            {
                if (j == y)
                    continue;
                while (vis[cnt])
                    cnt++;
                ans[i * m + j] = cnt++;
            }
        }
    }

    puts("Yes");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%c", ans[i * m + j], (j == m - 1) ? '\n' : ' ');
    return 0;
}