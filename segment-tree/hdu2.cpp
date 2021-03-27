#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include <algorithm>
#define maxn 200005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define LL long long
#include <map>
int Next[maxn];
int a[maxn];
int N;
map <int,int> pre;
int Max[maxn*4];
LL sum[maxn*4];
int lazy[maxn*4];
int mex[maxn];
void pushdown(int rt,int l,int r){
	if(lazy[rt]!=-1){
		int v=lazy[rt];
		lazy[rt<<1]=lazy[rt<<1|1]=v;
		Max[rt<<1]=Max[rt<<1|1]=v;
		int mid=(l+r)>>1;
		sum[rt<<1]=(mid-l+1)*v;
		sum[rt<<1|1]=(r-mid)*v;
		lazy[rt]=-1;
	}
}
 
void pushup(int rt){
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
 
void build(int l,int r,int rt){
	lazy[rt]=-1;
	if(l==r){
		Max[rt]=sum[rt]=mex[l];
		return ;
	}
 
	int mid=(l+r)/2;
	build(lson);
	build(rson);
	pushup(rt);
}
 
int GetPos(int l,int r,int rt,int v){
	if(l==r) return l;
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(Max[rt<<1]>v) return GetPos(lson,v);
	else return GetPos(rson,v);
}
 
void update(int l,int r,int rt,int L,int R,int v){
	if(l>=L&&r<=R){
		sum[rt]=v*(r-l+1);
		Max[rt]=v;
		lazy[rt]=v;
		return ;
	}
	pushdown(rt,l,r);
	int mid=(l+r)/2;
	if(mid>=L) update(lson,L,R,v);
	if(mid<R) update(rson,L,R,v);
	pushup(rt);
}
 
LL query(int l,int r,int rt,int L,int R){
	if(l>=L&&r<=R) return sum[rt];
	pushdown(rt,l,r);
	LL res=0;
	int mid=(l+r)/2;
	if(mid>=L) res+=query(lson,L,R);
	if(mid<R) res+=query(rson,L,R);
	return res;
}
 
int main(){
	while(~scanf("%d",&N)){
		if(!N) break;
		pre.clear();
		memset(Next,-1,sizeof(Next));
		int Min=0;
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			int cur=a[i];
			if(!pre.count(cur)) pre[cur]=i;
			else{
				Next[pre[cur]]=i-1;
				pre[cur]=i;
			}
			while(pre.count(Min)) Min++;
			mex[i]=Min;
		}
		for(int i=1;i<=N;i++){
			if(Next[i]==-1) Next[i]=N;
		}
		build(1,N,1);
		LL res=0;
		for(int i=1;i<=N;i++){
			res+=query(1,N,1,i,N);
			if(Max[1]<a[i]) continue;
			int pos=GetPos(1,N,1,a[i]);
			pos=max(pos,i);
			update(1,N,1,pos,Next[i],a[i]);
		}
		printf("%I64d\n",res);
	}
	return 0;
}
