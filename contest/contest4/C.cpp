#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int out[20][1 << 19];

int main()
{
    out[0][0] = 1;
    for (int i = 1; i < 16; i++)
    {
        for (int j = 0; j < (1 << (i - 1)); j++)
        {
            out[i][j * 2] = i + 1;
            out[i][j * 2 + 1] = out[i - 1][j];
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        printf("%d%c", out[15][i], (i == n - 1) ? '\n' : ' ');

    return 0;
}
