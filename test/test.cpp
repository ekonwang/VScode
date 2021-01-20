#include <bits/stdc++.h>
using namespace std;

int T,n,m,x,f[10100],a[10010],sg[100010];
bool vis[100010];

int main()
{
	for (int i=1; i<=10001; i++) f[i]=i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int ans=0;
		for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		if (ans) printf("Yes\n");
		else printf("No\n"); 
	}
	return 0;
}