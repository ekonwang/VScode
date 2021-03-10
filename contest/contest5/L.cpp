#include <cstring>
#include <deque>
#include <iostream>
#include <map>

using namespace std;
#define N 100010
#define mod 1000000007
#define ll long long

int n;
int in[N][2];
int maxy[N];
int maxx;
map<ll, int> dp;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &in[i][0], &in[i][1]);
    for (int i = 0; i < n; i++)
    {
        if (maxy[in[i][0]] < in[i][1])
            maxy[in[i][0]] = in[i][1];
        if (maxx < in[i][0])
            maxx = in[i][0];
    }
    for (ll i = maxx; i > 0; i--)
    {
        dp[i * N + maxy[i]] = 1;
        for (ll j = maxy[i] - 1; j > 0; j--)
        {
            dp[i * N + j] = dp[i * N + j + 1];
            if (j <= maxy[i + 1])
            {
                dp[i * N + j] += dp[(i + 1) * N + j];
                dp[i * N + j] %= mod;
            }
        }
    }
    printf("%d\n", dp[N + 1]);

    return 0;
}
