#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXN 100005
#define INF 2147483646
using namespace std;
int N,T;
int dp[MAXN];
int boss[MAXN];
vector<int> G[MAXN];

bool cmp(int x,int y){return dp[x]<dp[y];}
void DP(int x)
{
    if(!G[x].size()){dp[x]=1;return;}
    for(int i=0;i<G[x].size();i++)
    {
        DP(G[x][i]);
    }
    sort(G[x].begin(),G[x].end(),cmp);
    int need=((G[x].size()*T)-1)/100 + 1;
    for(int i=0;i<need;i++)dp[x]+=dp[G[x][i]];
}

int main()
{
    while(scanf("%d%d",&N,&T)==2&&(N||T))
    {
        for(int i=0;i<=N;i++){dp[i]=0;G[i].clear();}
        boss[0]=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&boss[i]);
            G[boss[i]].push_back(i);
        }
        DP(0);
        //for(int i=0;i<=N;i++)cout<<dp[i]<<" ";
        //puts("");
        printf("%d\n",dp[0]);
    }
    return 0;
}
