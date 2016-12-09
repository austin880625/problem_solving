#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#define MAXN 200
using namespace std;

struct Node
{
    int x,y;
    Node(int _x,int _y){x=_x;y=_y;}
};

int N,M;
string S[MAXN];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[MAXN][MAXN];
queue<Node> Q;

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)
        {
            cin>>S[i];
            for(int j=0;j<M;j++)
            {
                d[i][j]=10000;
                if(S[i][j]-'0'==1)Q.push(Node(i,j)),d[i][j]=0;
            }
        }
        while(!Q.empty())
        {
            Node x=Q.front();Q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x.x+dx[i],ny=x.y+dy[i];
                if(nx<0||nx>=N||ny<0||ny>=M)continue;
                if(d[nx][ny]==-1||d[nx][ny]>d[x.x][x.y]+1)
                {
                    d[nx][ny]=d[x.x][x.y]+1;
                    Q.push(Node(nx,ny));
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(j)printf(" ");
                printf("%d",d[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
