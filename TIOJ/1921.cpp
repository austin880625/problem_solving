#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 100005
#define LL  long long int

using  namespace std;

struct mac
{
    int d;
    LL p,r,g;
    bool operator <(const mac &x)const
    {
        return d<x.d;
    }
};

LL dp[MAXN];
mac M[MAXN];
int N,D;
LL C;

int main()
{
    scanf("%d%lld%d",&N,&C,&D);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%lld%lld%lld",&M[i].d,&M[i].p,&M[i].r,&M[i].g);
    }
    sort(M+1,M+1+N);
    M[0]=(mac){0,0,0,0};
    M[N+1]=(mac){D+1,0,0,0};
    dp[0]=C;
    for(int i=1;i<=N+1;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            if(dp[j]>=M[j].p)dp[i]=max(dp[i],dp[j]-M[j].p+M[j].r+M[j].g*(M[i].d-M[j].d-1));
        }
    }
    printf("%lld\n",dp[N+1]);
	return 0;
}
