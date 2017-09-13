#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define MAXN 100005
#define LL long long int
#define INF 1000000000000000000
using namespace std;

struct edge{
    int v;LL w;
};
struct node{
    int id;LL d;
    bool operator <(const node &x)const{
        return d>x.d;
    }
};

int N,M;
vector<edge> G[MAXN];
LL d[MAXN];
int p[MAXN];

priority_queue<node> Q;

int main(){
    while(scanf("%d%d",&N,&M)==2){
        for(int i=0;i<=N;i++)d[i]=INF,G[i].clear(),p[i]=0;
        for(int u,v,w,i=0;i<M;i++){
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back((edge){v,w});
            G[v].push_back((edge){u,w});
        }
        d[1]=0;
        Q.push((node){1,0});
        while(!Q.empty()){
            node x=Q.top();Q.pop();
            int u=x.id;
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i].v;LL w=G[u][i].w;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    p[v]=u;
                    Q.push((node){v,d[v]});
                }
            }
        }
        if(d[N]>=INF)puts("-1");
        else{
            int now=N;
            vector<int> path;
            while(now!=1){
                path.push_back(now);
                now=p[now];
            }
            printf("%d",1);
            for(int i=path.size()-1;i>=0;i--)printf(" %d",path[i]);
            puts("");
        }
    }
    return 0;
}
