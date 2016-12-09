#include <stdio.h>
#include <iostream>
#define MAXN 105
#define INF 2147483647
using namespace std;

int w[MAXN][MAXN];
int d[MAXN][MAXN];
int N;

int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&w[i][j]);
                d[i][j]=w[i][j];
                if(w[i][j]==0)d[i][j]=INF;
            }
        }
        for(int k=0;k<N;k++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(d[i][k]!=INF&&d[k][j]!=INF)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        int ans=INF;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(w[i][j]&&d[j][i]!=INF)ans=min(ans,w[i][j]+d[j][i]);
            }
        }
        if(ans==INF)
        {
            puts("-1");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
