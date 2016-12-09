#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 55
#define eps 1e-5
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int u,v;
    double w;
};

int T,N,M;
vector<edge> edges;
vector<int> G[MAXN];
double d[MAXN];
bool inq[MAXN];
int cnt[MAXN];

bool BellmanFord(double k)
{
    // when we return,the queue may not be empty
queue<int> Q;
    for(int i=1;i<=N;i++)
    {
        d[i]=0;
        cnt[i]=0;
        inq[i]=true;
        Q.push(i);
    }

    while(!Q.empty())
    {
        int now=Q.front();Q.pop();
        inq[now]=false;
        for(int i=0;i<G[now].size();i++)
        {
            edge &e=edges[G[now][i]];
            if(d[e.v]>d[now]+e.w-k)
            {
                d[e.v]=d[now]+e.w-k;
                if(!inq[e.v])
                {
                    inq[e.v]=true;
                    Q.push(e.v);
                    if(++cnt[e.v]>N)return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        edges.clear();
        scanf("%d %d",&N,&M);
        for(int i=0;i<=N;i++)G[i].clear();
        double L=0.0,R=0.0;
        for(int i=0;i<M;i++)
        {
            int u,v;double w;
            scanf("%d %d %lf",&u,&v,&w);
            G[u].push_back(edges.size());
            edges.push_back((edge){u,v,w});
            R=max(w,R);
            L=min(w,L);
        }
        R+=10;L-=10;
        printf("Case #%d: ",++kase);
        if(!BellmanFord(R)){puts("No cycle found.");continue;}
        while(R-L>eps)
        {
            double mid=(L+R)/2;
            if(BellmanFord(mid))R=mid;
            else L=mid;
        }

        printf("%.2lf\n",R);
    }
    return 0;
}
