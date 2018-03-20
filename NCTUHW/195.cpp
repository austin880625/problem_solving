#include <stdio.h>
#include <iostream>
#include <queue>
#define LL long long int
#define MAXN 21

using namespace std;

int w[25][25];
LL dp[22][1<<21];
int N,M;

struct state{
    int r;
    int s;
};

queue<state> Q;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=0;i<=N+1;i++){for(int j=0;j<(1<<N);j++)dp[i][j]=0;}
        for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)w[i][j]=0;
        for(int i=0,x,y;i<M;i++)scanf("%d%d",&x,&y),w[x][y]=1;
        int s=(1<<N)-1;
        Q.push((state){1,s});
        dp[1][s]=1;
        while(!Q.empty())
        {
            state S=Q.front();Q.pop();
            //if(S.r<=3)cout<<S.r<<" ";
            for(int j=0;j<N;j++){
                if(((S.s>>j)&1)&&w[S.r][j+1]!=1){
                    int t=((1<<N)-1)^(1<<j);
                    if(!dp[S.r+1][S.s&t])Q.push((state){S.r+1,(S.s&t)});
                    dp[S.r+1][S.s&t]+=dp[S.r][S.s];
                }
            }
        }
        printf("%lld\n",dp[N+1][0]);
    }
    return 0;
}
