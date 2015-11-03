#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int S,T;
const int INF=1000000;
int dp[4005];
vector<int> factor;
int isprime(int N)
{
    if(N==1)return 0;
    if(N==2)return 1;
    for(int i=2;i*i<=N;i++)
    {
        if(!(N%i))return 0;
    }
    return 1;
}

void calc(int N)
{
    int K=N;
    factor.clear();
    for(int i=2;i*i<=K;i++)
    {
        while(isprime(i)&&!(N%i))
        {
            factor.push_back(i);
            N/=i;
        }
    }
    if(isprime(N)&&N!=K&&N*N!=K)factor.push_back(N);
}
int main()
{
    int kase=0;
    while(scanf("%d %d",&S,&T)==2)
    {
        if(!S&&!T)break;
        for(int i=0;i<4005;i++)dp[i]=INF;
        if(T>=S)
        {
            dp[S]=0;
            for(int i=S;i<=T;i++)
            {
                if(dp[i]!=INF)
                {
                    calc(i);
                    for(int j=0;j<factor.size();j++)
                    {
                        if(dp[i]+1<dp[i+factor[j]])
                        {
                            dp[i+factor[j]]=dp[i]+1;
                        }
                    }
                }
            }
        }
        if(dp[T]!=INF)printf("Case %d: %d\n",++kase,dp[T]);
        else printf("Case %d: -1\n",++kase);
    }
    return  0;
}
