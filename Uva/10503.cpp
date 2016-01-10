#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXM 29
using namespace std;

struct domino
{
    int u,v;
};
int M,N;
vector<domino> X;
int vis[MAXM];
int S,T,a,b;

int dfs(int dep,int now)
{
    int res=0;
    if(dep==N)res|= X[now].v==T;
    vis[now]=vis[now^1]=1;
    for(int i=0;i<2*M;i++)
    {
        if(X[i].u==X[i].v&&i%2)continue;
        if(!vis[i]&&X[i].u==X[now].v){
            //cout<<dep<<" "<<i<<" "<<X[i].u<<" "<<X[i].v<<endl;
            res|=dfs(dep+1,i);
        }
    }
    vis[now]=vis[now^1]=0;
    return res;
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        if(!N)break;
        scanf("%d",&M);
        for(int i=0;i<MAXM;i++)vis[i]=0;
        scanf("%d%d%d%d",&a,&S,&T,&b);
        X.clear();
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&a,&b);
            X.push_back((domino){a,b});
            X.push_back((domino){b,a});
        }
        int ans=0;
        for(int i=0;i<2*M;i++)
        {
            if(X[i].u==S){ans|=dfs(1,i);}
        }
        printf(ans ? "YES" : "NO");
        puts("");
    }
    return 0;
}
/*
3
4
0 1
3 4
2 1
5 6
2 2
3 2
2
4
0 1
3 4
1 4
4 4
3 2
5 6
0
*/
