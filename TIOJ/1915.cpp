#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 500005

using namespace std;

struct Node
{
    int deg,id;
    bool operator <(const Node &x)const
    {
        return deg>x.deg;
    }
};
int T,N,M;
int allocated[MAXN];
int deg[MAXN];
priority_queue<Node> Q;
vector<int> G[MAXN];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=0;i<=N;i++)G[i].clear(),deg[i]=allocated[i]=0;
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        int ans1=0;
        for(int i=0;i<N;i++)
        {
            int t=0;
            for(int j=0;j<G[i].size();j++)
            {
                if(G[i][j]>i)t++;
            }
            ans1=max(ans1,t);
            Q.push((Node){deg[i],i});
        }
        int ans2=0;
        while(!Q.empty())
        {
            Node x=Q.top();Q.pop();
            if(allocated[x.id]){continue;}
            ans2=max(ans2,x.deg);
            allocated[x.id]=1;
            for(int i=0;i<G[x.id].size();i++)
            {
                deg[G[x.id][i]]--;
                Q.push((Node){deg[G[x.id][i]],G[x.id][i]});
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
