#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#define INF 2147483646

using namespace std;
int d[3][505][505];
int grid[505][505];
struct pos
{
    int x,y,trap;
};
queue<pos> Q;
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        int sx,sy,ex,ey;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<M;k++)
                {
                    d[i][j][k]=INF;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            string row;
            cin>>row;
            for(int j=0;j<M;j++)
            {
                if(row[j]=='A')
                    grid[i][j]=0;
                else if(row[j]=='B')
                    grid[i][j]=1;
                else if(row[j]=='C')
                    grid[i][j]=2;
                else if(row[j]=='#')
                    grid[i][j]=3;
                else if(row[j]=='.')
                    grid[i][j]=4;
                else if(row[j]=='X'){
                    grid[i][j]=5;
                    sx=i;sy=j;
                }
                else if(row[j]=='Y'){
                    grid[i][j]=6;
                    ex=i;ey=j;
                }
            }
        }

        Q.push((pos){sx,sy,0});
        d[0][sx][sy]=0;
        while(!Q.empty())
        {
            pos P=Q.front();Q.pop();
            int nx,ny;
            for(int i=0;i<4;i++)
            {
                nx=P.x+dx[i],ny=P.y+dy[i];
                if(nx<0||nx>=N||ny<0||ny>=M)continue;
                if(d[(P.trap+1)%3][nx][ny]==INF&&grid[nx][ny]!=(P.trap+1)%3&&grid[nx][ny]!=3)
                {
                    d[(P.trap+1)%3][nx][ny]=d[P.trap][P.x][P.y]+1;
                    Q.push((pos){nx,ny,(P.trap+1)%3});
                }
            }
        }
        int ans=INF;
        for(int i=0;i<3;i++)ans=min(ans,d[i][ex][ey]);
        if(ans==INF)printf("-1");
        else printf("%d",ans);
        puts("");
    }
    return 0;
}
