#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 1005

using namespace std;

struct edge
{
    int u,v,w;
};
int N,M;
vector<edge> E;
int d[MAXN];
int pre[MAXN];

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        E.clear();
        for(int i=1;i<=N;i++)d[i]=INF,pre[i]=-1;d[1]=0;
        for(int i=0,u,v,w;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            E.push_back((edge){u,v,w});
            E.push_back((edge){v,u,w});
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<E.size();j++)
            {
                edge &e=E[j];
                if(d[e.v]>d[e.u]+e.w)
                {
                    d[e.v]=d[e.u]+e.w;
                    pre[e.v]=j;
                }
            }
        }
        int ans=d[N];
        //cout<<ans<<endl;
        int cur=N;
        while(cur!=1)
        {
            E[pre[cur]].w=INF;
            E[pre[cur]^1].w=-E[pre[cur]^1].w;
            cur=E[pre[cur]].u;
        }
        for(int i=1;i<=N;i++)d[i]=INF;d[1]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<E.size();j++)
            {
                edge &e=E[j];
                if(d[e.v]>d[e.u]+e.w)
                {
                    d[e.v]=d[e.u]+e.w;
                }
            }
        }
        ans+=d[N];
        printf("%d\n",ans);
    }
    return 0;
}
