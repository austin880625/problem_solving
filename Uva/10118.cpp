#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int dp[41][41][41][41];
int candy[41][4];
int N;
int cnt(int x)
{
    int res=0;
    while(x>0)
    {
        res+=(x&1);
        x>>=1;
    }
    return res;
}
int DP(int p1,int p2,int p3,int p4,int basket)
{
    if(dp[p1][p2][p3][p4]!=-1)return dp[p1][p2][p3][p4];
    if(!(p1||p2||p3||p4)||cnt(basket)==5)return 0;
    int &res=dp[p1][p2][p3][p4];
    int delt=0;
    if(p1>0)
    {
        delt=(basket>>(candy[p1][0])&1);
        res=max(res,delt+DP(p1-1,p2,p3,p4,basket^(1<<candy[p1][0])));
    }
    if(p2>0)
    {
        delt=(basket>>(candy[p2][1])&1);
        res=max(res,delt+DP(p1,p2-1,p3,p4,basket^(1<<candy[p2][1])));
    }
    if(p3>0)
    {
        delt=(basket>>(candy[p3][2])&1);
        res=max(res,delt+DP(p1,p2,p3-1,p4,basket^(1<<candy[p3][2])));
    }
    if(p4>0)
    {
        delt=(basket>>(candy[p4][3])&1);
        res=max(res,delt+DP(p1,p2,p3,p4-1,basket^(1<<candy[p4][3])));
    }
    return res;
}
int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        for(int i=N;i>=1;i--)
        {
            for(int j=0;j<4;j++)
            {
                candy[0][j]=0;
                scanf("%d",&candy[i][j]);
            }
        }
        int basket=0;
        memset(dp,-1,sizeof(dp));
        printf("%d\n",DP(N,N,N,N,basket));
    }
}
