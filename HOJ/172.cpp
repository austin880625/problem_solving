#include <iostream>
#include <stdio.h>
#include <queue>
#define MAXN 1005
using namespace std;

struct Node
{
    int r,c,step;
    int B;
};

int dr[8]={1,-1,2,-2,1,-1,2,-2};
int dc[8]={2,2,1,1,-2,-2,-1,-1};
int N,M;
char grid[MAXN][MAXN];
int vis[2][MAXN][MAXN];
int sr,sc;
queue<Node> Q;
int bfs()
{
    Q.push((Node){sr,sc,0,0});
    vis[0][sr][sc];
    while(!Q.empty())
    {
        Node x=Q.front();Q.pop();
        if(grid[x.r][x.c]=='C'&&x.B)return x.step;
        for(int i=0;i<8;i++)
        {
            int nr=x.r+dr[i],nc=x.c+dc[i];
            if(nr>=N||nr<0||nc>=M||nc<0||grid[nr][nc]=='X')continue;
            int nb=x.B||grid[nr][nc]=='B';
            if(vis[nb][nr][nc])continue;
            vis[nb][nr][nc]=1;
            Q.push((Node){nr,nc,x.step+1,nb});
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&N,&M);
    for(int l=0;l<2;l++)for(int i=0;i<N;i++)for(int j=0;j<M;j++)vis[l][i][j]=0;
    for(int i=0;i<N;i++)
    {
        scanf("%s",grid[i]);
        for(int j=0;j<M;j++)
        {
            if(grid[i][j]=='A')sr=i,sc=j;
        }
    }
    printf("%d\n",bfs());
    return 0;
}
