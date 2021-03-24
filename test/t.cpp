#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
int const MAX = 200005;
ll const INF = 0x7fffffffffffffff;
char s[100];
ll mi[MAX << 2], lazy[MAX << 2];
int n, q;
 
void PushUp(int rt)
{
	mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
 
void PushDown(int rt)
{
	if(lazy[rt])
	{
		mi[rt << 1] += lazy[rt];
		mi[rt << 1 | 1] += lazy[rt];
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}
 
void Build(int l, int r, int rt)
{
	lazy[rt] = 0;
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
 
void Update(int L, int R, int c, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		mi[rt] += c;
		lazy[rt] += c;
		return;
	}
	ll mid = (l + r) >> 1;
	PushDown(rt);
	if(L <= mid)
		Update(L, R, c, lson);
	if(mid < R)
		Update(L, R, c, rson);
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
	cin >> n;
	Build(1, n, 1);
	cin >> q;
	while(q --)
	{
		int l, r, c;
		cin >> l >> r;
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