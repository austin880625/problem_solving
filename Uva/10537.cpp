#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <assert.h>

#define LL long long int
const LL INF=(1LL<<62LL)-1LL;
using namespace std;

struct Node{
    int id;
    LL d;
    bool operator <(const Node &x)const{
        return d>x.d;
    }
};

int N;
LL P;
char S,T;
LL d[256];
bool done[256];
int p[256];

vector<int> G[256];
priority_queue<Node> Q;

LL bins(LL x)
{
    LL L=0,R=INF;
    while(L<R)
    {
        LL mid=(L+R)/2LL;
        LL n=mid-(mid+19LL)/20LL;
        if(n<x)L=mid+1LL;
        else R=mid;
    }
    return L;
}

int main()
{
    int kase=0;
    while(scanf("%d",&N)==1&&N!=-1)
    {
        for(int i=0;i<256;i++)G[i].clear(),d[i]=INF,done[i]=false,p[i]=0;

        for(int i=0;i<N;i++)
        {
            char u[2],v[2];
            scanf("%s %s",u,v);
            G[(int)u[0]].push_back((int)v[0]);
            G[(int)v[0]].push_back((int)u[0]);
        }
        char s[2],t[2];
        scanf("%lld %s %s",&P,s,t);
        S=(int)s[0],T=(int)t[0];
        d[T]=P;
        Q.push((Node){T,P});
        while(!Q.empty())
        {
            Node x=Q.top();Q.pop();
            int u=x.id;
            if(done[u])continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++)
            {
                int v=G[u][i];
                LL w;
                //(d+x+19)/20=x => 19x=d+19
                if('a'<=u&&u<='z')w=1LL;
                else w=bins(d[u])-d[u];
                if(d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    Q.push((Node){v,d[v]});
                    p[v]=u;
                }
                else if(d[v]==d[u]+w&&u<p[v])
                {
                    p[v]=u;
                }
            }
        }
        assert(d[S]<INF);
        printf("Case %d:\n",++kase);
        printf("%lld\n",d[S]);
        for(int now=S;now!=T;now=p[now])
        {
            assert(now!=0);
            printf("%c-",(char)now);
        }
        printf("%c\n",(char)T);
        //puts("");
    }
    return 0;
}
