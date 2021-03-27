#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
#define MAXLL 0x7fffffffffffffff                                             //*
#define MAXINT 0x7fffffff                                                    //*
const int INF = 0x3f3f3f3f;                                                  //*
const ll INF_LL = 9223372036854775807LL;                                     //*
const double E = exp(1.0);                                                   //*
const double PI = acos(-1.0);                                                //*
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
ll lcd(ll a , ll b){return a * b / gcd(a,b);}                                //*
inline ll read(){                                                            //*
    char ch = getchar(); ll x = 0, f = 1;                                    //*
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}      //*
    while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}   //*
    return x * f;                                                            //*
}                                                                            //*
inline void write(ll x)                                                      //*
{                                                                            //*
    if(x<0) {                                                                //*
        putchar('-');                                                        //*
        x = -x;                                                              //*
    }                                                                        //*
    if(x>9) write(x / 10);                                                   //*
    putchar(x % 10 + '0');                                                   //*
}                                                                            //*
void init_cin(){                                                             //*
  std::ios::sync_with_stdio(false);                                          //*
  std::cin.tie(nullptr);                                                     //*
  std::cout.tie(nullptr);                                                    //*
}                                                                            //*
using namespace std;                                                         //*
//---------------------------------------------------------------------------//*

ll a[500001],op,l,r, k;
struct tree{
	ll add_a,add_a1,add_b,add_b1;
	ll l,r,maxa,se,maxb,sum,cnt; 
}s[2000001];

void push_up(ll p)
{
	s[p].maxa=max(s[p*2].maxa,s[p*2+1].maxa);
	s[p].maxb=max(s[p*2].maxb,s[p*2+1].maxb);
	s[p].sum=s[p*2].sum+s[p*2+1].sum;
	if(s[p*2].maxa==s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].se,s[p*2+1].se);
		s[p].cnt=s[p*2].cnt+s[p*2+1].cnt;
	}
	else if(s[p*2].maxa>s[p*2+1].maxa)
	{
		s[p].se=max(s[p*2].se,s[p*2+1].maxa);
		s[p].cnt=s[p*2].cnt;
	}
	else
	{
		s[p].se=max(s[p*2].maxa,s[p*2+1].se);
		s[p].cnt=s[p*2+1].cnt;
	}
}

void update(ll k1,ll k2,ll k3,ll k4,ll p)
{
	s[p].sum+=k1*s[p].cnt+k3*(s[p].r-s[p].l+1-s[p].cnt);
	s[p].maxb=max(s[p].maxb,s[p].maxa+k2);
	s[p].add_b=max(s[p].add_b,s[p].add_a+k2);
	s[p].add_b1=max(s[p].add_b1,s[p].add_a1+k4);
	s[p].maxa+=k1;
	s[p].add_a+=k1;
	s[p].add_a1+=k3;
	if(s[p].se!=-1e18)s[p].se+=k3;
}

void push_down(ll p)
{
	ll maxn=max(s[p*2].maxa,s[p*2+1].maxa);
	if(s[p*2].maxa==maxn)
	    update(s[p].add_a,s[p].add_b,s[p].add_a1,s[p].add_b1,p*2);
	else update(s[p].add_a1,s[p].add_b1,s[p].add_a1,s[p].add_b1,p*2);
	if(s[p*2+1].maxa==maxn)
		update(s[p].add_a,s[p].add_b,s[p].add_a1,s[p].add_b1,p*2+1);
	else update(s[p].add_a1,s[p].add_b1,s[p].add_a1,s[p].add_b1,p*2+1);
	s[p].add_a=s[p].add_b=s[p].add_a1=s[p].add_b1=0;
}

void build(ll l,ll r,ll p)
{
	s[p].l=l,s[p].r=r;
	if(l==r)
	{
		s[p].sum=a[l];
		s[p].maxa=a[l];
		s[p].maxb=a[l];
		s[p].se=-1e18;
		s[p].cnt=1;
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	push_up(p);
}

void update_min(ll p)
{
	if(s[p].l>r||s[p].r<l||k>=s[p].maxa)return;
	if(l<=s[p].l&&s[p].r<=r&&k>s[p].se)
	{
	    update(k-s[p].maxa,k-s[p].maxa,0,0,p);
		return;
	}
	push_down(p);
	update_min(p*2),update_min(p*2+1);
	push_up(p);
}

void update_add(ll p)
{
    if(s[p].l > r||s[p].r < l) return;
    if(l<=s[p].l && s[p].r<=r)
    {
        update(k, k, k, k, p);
        return;
    }
    push_down(p);
    update_add(p << 1), update_add(p<<1|1);
    push_up(p);
}

ll query_add(ll p)
{
	if(s[p].l>r||s[p].r<l)return 0;
	if(l<=s[p].l&&s[p].r<=r)return s[p].sum;
	push_down(p);
	return query_add(p*2)+query_add(p*2+1);
}

ll query_maxa(ll p)
{
	if(s[p].l>r||s[p].r<l)return -1e18;
	if(l<=s[p].l&&s[p].r<=r)return s[p].maxa;
	push_down(p);
	return max(query_maxa(p*2),query_maxa(p*2+1));
}

ll query_maxb(ll p)
{
	if(s[p].l>r||s[p].r<l)return -1e18;
	if(l<=s[p].l&&s[p].r<=r)return s[p].maxb;
	push_down(p);
	return max(query_maxb(p*2),query_maxb(p*2+1));
}

int main()
{   
	ll n=read(),m=read();
	for(ll i=1;i<=n;i++)
	    a[i]=read();
	build(1,n,1);
	for(ll i=1;i<=m;i++) 
	{
		cin >> op >> l >> r;
		if(op==1) {cin >> k; update_add(1); }
		if(op==2) {cin >> k; update_min(1); }
		if(op==3) cout << query_add(1) << endl;
		if(op==4) cout << query_maxa(1) << endl;
		if(op==5) cout << query_maxb(1) << endl;
	}
	return 0;
}

