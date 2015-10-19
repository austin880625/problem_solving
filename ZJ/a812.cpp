#include<iostream>
#include<stdio.h>
#include<string.h>
#define ll long long
using namespace std;
int x,y,M;
ll dp[65][65][3605];
ll ans;
int main()
{
    while(scanf("%d %d %d",&x,&y,&M)==3)
    {
        ans=0;
        memset(dp,0,sizeof(dp));
        dp[1][0][0]=1;
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                for(int k=0;k<M;k++)
                {
                    if(i!=x)dp[i+1][j][(k*2)%M]+=dp[i][j][k];
                    if(j!=y&&j+1<=i)dp[i][j+1][(k*2+1)%M]+=dp[i][j][k];
                    //cout<<i+1<<" "<<j<<" "<<(k*2)%M<<" "<<i<<" "<<j+1<<" "<<(k*2)%M<<endl;
                }
            }
        }
        
        for(int i=0;i<M;i++)ans+=dp[x][y][i]*i;
        printf("%lld\n",ans);
        break;
    }
    return 0;
}