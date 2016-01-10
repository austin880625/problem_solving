#include <iostream>
#include <stdio.h>
#define MAXN 62505
#define INF 2147483646
using namespace std;
int T,N,P,Q;
int dp[MAXN];
int g[MAXN];
int a[MAXN],b[MAXN];
int f[MAXN];
int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        scanf("%d%d%d",&N,&P,&Q);
        for(int i=0;i<=max(P,Q)+1;i++){f[i]=0;g[i]=INF;}
        for(int i=1;i<=P+1;i++)
        {
            scanf("%d",&a[i]);
            f[a[i]]=i;
        }
        for(int i=1;i<=Q+1;i++)
        {
            scanf("%d",&b[i]);
            b[i]=f[b[i]];
        }
        g[1]=dp[1]=1;
        for(int i=1;i<=Q+1;i++)
        {
            int l=1,r=i;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(g[mid]<b[i])l=mid+1;
                else r=mid;
            }
            //cout<<l<<endl;
            dp[i]=l;
            g[l]=min(g[l],b[i]);
        }
        printf("Case %d: %d\n",++kase,dp[Q+1]);
    }
    return 0;
}
