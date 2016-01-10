#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#define MAXN 105
#define MAXM 35
#define INF 0x3f3f3f3f
using namespace std;

int M,N;
int P[MAXM];
int dp1[MAXM][MAXN];
int dp2[MAXM][MAXN];

int main()
{
    while(scanf("%d%d",&N,&M)==2&&(N||M))
    {
        for(int i=1;i<=M;i++)scanf("%d",&P[i]);
        sort(P+1,P+1+M);
        for(int i=0;i<=N;i++)dp1[0][i]=0,dp2[0][i]=INF;
        int ans=0;
        for(int i=1;i<=M;i++)
        {
            //cout<<"P["<<i<<"]: "<<P[i]<<endl;
            dp1[i-1][0]=INF;
            for(int j=1;j<=N;j++)
            {
                dp1[i][j]=dp1[i-1][j];
                for(int k=1;k<=j;k++)
                {
                    int minU=min(dp1[i-1][j-k],P[i]/k);
                    if(dp1[i][j]<minU)
                    {
                        dp1[i][j]=minU;
                        //cout<<i<<endl;
                    }
                    //if(i==2&&j==2&&k==1)cout<<dp1[i-1][j-k]<<" "<<dp1[i][j]<<"\n";
                }

                //if(i==2&&j==2)cout<<dp1[i][j]<<"\n";
            }
            //puts("");
        }
        for(int i=1;i<=M;i++)
        {
            dp2[i-1][0]=0;
            for(int j=1;j<=N;j++)
            {
                dp2[i][j]=dp2[i-1][j];
                for(int k=1;k<=j;k++)
                {
                    if(P[i]/k>=dp1[M][N])dp2[i][j]=min(dp2[i][j],dp2[i-1][j-k]+P[i]);
                }
            }
        }

        printf("%d %d\n",dp1[M][N],dp1[M][N] ? dp2[M][N] : 0);
    }
    return 0;
}
