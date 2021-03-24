/* 
	Bug : << 2 -> << 1
 */
#include <bits/stdc++.h>
using namespace std;
int p;
long long a[100007];
struct node{
    long long v, mul, add;
}st[400007];
//buildtree
void bt(int root, int l, int r){
//初始化lazytag
    st[root].mul=1;
    st[root].add=0;
    if(l==r){
        st[root].v=a[l];
    }
    else{
        int m=(l+r)/2;
        bt(root*2, l, m);
        bt(root*2+1, m+1, r);
        st[root].v=st[root << 1].v+st[root << 1|1].v;
    }
    st[root].v%=p;
    return ;
}

void pushdown(int root, int l, int r){
    int m=(l+r)/2;
    st[root*2].v=(st[root*2].v*st[root].mul+st[root].add*(m-l+1))%p;
    st[root*2+1].v=(st[root*2+1].v*st[root].mul+st[root].add*(r-m))%p;
    st[root*2].mul=(st[root*2].mul*st[root].mul)%p;
    st[root*2+1].mul=(st[root*2+1].mul*st[root].mul)%p;
    st[root*2].add=(st[root*2].add*st[root].mul+st[root].add)%p;
    st[root*2+1].add=(st[root*2+1].add*st[root].mul+st[root].add)%p;
    st[root].mul=1;
    st[root].add=0;
    return ;
}

