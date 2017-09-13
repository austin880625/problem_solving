#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

#define MAXN 105
#define MOD 1000000007
#define P 18301
#define LL long long

using namespace std;

int N;
vector<int> G[2][MAXN];
int sz[MAXN];
vector<int> centroid;

void get_cen(int t, int now, int fa)
{
    sz[now]=1;
    int maxch=0;
    for(int i=0;i<G[t][now].size();i++)
    {
        int v=G[t][now][i];
        if(v==fa)continue;
        get_cen(t,v,now);
        maxch=max(maxch,sz[v]);
        sz[now]+=sz[v];
    }
    maxch=max(maxch,N-sz[now]);
    if(maxch*2<=N)centroid.push_back(now);
}

LL get_hash(int t, int now, int fa)
{
    LL res=1;
    set<LL> ch_hash;
    for(int i=0;i<G[t][now].size();i++)
    {
        int v=G[t][now][i];
        if(v==fa)continue;
        ch_hash.insert(get_hash(t,v,now));
    }
    for(set<LL>::iterator it=ch_hash.begin();it!=ch_hash.end();it++)
    {
        res=((res^(*it))*P)%MOD;
    }
    return res;
}

int main()
{
    while(scanf("%d",&N)==1&&N!=0)
    {
        for(int i=0;i<=N;i++)G[0][i].clear(),G[1][i].clear();
        for(int i=0,u,v;i<N-1;i++)
        {
            scanf("%d%d",&u,&v);
            G[0][u].push_back(v);
            G[0][v].push_back(u);
        }
        centroid.clear();
        get_cen(0,1,0);
        assert(centroid.size()<=2);
        LL h1=get_hash(0,centroid[0],0);
        for(int i=0,u,v;i<N-1;i++)
        {
            scanf("%d%d",&u,&v);
            G[1][u].push_back(v);
            G[1][v].push_back(u);
        }
        centroid.clear();
        get_cen(1,1,0);
        assert(centroid.size()<=2);
        int ans=0;
        LL h2=get_hash(1,centroid[0],0);
        if(h1==h2)ans=1;
        if(centroid.size()==2){
            h2=get_hash(1,centroid[1],0);
            if(h1==h2)ans=1;
        }
        printf(ans ? "Same\n" : "Different\n");
    }
    return 0;
}
