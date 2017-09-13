#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAXN 505

using namespace std;

int N,M;
vector<int> G[MAXN];
int vis[MAXN];
int ans=10000000;

struct p{int a,b;};
queue<p> Q;

void test(int x)
{
    for(int i=0;i<=N;i++)vis[i]=10000000;
    while(!Q.empty())Q.pop();
    Q.push((p){x,1});
    while(!Q.empty()){
        p y=Q.front();Q.pop();
        int u=y.a;
        vis[u]=y.b;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(v==x){ans=min(ans,vis[u]);return ;}
            if(vis[v]>vis[u]+1)
            {
                vis[v]=vis[u]+1;
                Q.push((p){v,vis[u]+1});
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&N,&M)==2&&(N||M))
    {
        ans=10000000;
        for(int i=0;i<=N;i++)G[i].clear();
        for(int i=0,u,v;i<M;i++)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        for(int i=1;i<=N;i++)test(i);
        printf("%d\n",ans==10000000 ? 0 : ans);
    }
    return 0;
}
