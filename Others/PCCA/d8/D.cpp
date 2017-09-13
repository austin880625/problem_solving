#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define LL long long int

#define MAXN 100005
using namespace std;

int N,M;
vector<int> G[MAXN];
LL dp[MAXN];
int deg[MAXN];
int odeg[MAXN];
queue<int> Q;

int main(){
    while(scanf("%d%d",&N,&M)==2){
        for(int i=0;i<=N;i++)dp[i]=deg[i]=odeg[i]=0,G[i].clear();
        for(int i=0,u,v;i<M;i++){
            scanf("%d%d",&u,&v);
            if(u>v)G[v].push_back(u),deg[u]++;
            else G[u].push_back(v),deg[v]++;
            odeg[u]++,odeg[v]++;
        }
        for(int i=1;i<=N;i++){
            if(deg[i]==0)Q.push(i),dp[i]=odeg[i];
        }
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i];
                if(dp[v]<(dp[u]/odeg[u]+1)*odeg[v]){
                    dp[v]=(dp[u]/odeg[u]+1LL)*odeg[v];

                }
                deg[v]--;
                if(!deg[v])Q.push(v);
            }
        }
        LL ans=0,id=0;
        for(int i=1;i<=N;i++){
            if(ans<dp[i]){
                ans=dp[i];
                id=i;
            }
            //cout<<i<<" "<<odeg[i]<<" "<<dp[i]<<endl;
        }
        printf("%I64d\n",(LL)ans);
    }
    return 0;
}
