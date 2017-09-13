#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 100005

using namespace std;

struct Dom
{
    int d,n,id;
    bool operator <(const Dom &x)
    {
        return d>x.d;
    }
};
Dom D[15];
int N,C;
int dp[2][100005];

int main()
{
    while(scanf("%d%d",&C,&N)==2)
    {
        for(int i=0;i<2;i++)for(int j=0;j<=C;j++)dp[i][j]=0;
        D[0].n=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&D[i].n,&D[i].d);
            D[i].id=i;
        }
        dp[0][0]=1;
        for(int i=0,t=0;i<N;i++,t^=1)
        {
            for(int j=0;j<=C;j++)
            {
                if(dp[t][j])
                {
                    for(int k=0;k<=D[i+1].n;k++)
                    {
                        if(j+D[i+1].d*k<=C)dp[t^1][j+D[i+1].d*k]=1;
                    }
                }
            }
        }
        for(int ans=C;ans>=0;ans--)if(dp[N&1][ans]){printf("%d\n",ans);break;}
    }
    return 0;
}
