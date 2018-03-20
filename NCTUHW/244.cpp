#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <queue>
#define MAXN 5005
#define LL long long int
#define INF 1000000000000LL

using namespace std;

struct edge{
    int v;LL w;
    edge(int _v, LL _w){v=_v;w=_w;}
    bool operator <(const edge &x)const{return w>x.w;}
};

int T,M,N;
int s,t;
vector<edge> G[MAXN];
LL h[MAXN];
LL d[MAXN];
int cnt[MAXN];
int inq[MAXN];
queue<int> Q;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&N,&M,&s,&t);
        for(int i=0;i<=N;i++){G[i].clear();d[i]=INF;inq[i]=cnt[i]=0;}
        while(!Q.empty())Q.pop();
        for(int i=1;i<=N;i++)scanf("%lld",h+i);
        for(int i=0;i<M;i++){
            int u,v;LL w;
            scanf("%d%d%lld",&u,&v,&w);
            G[u].push_back(edge(v,w+h[u]-h[v]));
            G[v].push_back(edge(u,w+h[v]-h[u]));
        }
        d[t]=0;Q.push(t);inq[t]=1;
        LL ans=INF;
        while(!Q.empty()){
            int u=Q.front();Q.pop();inq[u]=0;
            for(int i=0;i<G[u].size();i++){
                edge &e=G[u][i];int v=e.v;
                assert(d[u]!=INF);
                if(d[v]>d[u]+e.w){
                    d[v]=max(0LL,d[u]+e.w);
                    if(!inq[v]){
                        Q.push(v);
                    }
                }
            }
        }
        ans=d[s];
        if(ans<0){printf("0\n");continue;}
        printf("%lld\n",ans);
    }
}
