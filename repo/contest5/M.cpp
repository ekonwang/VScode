#include <cstring>
#include <iostream>

using namespace std;
#define mod 1000000007
#define ll long long

ll quick(ll a, ll p)
{
    ll res = 1, temp = a % mod;
    while (p)
    {
        if (p & 1)
            res = res * temp % mod;
        temp = temp * temp % mod;
        p >>= 1;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ll res = (quick(2, b + 1) - quick(2, a) + mod) *
                 (quick(3, d + 1) - quick(3, c) + mod) % mod * (mod + 1) / 2 %
                 mod;
        printf("%d\n", res);
    }

    return 0;
}