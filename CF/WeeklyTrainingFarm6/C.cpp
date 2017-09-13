#include <stdio.h>
#include <iostream>
#define LL long long int
#define INF 1000000000000000
#define MAXN 105

using namespace std;

int N,M,K;
LL dp[MAXN][MAXN][MAXN];
LL P[MAXN][MAXN];
int C[MAXN];

int main()
{
    while(scanf("%d%d%d",&N,&M,&K)==3)
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d",C+i);
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf("%I64d",&P[i][j]);
            }
        }

        LL ans=INF;

        for(int i=0;i<=M;i++)
        {
            dp[0][i][0]=0;
            for(int j=1;j<=K;j++)dp[0][i][j]=INF;
        }
        //cout<<"YEEEE"<<dp[0][2][3]<<endl;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                for(int k=0;k<=K;k++)
                {
                    dp[i][j][k]=INF;
                    if(i==1&&k==1){
                        dp[i][j][k]=(C[i]==0 ? P[i][j] : (j==C[i] ? 0 : INF));
                        if(k==K&&i==N)ans=min(ans,dp[i][j][k]);
                        continue;
                    }
                    if(k==0||(C[i]!=0&&j!=C[i]))
                        continue;

                    dp[i][j][k]=dp[i-1][j][k]+(j==C[i] ? 0 : P[i][j]);
                    for(int l=1;l<=M;l++){
                        if(l==j)continue;
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][l][k-1]+(j==C[i] ? 0 : P[i][j]) );
                        //if(i==2&&j==1&&k==1)cout<<"YEE"<<l<<" "<<dp[i-1][l][k-1]<<" "<<dp[i][j][k]<<endl;
                    }

                    if(k==K&&i==N)ans=min(ans,dp[i][j][k]);
                    //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                }
                //puts("");
            }
            //puts("");
        }
        printf("%I64d\n",ans>=INF ? -1 : ans);
    }
    return 0;
}
