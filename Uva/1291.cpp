#include <iostream>
#include <stdio.h>
#include <vector>
#define INF 0x3f3f3f
#define MAXN 10000000
using namespace std;

int N,dp[MAXN][5][5];
int w[5][5]={
    {1,2,2,2,2},
    {INF,1,3,4,3},
    {INF,3,1,3,4},
    {INF,4,3,1,3},
    {INF,3,4,3,1}
};
vector<int> step;

int main()
{
    int x;
    while(1){
        step.clear();
        while(scanf("%d",&x)==1&&x!=0)
        {
            step.push_back(x);
        }
        if(!step.size())break;
        N=step.size();
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<5;j++)
            {
                for(int k=0;k<5;k++)
                    dp[i][j][k]=INF;
            }
        }
        dp[0][0][0]=0;
        for(int i=1;i<=N;i++)
        {
            int nxt=step[i-1];
            for(int j=0;j<5;j++)
            {
                for(int k=0;k<5;k++)
                {
                    if(j!=nxt)
                    {
                        dp[i][j][nxt]=min(dp[i][j][nxt],dp[i-1][j][k]+w[k][nxt]);
                    }
                    if(k!=nxt)
                    {
                        dp[i][nxt][k]=min(dp[i][nxt][k],dp[i-1][j][k]+w[j][nxt]);
                    }
                    if(j==nxt||k==nxt)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]+1);
                    }
                }
            }
        }
        int ans=INF;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                ans=min(ans,dp[N][i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
