#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 200005
#define LL long long int
using namespace std;
int N,Q;
vector<int> G[MAXN];
LL V[MAXN];
int tour[MAXN];
LL A[MAXN];
int sz[MAXN];

int lowbit(int x){return x&(-x);}
void add(int x,LL v)
{
    while(x<=N)
    {
        A[x]+=v;
        x+=lowbit(x);
    }
}
LL query(int l,int r)
{
    LL sumr=0,suml=0;
    while(r>0)
    {
        sumr+=A[r];
        r-=lowbit(r);
    }
    l--;
    while(l>0)
    {
        suml+=A[l];
        l-=lowbit(l);
    }
    return sumr-suml;
}

int dfs_clock;
void dfs(int now,int fa)
{
    sz[now]=1;
    add(++dfs_clock,V[now]);
    tour[now]=dfs_clock;
    for(int i=0;i<G[now].size();i++)
    {
        int to=G[now][i];
        if(to!=fa)
        {
            dfs(to,now);
            sz[now]+=sz[to];
        }
    }
}

int main()
{
    while(scanf("%d%d",&N,&Q)==2)
    {
        dfs_clock=0;A[0]=0;
        for(int i=1;i<=N;i++){scanf("%lld",&V[i]);G[i].clear();sz[i]=0;A[i]=0;}
        for(int i=1;i<=N-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1,-1);
        //cout<<A[tour[1]]<<endl;
        //for(int i=1;i<=N;i++){add(tour[i],A[tour[i]]);}
        //for(int i=1;i<=N;i++)printf("%d\n",A[i]);
        for(int i=0;i<Q;i++)
        {
            int c,k;
            LL v;
            scanf("%d%d",&c,&k);
            if(c==1)
            {
                scanf("%lld",&v);
                add(tour[k],v-V[k]);
                V[k]=v;
            }
            else
                printf("%lld\n",query(tour[k],tour[k]+sz[k]-1));
        }
    }
    return 0;
}
