#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXN 10000
#define INF 2147483646
using namespace std;
int N;
struct bulb
{
    int V,K,C,L;
    bool operator <(const bulb &rhs)const
    {
        return V<rhs.V;
    }
}B[MAXN];
int dp[MAXN];
int s[MAXN];

int main()
{
    while(scanf("%d",&N)==1)
    {
        if(!N)break;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d%d",&B[i].V,&B[i].K,&B[i].C,&B[i].L);
        }
        sort(B,B+N);
        s[0]=0;
        for(int i=1;i<=N;i++)
        {
            s[i]=s[i-1]+B[i-1].L;
            dp[i]=INF;
        }
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*B[i-1].C+B[i-1].K);
            }
        }
        printf("%d\n",dp[N]);
    }
    return 0;
}
