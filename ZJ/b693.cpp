#include <stdio.h>
#include <iostream>
#include <string.h>

#define LL long long int
#define MAXN 17

using namespace std;

LL dp[2][1<<MAXN][2];
int C[MAXN][MAXN][2];
LL N,M;

int main()
{
    while(scanf("%lld%lld",&N,&M)==2)
    {
        memset(dp,0,sizeof(dp));
        memset(C,0,sizeof(C));
        int mask=(1<<(N))-1;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d%d",&C[i][j][0],&C[i][j][1]);
            }
        }
        dp[0][0][0]=1;
        dp[0][0][1]=1;
        int cur=1;
        LL ans=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                for(int S=0;S<(1<<N);S++)
                {
                    //cout<<S<<endl;
                    if(!dp[cur^1][S][0])continue;
                    int up=(S>>(N-1))&1;
                    int left=S&1;
                    //int now=S&1;
                    for(int fill=0;fill<2;fill++)
                        if(C[i-1][j][up]!=C[i][j][fill] && C[i][j-1][left]!=C[i][j][fill])
                        {
                            dp[cur][((S<<1)|fill)&mask][1] += dp[cur^1][S][1];
                            dp[cur][((S<<1)|fill)&mask][1]%=M;
                            //cout<<i<<" "<<j<<"  "<<fill<<" "<<dp[cur^1][S][1]<<endl;
                            dp[cur][((S<<1)|fill)&mask][0] = 1;
                        }
                    //if(C[i-1][j][up]!=C[i][j][1] && C[i][j-1][left]!=C[i][j][1]) r++;

                }
                for(int S=0;S<(1<<N);S++)
                {
                    //cout<<i<<" "<<j<<"  "<<dp[cur][S][1]<<endl;
                    dp[cur^1][S][0]=dp[cur^1][S][1]=0;
                }
                cur^=1;
            }
        }
        for(int S=0;S<(1<<(N));S++)ans+=dp[cur^1][S][1],ans%=M;
        printf("%lld\n",ans);
    }
    return 0;
}
