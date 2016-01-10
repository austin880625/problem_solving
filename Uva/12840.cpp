#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXS 400
#define MAXN 55
#define INF 2147483647
using namespace std;

int dp[MAXS];
int P[MAXN];
int T,N,S;

int main()
{
    int kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&S);
        for(int i=0;i<N;i++)scanf("%d",&P[i]);
        sort(P,P+N);
        for(int i=0;i<=S;i++)dp[i]=INF;
        dp[0]=1;
        for(int i=0;i<=S;i++)
        {
            if(dp[i]&&dp[i]!=INF)
                for(int j=0;j<N;j++)
                {
                    dp[i+P[j]]=min(dp[i]+1,dp[i+P[j]]);
                }
        }
        printf("Case %d: ",++kase);
        if(dp[S]==INF)
        {
            printf("impossible\n");
        }
        else
        {
            printf("[%d]",dp[S]-1);
            int t=S,step=dp[S];
            while(t!=0)
            {
                for(int i=N-1;i>=0;i--)
                {
                    if(t>=P[i]&&dp[t-P[i]]==step-1){step--;printf(" %d",P[i]);t-=P[i];break;}
                }
            }
            puts("");
        }
    }
    return 0;
}
