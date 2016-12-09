#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define LL long long int
#define MAXN 1000005
using namespace std;

struct edge
{
    int u,v;
    LL w;
    bool operator <(const edge& rhs)const
    {
        return w<rhs.w;
    }
};

int N,M;
edge E[MAXN*3];
int p[MAXN];
int find(int x)
{
    return x==p[x] ? x : p[x]=find(p[x]);
}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<=N;i++)p[i]=i;
        int es=0;
        LL ans=0;
        for(int i=0;i<M;i++)
        {
            int a,b;
            LL c,d;
            scanf("%d%d%lld%lld",&a,&b,&c,&d);
            if(c<d)
            {
                ans+=c-d;
                int u=find(a),v=find(b);
                if(u!=v)
                {
                    p[u]=v;
                }
                continue;
            }
            E[es++]=(edge){a,b,c-d};
        }
        sort(E,E+es);
        for(int i=0;i<es;i++)
        {
            int u=find(E[i].u),v=find(E[i].v);
            if(u!=v)
            {
                p[u]=v;
                ans+=E[i].w;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
