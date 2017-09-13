#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 50000
#define MAXN 100005
#define MAXM 15
#define MAXNODE 1055
using namespace std;

int N,M;
int F[MAXN];
int A[MAXM];

struct edge{
    int u,v,cap,flow;
};
vector<edge> E;
vector<int> G[MAXNODE];
int c[MAXNODE];
int d[MAXNODE];
int cur[MAXNODE];
int ans;
queue<int> Q;

int BFS(int s,int t)
{
    for(int i=0;i<MAXNODE;i++)d[i]=0;
    d[s]=1;
    Q.push(s);
    while(!Q.empty())
    {
        int now=Q.front();Q.pop();
        for(int i=0;i<G[now].size();i++)
        {
            edge &e=E[G[now][i]];
            if(d[e.v]||e.cap<=e.flow)continue;
            d[e.v]=d[now]+1;
            Q.push(e.v);
        }
    }
    return d[t];
}

int DFS(int now,int bottleneck,int t)
{
    int res=0;
    //cout<<now<<" "<<d[now]<<" "<<bottleneck<<endl;
    if(now==t||!bottleneck)return bottleneck;
    for(int i=cur[now];i<G[now].size();i++)
    {
        edge &e=E[G[now][i]];
        //cout<<d[e.u]<<" "<<d[e.v]<<endl;
        if(d[e.v]!=d[e.u]+1)continue;
        int d=DFS(e.v,min(bottleneck,e.cap-e.flow),t);
        if(d>0)
        {
            res+=d;
            e.flow+=d;
            E[G[now][i]^1].flow-=d;
            bottleneck-=d;
            if(bottleneck==0){cur[now]=i;break;}
        }
    }
    return res;
}

int Dinic(int s,int t)
{
    int f=0;
    while(BFS(s,t))
    {
        for(int i=0;i<MAXNODE;i++)cur[i]=0;
        f+=DFS(s,INF,t);
        //cout<<d[t]<<endl;
    }
    return f;
}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)F[i]=0;
        for(int i=0;i<MAXNODE;i++)c[i]=0,G[i].clear();
        E.clear();
        for(int i=0;i<N;i++)
        {
            for(int j=0,t;j<M;j++)
            {
                scanf("%d",&t);
                F[i]<<=1;F[i]|=t;
            }
            c[F[i]]++;
        }
        int s=1024;
        for(int i=0;i<1024;i++)
        {
            if(c[i])
            {
                G[s].push_back(E.size());
                E.push_back((edge){s,i,c[i],0});
                G[i].push_back(E.size());
                E.push_back((edge){i,s,0,0});
                for(int t=1;t<=M;t++)
                {
                    if((i>>(M-t))&1)
                    {
                        G[i].push_back(E.size());
                        E.push_back((edge){i,s+t,c[i],0});
                        G[s+t].push_back(E.size());
                        E.push_back((edge){s+t,i,0,0});
                    }
                }
            }
        }
        int t=1040;
        for(int i=0;i<M;i++)
        {
            scanf("%d",A+i);
            G[s+1+i].push_back(E.size());
            E.push_back((edge){s+1+i,t,A[i]});
            G[t].push_back(E.size());
            E.push_back((edge){t,s+1+i,0,0});
        }
        //for(auto e:E){cout<<e.u<<" "<<e.v<<endl;}
        ans=Dinic(s,t);
        printf(ans==N ? "YES" : "NO");
        puts("");
    }
    return 0;
}
