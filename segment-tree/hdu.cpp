/* 线段树树上二分 */
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int sz=200100;
int n,a[sz],pre[sz],s[sz];
long long ans,add;
template <typename Tp> bool read(Tp &x)
{
    x=0;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!=-1) ch=getchar();
    if(ch==-1) return false;
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return true;
}
int min(int x,int y){return x<y?x:y;}
int main()
{
    while(read(n)&&n)
    {
        for(int i=1;i<=n;i++)
          read(a[i]);
        memset(pre,0,sizeof(pre));
        memset(s,0,sizeof(s));
        ans=add=0;
        for(int i=1;i<=n;i++,ans+=add)
            if(a[i]<=n)
            {
            int temp=pre[a[i]];
            pre[a[i]]=i;
            for(int j=a[i];j<=n;j++)
            {
                s[j]=(j==0?pre[j]:min(s[j-1],pre[j]));
                if(s[j]>temp)
                  add+=s[j]-temp;
                else//s滿足非嚴格遞減，break以免TLE
                  break;
            }
            }
        printf("%lld\n",ans);
    }
    return 0;