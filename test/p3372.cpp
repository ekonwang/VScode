#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
int const MAX = 110000;
ll const INF = 0x7fffffffffffffff;
char s[100];
ll mi[MAX << 1], lp[MAX << 1], lm[MAX << 1];
int n, m, p;
 
void PushUp(int rt)
{
    mi[rt] = mi[rt << 1] + mi[rt << 1|1];
}

void Build(int l, int r, int rt)
{
	lp[rt] = lm[rt] = 0;
	if(l == r)
	{
        cin >> mi[rt];
		return;
	}
	int mid = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

void PushDownM(int rt)
{
    if(ll tmp = lm[rt]) 
    {
        lm[rt << 1] *= tmp;
        mi[rt << 1] *= tmp;
        lm[rt << 1|1] = tmp;
        mi[rt << 1|1] *= tmp; 
        lm[rt] = 0;
    }
}

void PushDownP(int rt)
{
    if(ll tmp = lp[rt])
    {
        lp[rt << 1] += tmp;
        
    }
}

void UpdateM(int L, int R, int c, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		mi[rt] *= c;
		lm[rt] *= c;
		return;
	}
	ll mid = (l + r) >> 1;
	PushDownM(rt);
	if(L <= mid)
		Update(L, R, c, lson);
	if(mid < R)
		Update(L, R, c, rson);
	PushUp(rt);
}
void UpdateP(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && r <= R)
	{
		mi[rt] += c;
		lazy[rt] += c;
		return;
	}
    ll mid = (l + r) >> 1;
	PushDownP(rt);
	if(L <= mid)
		UpdateP(L, R, c, lson);
	if(mid < R)
		UpdateP(L, R, c, rson);
	PushUp(rt);
}
 
ll Query(int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
		return mi[rt];
	int mid = (l + r) >> 1;
	ll ans = INF;
	PushDown(rt);
	if(L <= mid)
		ans = min(ans, Query(L, R, lson));
	if(mid < R)
		ans = min(ans, Query(L, R, rson));
	return ans;
}
 
int main()
{
	cin >> n >> m >> p;
	Build(1, n, 1);
	while(m--)
	{
		int ins, l, r, c;
        cin >> ins >> l >> r;
        if(ins == 1) {
            cin >> c;

        }
        else if (ins == 2) {

        }
        else {

        }
		l ++;
		r ++;
		if(getchar() == ' ')
		{
			cin >> c;
			if(l <= r)
				Update(l, r, c, 1, n, 1);
			else
			{
				Update(1, r, c, 1, n, 1);
				Update(l, n, c, 1, n, 1);
			}
		}
		else
		{
			if(l <= r)
				cout << Query(l, r, 1, n, 1) << endl;
			else
				cout << min(Query(1, r, 1, n, 1), Query(l, n, 1, n, 1)) << endl;
		}
	}
    return 0;
}

/* 
// debug log
// int -> ll
// scanf -> cin
// more space
//  
*/