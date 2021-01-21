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

vector<int> edges[N];
int b[N];
int n;
int m;
bool vis[N];
queue<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = true;
            int ans = 0;
            while (q.size())
            {
                int f = q.front();
                q.pop();
                ans += b[f];
                for (int j = 0; j < edges[f].size(); j++)
                {
                    int t = edges[f][j];
                    if (!vis[t])
                    {
                        q.push(t);
                        vis[t] = true;
                    }
                }
            }
            if (ans & 1)
            {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}