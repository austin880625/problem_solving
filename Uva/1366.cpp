#include <iostream>
#include <stdio.h>
#define MAXN 505
using namespace std;

int N,M;
int dp[MAXN][MAXN];
int MINER[2][MAXN][MAXN];
void print()
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<=N;j++)
        {
            for(int k=0;k<=M;k++)
            {
                printf("%d\t",MINER[i][j][k]);
            }
            puts("");
        }
        puts("");
    }
}
int main()
{
    while(scanf("%d%d",&N,&M)==2&&(N||M))
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<=N;j++)
            {
                for(int k=0;k<=M;k++)
                {
                    MINER[i][j][k]=0;
                    if(j&&k){
                        scanf("%d",&MINER[i][j][k]);
                        if(i==0)MINER[i][j][k]+=MINER[i][j][k-1];
                        else MINER[i][j][k]+=MINER[i][j-1][k];
                    }
                    dp[j][k]=0;
                }
            }
        }
        //print();
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                dp[i][j]=max(dp[i-1][j]+MINER[0][i][j],dp[i][j-1]+MINER[1][i][j]);
            }
        }
        printf("%d\n",dp[N][M]);
    }
}
