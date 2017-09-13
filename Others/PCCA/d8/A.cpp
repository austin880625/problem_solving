#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10005
using namespace std;

int N;
vector<int> G[2][305];
int cnt;
int p[MAXN];
int vis[MAXN];
int dj[MAXN];
char A[305][305];
int ans[305];

int find(int x){return x==dj[x] ? x : dj[x]=find(dj[x]);}
void join(int x,int y){
    int u=find(x),v=find(y);

    if(u!=v){
        dj[u]=v;
    }
}
int main(){
    while(scanf("%d",&N)==1){
        cnt=0;
        for(int i=0;i<N;i++){
            scanf("%d",p+i);
            dj[i]=i;
            G[0][i].clear();
            G[1][i].clear();
        }
        for(int i=0;i<N;i++){
            scanf("%s",A[i]);
            for(int j=0;j<N;j++){
                if(A[i][j]=='1')join(i,j);
            }
        }
        for(int i=0;i<N;i++){
            int g=find(i);
            G[0][g].push_back(p[i]);
            G[1][g].push_back(i);
        }
        for(int i=0;i<N;i++){
            if(G[0][i].size()){sort(G[0][i].begin(),G[0][i].end());}
        }
        for(int i=0;i<N;i++){
            int u=find(i);
            for(int j=0;j<G[0][u].size();j++){
                ans[G[1][u][j]]=G[0][u][j];
            }
        }
        printf("%d",ans[0]);
        for(int i=1;i<N;i++)printf(" %d",ans[i]);
        puts("");
        //fflush(stdout);
    }
    return 0;
}
