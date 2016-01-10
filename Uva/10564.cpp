#include <iostream>
#include <stdio.h>
#include <string.h>
#define LL long long int
using namespace std;

LL dp[50][50][550];

int hg[50][50];
int N,S;

int main()
{
    while(scanf("%d%d",&N,&S)==2&&(N||S))
    {
        memset(dp,0,sizeof(dp));
        int t=0;
        for(int i=N;i>=1;i--)
        {
            for(int j=0;j<i;j++)scanf("%d",&hg[t][j]);
            hg[t][i]=-1;
            t++;
        }
        for(int i=2;i<=N;i++)
        {
            for(int j=0;j<i;j++)scanf("%d",&hg[t][j]);
            hg[t][i]=-1;
            t++;
        }
        for(int i=0;i<N;i++)dp[t][i][S]=dp[t-1][i][S-hg[t-1][i]]=1;
        for(int i=t-2;i>=0;i--)
        {
            for(int j=0;hg[i][j]!=-1;j++)
            {
                //if(i==t-6)cout<<hg[i][j]<<endl;
                for(int k=0;k<=S;k++)
                {
                    //if(i==t-6&&k==2)
                    if(k+hg[i][j]<=S)
                    if(i>=N-1)dp[i][j][k]=dp[i+1][j][k+hg[i][j]]+dp[i+1][j+1][k+hg[i][j]];
                    else
                    {
                        if(j>0)dp[i][j][k]+=dp[i+1][j-1][k+hg[i][j]];
                        if(hg[i][j+1]!=-1)dp[i][j][k]+=dp[i+1][j][k+hg[i][j]];
                    }
                    //if(i==t-5&&j==0&&k==10)printf("%d \n",dp[i][j][k]);
                }
                //puts("");
            }
        }
        LL ans=0,k=N;
        for(int i=N-1;i>=0;i--)if(dp[0][i][0]){k=i;ans+=dp[0][i][0];}
        if(ans)printf("%lld\n",ans);
        else {puts("0");puts("");continue;}
        printf("%d ",k);
        int sum=0,i=0;
        while(i<t-1)
        {
            if(i<N-1)
            {
                if(k>0)
                    if(dp[i+1][k-1][sum+hg[i][k]]){printf("L");sum+=hg[i][k];k=k-1;}
                    else {printf("R");sum+=hg[i][k];}
                else
                {
                    printf("R");sum+=hg[i][k];
                }
            }
            else
            {
                if(dp[i+1][k][sum+hg[i][k]]){printf("L");sum+=hg[i][k];}
                else {printf("R");sum+=hg[i][k];k=k+1;}
            }
            i++;
        }
        puts("");
    }
    return 0;
}