void ud1(int root, int stdl, int stdr, int l, int r, long long k){
    if(r<stdl || stdr<l){
        return ;
    }
    if(l<=stdl && stdr<=r){
        st[root].v=(st[root].v*k)%p;
        st[root].mul=(st[root].mul*k)%p;
        st[root].add=(st[root].add*k)%p;
        return ;
    }
//假如给出的区间和本区间有交集，但是也有不交叉的部分
//先传递lazytag
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud1(root*2, stdl, m, l, r, k);
    ud1(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//update2，加法，和乘法同理
void ud2(int root, int stdl, int stdr, int l, int r, long long k){
    if(r<stdl || stdr<l){
        return ;
    }
    if(l<=stdl && stdr<=r){
        st[root].add=(st[root].add+k)%p;
        st[root].v=(st[root].v+k*(stdr-stdl+1))%p;
        return ;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud2(root*2, stdl, m, l, r, k);
    ud2(root*2+1, m+1, stdr, l, r, k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return ;
}
//访问，和update一样
long long query(int root, int stdl, int stdr, int l, int r){
    if(r<stdl || stdr<l){
        return 0;
    }
    if(l<=stdl && stdr<=r){
        return st[root].v;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    return (query(root*2, stdl, m, l, r)+query(root*2+1, m+1, stdr, l, r))%p;
}
int main(){
	ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m >> p;
    for(int i=1; i<=n; i++){
		cin >> a[i];
    }
    bt(1, 1, n);
    while(m--){
        int chk;
		cin >> chk;
        int x, y;
        long long k;
        if(chk==1){
			cin >> x >> y >> k;
            ud1(1, 1, n, x, y, k);
        }
        else if(chk==2){
			cin >> x >> y >> k;
            ud2(1, 1, n, x, y, k);
        }
        else{
			cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}








/* bug eccurs 
   date : 3/24/2021
  	*/


// #include <cstdio>
// #include <bits/stdc++.h>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lson l, mid, rt << 1
// #define rson mid + 1, r, rt << 1 | 1
// using namespace std;
// int const MAX = 110000;
// ll const INF = 0x7fffffffffffffffLL;
// char s[100];
// ll mi[MAX << 2], lp[MAX << 2], lm[MAX << 2];
// int n, m, p;
 
// void PushUp(int rt)
// {
//     mi[rt] = mi[rt << 1] + mi[rt << 1|1];
// }

// void Build(int l, int r, int rt)
// {
// 	lp[rt] = 0;
// 	lm[rt] = 1;
// 	if(l == r)
// 	{
//         cin >> mi[rt];
// 		return;
// 	}
// 	int mid = (l + r) >> 1;
// 	Build(lson);
// 	Build(rson);
// 	PushUp(rt);
// }

// void PushDownP(int l, int r, int rt);
// void PushDownM(int l, int r, int rt)
// {
// 	if(rt > (n << 2)) return;
// 	ll tmp = lm[rt];
//     if(tmp != 1) 
//     {
//         lm[rt << 1] *= tmp;
//         mi[rt << 1] *= tmp;
//         lm[rt << 1|1] *= tmp;
//         mi[rt << 1|1] *= tmp; 
//         lm[rt] = 1;
// 		int m = (l + r) >> 1;
// 		if(lp[rt << 1]) PushDownP(l, m, rt << 1);
// 		if(lp[rt << 1|1]) PushDownP(m+1, r, rt << 1|1);
//     }
// }

// void PushDownP(int l, int r, int rt)
// {	
// 	if(rt > (n << 2)) return;
//     if(ll tmp = lp[rt])
//     {
// 		// lp, lm
//         lp[rt << 1] += tmp;
//         mi[rt << 1] += tmp * (r - l + 1);
//         lp[rt << 1|1] += tmp;
//         mi[rt << 1|1] += tmp * (r - l + 1); 
//         lp[rt] = 0;
// 		int m = (l + r) >> 1;
// 		if(lm[rt << 1]) PushDownM(l, m, rt << 1);
// 		if(lm[rt << 1|1]) PushDownM(m + 1, r, rt << 1|1);
//     }
// }

// void UpdateM(int L, int R, int c, int l, int r, int rt)
// {
// 	if(L <= l && r <= R)
// 	{
// 		mi[rt] *= c;
// 		lm[rt] *= c;
// 		PushDownP(l, r, rt);
// 		return;
// 	}
// 	ll mid = (l + r) >> 1;
// 	PushDownM(l, r, rt);
// 	if(L <= mid)
// 		UpdateM(L, R, c, lson);
// 	if(mid < R)
// 		UpdateM(L, R, c, rson);
// 	PushUp(rt);
// }
// void UpdateP(int L, int R, int c, int l, int r, int rt)
// {
//     if(L <= l && r <= R)
// 	{
// 		mi[rt] += c * (r - l + 1);
// 		lp[rt] += c;
// 		PushDownM(l, r, rt);
// 		return;
// 	}
//     ll mid = (l + r) >> 1;
// 	PushDownP(l, r, rt);
// 	if(L <= mid)
// 		UpdateP(L, R, c, lson);
// 	if(mid < R)
// 		UpdateP(L, R, c, rson);
// 	PushUp(rt);
// }
 
// ll Query(int L, int R, int l, int r, int rt)
// {
// 	if(L <= l && r <= R)
// 		return mi[rt];
// 	int mid = (l + r) >> 1;
// 	ll ans = 0;
// 	PushDownP(l, r, rt);
// 	PushDownM(l, r, rt);
// 	if(L <= mid)
// 		ans += Query(L, R, lson);
// 	if(mid < R)
// 		ans += Query(L, R, rson);
// 	return ans;
// }
 
// int main()
// {
// 	cin >> n >> m >> p;
// 	Build(1, n, 1);
// 	while(m--)
// 	{
// 		int ins, l, r, c;
//         cin >> ins >> l >> r;
//         if(ins == 1) {
//             cin >> c;
// 			UpdateM(l, r, c, 1, n, 1);
//         }
//         else if (ins == 2) {
// 			cin >> c;
// 			UpdateP(l, r, c, 1, n, 1);
//         }
//         else {
// 			cout << "Q: " << Query(l, r, 1, n, 1) % p << endl;;
//         }
// 	}
//     return 0;
// }

// /* 
// // debug log
// // int -> ll
// // scanf -> cin
// // more space
// //  
// */