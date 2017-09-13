#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 505

using namespace std;

int assigned[MAXN];
int w[MAXN][MAXN];
char ans[MAXN];
vector<int> G[MAXN];
int N,M,B;

void fill(int x){
    ans[x]='a';
    assigned[x]=1;
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        if(!assigned[v]){
            ans[v]='a';
            assigned[v]=1;
        }
    }
    for(int i=1;i<=N;i++){
        if(!assigned[i])ans[i]='c',assigned[i]=1;
    }
}

int verify(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(abs(ans[i]-ans[j])<=1){
                if(!w[i][j])return 0;
            }
            else if(w[i][j])return 0;
        }
    }
    return 1;
}

int main(){
    while(scanf("%d%d",&N,&M)==2){
        B=0;
        for(int i=0;i<=N;i++){
            G[i].clear();
            assigned[i]=0;
            for(int j=0;j<=N;j++)w[i][j]=0;
        }
        for(int i=0,u,v;i<M;i++){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            w[u][v]=w[v][u]=1;
        }
        for(int i=1;i<=N;i++){
            if(G[i].size()==N-1){
                B++;
                assigned[i]=1;
                ans[i]='b';
            }
        }
        for(int i=1;i<=N;i++){
            if(!assigned[i])fill(i);
        }
        ans[N+1]='\0';
        //printf("%s\n",ans+1);
        int ans1=verify();
        //ans[N+1]='\0';
        printf(ans1 ? "Yes\n" : "No\n");
        if(ans1)printf("%s\n",ans+1);
    }
    return 0;
}
