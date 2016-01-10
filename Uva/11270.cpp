#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
const int MAXM=15;
unsigned long long int dp[2][1<<MAXM];
unsigned long long int ans[101][101];
int n,m;

int left(int x)
{
    return ((x<<1)^(1<<m))^3;
}
int empty(int x)
{
    return (x<<1)^(1<<m);
}
int upper(int x)
{
    return (x<<1)^1;
}

int trans(int x)
{
    for(int i=0;i<m;i++)
    {
        printf("%d",x&1);
        x>>=1;
    }
    printf(" ");
}

int main()
{
    memset(ans,-1,sizeof(ans));
    while(scanf("%d%d",&m,&n)==2)
    {
        if(m>n)swap(n,m);
        if(ans[n][m]!=-1){printf("%llu\n",ans[n][m]);continue;}
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cur^=1;
                memset(dp[cur],0,sizeof(dp[cur]));
                for(int k=0;k<(1<<m);k++)
                {
                    //puts("");
                    if(k&(1<<(m-1)))
                    {
                        //cout<<k<<" "<<trans(k)<<endl;
                        if(j&&!(k&1))dp[cur][left(k)]+=dp[cur^1][k];
                        dp[cur][empty(k)]+=dp[cur^1][k];
                    }
                    else
                    {
                        if(i)dp[cur][upper(k)]+=dp[cur^1][k];
                    }
                }
            }
        }
        ans[n][m]=ans[m][n]=dp[cur][(1<<m)-1];
        printf("%llu\n",dp[cur][(1<<m)-1]);
    }
    return 0;
}
