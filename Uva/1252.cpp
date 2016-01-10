#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 140
#define MAXM 13
#define INF 0x3f3f3f3f
using namespace std;
int N,M;
int dp[1<<MAXM][1<<MAXM];
char s[MAXM];
int val[MAXN];
void print(int x)
{
    for(int i=0;i<M;i++)
    {
        printf("%d",(x>>(M-i-1))&1);
    }
    puts("");
}

int DP(int S,int ans)
{
    int rep=0;
    //print(S),print(ans);
    if(dp[S][ans]!=-1)return dp[S][ans];
    for(int i=0;i<N;i++)
    {
        if(ans==(S&val[i]))rep++;
    }
    if(rep<=1)return dp[S][ans]=0;
    //cout<<rep<<endl;
    int res=INF;
    for(int i=0;i<M;i++)
    {
        if(!((S>>i)&1))res=min(res,1+max(DP(S^(1<<i),ans),DP(S^(1<<i),ans^(1<<i))));
    }
    //cout<<res<<endl;
    return dp[S][ans]=res;
}

int main()
{
    while(scanf("%d%d",&M,&N)==2&&(N||M))
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            scanf("%s",s);
            val[i]=0;
            for(int j=0;j<M;j++)
            {
                val[i]<<=1;
                val[i]^=(int)(s[j]-'0');
            }
            //cout<<"yee"<<endl;
        }
        int res=DP(0,0);
        printf("%d\n",res);
    }
    return 0;
}
