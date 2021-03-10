#include <bits/stdc++.h>
using namespace std;
#define eps 1e-7

double h, l, w;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf%lf", &h, &l, &w);
        double alpha = atan(w / 2. / h);
        double r1 = l * tan(alpha / 2) / (1 - tan(alpha / 2));
        // printf("%.8f\n", r1);
        if ((l + r1) * cos(alpha) > h)
        {
            double ll = (h - l) / 2, rr = 1e9;
            while (ll < rr - eps)
            {
                double mm = (ll + rr) / 2;
                double x = asin(sqrt((h - l) / 2. / mm));
                if (2 * mm * (1 + sin(2 * x)) > w)
                    rr = mm;
                else
                    ll = mm;
            }
            printf("%.8f\n", (ll + rr) / 2);
        }
        else
            printf("%.8f\n", r1);
    }

    return 0;
}