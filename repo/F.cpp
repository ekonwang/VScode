#pragma GCC optimize(2)
#include <cstring>
#include <iostream>

using namespace std;
int n;
int a[100010];
int b[100010];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
        b[i] = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            if (b[i] == 1)
            {
                puts("No");
                return 0;
            }
            else
            {
                b[i] = 0;
                b[i + 1] = 0;
            }
        if (a[i] == 2)
            if (b[i] == 0)
            {
                puts("No");
                return 0;
            }
            else
            {
                b[i] = 1;
                b[i + 1] = 1;
            }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (b[i] == b[i + 1] && b[i] != -1)
            {
                puts("No");
                return 0;
            }
            else if (b[i] != -1)
                b[i + 1] = 1 - b[i];
        }
    }
    puts("Yes");
    return 0;
}