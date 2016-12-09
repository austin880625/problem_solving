#include <stdio.h>
#include <iostream>
#include <assert.h>

using namespace std;

int N;
int adj[18];
int cover[1048576];
int dp[1048576];

int DP(int S)
{
    if(!S)return dp[S]=0;
    if(dp[S]!=-1)return dp[S];
    int res=0;
    //pick every subset of S
    for(int i=S;i>0;i=(i-1)&S)
    {
        assert((S|i)==S);
        if(cover[i]==(1<<N)-1)res=max(res,DP(S^i)+1);
    }
    return dp[S]=res;
}

int main()
{
    int kase=0;
    while(scanf("%d",&N)==1&&N!=0)
    {
        for(int i=0;i<N;i++)
        {
            int m;
            adj[i]=(1<<i);
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int a;
                scanf("%d",&a);
                adj[i]|=(1<<a);
            }
        }
        for(int S=0;S<(1<<N);S++)
        {
            dp[S]=-1;
            cover[S]=0;
            for(int i=0;i<N;i++)
            {
                if((S>>i)&1)cover[S]|=adj[i];
            }
        }
        printf( "Case %d: %d\n",++kase,DP( (1<<N)-1 ) );
    }
    return 0;
}
