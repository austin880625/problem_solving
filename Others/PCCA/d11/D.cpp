#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100005
#define INF 100000000000000000LL
#define LL long long int

using namespace std;

struct edge{
    int v,train;
    LL w;
    bool operator <(const edge &x)const{
        return w>x.w;
    }
};

int N,M,K;
vector<edge> G[MAXN];
priority_queue<edge> Q;
LL d[MAXN];
int p[MAXN];
int vis[MAXN];

int main(){
    while(scanf("%d%d%d",&N,&M,&K)==3){
        for(int i=1;i<=N;i++)G[i].clear(),d[i]=INF,p[i]=-1,vis[i]=0;
        for(int i=0,u,v,w;i<M;i++){
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back((edge){v,0,w});
            G[v].push_back((edge){u,0,w});
        }
        for(int i=0,s,t;i<K;i++){
            scanf("%d%d",&s,&t);
            G[1].push_back((edge){s,1,t});
        }

        int ans=0;
        //for(int i=0;i<E.size();i++)cout<<istrain[i];puts("");
        d[1]=0;
        Q.push((edge){1,0,0});
        while(!Q.empty()){
            edge x=Q.top();Q.pop();
            int u=x.v;
            if(vis[u])continue;
            vis[u]=1;
            for(size_t i=0;i<G[u].size();i++){
                edge &e=G[u][i];
                int v=e.v;

                if(d[v]>d[u]+e.w){
                    if(p[v]==1)ans--;
                    p[v]=e.train;
                    if(!vis[v])Q.push((edge){v,0,d[v]=d[u]+e.w});
                    if(p[v]==1)ans++;
                }
                else if(d[v]==d[u]+e.w&&e.train<p[v]){
                    ans--;
                    p[v]=e.train;
                    //if(p[v]==1)ans++;
                }

            }
        }
        printf("%d\n",K-ans);
    }
    return 0;
}
