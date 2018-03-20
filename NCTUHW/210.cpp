#include <stdio.h>
#include <iostream>
#include <vector>

#define MAXN 1005

using namespace std;

int N;
int dfs_clk,scc_cnt;
int stamp_owner[MAXN];
int vis[MAXN];
int sccno[MAXN];
int indeg[MAXN];
vector<int> SCC[MAXN],G[MAXN],Gr[MAXN],SCCG[MAXN];

void dfs_for_stamp(int now){
    vis[now]=1;
    for(int i=0;i<Gr[now].size();i++){
        int v=Gr[now][i];
        if(vis[v])continue;
        dfs_for_stamp(v);
    }
    stamp_owner[++dfs_clk]=now;
}
void dfs_for_scc(int now){
    vis[now]=1;
    sccno[now]=scc_cnt;
    SCC[scc_cnt].push_back(now);
    for(int i=0;i<G[now].size();i++){
        int v=G[now][i];
        if(vis[v])continue;
        dfs_for_scc(v);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        dfs_clk=0;
        for(int i=0;i<N;i++)G[i].clear(),Gr[i].clear(),SCC[i].clear(),SCCG[i].clear(),vis[i]=sccno[i]=indeg[i]=0,stamp_owner[i]=-1;
        for(int i=0;i<N;i++){
            for(int j=0,w;j<N;j++){
                scanf("%d",&w);
                if(w==1){G[i].push_back(j),Gr[j].push_back(i);}
            }
        }
        for(int i=0;i<N;i++)if(!vis[i])dfs_for_stamp(i);
        for(int i=0;i<N;i++)vis[i]=0;
        scc_cnt=0;
        for(int i=dfs_clk;i>=1;i--){
            if(!vis[stamp_owner[i]])dfs_for_scc(stamp_owner[i]),scc_cnt++;
        }
        for(int u=0;u<N;u++){
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i];
                if(sccno[u]!=sccno[v])SCCG[sccno[u]].push_back(sccno[v]),indeg[sccno[v]]++;
            }
        }
        int ans=10000;
        for(int i=0;i<scc_cnt;i++){
            if(indeg[i]==0)ans=min(ans,(int)SCC[i].size());
        }
        printf("%d\n",ans);
        //if(T)puts("");
    }
    return 0;
}
