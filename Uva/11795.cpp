#include <iostream>
#include <stdio.h>
#define MAXN 18
#define LL long long int
using namespace std;

int T,N;
int R[MAXN];
char s[MAXN];
LL dp[1<<MAXN];
LL DP(int S)
{
    if(S==(1<<(N+1))-1)return dp[S]=1LL;
    if(dp[S])return dp[S];
    int canfight=0;
    for(int i=0;i<=N;i++)
    {
        if((S>>i)&1)
        {
            canfight|=R[i];
            //cout<<"r "<<R[i]<<endl;
        }
    }
    //cout<<"c"<<S<<" "<<canfight<<endl;
    LL res=0;
    for(int i=0;i<=N;i++)
    {
        if(!((S>>i)&1)&&(canfight>>i)&1)
        {
            //cout<<(S^(1<<i))<<endl;
            res+=DP(S^(1<<i));
        }
    }
    return dp[S]=res;
}

int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<=N;i++)
        {
            scanf("%s",s);
            R[i]=0;
            for(int j=0;j<N;j++)
            {
                R[i]|=((int)(s[j]-'0'))<<j;
            }
            R[i]<<=1,R[i]|=1;
        }
        //cout<<R[0]<<endl;
        for(int i=0;i<=(1<<(N+1));i++)dp[i]=0;
        //DP(R[0]);
        LL ans=DP(1);
        printf("Case %d: %lld\n",++kase,ans);
    }
}
