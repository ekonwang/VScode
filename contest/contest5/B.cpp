#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define N 1001

void sol()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
        cout << "Yes" << endl;
    else
    {
        if (k == 2)
            if (n % 2)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        else if (n == 4 && k == 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
    return 0;
}